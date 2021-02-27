### Notes on Stack in C++

### String Usages
#### remove specific char
```c++
#include<algorithm>
using namespace std;
main() {
   string my_str = "ABAABACCABA";

   cout << "Initial string: " << my_str << endl;

   my_str.erase(std::remove(my_str.begin(), my_str.end(), 'A'), my_str.end()); //remove A from string
   cout << "Final string: " << my_str;
}
```
这里面算法分成两个部分
（1）  std:: remove(my_str.begin(), my_str.end(), 'A')
这里remove是algorithm 里面的函数，返回remove理由最后的iter的位置
（2）  erase 是string的自带函数
这里面主要将两个iter之间的额的部分给删除

### C++ 编程常识
namespace 里面的函数声明， 有两种情况
（1） 有头文件的情况，将函数在头文件里面声明就可以了
（2） 没有头文件的情况， 可以再调用的函数的开辟一个namespace，在namespace里面声明函数。

### string 函数的调用
```c++
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
int ss;
char temp[64];
string str;
ss = 1000;
sprintf(temp, "%d", ss);
string s(temp);

//调用string的方法
cout<<s.c_str()<<endl; //1000
cout<<s.size()<<endl;  //长度为4
```

### vector 进行可视化

