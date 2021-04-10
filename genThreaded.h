//
// Created by hp on 05/04/2021.
//

#ifndef AL_LIST_GENTHREADED_H
#define AL_LIST_GENTHREADED_H
template<class T>
class ThreadedNode{
    public:
        ThreadedNode(){
            left = right = nullptr;
        }
        ThreadedNode(const T& e, ThreadedNode<T> *l= nullptr, ThreadedNode<T> *r= nullptr){
            el = e; left = l; right =r; successor = 0;
        }
        T el;
        ThreadedNode *left, *right;
        unsigned int successor : 1;

};

template<class T>
class ThreadedTree{
    public:
        ThreadedTree(){
            root = nullptr;
        }
        void insert(const T&);
        void inorder();


    protected:
        ThreadedNode<T>* root;
        virtual void visit(const ThreadedNode<T> *p){
            std::cout<<p->el<<" ";
        }
};


//template<class T>
//void ThreadedTree<T>::insert(const T& el) {
//    ThreadedNode<T> *p, *prev = nullptr, *newNode;
//    newNode = new ThreadedNode<T>(el);
//    if (root == nullptr){
//        root = newNode;
//        return;
//    }
//
//    p = root;
//
//    while( p != nullptr){
//        prev = p;
//        if(p->el > el)
//            p=p->left;
//        else if (p->successor == 0)
//            p = p->right;
//        else break;   //reach the leave
//    }
//
//    if (prev->el > el ){
//        prev->left = newNode;
//        newNode->successor = 1;
//        newNode->right = prev;
//    }
//    else if (prev->successor == 1){
//        newNode->successor = 1;
//        prev->successor = 0;
//        newNode->right = prev->right;
//        prev->right = newNode;
//    }
//    else{
//        prev->right = newNode;
//        newNode->successor = 0;
//    }
//}
//

template<class T>
void ThreadedTree<T>::insert(const T & el) {
    ThreadedNode<T> * newNode = new ThreadedNode<T>(el);
    if (root == nullptr) {
        root = newNode;
        return;
    }

    ThreadedNode<T> *p, *prev;
    p = root;

    while(p!= nullptr){

        prev = p;

        //find the parent node for the new node
        if(el<p->el) //move left
        {
            p=p->left;
        }else if(p->successor==0){  // move right
            p=p->right;
        }else{
            break;
        }
    }

    // connect
    if(el<prev->el){
        prev->left = newNode;
        newNode->right = prev;
        newNode->successor = 1;
    }else if (prev->successor==1){
        newNode->right = prev->right;
        newNode->successor = 1;
        prev->right = newNode;
        prev->successor=0;
    }else{
        prev->right = newNode;
    }

}



template<class T>
void ThreadedTree<T>::inorder() {
    ThreadedNode<T> *prev, *p=root;

    if(p!= nullptr){
        while(p->left != nullptr){
            p=p->left;
        }

        while(p!= nullptr){
            visit(p);
            prev = p;
            p = p->right;
            if(p != nullptr && prev->successor== 0){
                while(p->left != nullptr)
                    p=p->left;
            }
        }
    }
}

#endif //AL_LIST_GENTHREADED_H
