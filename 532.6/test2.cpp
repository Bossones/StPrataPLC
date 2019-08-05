#include "nmspc.hpp"

int main() {
	Move sik(2.3, 3.5);
	Move sok {8.9, 23.5};
	sik.showmove();
	sik.reset(5.6, 7.2);
	sik.showmove();
	sik.add(sok).showmove();
	return 0;
}