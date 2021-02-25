//
// Created by hp on 23/02/2021.
//

#ifndef AL_LIST_GET_UNIFORM_DISTRIBUTION_H
#define AL_LIST_GET_UNIFORM_DISTRIBUTION_H
#include <bits/stdc++.h>

int64_t rand64(int64_t nMax = 9223999036854775807U)
{
    int64_t nRandData = 0;
    for(int i=0; i<8; i++){
        int64_t  nMask =0xFF;
        nMask = nMask<<(i*8);
        int bData = ((nMax & nMask)>>(i*8)) & 0xFF;
        if(bData > 0) {
            int64_t nData = rand() % bData;
            nRandData |= nData << (i * 8);
        }
    }
    return nRandData;
}


double uniform_distribution(){
    int32_t e = -1 + 64;    // want e = -1, -64 happens always below
    uint64_t m = 0;      // this must be at least 64 bits
    do{
        m = rand64();    // get 64 random bits
        e = e - 64;      // we used 64 bits
        if (e < -1074)
            return 0.0;   // will round to 0.0
    }while (m == 0);    // if all bits are so far 0, continue till we get a 1

    // pos will be the index of the leading 1 in the mantissa
    int32_t pos = 63;       // start at highest bit
    while (((m >> pos) & 1) == 0)
        pos = pos - 1;

    pos = 63 - pos;     // invert for ease of use. pos is now the # of leading 0s

    if (pos != 0){
        // we need more bits: shift m, and adjust exponent
        m = (m << pos) | (rand64() >> (64-pos));
        e = e - pos;
    }

    // at this point, e is the exponent value
    // m has a 1 in the highest bit, then 63 more bits,
    // enough to pick the proper 52 for the mantissa and round correctly

    if (e > -1023){
        // normal numbers
        m = m >> 10;              // shift unneeded bits out, 54 left
        m = (m >> 1) + (m & 1);   // shift and round
        if ((m>>53) == 1)
            // rounding caused overflow past implicit leading 1, fix exponent, m fixed below
            e = e + 1;
    }
    else{
        // subnormal numbers, want top 52 bits of m
        int32_t d = -1023 - e;        // amount e is past the smallest e = -1023

        m = m >> (11 + d);       // want 52 bits left, minus the excess, plus 1 for carry
        m = (m >> 1) + (m & 1);   // shift and round
        e = -1023;                // where we are
        if ((m>>52) == 1)
            // rounding caused overflow into implicit leading 0, fix exponent, m fixed below
            e = e + 1;
    }

    uint64_t mask = 1;             // a single one bit
    mask = (mask << 52) - 1;      // done this way to avoid language specific shift issues
    m = m & mask;                 // mask bits 52-63 out. m now ready

    // now e is the final exponent and m is the final 52 bit mantissa, with no leading 1

    // create final 64 bit representation of the final value
    int64_t fi;
    fi = e + 1023;                // exponent
    fi = fi << 52;                // room for m
    fi = fi | m;                 // final value

    // language specific conversion trick
    //double f = convert fi

    // some example ways to convert are
    // C/C++ :  memcpy(&f,&fi,8)  // other methods often use undefined behavior
    // C#    :  f = BitConverter.Int64BitsToDouble(fi)
    // Java  :  f = Double.longBitsToDouble(fi)
    double f;
    memcpy(&f,&fi,8);
    return f;
}

#endif //AL_LIST_GET_UNIFORM_DISTRIBUTION_H
