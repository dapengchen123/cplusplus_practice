//
// Created by hp on 27/02/2021.
//

#ifndef AL_LIST_GENARRAYQUEUE_H
#define AL_LIST_GENARRAYQUEUE_H

template<class T, int size = 100>
class ArrayQueue {
public:
    ArrayQueue(){
        first = last =-1;
    }

    void enqueue(T);
    T dequeue();
    bool isFull(){
        return (first==0 && last==size-1) || last+1==first;
    }
    bool isEmpty(){
        return first == -1;
    }

private:
    int first, last;
    T storage[size]
};


#endif //AL_LIST_GENARRAYQUEUE_H
