cmake_minimum_required(VERSION 3.5.1)
project(al_list)

set(CMAKE_CXX_STANDARD 14)

add_executable(al_list main.cpp intSLList.h intSLList.cpp DLList.h SkipL.h get_Uniform_distribution.h genarrayqueue.h queuesystem.h Test_queue_process.h manager_queue.h service.h customer.h random.h event_queue.h)