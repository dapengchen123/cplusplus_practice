
#include<iostream>
#include<string>
#include<algorithm>


void permute(std::string a, int l, int r)
{
    if(l==r)
        std::cout<<a<<std::endl;
    for(int i=l; i<=r; i++)
    {
        std::swap(a[l],a[i]);
        permute(a,l+1,r);
        std::swap(a[l],a[i]);
    }
}



int main(){

    std::string str = "ABC";
    int n = str.length();
    permute(str, 0 ,n-1);
    return 0;
}

// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/