#include "bank.hpp"

//Come person or not?
bool comePerson(const double & PEP_PER_HOR) { 
    std::random_device rd;
    std::mt19937 mersenne(rd());
    return (((mersenne() % 50 + 1) * PEP_PER_HOR / 50) < 1);
}

int main() {
    using std::cout; //directives for input/output
    using std::endl;
    using std::cin;

    queue left; //Left ATM
    queue right; //Right ATM

    unsigned int line, wait_time_left, wait_time_right, vremya, PEP_PER_HOR, allPerson, turnaway;
    line = wait_time_left = wait_time_right = vremya = PEP_PER_HOR = allPerson = turnaway = 0;

    cout << "Enter modelling time: ";
    cin >> vremya;
    cout << "Enter expecting value of PEP PER HOR: ";
    cin >> PEP_PER_HOR;

    //Time modeling
    for (unsigned int i = 0; i <= vremya; ++i) {
        if (comePerson(60 / static_cast<double>(PEP_PER_HOR))) {
            allPerson++;
            //Comporise 2 queues
            if (left.getTop() <= right.getTop()) {
                if(!left.pushqu(i, wait_time_left))
                    turnaway++;
                else {
                    wait_time_left += left.getEndPCS();
                    line += wait_time_left;
                }
            }
            else if (left.getTop() > right.getTop()) {
                if (!right.pushqu(i, wait_time_right))
                    turnaway++;
                else {
                    wait_time_right += right.getEndPCS();
                    line += wait_time_right;
                }
            }
        }
        if ((!left.isempty()) && (i == left.timeToEnd())) {
            left.popqu();
        }
        if ( (!right.isempty()) && (i == right.timeToEnd()) ) {
            right.popqu();
        }
        if (wait_time_left > 0)
            wait_time_left--;
        if (wait_time_right > 0)
            wait_time_right--;
    }

    cout << "All Person: " << allPerson << endl;
    cout << "Turnaway person: " << turnaway << endl;
    if (allPerson > 0)
        cout << "Average time of waiting: " << line / (allPerson - turnaway) << endl;
    return 0;
}