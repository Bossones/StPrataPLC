#include "worker.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//member functions for Worker

Worker::~Worker() {}

void Worker::Data() const
{
    cout << "Name: "<< fullname << endl;
    cout << "Employee ID:" << id << endl;
}
void Worker::Get()
{
    cout << "Enter fullname: ";
    std::getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

//member functions for Teacher

void Teacher::Data() const {
    cout << "Years of teaching: " << yearsOfTeaching << endl;
}

void Teacher::Get() {
    cout << "Enter years of teaching: ";
    cin >> yearsOfTeaching;
    while (cin.get() != '\n')
        continue;
}

void Teacher::Set() {
    Worker::Get();
    this->Get();
}

void Teacher::Show() const {
    Worker::Data();
    this->Data();
}

