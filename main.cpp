#include <iostream>
#include "priority.h"


int main() {

    Parrots::Priority_queue pq;
    pq.push(1,1);
    pq.push(3,3);
    pq.push(47,47);
    pq.push(6,6);
    pq.push(17,17);
    pq.push(10,10);
    pq.push(27,27);
    pq.push(57,57);

    std::cout<<"the lowest number is "<<pq.peek()<<"\n";
    std::cout<<"visualization the whole nodes \n";
    pq.visualization();

    return 0;
}
