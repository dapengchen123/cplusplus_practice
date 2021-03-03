//
// Created by hp on 01/03/2021.
//

#ifndef AL_LIST_MANAGER_QUEUE_H
#define AL_LIST_MANAGER_QUEUE_H

#include <queue>
#include <functional>

#include "random.h"
#include "event_queue.h"
#include "service.h"
#include "customer.h"


#define INIT_ARRIVIED_EVENT_NUM 5

namespace Parrots{

    class Manager{
    public:
        Manager(int total_serve_time, int service_num)
            : _total_serve_time(total_serve_time),
              _service_num(service_num),
              _customer_stay_time(0),
              _total_served_customer_num(0){}

        ~Manager(){};

        // 启动模拟
        void simulation(int simulation_num);

        double get_avg_stay_time() {
            return _avg_stay_time;
        }

        double get_avg_customers(){
            return _avg_customers;
        }

    private:
        void run();
        void init();
        void end();
        int get_idle_service_index();
        void customer_arrived();
        void customer_departure();
        void generate_arrived_event(int& current_time);
        void generate_departure_event(int service_index, int current_time);

        int _total_serve_time;
        int _service_num;
        long long _customer_stay_time;
        long long _total_served_customer_num;
        double _avg_customers;
        double _avg_stay_time;
        int _generate_arrived_time;
        Parrots::Services*  _services;
        const Parrots::Event* _current_event;

        std::queue<Customer> _customer_queue;
        std::priority_queue<Event, std::vector<Event>, std::greater<Event>> _event_queue;

    };


    int Manager::get_idle_service_index() {
        for(int i = 0; i< _service_num; i++){
            if(_services[i].is_idle())
                return i;
        }
        return -1;
    }

    void Manager::generate_arrived_event(int &current_time) {
        // 往时间队列里面塞人
        Parrots::Event event;
        int customer_per_minute = Random::uniform(RANDOM_PER_MINUTE);
        while (customer_per_minute > 0) {
            event = Parrots::Event(current_time);
            _event_queue.push(event);
            --customer_per_minute;
        }
        ++current_time;
    }

    void Manager::generate_departure_event(int service_index, int current_time) {
        //
        _services[service_index].serve_customer(_customer_queue.front());
        _services[service_index].set_busy();
        _services[service_index].set_service_start_time(current_time);
        _customer_queue.pop();

        int duration = _services[service_index].get_customer_duration();
        Parrots::Event event=Parrots::Event(current_time+duration, Parrots::EventType::DEPARTURE, service_index);
        _event_queue.push(event);

    }

    void Manager::customer_arrived() {
        int idle_service_num = get_idle_service_index();
        int current_time = _current_event->occur_time;
        Parrots::Customer customer = Parrots::Customer(current_time);
        _customer_queue.push(customer);
        _event_queue.pop();

        if (idle_service_num != -1)
            generate_departure_event(idle_service_num, current_time);
    }

    void Manager::customer_departure() {
        int current_time = _current_event->occur_time;
        int service_index = _current_event->service_index;

        _customer_stay_time += current_time -
                               _services[service_index].get_customer_arrive_time();
        ++_total_served_customer_num;

        _services[service_index].set_idle();
        _event_queue.pop();

        if(_customer_queue.size() > 0) {
            service_index = get_idle_service_index();//always get one idle service
            generate_departure_event(service_index, current_time);
        }
    }

    void Manager::init(){
        // init services
        _services = new Parrots::Services[_service_num];

        // init queue
        _generate_arrived_time = 0;
        while(_generate_arrived_time < INIT_ARRIVIED_EVENT_NUM){
            generate_arrived_event(_generate_arrived_time);
        }
    }


    void Manager::run(){
        while (!_event_queue.empty()){
            _current_event = &_event_queue.top();
            if(_current_event->occur_time >= _total_serve_time)
                break;
            if (_customer_queue.empty() && _event_queue.size() <= _service_num){
                generate_arrived_event(_generate_arrived_time);
                _current_event = &_event_queue.top();
            }

            if(_current_event->event_type == EventType::ARRIVED)
                customer_arrived();
            else if (_current_event->event_type ==EventType::DEPARTURE)
                customer_departure();
        }

    }


    void Manager::end(){
        for (int i=0; i<_service_num; i++){
            if(!_services[i].is_idle()){
                int service_start_time = _services[i].get_service_start_time();
                int arrive_time = _services[i].get_customer_arrive_time();
                int duration = _services[i].get_customer_duration();

                _customer_stay_time += service_start_time + duration - arrive_time;
                ++_total_served_customer_num;
            }
        }

        while(!_customer_queue.empty())
            _customer_queue.pop();
        while(!_event_queue.empty())
            _event_queue.pop();
        delete[] _services;
    }


    void Manager::simulate(int simulate_num) {
        long long total_serve_time = _total_serve_time * simulate_num;

        while(simulate_num-- > 0) {
            init();
            run();
            end();
        }

        _avg_stay_time = static_cast<double>(_customer_stay_time) / static_cast<double>(_total_served_customer_num);
        _avg_customers = static_cast<double>(_total_served_customer_num) / static_cast<double>(total_serve_time);

    }




}

#endif //AL_LIST_MANAGER_QUEUE_H
