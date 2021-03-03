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