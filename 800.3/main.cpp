#include "worker.hpp"
#include "queuetp.hpp"
#include <iostream>

int main() {
    using std::cout;
    using std::endl;
    using std::cin;

    stack<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout << que.getData() << endl;
    que.delCur();
    cout << que.getData() << endl;
    que.delCur();
    cout << que.getData() << endl;
    que.delCur();

    stack<double *> quew;
    double x1 = 1.2;
    double x2 = 1.3;
    double x3 = 1.4;
    quew.push(&x1);
    quew.push(&x2);
    quew.push(&x3);
    cout << *quew.getData() << endl;
    quew.delCur();
    cout << *quew.getData() << endl;
    quew.delCur();
    cout << *quew.getData() << endl;
    quew.delCur();

    stack<Teacher *> quedo;
    Teacher t1("Xeniu Falks", 111234, 10);
    Teacher t2("Ruta Penutra", 112345, 5);
    Teacher t3("Trinity Gosefs", 111111, 14);
    quedo.push(&t1);
    quedo.push(&t2);
    quedo.push(&t3);
    Teacher t4, t5, t6;
    quedo.pop(&t4);
    quedo.pop(&t5);
    quedo.pop(&t6);
    t4.Show();
    t5.Show();
    t6.Show();
    return 0;
}