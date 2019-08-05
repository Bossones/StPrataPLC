#ifndef NMSPC_HPP_
#define NMSPC_HPP_

#include <iostream>

class Move
{
public:
	Move(double a = 0, double b = 0);
	void showmove() const;
	Move add(const Move & m) const;
	void reset(double a = 0, double b = 0);
	double getx() const {return x_;}
	double gety() const {return y_;}
private:
	double x_;
	double y_;
};

#endif