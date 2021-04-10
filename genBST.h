#ifndef AL_LIST_GENBST_H
#define AL_LIST_GENBST_H

#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
template<class T, int capacity=30>
class Stack{
    public:
        Stack(){
            p.reserve(capacity);
        }

        void clear(){
            p.clear();
        }

        bool isEmpty() const{
            return p.empty();
        }

        T& topE1(){
            return p.back();
        }

        T pop(){
            T val = p.back();
            p.pop_back();
            return val;
        }

        void push(const T& el){
            p.push_back(el);
        }

        void visualize(){
            for(auto it=p.begin(); it!=p.end(); it++)
                std::cout<<(*it)->el<<" ";
            std::cout<<"\n";
        }
    private:
        std::vector<T> p;
};


template<class T>
class Queue : public std::queue<T>{
public:
    T dequeue(){
        T tmp = std::queue<T>::front();
        std::queue<T>::pop();
        return tmp;
    }

    void enqueue(const T& el){
        push(el);
    }
};

template<class T>
class BSTNode{
public:
    BSTNode(){
        left = right = nullptr;
    }

    BSTNode(const T& e, BSTNode<T> *l=nullptr, BSTNode<T> *r = nullptr){
        el = e; left = l; right = r;
    }
    T el;
    BSTNode<T> *left, *right;
};

template<class T>
class BST{
public:
    BST(){
        root=0;
    }
    ~BST(){

    }
    void clear(){

        root =nullptr;
    }
    bool isEmpty() const{
        return root==nullptr;
    }
    void preorder(){
        preorder(root);
    }
    void inorder(){
        inorder(root);
    }
    void postorder(){
        postorder(root);
    }
    T* search(const T& el) const{
        return search(root, el);
    }

    void breadthFirst();
    void iterativePreorder();
    void iterativeInorder();
    void iterativePostorder();
    void MorrisInorder();
    void insert(const T&);
    void deleteByMerging(BSTNode<T>*&);
    void findAndDeleteByMerging(const T&);
    void findAndDeleteByCopying(const T&);
    void deleteByCopying(BSTNode<T>*&);
    void balanceArray(T [], int);
    void visualize_tree();
    void createbackbone();
    void createPerfectTree();

protected:

    BSTNode<T>* root;
    void clear(BSTNode<T>*);
    T* search(BSTNode<T>*, const T&);
    void preorder(BSTNode<T>*);
    void inorder(BSTNode<T>*);
    void postorder(BSTNode<T>*);
    void balance(T*, int, int);
    void printnode(const BSTNode<T>*, int );
    void rotateRight(BSTNode<T>*, BSTNode<T>*,BSTNode<T>*);
    void rotateLeft(BSTNode<T>*, BSTNode<T>*, BSTNode<T>*);
    virtual void visit(BSTNode<T>* p){
        std::cout<<p->el<<"\n";
    }

};

template<class T>
void BST<T>::createPerfectTree() {
    int n = 0;
    BSTNode<T> *p=root, *prev= nullptr, *chi= nullptr;
    while(p!= nullptr) {
        p = p->right;
        n = n+1;
    }
    int m=  std::exp2(std::floor(std::log2(n+1)))-1;
    std::cout<<m;
    p=root;
    // pre_global_rotation
    for(int i=0;i <(n-m); i++){
        chi = p->right;
        rotateLeft(prev, p, chi);
        prev = chi;
        p = chi->right;
        std::cout<<"the rotation"<<std::endl;
        visualize_tree();
    }


    while(m>1){
        m = m/2;
        prev= nullptr;
        p = root;
        for(int i=0;i<m;i++) {
            chi = p->right;
            rotateLeft(prev, p, chi);
            prev = chi;
            p = chi->right;
            std::cout<<"the rotation"<<std::endl;
            visualize_tree();
        }
    }

}

template<class T>
void BST<T>::rotateLeft(BSTNode<T> * gra, BSTNode<T> * par, BSTNode<T> *chi) {
        if(gra == nullptr){
            par->right = chi->left;
            chi->left = par;
            root = chi;
        }else{
            par->right = chi->left;
            chi->left = par;
            gra->right = chi;
        }
}

template<class T>
void BST<T>::rotateRight(BSTNode<T> * gra, BSTNode<T> * par, BSTNode<T> *chi) {
    if(gra == nullptr){
        par->left = chi->right;
        chi->right = par;
        root = chi;
    }else{
        par->left = chi->right;
        chi->right = par;
        gra->right = chi;
    }

}

template<class T>
void BST<T>::createbackbone() {
    BSTNode<T> *tmp=root, *prev= nullptr, *child= nullptr;
    while(tmp!= nullptr){
        if(tmp->left!= nullptr) {
            child = tmp->left;
            rotateRight(prev, tmp, child);
            tmp=child;
        }
        else{
            prev = tmp;
            tmp = tmp->right;
        }
        std::cout<<"the adjust the tree"<<std::endl;
        visualize_tree();
    }
}



template<class T>
void BST<T>::printnode(const BSTNode<T> *p, int level) {
    level = level+1;
    if(p->left!= nullptr)
        printnode(p->left, level);

    for(int i=0;i<level;i++) std::cout<<"    ";
    std::cout<<p->el<<std::endl;

    if(p->right!= nullptr)
        printnode(p->right, level);

}

template<class T>
void BST<T>::visualize_tree() {
    int level=0;
    printnode(root, 0);

}


template<class T>
void BST<T>::balanceArray(T array[], int n) {
    std::sort(array, array+n);
    balance(array,0, n-1);
}

template<class T>
void BST<T>::balance(T * array, int start, int end) {
    if(start<=end){
        int middle = (start+end)/2;
        insert(array[middle]);
        balance(array, start, middle-1);
        balance(array, middle+1, end);
    }
}


template<class T>
void BST<T>::findAndDeleteByCopying(const T& el) {
    BSTNode<T> *prev, *p=root;
    //find the node of the mentioned value



    while(p != nullptr){
        if(el<p->el){
            prev = p;
            p = p->left;

        }else if (el>p->el){
            prev = p;
            p= p->right;
        }else break;
    }

    if(p!= nullptr && p->el==el){
        if(p==root){
            deleteByCopying(root);
        }else if(prev->right->el == el){
            deleteByCopying(prev->right);
        }else{
            deleteByCopying(prev->left);
        }


    }else{
        std::cout<<"there is no value:"<<el<<std::endl;
    }

}

template<class T>
void BST<T>::findAndDeleteByMerging(const T& el) {
    BSTNode<T> *prev, *p=root;
    //find the node of the mentioned value



    while(p != nullptr){
        if(el<p->el){
            prev = p;
            p = p->left;

        }else if (el>p->el){
            prev = p;
            p= p->right;
        }else break;
    }

    if(p!= nullptr && p->el==el){
        if(p==root){
            deleteByMerging(root);
        }else if(prev->right->el == el){
            deleteByMerging(prev->right);
        }else{
            deleteByMerging(prev->left);
        }

    }else{
        std::cout<<"there is no value:"<<el<<std::endl;
    }
}


template<class T>
void BST<T>::deleteByCopying(BSTNode<T> *& node) {
    BSTNode<T> *tmp, *prev, *p;
    tmp = node;
    if(node->right== nullptr)
        node = node->left;
    else if (node->left == nullptr)
        node = node->right;
    else{
        p = node->left;
        if (p->right==nullptr){
            node = p;
            node->right = tmp->right;
        }else{
            while (p->right != nullptr) {
                prev = p;
                p = p->right;
            }
            // 开始嫁接
            prev->right = p->left;
            node = p;
            node->right = tmp->right;
            node->left = tmp->left;

        }
    }
    delete tmp;
}

template<class T>
void BST<T>::deleteByMerging(BSTNode<T> *& node) {
    BSTNode<T> *tmp = node;

    if(node != nullptr) {
        if (node->right == nullptr)
            node = node->left;
        else if(node->left == nullptr)
            node = node->right;
        else{
            tmp = node->left;
            while(tmp->right != nullptr)
                tmp = tmp->right;

            tmp->right = node->right;
            tmp = node;
            node = node->left;
        }
        delete tmp;
    }
}

template<class T>
void BST<T>::iterativePreorder() {
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    if(p!= nullptr){
        travStack.push(p);
        while(!travStack.isEmpty()){
            p=travStack.pop();
            visit(p);
            if(p->right != nullptr)
                travStack.push(p->right);
            if(p->left != nullptr)
                travStack.push(p->left);
        }
    }
}


template<class T>
void BST<T>::iterativeInorder() {

    if(root == nullptr)
        return;
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    travStack.push(p);
    while(!travStack.isEmpty()){
        while(p!= nullptr)
        {

            p = p->left;
            if (p != nullptr)
                travStack.push(p);
//            std::cout<<"visual 3"<<std::endl;
//            travStack.visualize();
        }

        p = travStack.pop();
//        std::cout<<"visual 1"<<std::endl;
//        travStack.visualize();
//        std::cout<<"output"<<std::endl;
        visit(p);
        if(p->right!= nullptr){
            p = p->right;
            travStack.push(p);
//            std::cout<<"visual 2"<<std::endl;
//            travStack.visualize();
        }else{
            p=nullptr;
        }

    }
}

template<class T>
void BST<T>::iterativePostorder() {

    if(root == nullptr)
        return;

    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    // load the
    do{

        while(p!= nullptr)
        {
            if(p->right != nullptr)
                travStack.push(p->right);
            travStack.push(p);
            p = p->left;
        }
        p = travStack.pop();
//        std::cout<<"visual 2"<<std::endl;
//        travStack.visualize();

        if(p->right != nullptr && travStack.topE1()==p->right)
        {
            travStack.pop();
            travStack.push(p);
//            std::cout<<"visual 3"<<std::endl;
//            travStack.visualize();
            p = p->right;
        }else{
//            std::cout<<"output:"<<p->el<<"\n";
            visit(p);
            p = nullptr;
        }
    }while(!travStack.isEmpty());

}


template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) {
    while (p!= nullptr)
        if(el == p->el)
            return &p->el;
        else if (el<p->el)
            p = p->left;
        else p = p->right;
    return 0;
}

template<class T>
void BST<T>::breadthFirst() {
    Queue<BSTNode<T>*> queue;
    BSTNode<T> *p = root;
    if(p != 0) {
        queue.enqueue(p);
        while(!queue.empty()){
            p = queue.dequeue();
            visit(p);
            if (p->left != nullptr)
                queue.enqueue(p->left);
            if (p->right != nullptr)
                queue.enqueue(p->right);
        }
    }
}


template<class T>
void BST<T>::inorder(BSTNode<T> *p){
    if (p!= nullptr){
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template<class T>
void BST<T>::preorder(BSTNode<T> *p) {
    if(p!= nullptr){
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T> *p){
    if(p!= nullptr){
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}




template<class T>
void BST<T>::insert(const T& el){
    if(root == nullptr)
    {
        root = new BSTNode<T>(el);
        return;
    }

    BSTNode<T> *p = root, *prev= nullptr;
    while(p != nullptr){
        prev = p;
        if(el<p->el)
            p=p->left;
        else p=p->right;
    }

    if(el<prev->el)
        prev->left = new BSTNode<T>(el);
    else
        prev->right = new BSTNode<T>(el);
}




#endif //AL_LIST_GENBST_H
