//
// Created by hp on 26/02/2021.
//
#include "gnStack.h"
#include <string>
#include <algorithm>
#include <iostream>
namespace Parrots {

    void remove_char_from_string(std::string& tar_str, char c) {
        tar_str.erase(std::remove(tar_str.begin(), tar_str.end(), c), tar_str.end());
    }

    void add_largenumbers(std::string& n1, std::string& n2) {
        remove_char_from_string(n1,' ');
        remove_char_from_string(n2,' ');
        Stack<char, 1000> stack1;
        Stack<char, 1000> stack2;
        Stack<char, 1000> sumstack;

        for (auto a:n1) stack1.push(a);
        for (auto a:n2) stack2.push(a);

        int s1, s2, sum, residual, value=0;

        while(!(stack1.isEmpty() && stack2.isEmpty() && value==0)){
            if (stack1.isEmpty()) s1=0;
            else s1 = stack1.pop() - '0';

            if (stack2.isEmpty()) s2=0;
            else s2 = stack2.pop() - '0';

            sum = s1+s2+value;
            std::cout<<sum<<std::endl;
            residual = sum%10;
            std::cout<<"residual:"<<residual<<std::endl;
            value = sum/10;
            std::cout<<"value:"<<value<<std::endl;

            std::string s = std::to_string(residual);
            sumstack.push(s.c_str());
        }
        sumstack.visualize();

    }

}


