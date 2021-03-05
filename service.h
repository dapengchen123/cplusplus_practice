//
// Created by hp on 01/03/2021.
//

#ifndef AL_LIST_SERVICE_H
#define AL_LIST_SERVICE_H

#include "customer.h"
namespace Parrots {
    enum class ServiceStatus {
        BUSY,
        IDLE
    };

    class Services {
    public:
        Services() : _service_status(ServiceStatus::IDLE), _service_start_time(0){}
    private:
        Customer _customer;
        ServiceStatus _service_status;
        int _service_start_time;
    };
}
#endif

//    class Services {
//    public:
//        Services() : _service_status(ServiceStatus::IDLE) {}
//
//        bool is_idle() const {
//            if (_service_status == ServiceStatus::IDLE) return true;
//            else return false;
//        }
//
//        void serve_customer(Customer customer) {
//            this->_customer = customer;
//        }
//
//        void set_busy() {
//            _service_status = ServiceStatus::BUSY;
//        }
//
//        void set_idle() {
//            _service_status = ServiceStatus::IDLE;
//        }
//
//        int get_customer_arrive_time() const {
//            return _customer.arrive_time;
//        }
//
//        int get_customer_duration() const {
//            return _customer.duration;
//        }
//
//        void set_service_start_time(int sst) {
//            _service_start_time = sst;
//        }
//
//        int get_service_start_time() const {
//            return _service_start_time;
//        }
//
//    private:
//        Customer _customer;
//        ServiceStatus _service_status;
//        int _service_start_time;
//
//    };

 //AL_LIST_SERVICE_H
