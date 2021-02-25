//
// Created by hp on 22/02/2021.
//

#ifndef AL_LIST_INTSLLIST_H
#define AL_LIST_INTSLLIST_H
#include<array>
namespace Parrots {
    class IntSLLNode {
    public:
        int info;
        IntSLLNode *next;

        IntSLLNode() {
            next = nullptr;
        }

        IntSLLNode(int val, IntSLLNode *ptr = nullptr) {
            info = val;
            next = ptr;
        }

        void deleteNode(int val);
    };

    class IntSLList {
    public:
        IntSLList() {
            head = nullptr;
            tail = nullptr;
        }

        ~IntSLList();

        int isEmpty() const {
            return head == nullptr;
        }

        void addToHead(int);

        void addToTail(int);

        int deleteFromHead();

        int deleteFromTail();

        void deleteNode(int);

        bool isInList(int) const;

        void visualize();

        template<std::size_t N>
        void Initial_witharray(const std::array<int, N>& array){
            for(int a:array) addToTail(a);
        }



    private:
        IntSLLNode *head, *tail;

    };

}
#endif //AL_LIST_INTSLLIST_H
