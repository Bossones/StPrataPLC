#include "vector.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

int main() {
	using vec::Vector;
	std::ofstream fout;
	fout.open("text.txt");
	if (!fout.is_open()) {
		std::cout << "Sorry, couldnt open the file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	Vector result(0.0, 0.0);
	Vector step;
	step.change_mod(Vector::POL);
	srand(time(0));
	unsigned int steps = 0;
	double target;
	double dstep;
	double direction;
	std::cout << "Enter target distance (q to quit) ";
	while (std::cin >> target) {
		std::cout << "Enter step length: ";
		if (!(std::cin >> dstep))
			break;
		while (result.get_mod() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			fout << "Step: " << steps << " " << result << std::endl;
		}
		fout << "After " << steps << " steps, the subject"
			"has the following location:\n";
		fout << result << std::endl;
		fout << "Average outward distance per step = "
			<< result.get_mod() / steps << std::endl;
		steps = 0;
		result.reset(0.0, 0.0);
		std::cout << "Enter target distance (q to quit): ";
	}
	std::cout << "Bye!" << std::endl;
	std::cin.clear();
	while(std::cin.get() != '\n')
		continue;
	fout.close();
	return 0;
}
