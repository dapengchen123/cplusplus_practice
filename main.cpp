#include <iostream>
#include <array>
#include "genBST.h"
#include "AVLtree.h"
#include "genThreaded.h"
#define ThreadTree_ON 1
int main() {


    AVLtree<int> avl;


    avl.insert(100);
    avl.insert(90);
    avl.insert(80);
    avl.insert(70);
    avl.insert(60);
    avl.insert(50);
    avl.insert(40);
    avl.insert(30);
    avl.insert(20);
    avl.insert(10);
    avl.insert(5);
    avl.visualize_tree();
//    bst.insert(5);
//    bst.insert(10);
//    bst.insert(20);
//    bst.insert(15);
//    bst.insert(30);
//    bst.insert(25);
//    bst.insert(40);
//    bst.insert(23);
//    bst.insert(28);


//    int array[] = {10,5,15,20,23,25,28,30,40};
//    int n = sizeof(array)/sizeof(array[0]);
//    bst.balanceArray(array, n);
//    std::cout<<"visualization"<<std::endl;
//    bst.visualize_tree();
//    bst.createbackbone();
//    std::cout<<"create the backbone"<<std::endl;
//    bst.visualize_tree();
//    bst.createPerfectTree();



    return 0;
}
