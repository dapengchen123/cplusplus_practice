//
// Created by hp on 01/03/2021.
//

#ifndef AL_LIST_CUSTOMER_H
#define AL_LIST_CUSTOMER_H

#include "random.h"

namespace Parrots {
    class Customer {

    public:
        Customer() : _arrive_time(0),
                     _duration(Random::uniform(RANDOM_DURATION)), _left_time(0) {}

        Customer(int arrive_time) : _arrive_time(arrive_time),
                                    _duration(Random::uniform(RANDOM_DURATION)), _left_time(0) {}

    private:
        int _arrive_time;
        int _duration;
        int _left_time;
    };
}
#endif //AL_LIST_CUSTOMER_H
