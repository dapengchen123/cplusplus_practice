### Queue 的实现原理
queue 为了最大限度的利用空间，一般采用circular array的形式。
但是由于circular array 是利用普通array的形式进行实现的, 因此有两种情况说明这个队列是满的
（1） 一种是last iterator 在first iterator的左边
（2） 一种是first iterator 在数组的第一个位置上， last iterator 在数据的最后一个位置上.

#### Arrayqueue 的实现原理
1， enqueue：在queue没有满的情况下，  

(1) 一种是特殊情况，last已经到达最后了

(2)一种情况是，first 还没有开始
 
(3) 另一种情况是普通的情况，需要在last后面增加元素

2， dequeue:
在队列不是空队列的情况下

(1) first在最后一个位置，需要移到第一个位置 

(2) 一般情况下，first 往后移动一个位置

(3) 当last和first重合的时候，只剩下了最后一个元素，在交出元素以后， last和first重置到-1.


### Bank One Example 
英文扫盲： clerk 做文书工作的人

### 银行系统排队的问题
![alt text](imgs/bank_queue.png "images")


（1）首先要产生在某一次模拟中足量的arrive event进行处理， 在还存在event的时候
   1.1  arrive event    
   1.2  departure event
   1.3
#### 实现细节
（1） 栈和队列都属于一种特殊的数据结构，只能通过访问顶层数据并不断剔除数据的方法进行全部访问，因此没有直接的迭代器

（2） 友元进行输入输出
```c++
ostream& operator<<(ostream& _cout, Date& date)
{
	_cout << date._year << "-" << date._month << "-" << date._day;
	return _cout;
}

```

(3)

### 实现一个priority queue  

https://www.geeksforgeeks.org/priority-queue-using-linked-list/

### 如何成长成一名架构师

https://www.zhihu.com/question/40520339/answer/99790593

### 如何使用 pybind
https://www.jianshu.com/p/9619f8f02891

在程序中用pybind11，讲一个priority queue的实现转移至python中

(1) 首先切换到conda python3的环境中

(2）安装 pybind11的c++库， 直接从源码中进行build，并且通过make install 进行安装

(3) 在CMakeLists 中添加 
···
find_package(pybind11 CONFIG)
···

这里和传统的C++程序不同不存在如main函数一样的接口函数，倒是类似于C++中的库函数
在cmake中

pybind11_add_module(prority_queue priority.cpp )

这里prority_queue 是库的名称--编译成功以后， 在python 中import prority_queue进行使用
   priority.cpp 是相关的源码以及定义的pybind11接口

(4) 实例代码

### 函数的代码
```c++
#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}
PYBIND11_MODULE(example, m){
    m.doc() = "pybind11 example plugin";
    m.def("add", &add, "A function which add two number");
}
```
### 类的代码
```c++
/*
                省略 priority queue的源码
 */
PYBIND11_MODULE(prority_queue, m) {
    pybind11::class_<Priority_queue>(m, "Priority_queue")
    .def(pybind11::init<>())
    .def("push", &Priority_queue::push)
    .def("pop", &Priority_queue::pop)
    .def("visulization",&Priority_queue::visualization);
}

```
更复杂的python继承C++功能的规则可以参见
https://pybind11.readthedocs.io/en/stable/advanced/classes.html