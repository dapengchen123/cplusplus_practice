//
// Created by hp on 01/03/2021.
//

#ifndef AL_LIST_EVENT_QUEUE_H
#define AL_LIST_EVENT_QUEUE_H

#include "random.h"
namespace Parrots{

    enum class EventType : int{
    ARRIVED,
    DEPARTURE
    };

    class Event{
public:
    Event():occur_time(Random::uniform(RANDOM_DURATION)),
            event_type(EventType::ARRIVIED),
            service_index(-1),
            next(nullptr){}

    Event(int occur_time):occur_time(occur_time),
                          event_type(EventType::ARRIVIED),
                          service_index(-1),
                          next(nullptr){}

    Event(int occur_time, EventType event_type, int service_index):
            occur_time(occur_time),
            event_type(event_type),
            service_index(service_index),
            next(nullptr) {}

            friend bool operator< (const Event& event1, const Event& event2);
            friend bool operator> (const Event& event1, const Event& event2);
private:
    int occur_time;
    int service_index;
    EventType event_type;
    Event *next;
};

    inline bool operator< (const Event& event1, const Event& event2){
        return event1.occur_time < event2.occur_time;
    }
    inline bool operator> (const Event& event1, const Event& event2){
        return event2 < event1;
    }

}
#endif //AL_LIST_EVENT_QUEUE_H

