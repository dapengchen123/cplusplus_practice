//
// Created by hp on 22/02/2021.
//
#include <iostream>
#include "intSLList.h"

namespace Parrots{

    IntSLList::~IntSLList() {
        IntSLLNode *p;
        while(!isEmpty()){
            p = head->next;
            delete head;
            head = p;
        }
    }

    void IntSLList::addToHead(int val) {
        head = new IntSLLNode(val, head);
        if (tail == nullptr)
            tail = head;
    }

    void IntSLList::addToTail(int val) {
        if (tail != nullptr){
        tail->next = new IntSLLNode(val);
        tail = tail->next;
        }
        else head = tail = new IntSLLNode(val);

        std::cout<< val<<'\n';
    }

    int IntSLList::deleteFromHead() {
        if(!isEmpty()) {
            int val = head->info;
            IntSLLNode *p = head;
            if (head == tail)
                head = tail = nullptr;
            else
                head = head->next;

            delete p;
            return val;
        }else {
            std::cout<<"This is an empty list\n";
            return 0;
        }
    }

    int IntSLList::deleteFromTail() {

        int val = tail->info;
        if (head == tail){
            head = tail = nullptr;
        }
        else{
            IntSLLNode* tmp;
            for(tmp= head; tmp->next != tail; tmp = tmp->next);
            delete tail;
            tail = tmp;
            tail->next = nullptr;
        }
            return val;
    }

//    void IntSLList::deleteNode(int val) {
//        if (head != nullptr){
//            if (head == tail && head->info == val){
//                delete head;
//                head = tail = nullptr;
//            }
//            else if (head->info == val){
//                IntSLLNode* p=head;
//                head = head->next;
//                delete p;
//            }
//            else{
//                IntSLLNode *tmp, *pred;
//                for(pred=head, tmp=head->next;  //初始化指针
//                    (tmp!= nullptr) && (tmp->info != val); //当条件没有满足时
//                    pred=pred->next, tmp=tmp->next); //指针往前移动
//
//                if (tmp != nullptr){
//                    pred->next = tmp->next;
//                    if  (tmp == tail)
//                        tail = pred;
//                    delete tmp;
//                }
//            }
//
//        }
//
//    }


    void IntSLList::deleteNode(int val){
        if(!isEmpty()){
            if (head==tail && head->info==val){
                delete head;
                head = tail = nullptr;
            }
            else if(head->info==val){
                IntSLLNode *tmp = head;
                head = head->next;
                delete tmp;
            }else{
                IntSLLNode *tmp, *pred;

                for(pred=head, tmp=head->next;  //初始化指针
                (tmp!= nullptr) && (tmp->info != val); //当条件没有满足时
                pred=pred->next, tmp=tmp->next); //指针往前移动

                if(tmp != nullptr){
                    pred->next = tmp->next;
                    if  (tmp == tail)
                        tail = pred;
                    delete tmp;
                }
            }

        }
    }




    bool IntSLList::isInList(int val) const {

        if (!isEmpty()){
            IntSLLNode* tmp;
            for (tmp=head; (tmp!= nullptr)&&(tmp->info != val); tmp=tmp->next);
            return tmp != nullptr;
        }

        return false;
    }

    void IntSLList::visualize() {


        if (head == nullptr){
            std::cout<<"no elements"<<'\n';
        }
        else if ( head == tail){
            std::cout<<head->info<<'\n';
        }else{
            std::cout<<head->info<<'\n';
            IntSLLNode* p=head;
            while(p->next != nullptr){
                p=p->next;
                std::cout<<p->info<<'\n';
            }
        }

    }

}