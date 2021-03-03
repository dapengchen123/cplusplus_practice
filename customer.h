//
// Created by hp on 01/03/2021.
//

#ifndef AL_LIST_CUSTOMER_H
#define AL_LIST_CUSTOMER_H

#include "random.h"

class Customer{

public:
    Customer():arrive_time(0),
    duration(Random::uniform(RANDOM_DURATION)),
    next(nullptr){}

    Customer(int arrive_time):arrive_time(arrive_time),
    duration(Random::uniform(RANDOM_DURATION)),
    next(nullptr){}

private:
    int arrive_time;
    int duration;
    Customer* next;
};
#endif //AL_LIST_CUSTOMER_H
