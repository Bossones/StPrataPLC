#include "nmspc.hpp"

Plorg::Plorg(const std::string & name, const short & CI) { name_ = name; CI_ = CI; }

void Plorg::showplorg() const {
	using std::cout;
	using std::endl;
	cout << "Name: " << name_ << endl;
	cout << "CI: " << CI_ << endl;
}