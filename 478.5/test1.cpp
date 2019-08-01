//From Steven Prata's book "Programming language C++" 426.5
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <array>
#include <new>
#include "nmspc.hpp"


int main() {
	int num1 = 15;
	int num2 = 20;
	double num3 = 2.4;
	double num4 = 5.5;
	std::cout << test::average(num1, num2) << std::endl;
	std::cout << test::average(num3, num4) << std::endl;
    return 0;
}
