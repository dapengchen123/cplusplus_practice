//
// Created by hp on 19/03/2021.
//

#ifndef AL_LIST_PRIORITY_H
#define AL_LIST_PRIORITY_H

namespace Parrots{
    class Node{

        public:
            Node(){next= nullptr;}
            Node(int d, int p){data=d; priority=p;next=nullptr;}

            int data;

            //low value high priority
            int priority;
            Node* next;

    };


    class Priority_queue{

        public:
            Priority_queue(){head= nullptr;}
            ~Priority_queue();

            bool isEmpty();
            void pop();
            void push(int, int);
            int peek();
            void visualization();
        private:
            Node* head;

    };

    Priority_queue::~Priority_queue() {
        // should delete along the list
        Node* start=head;
        while(!isEmpty()){
            start = head->next;
            delete head;
            head = start;
        }
    }

    void Priority_queue::pop(){
        Node* temp = head->next;
        delete head;
        head = temp;
    }

    bool Priority_queue::isEmpty() {
        return head== nullptr;
    }

    void Priority_queue::push(int d, int p) {

        Node* temp = new Node(d,p);

        if (head==nullptr) {
            head=temp;
        }else{
            //case 1 : the temp has a lower value, it will replace the head
            if(temp->priority<head->priority){
                temp->next = head;
                head = temp;
            }else {
                //Traverse the list and find a posiiton to insert new node
                Node *start = head;
                while (start->next != nullptr && start->next->priority < p) {
                    start = start->next;
                }
                // Either at the ends of the lists or the requried position
                temp->next = start->next;
                start->next = temp;
            }
        }
    }

    int Priority_queue::peek(){
        return head->data;
    }



    void Priority_queue::visualization() {
        Node* start=head;
        while(start != nullptr) {
            std::cout << start->data << " ";
            start = start->next;
        }
    }
}




#endif //AL_LIST_PRIORITY_H
