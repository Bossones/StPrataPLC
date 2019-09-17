#ifndef PERSON_HPP__
#define PERSON_HPP__

#include <string>
#include <iostream>
#include <random>

class Person {
private:
    std::string fullname;
protected:
    virtual void Data() const;
public:
    Person() : fullname("no name") {}
    Person(const char * s) : fullname(s) {} 

    virtual ~Person() {}
    virtual void Show() const = 0;
};

class Gunslinger : virtual public Person {
private:
    double time_;
    int nas_;
protected:
    virtual void Data() const;
public:
    Gunslinger() : Person(), time_(0), nas_(0) {}
    Gunslinger(const char * name, const double & time, const int & nas ) :
                Person(name), time_(time), nas_(nas) {}
    
    virtual ~Gunslinger() {}
    virtual double Draw();
    virtual void Show() const;
};

class Card {
private:
    int znach_;
    std::string mas_;
public:
    friend std::ostream & operator<<(std::ostream & os, const Card & cd);

    void DefThis() {
        int help;
        std::random_device rd;
        std::mt19937 mersenne(rd());
        znach_ = mersenne() % 13 + 1;
        help = mersenne() % 4;
        switch (help)
        {
        case 0:
            mas_ = "Heart";
            break;
        case 1:
            mas_ = "Diamond";
            break;
        case 2:
            mas_ = "Club";
            break;
        default:
            mas_ = "Spade";
            break;
        }
    }
};

class PokerPlayer : virtual public Person {
private:
    Card cd;
protected:
    virtual void Data() const;
public:
    PokerPlayer() : Person(), cd() {}
    PokerPlayer(const char * s) : Person(s) {
        cd.DefThis();
    }

    virtual ~PokerPlayer() {}
    virtual Card Draw();
    virtual void Show() const;
};

class BadDude : public PokerPlayer, public Gunslinger {
private:
    double timeToFire_;
    Card nextCd;
protected:
    virtual void Data() const;
public:
    BadDude(const char * s, const double & time, const int & nas) : Person(s), Gunslinger(s, time, nas), PokerPlayer(s) {
        std::random_device rd;
        std::mt19937 mersenne(rd());

        timeToFire_ = (mersenne() % 10 + 1) / static_cast<double>(10);
        nextCd.DefThis();
    }

    BadDude() : Person(), Gunslinger(), PokerPlayer(), timeToFire_(0), nextCd() {}
    virtual ~BadDude() {}

    double Gdraw();

    Card Cdraw() {
        return nextCd;
    }

    virtual void Show() const;

};



#endif