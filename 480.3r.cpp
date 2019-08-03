#include <iostream>
#include <new>

struct chaff {
	char dream[20];
	int siag;
};

namespace {
	char buffer[2000];
}

int main() {
	char* buf = new char[200];
	chaff* dom = new (buf) chaff[2];
	for(int i = 0; i < 2; i++) {
		std::cout << "Enter name: ";
		std::cin >> dom[i].dream;
		std::cout << "Enter siag: ";
		std::cin >> dom[i].siag;
	}
	for (int i = 0; i < 2; i++) {
		std::cout << "Dream is: " << dom[i].dream << std::endl;
		std::cout << "Siag is: " << dom[i].siag << std::endl;
	}
	return 0;
}