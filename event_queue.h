//
// Created by hp on 01/03/2021.
//

#ifndef AL_LIST_EVENT_QUEUE_H
#define AL_LIST_EVENT_QUEUE_H

#include "random.h"
#include<iostream>


namespace Parrots{

    enum EventType{
        ARRIVED,
        DEPARTURE
    };

    class Event{
    public:

        Event(): _occur_time(Random::uniform(RANDOM_DURATION)), _service_index(-1), _event_type(EventType::ARRIVED){}

        explicit Event(int occur_time): _occur_time(occur_time), _service_index(-1), _event_type(EventType::ARRIVED){}

        Event(int occur_time, int service_index, EventType event_type): _occur_time(occur_time), _service_index(service_index), _event_type(event_type){}

        friend bool operator< (const Event& event1, const Event& event2);
        friend bool operator> (const Event& event1, const Event& event2);
        friend std::ostream& operator<<(std::ostream& _cout, const Event&  event);

        int _occur_time;
        int _service_index;
        EventType _event_type;
    };

    inline bool operator<(const Event& event1, const Event& event2){
        return event1._occur_time< event2._occur_time;
    }
    inline bool operator>(const Event& event1, const Event& event2){
        return event2<event1;
    }

    inline std::ostream& operator<<(std::ostream& _cout, const Event&  event ){
      _cout <<"event type: "<< event._event_type<<"  service index "<<event._service_index<<"  occur time "<<event._occur_time<<'\n';
      return _cout;
    }
}




#endif //AL_LIST_EVENT_QUEUE_H


//
//namespace Parrots{
//
//    enum class EventType : int{
//    ARRIVED,
//    DEPARTURE
//    };
//
//    class Event{
//public:
//    Event():occur_time(Random::uniform(RANDOM_DURATION)),
//            event_type(EventType::ARRIVED),
//            service_index(-1),
//            next(nullptr){}
//
//    Event(int occur_time):occur_time(occur_time),
//                          event_type(EventType::ARRIVED),
//                          service_index(-1),
//                          next(nullptr){}
//
//    Event(int occur_time, EventType event_type, int service_index):
//            occur_time(occur_time),
//            event_type(event_type),
//            service_index(service_index),
//            next(nullptr) {}
//
//            friend bool operator< (const Event& event1, const Event& event2);
//            friend bool operator> (const Event& event1, const Event& event2);
//private:
//    int occur_time;
//    int service_index;
//    EventType event_type;
//    Event *next;
//};
//
//    inline bool operator< (const Event& event1, const Event& event2){
//        return event1.occur_time < event2.occur_time;
//    }
//    inline bool operator> (const Event& event1, const Event& event2){
//        return event2 < event1;
//    }
//
//}


