#ifndef VINTAGEPORT_HPP__
#define VINTAGEPORT_HPP__

#include "port.hpp"

class vintageport : public port {
private:
    char * nickname;
    int year;
public:
    vintageport();
    vintageport(const char * br, int b, const char * nn, int y);
    vintageport(const vintageport & vp);
    virtual ~vintageport() { delete [] nickname;}

    vintageport & operator=(const vintageport & vp);

    virtual void Show() const;
    friend std::ostream & operator<<(std::ostream & os, const vintageport & vp);
};

#endif