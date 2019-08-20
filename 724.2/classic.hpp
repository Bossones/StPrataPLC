#ifndef CLASSIC_HPP__
#define CLASSIC_HPP__

#include "cd.hpp"

class classic :public cd {
private:
    char * name_of_song;
public:

    classic(const char * name_, const char * s1, const char * s2, 
            int n, double x);
    classic();
    classic(const classic & d);
    virtual ~classic();
    virtual void Report() const;

    classic & operator=(const classic & d);
};

#endif