#ifndef CLASSIC_HPP_
#define CLASSIC_HPP_

#include "Cd.hpp"

class Classic :public Cd {
private:
    char name_of_song[100];
public:
    Classic();
    Classic(const char * name_, const char * s1, const char * s2, const int & n, const double & x);
    Classic(const Classic & tresk);

    virtual ~Classic();
    virtual void Report() const;

    Classic & operator=(const Classic & tresk);


};

#endif