#include "bank.hpp"

//Function class queue::

queue::queue() {
    first = nullptr;
    end = nullptr;
    top = 0;
}

queue::~queue() {
    Node * temp = nullptr;
    while (first != nullptr) {
        temp = first->next;
        delete first;
        first = temp;
    }
}

bool queue::popqu() {
    if (this->isempty()) {
        //std::cout << "Cant pop Item because it's empty" << std::endl;
        return false;
    }
    if (first != end) {
        Node * temp = nullptr;
        temp = first->next;
        delete first;
        first = temp;
        top--;
    }
    else {
        delete first;
        first = nullptr;
        end = nullptr;
        top--;
    }
    return true;
}

bool queue::pushqu(const unsigned int & TMST, const unsigned int & TMNQ) {
    if (this->isfully()) {
        //std::cout << "Cant push item because it's full" << std::endl;
        return false;
    }
    if (end != nullptr) {
        end->next = new Node;
        end = end->next;
        end->obj.setTMST(TMST);
        end->obj.setPCS();
        end->obj.setTMNQ(TMNQ);
        end->next = nullptr;
    }
    else {
        first = new Node;
        first->obj.setTMST(TMST);
        first->obj.setPCS();
        first->obj.setTMNQ(TMNQ);
        first->next = nullptr;
        end = first;
    }
    top++;
    return true;
}

bool queue::isempty() {
    return top == 0;
}

bool queue::isfully() {
    return top == MAX;
}

unsigned int queue::getEndPCS() const {
    if(end != nullptr) {
        return end->obj.getPCS();
    }
    else {
        //std::cout << "Cant return beacise item is empty" << std::endl;
        return 0;
    }
}

unsigned int queue::getFirstPCS() const {
    if(first != nullptr) {
        return first->obj.getPCS();
    }
    else {
        //std::cout << "Cant return beacise item is empty" << std::endl;
        return 0;
    }
}

unsigned int queue::getTMST() const {
    if(first != nullptr) {
        return first->obj.getTMST();
    }
    else {
        //std::cout << "Cant return beacise item is empty" << std::endl;
        return 0;
    }
}

unsigned int queue::getTMNQ() const {
    if(first != nullptr) {
        return first->obj.getTMNQ();
    }
    else {
        //std::cout << "Cant return beacise item is empty" << std::endl;
        return 0;
    }
}

//Function class visitor::

unsigned int visitor::getPCS() const {
    return processtime;
}

unsigned int visitor::getTMNQ() const {
    return timeInQueue;
}

unsigned int visitor::getTMST() const {
    return timest;
}

void visitor::setPCS() {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    processtime = mersenne() % 3 + 1;
}

void visitor::setTMST(const unsigned int & TMST) {
    timest = TMST;
}

void visitor::setTMNQ(const unsigned int & TMNQ) {
    timeInQueue = TMNQ;
}