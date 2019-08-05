#ifndef NMSPC_HPP_
#define NMSPC_HPP_

#include <iostream>
#include <string>

class Plorg {
public:
	Plorg(const std::string & name = "Plorga", const short & CI = 50);
	void changeCI(const short & CI) { CI_ = CI; }
	void showplorg() const;
private:
	std::string name_;
	short CI_;
};
#endif