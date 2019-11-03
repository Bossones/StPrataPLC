#include <iostream>
#include "customer.hpp"
#include <queue>
#include <random>

bool newcustomer(double x){
    std::random_device rd;
    std::mt19937 mersenne(rd());
    return (mersenne() % 32500 / 32500.0 * (60 / x)) < 1;
}

int main() {
    double PEOP_PER_HOUR;
    int MODELLING_TIME;
    int QUEUE_SIZE;
    int all_peop = 0;
    int goAway_peop = 0;
    int wait_time = 0;
    int curr_waiting_time = 0;
    int curr_peop = 0;
    std::queue<customer> que;

    std::cout << "Enter peoples per hour: ";
    std::cin >> PEOP_PER_HOUR;
    std::cout << "Enter max size of queue: ";
    std::cin >> QUEUE_SIZE;
    std::cout << "Enter modelling time: ";
    std::cin >> MODELLING_TIME;

    for (int i = 0; i < MODELLING_TIME; ++i) {
        if(newcustomer(PEOP_PER_HOUR)) {
            if(curr_peop >= QUEUE_SIZE) {
                ++goAway_peop;
                ++all_peop;
            }
            else {
                que.push(customer(curr_waiting_time, i));
                ++curr_peop;
                ++all_peop;
                if (curr_peop > 1)
                    wait_time += curr_waiting_time;
                curr_waiting_time += que.back().work();
            }
        }
        if (!que.empty() && que.front().timeEnd() == i) {
            que.pop(); 
            --curr_peop;    
        }
        if(curr_waiting_time > 0)
            --curr_waiting_time;
    }

    std::cout << "All peoples: " << all_peop << std::endl;
    std::cout << "Go away peoples: " << goAway_peop << std::endl;
    std::cout << "Waiting time per people: " << static_cast<double>(wait_time) / (all_peop - goAway_peop) << std::endl;
    std::cout << "Wait time: " << wait_time << std::endl;
    return 0;
}