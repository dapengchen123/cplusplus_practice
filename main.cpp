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


//    Parrots::IntSLList singlelist;
//    std::array<int, 8> array={1, 2, 7, 9, 10, 12, 16, 19};
//    singlelist.Initial_witharray<8>(array);
//    std::cout << "Hello, World!" << std::endl;
//    singlelist.visualize();
//    std::cout << "delete from tail" << std::endl;
//    singlelist.deleteFromTail();
//    singlelist.visualize();
//    std::cout << "delete from tail" << std::endl;
//    singlelist.deleteFromTail();
//    singlelist.visualize();
//    std::cout<<"starting the DLList part \n";

//    Parrots::DLList<int> doublelist;
//    std::array<int, 8> array_0={5,6,7,8,1,2,3,4};
//    doublelist.Initial_witharray<8>(array_0);
//    doublelist.visualize();
//    std::cout << "delete from tail" << std::endl;
//    doublelist.deleteFromDLLTail();
//    doublelist.visualize();
//    std::cout << "delete from tail" << std::endl;
//    doublelist.deleteFromDLLTail();
//    doublelist.visualize();
//    std::cout << "add from tail" << std::endl;
//    doublelist.addToDLLTail(17);
//    doublelist.visualize();
//    std::cout << "add from tail" << std::endl;
//    doublelist.addToDLLTail(19);
//    doublelist.visualize();


    Parrots::SkipList<int> skiplist;
    std::array<int, 24> array_2={5,6,7,8,1,2,3,4,
                                 15,16,17,18,11,12,13,14,
                                 25,26,27,28,21,22,23,24};
    skiplist.Initial_witharray<24>(array_2);
    skiplist.visualize();
    std::cout<<"searching the elements 2 \n";
    int* p1;
    p1 = skiplist.skipListSearch(2);
    if (p1!= nullptr) std::cout<<"successfully found "<< *p1 <<'\n';
    std::cout<<"searching the elements 6 \n";
    auto p2 = skiplist.skipListSearch(36);
    if (p2!= nullptr) std::cout<<"successfully found"<< *p2 <<'\n';





    return 0;
}
