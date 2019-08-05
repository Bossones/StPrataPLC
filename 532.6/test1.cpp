#include "nmspc.hpp"

Move::Move(double a, double b) {
	x_ = a;
	y_ = b;
}

Move Move::add(const Move & m) const {
	Move sok {m.getx(), m.gety()}
	return sok;
}

void Move::reset(double a, double b) {
	x_ = a;
	y_ = b;
}

void Move::showmove() const {
	using std::cout;
	using std::endl;
	cout << "x: " << x_ << " y: " << y_ << endl;
}