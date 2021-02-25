//
// Created by hp on 23/02/2021.
//

#ifndef AL_LIST_DLLIST_H
#define AL_LIST_DLLIST_H

namespace Parrots {
    template<class T>
    class DLLNode {
    public:
        DLLNode() {
            prev = next = nullptr;
        }

        DLLNode(const T &el, DLLNode *n = nullptr, DLLNode *p = nullptr) {
            info = el;
            next = n;
            prev = p;
        }

        DLLNode *prev, *next;
        T info;
    };

    template<class T>
    class DLList {
    public:
        DLList() {
            head = tail = nullptr;
        }

        ~DLList() {
            DLLNode<T> *p;
            while (!isEmpty()) {
                p = head->next;
                delete head;
                head = p;
            }
        }

        bool isEmpty() {
            return head == nullptr;
        }

        void addToDLLTail(const T &);

        T deleteFromDLLTail();

        void visualize();

        template<std::size_t N>
        void Initial_witharray(const std::array <T, N> &array) {
            for (T a:array) addToDLLTail(a);
        }

    protected:
        DLLNode<T> *head, *tail;

    };

    template<class T>
    void DLList<T>::addToDLLTail(const T &val) {
        if (!isEmpty()) {
            tail = new DLLNode<T>(val, nullptr, tail);
            tail->prev->next = tail;
        } else {
            head = tail = new DLLNode<T>(val);
        }
    }

    template<class T>
    T DLList<T>::deleteFromDLLTail() {

        if (!isEmpty()) {
            T val = tail->info;
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
        }
    }

    template<class T>
    void DLList<T>::visualize() {
        if (!isEmpty()) {
            DLLNode<T> *p = head;
            while (p != nullptr) {
                std::cout << p->info << '\n';
                p = p->next;
            }
        } else {
            std::cout << "there is no elements in the DLList\n";
        }
    }
}

#endif //AL_LIST_DLLIST_H
