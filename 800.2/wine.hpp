#ifndef WINE_HPP__
#define WINE_HPP__

#include <iostream>
#include <string>
#include <valarray>
#include "pair.hpp"

class Wine : private Pair<std::valarray<int>, std::valarray<int>>, private std::string {
private:
    typedef std::valarray<int> ArrayInt;
    int years;
public:
    Wine(const char * lab, const int & y, const int yr[], const int bot[]);
    Wine(const char * lab = "NOPE", const int & y = 0);
    std::string & Label();
    void GetBottles();
    void Show() const;
    int Sum() const;
};

#endif