//
// Created by hp on 26/02/2021.
//

#ifndef AL_LIST_GNSTACK_H
#define AL_LIST_GNSTACK_H
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

namespace Parrots {
    template<class T, int capacity = 10>
    class Stack {
    public:
        Stack() {
            data.reserve(capacity);
        }

        void clear() {
            data.clear();
        }

        bool isEmpty() const {
            return data.empty();
        }

        // pop && push
        // 1, vector.back(): back 是取值的意思
        // 2, vector.pop_back(): 是把最后一个元素去除

        T &E1_val() {
            return data.back();
        }

        T pop() {
            T e1 = data.back();
            data.pop_back();
            return e1;
        }

        void push(const T &e1) {
            data.push_back(e1);
        }

        void visualize(){
            for (auto a:data) std::cout<<a<<" ";
            std::cout<<"\n";
        }

        void reverse(){
           std::reverse(data.begin(), data.end());
        }



    private:
        std::vector<T> data;


    };

    void remove_char_from_string(std::string&, char);
    void add_largenumbers(std::string&, std::string&);
}

#endif //AL_LIST_GNSTACK_H
