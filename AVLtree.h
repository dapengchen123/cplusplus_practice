//
// Created by hp on 09/04/2021.
//

#ifndef AL_LIST_AVLTREE_H
#define AL_LIST_AVLTREE_H

#include<iostream>
#include<cmath>


template<class T>
class AVLnode{
    public:
        AVLnode(){
            left = nullptr;
            right = nullptr;
            height = 1;
            key = NULL;
        }

        AVLnode(const T& val, int h=1, AVLnode<T>* l= nullptr, AVLnode<T>* r= nullptr){
            key = val;
            height = h;
            left = l;
            right = r;
        }

        AVLnode<T>  *left, *right;
        T key;
        int height;
};


template<class T>
class AVLtree{
public:
    AVLtree(){
        root=nullptr;
    }
    ~AVLtree(){}

    void insert(const T&);
    void delete_ele(const T&);
    void visualize_tree();
private:
    AVLnode<T> *root=nullptr;
    AVLnode<T>* insert(AVLnode<T>*, const T&);
    AVLnode<T>* delete_ele(AVLnode<T>*, const T&);
    int getBalance(AVLnode<T>*);
    void printnode(const AVLnode<T>*, int);
    AVLnode<T>* rightRotate(AVLnode<T>*);
    AVLnode<T>* leftRotate(AVLnode<T>*);
    void deleteByCopying(AVLnode<T>*&);
    int height(AVLnode<T>* );
};

/*        z                             z                           x
 *       / \                           / \                         /  \
 *      y  T4    left rotate (y)      x   T4   right rotate(z)    y     z
 *     / \      ----------------->   / \       -------------->   / \   / \
 *    T1  x                         y   T3                      T1 T2 T3 T4
 *       / \                       / \
 *      T2  T3                    T1 T2
 *
 *
 *        z                               z                                     x
 *       /  \                           /   \                                 /    \
 *      T1   y    right rotate(y)      T1     x     left rotate(y)           z      y
 *         /  \  ------------------>        /  \    -------------->         / \    /  \
 *        x   T4                           T2   y                          T1  T2 T3  T4
 *       /  \                                  /  \
 *      T2  T3                                T3  T4
 * */


template<class T>
void AVLtree<T>::deleteByCopying(AVLnode<T> *& node) {
    AVLtree<T> *p, *prev;

    p=node;
    if(node->right == nullptr)
        node = node->left;
    else if (node->left == nullptr)
        node = node->right;
    else{
        p = node->left;
        prev =node;
        while(p->right != nullptr){
            prev = p;
            p = p->right;
        }
        node->key = p->key;
        prev->left = p->left;
    }
   delete p;
}


template<class T>
void AVLtree<T>::delete_ele(const T& val) {
    if(root == nullptr)
        return;
    root = delete_ele(root, val);
}


template<class T>
AVLnode<T>* AVLtree<T>::delete_ele(AVLnode<T> *p, const T& val) {
    if (p== nullptr)
        std::cout<<"there is no such a element"<<std::endl;


    if(val<p->key){
        p->left = delete_ele(p->left, val);
    }else if(val>p->key){
        p->right = delete_ele(p->right, val);
    }else{
        deleteByCopying(p);




    }

}



template<class T>
int AVLtree<T>::height(AVLnode<T>* p){
    if (p == nullptr)
        return 0;

    return p->height;
}

template<class T>
void AVLtree<T>::printnode(const AVLnode<T>* p, int level){
    level = level + 1;
    if(p->left != nullptr)
        printnode(p->left, level);

    for(int i=0; i<level; i++)
        std::cout<<"     ";
    std::cout<<p->key<<std::endl;

    if(p->right != nullptr)
        printnode(p->right, level);
}

template<class T>
void AVLtree<T>::visualize_tree() {
    int level=0;
    printnode(root,0);
}

template<class T>
AVLnode<T>* AVLtree<T>::leftRotate(AVLnode<T>* y){
    AVLnode<T> * x=y->right;
    AVLnode<T> * T2 = x->left;

    // perform rotation
    y->right = T2;
    x->left = y;

    // update height
    y->height = std::max(height(y->left),
                         height(y->right))+1;

    x->height = std::max(height(x->left),
                         height(x->right))+1;



    // return the root node
    return x;
}

template<class T>
AVLnode<T>* AVLtree<T>::rightRotate(AVLnode<T>* y){
    AVLnode<T>* x = y->left;
    AVLnode<T>* T3 = x->right;

    // perform rotation
    y->left = T3;
    x->right = y;

    //update
    y->height = std::max(height(y->left),
                         height(y->right))+1;

    x->height = std::max(height(x->left),
                         height(x->right))+1;



    // return new root
    return x;
}




template<class T>
int AVLtree<T>::getBalance(AVLnode<T>* p) {
    return height(p->left) - height(p->right);
}


template<class T>
void AVLtree<T>::insert(const T& val){

    if(root == nullptr) {
        root = new AVLnode <T>(val);
        visualize_tree();
        return;
    }

    root = insert(root, val);
    visualize_tree();
}



/*
 *  Left Right Case                  Left Left Case
 *        z                             z                           x
 *       / \                           / \                         /  \
 *      y  T4    left rotate (y)      x   T4   right rotate(z)    y     z
 *     / \      ----------------->   / \       -------------->   / \   / \
 *    T1  x                         y   T3                      T1 T2 T3 T4
 *       / \                       / \
 *      T2  T3                    T1 T2
 *
 */

template<class T>
AVLnode<T>* AVLtree<T>::insert( AVLnode<T>* p, const T& val){
    if(p== nullptr)
        return new AVLnode<T>(val);
    // 1
    if(val<p->key){
        p->left = insert(p->left, val);
    }else if(val>p->key){
        p->right = insert(p->right, val);
    }else return p;

    // 2. Update height of this ancester node
    p->height = 1 + std::max(height(p->left), height(p->right));

    // 3. Get the balance factor

    int balance = getBalance(p);


    // If this node becomes unbalanced, then there are 4 cases

    //Left Left Case
    if(balance>1 && val<p->left->key)
        return rightRotate(p);

    //Left Right Case
    if(balance>1 && val>p->left->key){
        p->left = leftRotate(p->left);
        return rightRotate(p);
    }

    //Right Right Case
    if(balance<-1 && val>p->right->key){
        return leftRotate(p);
    }

    //Right Left Case
    if(balance<-1 && val<p->right->key){
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }


    return p;
}


#endif //AL_LIST_AVLTREE_H
