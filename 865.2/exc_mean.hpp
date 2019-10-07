#ifndef EXC_MEAN_HPP__
#define EXC_MEAN_HPP__

#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error {
private:
    double v1;
    double v2;
public:
    bad_hmean(const double & d1 = 0, const double & d2 = 0) : v1(d1), v2(d2), std::logic_error("Bad value") {}
    virtual const char * what() const noexcept {  
        std::cout << std::endl;
        std::cout << "////////////////////////////" << std::endl;
        std::cout << std::logic_error::what() << std::endl;
        std::cout << "Function hmean is bad\ninvalid arguments: a = -b" << std::endl;
        return "///////////////////////////////";
    }
};

class bad_gmean : public std::logic_error {
private:
    double v1;
    double v2;
public:
    bad_gmean(const double & d1 = 0, const double & d2 = 0) : v1(d1), v2(d2), std::logic_error("Bad values") {}
    virtual const char * what() const noexcept {
        std::cout << std::endl; 
        std::cout << "/////////////////////////" << std::endl;
        std::cout << std::logic_error::what() << std::endl;
        std::cout << "Function gmean is bad\nValues must be >0" << std::endl;
        return "///////////////////////////////";
    }
};


#endif