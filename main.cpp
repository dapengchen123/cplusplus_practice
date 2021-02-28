#include <iostream>
#include <array>
#include "intSLList.h"
#include "DLList.h"
#include "SkipL.h"

void choosePowers(int maxLevel) {
    int powers[maxLevel];
    powers[maxLevel-1] = (2<<(maxLevel-1)) - 1; // 2^maxLevel - 1
    for (int i = maxLevel -2, j = 0; i>=0; i--, j++){
        powers[i] = powers[i+1] -(2<<j);
    } //

    for (int i=0; i<maxLevel; i++){
        std::cout << powers[i] <<'\n';
    }
}

int main() {







    return 0;
}
