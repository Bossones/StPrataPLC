#ifndef CD_HPP__
#define CD_HPP__

#include <iostream>

class cd {
private:
    char * performers;
    char * label;
    int selections;
    double playtime;
public:
    cd(const char * s1, const char * s2, int n, double x);
    cd(const cd & d);
    cd();

    virtual ~cd();
    virtual void Report() const;

    cd & operator=(const cd & d);

};

#endif