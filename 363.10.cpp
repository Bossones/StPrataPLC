//From Steven Prata's book "Programming language C++" 363.10
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <array>

using namespace std;

double add(double x, double y) {
	return x + y;
}

double min(double x, double y) {
	return x - y;
}

double mul(double x, double y) {
	return x * y;
}

double calculate(double x, double y, double (*ph_ptr)(double, double)) {
	return ph_ptr(x, y);
}

int main() {
	short choise;
	double x, y;
	double (*pf[3])(double, double) = {add, min, mul};
	cout << "Enter numbers x and y: ";
	cin >> x >> y;
	cout << "Enter your choise:" << endl;
	cout << "+  --  0" << endl << "-  --  1" << endl << "*  --  2" << endl;
	cin >> choise;
	cout << calculate(x, y, pf[choise]) << endl;
	cout << "Done" << endl;
    return 0;
}
