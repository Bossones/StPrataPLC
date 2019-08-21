#ifndef PORT_HPP__
#define PORT_HPP__

#include <iostream>

class port {
private:
    char * brand;
    char style[20];
    unsigned int bottles;
public:
    port(const char * br = "none", const char * st = "none", int b = 0);
    port(const port & p);
    virtual ~port() {delete [] brand;}

    port & operator=(const port & p);
    port & operator+=(int b);
    port & operator-=(int b);

    unsigned int BottleCount() const {return bottles;}
    virtual void Show() const;
    friend std::ostream & operator<<(std::ostream & os, const port & p);
};


#endif