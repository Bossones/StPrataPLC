#include "bank.hpp"

queue::queue() : top(0), first(nullptr), end(nullptr) {}

queue::~queue() {
    Node * temp;
    while (first != nullptr) {
        temp = first->next;
        delete first;
        first = temp;
    }
    first = nullptr;
    end = nullptr;
}

bool queue::isempty() const {
    return top == 0;
}

bool queue::isfully() const {
    return top == MAX;
}

bool queue::pushqu(const unsigned int & TMST, const unsigned int & TMNQ) {
    if (this->isfully())
        return false;
    else if (first == nullptr) {
        first = new Node(TMST, TMNQ);
        first->next = nullptr;
        end = first;
    }
    else {
        end->next = new Node(TMST, TMNQ);
        end = end->next;
        end->next = nullptr;
    }
    top++;
    return true;
}

bool queue::popqu() {
    if (this->isempty())
        return false;
    else if (first == nullptr) {
        delete first;
        first = nullptr;
        end = nullptr;
    }
    else {
        Node * temp = nullptr;
        temp = first->next;
        delete first;
        first = temp;
    }
    top--;
    return true;
}

const unsigned int queue::timeToEnd() const {
    return (first->obj.getPCS() + first->obj.getTMST() + first->obj.getTMNQ());
}

const unsigned int queue::getTop() const {
    return top;
}

const unsigned int queue::getEndPCS() const {
    return end->obj.getPCS();
}

//Functions class visitor

visitor::visitor(const unsigned int & TMST, const unsigned int & TMNQ) {
    timest = TMST;
    timeInQueue = TMNQ;
    std::random_device rd;
    std::mt19937 mersenne(rd());
    processTime = mersenne() % 3 + 1;
}

unsigned int visitor::getTMST() const {
    return timest;
}

unsigned int visitor::getPCS() const {
    return processTime;
}

unsigned int visitor::getTMNQ() const {
    return timeInQueue;
}



