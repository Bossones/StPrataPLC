#include "nmspc.hpp"

int main() {
	Stack oper;
	Item cust {"Charli", 250};
	Item custo {"Bravo", 300};
	Item custom {"Costa", 400};
	oper.push(cust);
	oper.push(custo);
	oper.push(custom);
	oper.showall();
	oper.pop(cust);
	std::cout << "Cust is " << cust.fullname << " " << cust.payment << std::endl;
	return 0;
}