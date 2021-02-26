### Notes on Stack in C++

### String Usages
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
