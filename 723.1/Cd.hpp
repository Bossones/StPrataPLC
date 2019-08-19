#ifndef CD_HPP_
#define CD_HPP_

#include <iostream>


class Cd {
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(const char * s1, const char * s2, const int & n, const double & x);
    Cd(const Cd & d);
    Cd();

    virtual ~Cd();
    virtual void Report() const;

    Cd & operator=(const Cd & d);
};

#endif