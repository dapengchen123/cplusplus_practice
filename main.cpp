#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include "manager_queue.h"


int main() {
    int total_serve_time = 20;
    int service_num = 5;
    Parrots::Manager manager(20,5);
    manager.simulation(2);



    return 0;
}
