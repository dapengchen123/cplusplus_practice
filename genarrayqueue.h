//
// Created by hp on 27/02/2021.
//

#ifndef AL_LIST_GENARRAYQUEUE_H
#define AL_LIST_GENARRAYQUEUE_H

namespace Parrots {
    template<class T, int size = 100>
    class ArrayQueue {
    public:
        ArrayQueue() {
            first = last = -1;
        }

        void enqueue(T);

        T dequeue();

        bool isFull() {
            return (first == 0 && last == size - 1) || last + 1 == first;
        }

        bool isEmpty() {
            return first == -1;
        }

    private:
        int first, last;
        T storage[size]
    };

    template<class T, int size>
    void ArrayQueue<T, size>::enqueue(T el) {
        if (!isFull()) {
            if (last == size - 1 || last == -1) {
                storage[0] = el;
                last = 0;
                if (first == -1)
                    first = 0;
            } else {
                storage[++last] = el;
            }

        } else std::cout << "Full queue. \n";
    }

    template<class T, int size>
    T ArrayQueue<T, size>::dequeue() {
        if (!isEmpty()) {
            T tmp = storage[first];
            if(first==last) first=last=-1;
            elseif (first==size-1)   first =0;
            else first = first+1;
            return tmp;
        }
        else std::cout << "Empty queue. \n";
    }

}

#endif //AL_LIST_GENARRAYQUEUE_H
