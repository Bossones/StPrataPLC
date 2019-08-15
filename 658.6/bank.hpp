#ifndef BANK_HPP_
#define BANK_HPP_

#include <iostream>
#include <random>

class visitor {
public:
    //void setTMST(const unsigned int & TMST);
   // void setPCS();
    //void setTMNQ(const unsigned int & TMNQ);
    visitor() {};
    visitor(const unsigned int & TMST, const unsigned int & TMNQ);
    unsigned int getTMST() const;
    unsigned int getPCS() const;
    unsigned int getTMNQ() const;
private:
    unsigned int timest;
    unsigned int processTime;
    unsigned int timeInQueue;
};

class queue {
public:
    queue();
    ~queue();
    bool isempty() const;
    bool isfully() const;
    bool pushqu(const unsigned int & TMST, const unsigned int & TMNQ);
    bool popqu();
    const unsigned int timeToEnd() const;
    const unsigned int getTop() const;
    const unsigned int getEndPCS() const;
private:
    enum {MAX = 10};
    struct Node {
        Node() {};
        Node(const unsigned int & TMST, const unsigned int & TMNQ) {
            obj = visitor(TMST, TMNQ);
        }
        visitor obj; 
        Node * next;
    };
    Node * first;
    Node * end;
    unsigned int top;
};

#endif