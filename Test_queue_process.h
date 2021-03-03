//
// Created by hp on 01/03/2021.
//

#ifndef AL_LIST_TEST_QUEUE_PROCESS_H
#define AL_LIST_TEST_QUEUE_PROCESS_H
#include <ctime>

namespace Parrots {
    class Test {
    public:
        static void run(int total_serve_time, int service_num, int simulate_num);

        static void print_current_time();

    };

    void Test::print_current_time() {
        std::time_t t = time(0);
        char tmp[64];
        std::strftime(tmp, sizeof(tmp), "%Y/%m/%d %X", localtime(&t));
        std::cout << "current time : " << tmp << std::endl;
    }

    void Test::run(int total_serve_time, int service_num, int simulate_num) {
        std::srand(static_cast<unsigned int>(std::time(0)));
        std::time_t start, end;
        std::time(&start);


        std::time(&end);

        std::cout << "Simulate cost time: "
                  << std::difftime(end, start) << " s " << std::endl;

    }
}
#endif //AL_LIST_TEST_QUEUE_PROCESS_H
