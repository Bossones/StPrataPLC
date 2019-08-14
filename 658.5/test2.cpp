#include "bank.hpp"

bool comePerson(const unsigned int & x) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    return (((mersenne() % 50 + 1) * x / 50) < 1);
}

int main () {
    using std::cout;
    using std::endl;
    using std::cin;
    queue poshla;
    unsigned int wait_time, vremya, line, allPerson, turnaway, people_per_hour;
    wait_time = vremya = line = allPerson = turnaway = people_per_hour = 0;

    cout << "Enter time of modeling in minutes: ";
    cin >> vremya;
    cout << "Enter expecting value people per hour: ";
    cin >> people_per_hour;

    for (int i = 0; i <= vremya; ++i) {
        if (comePerson(60/people_per_hour)) {
            allPerson++;
            if(!poshla.pushqu(i, wait_time)) {
                turnaway++;
            }
            else {
                wait_time += poshla.getEndPCS();
                line += wait_time;
            }
        }
        if (!poshla.isempty() && (i == (poshla.getFirstPCS() + poshla.getTMNQ() + poshla.getTMST()))) {
            poshla.popqu();
        }
        if (wait_time > 0)
            wait_time--;
    }

    cout << "All person: " << allPerson << endl;
    cout << "Turnaway: " << turnaway << endl;
    if (allPerson)
        cout << "Average time of waiting is: " << line / (allPerson - turnaway) << endl;
    return 0;
}