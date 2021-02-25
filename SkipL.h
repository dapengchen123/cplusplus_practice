//
// Created by hp on 23/02/2021.
//

#ifndef AL_LIST_SKIPL_H
#define AL_LIST_SKIPL_H
#include "get_Uniform_distribution.h"

namespace Parrots {
    const int maxLevel = 3;

    template<class T>
    class SkipListNode {
    public:
        SkipListNode() {}

        T key;
        SkipListNode **next;
    };

    template<class T>
    class SkipList {
    public:
        SkipList();

        bool isEmpty() const;

        void choosePowers();

        int chooseLevel();

        T* skipListSearch(const T &);

        void skipListInsert(const T &);

        template<size_t N>
        void Initial_witharray(const std::array<T, N>& array){
            for(T a:array) skipListInsert(a);
        }

        void visualize();
    private:

        typedef SkipListNode<T> *nodePtr;
        nodePtr root[maxLevel];
        int powers[maxLevel];
    };

    template<class T>
    SkipList<T>::SkipList() {
        for (int i = 0; i < maxLevel; i++)
            root[i] = nullptr;
        choosePowers();
    }

    template<class T>
    bool SkipList<T>::isEmpty() const {
        return root[0] == nullptr;
    }

    template<class T>
    void SkipList<T>::choosePowers() {
        powers[maxLevel - 1] = (2 << (maxLevel - 1)) - 1; // 2^maxLevel - 1
        for (int i = maxLevel - 2, j = 0; i >= 0; i--, j++)
            powers[i] = powers[i + 1] - (2 << j);  //
    }

    template<class T>
    int SkipList<T>::chooseLevel() {
        int i, r = rand() % powers[maxLevel - 1] + 1;
        for (i = 1; i < maxLevel; i++)
            if (r < powers[i])
                return i - 1; // return a level < the highest level;
        return i - 1; // return the highest level;
    }

    template<class T>
    void SkipList<T>::visualize() {
        for (int lvl = maxLevel-1; lvl>=0; lvl--){
            nodePtr curr=root[lvl];
            std::cout<<"the level "<<lvl<<" elements\n";
            while(curr != nullptr){
                std::cout<<curr->key<<" ";
                curr=*(curr->next+lvl);
            }
            std::cout<<"\n";
        }

    }

//    template<class T>
//    T* SkipList<T>::skipListSearch(const T & key) {
//        if (isEmpty()) return nullptr;
//        nodePtr prev, curr;
//        int lvl;
//        for (lvl = maxLevel-1; lvl >=0 && !root[lvl]; lvl--);
//        prev = curr = root[lvl];
//        while(true) {
//
//            if (key == curr->key){
//                return  &curr->key;
//            }else if (key < curr->key){
//                if (lvl == 0 )
//                    return nullptr;
//                else if (curr == root[lvl])
//                    curr = root[--lvl];
//                else
//                    curr = *(prev->next+ --lvl);
//            }
//            else{
//                prev = curr;
//                if (*(curr->next + lvl) != nullptr)
//                    curr = *(curr->next +lvl);
//                else{
//                    for (lvl--; lvl >= 0 && *(curr->next +lvl) ==0; lvl --);
//                    if (lvl >= 0)
//                        curr = *(curr->next +lvl);
//                    else
//                        return 0;
//                }
//            }
//        }
//    }

    template<class T>
    T* SkipList<T>::skipListSearch(const T& key) {
        if (isEmpty()) {
            std::cout<<"this is a null skip list\n";
            return nullptr;
        }
        nodePtr prev, curr;  // 初始化指针
        int lvl;
        for (lvl = maxLevel - 1; lvl != 0 && root[lvl] == nullptr; lvl--);   // 将prev 和 curr 指针初始化到合适的地方
        prev = curr = root[lvl];                           // 初始化 prev 和 curr 指针

        // 分情况讨论
        while (true) {
            if (curr->key == key) {  //case1  curr 等于 key
                return &curr->key;
            } else if (curr->key < key) { //case 2  curr 小于 key
                prev = curr;  //将 prev 移动到 curr的位置
                if (*(curr->next + lvl) != nullptr)
                    curr = *(curr->next + lvl);
                else {
                    for (lvl--; lvl >= 0 && *(curr->next + lvl) != nullptr; lvl--);
                    if (lvl >= 0)
                        curr = *(curr->next + lvl);
                    else return nullptr;
                }
            } else { //case 3 curr  大于 key
                // 分情况讨论

                if (lvl == 0) return nullptr; // 1， lvl == 0
                else if (curr==root[lvl])     // 2,  lvl == 1
                    curr = root[--lvl];
                else
                    curr = *(prev->next + --lvl); // 3, lvl == 2
            }
        }

    }

    template<class T>
    void SkipList<T>::skipListInsert(const T& key) {
        nodePtr curr[maxLevel], prev[maxLevel];
        // 应该是检索部分
        curr[maxLevel-1] = root[maxLevel-1];
        prev[maxLevel-1] = nullptr;

        // 将要新建的节点的邻居都提前找到
        for (int lvl = maxLevel-1; lvl >= 0; lvl--){
            while (curr[lvl] && curr[lvl]->key<key){ //进行跳转到下一个节点
                prev[lvl] = curr[lvl];
                curr[lvl] = *(curr[lvl]->next + lvl);
            }

            if(curr[lvl] && curr[lvl]->key == key)  //这是因为已经有相同值的节点了，不需要进一步引入
                return;

            if(lvl > 0) {
                if (prev[lvl] == nullptr) {
                    curr[lvl - 1] = root[lvl - 1];
                    prev[lvl - 1] = nullptr;

                } else {
                    prev[lvl - 1] = prev[lvl];
                    curr[lvl - 1] = *(prev[lvl]->next + lvl - 1);
                }
            }

        }
        // 进行节点新建的活动
        int lvl = chooseLevel();
        nodePtr newNode = new SkipListNode<T>;
        newNode->next = new nodePtr[sizeof(nodePtr)*(lvl+1)];
        newNode->key = key;

        // 将邻居进行重新连接
        for (int i=0; i<=lvl; i++){
            *(newNode->next + i) = curr[i];   //初始化
            if (prev[i] == 0)
                root[i] = newNode;
            else *(prev[i]->next+i) = newNode;
        }
    }
}

#endif //AL_LIST_SKIPL_H
