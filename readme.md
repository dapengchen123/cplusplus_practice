### Queue 的实现原理
queue 为了最大限度的利用空间，一般采用circular array的形式。
但是由于circular array 是利用普通array的形式进行实现的, 因此有两种情况说明这个队列是满的
（1） 一种是last iterator 在first iterator的左边
（2） 一种是first iterator 在数组的第一个位置上， last iterator 在数据的最后一个位置上.


