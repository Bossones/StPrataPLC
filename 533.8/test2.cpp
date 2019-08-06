#include "list.hpp"

int main() {
	{
		item sok;
		List keks("Stringsigna", 300);
		keks.push("Hi person", 100);
		keks.push("Iltavina", 250);
		keks.push("What are you doing?", 230);
		keks.showall();
		keks.pop(sok);
		std::cout << "sok name: " << sok.name << "; sok number: " << sok.number;
		std::cout << std::endl;
		keks.visit(iitem);
		keks.showall();
		keks.visit(sitem);
		keks.showall();
	}
	return 0;
}