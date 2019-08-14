#ifndef BANK_HPP_
#define BANK_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class visitor {
private:
    unsigned int processtime;
    unsigned int timest;
    unsigned int timeInQueue;
public:
    void setPCS();
    void setTMST(const unsigned int & TMST);
    void setTMNQ(const unsigned int & TMNQ);
    unsigned int getPCS() const;
    unsigned int getTMST() const;
    unsigned int getTMNQ() const;
};

class queue
{
private:
    struct Node {
        visitor obj;
        Node * next;
    };
    Node * first;
    Node * end;
    unsigned int top;
    enum {MAX = 10};
public:
    queue();
    ~queue();
    bool popqu();
    bool pushqu(const unsigned int & TMST, const unsigned int & TMNQ);
    bool isfully();
    bool isempty();
    unsigned int getEndPCS() const;
    unsigned int getFirstPCS() const;
    unsigned int getTMST() const;
    unsigned int getTMNQ() const;
};


#endif