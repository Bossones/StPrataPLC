#ifndef COW_HPP__
#define COW_HPP__

#include <iostream>
#include <cstdlib>
#include <cstring>

class Cow {
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;
};

#endif