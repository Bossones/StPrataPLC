#ifndef CUSTOMER_HPP__
#define CUSTOMER_HPP__

#include <ctime>
#include <cstdlib>

class customer {
private:
    int work_time;
    int time_to_end;
public:
    customer() {
        std::srand(std::time(0));
        work_time = std::rand() % 3 + 1;
    }

    customer(const int & curr_waiting_time, const int & now_time) {
        std::srand(std::time(0));
        work_time = std::rand() % 3 + 1;
        time_to_end = now_time + curr_waiting_time + work_time;
    }

    int work() const {
        return work_time;
    }

    const int & timeEnd() const {
        return time_to_end;
    }
};

#endif