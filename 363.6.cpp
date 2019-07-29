//From Steven Prata's book "Programming language C++" 363.6
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

const unsigned short SIZE = 200;

void Fill_array(double* mass, unsigned short size) {
	cout << "Enter mass: ";
	for (int i = 0; i < size; i++) {
		cin >> mass[i];
		if (cin.fail()) {
			cin.clear();
			while (cin.get() != '\n')
			cout << "Okay, lets go to do something" << endl;
			break;
		}
	}
}

void Show_array(double* mass, unsigned short size) {
	cout << "Massive: ";
	for (int i = 0; i < size; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

void Reverse_array(double* mass, unsigned short size) {
	double trans;
	for (int i = 0; i < size--; i++) {
		trans = mass[i];
		mass[i] = mass[size];
		mass[size] = trans;
	}
}


int main() {
	double mass[10] {};
	Fill_array(mass, 10);
	Show_array(mass, 10);
	Reverse_array(mass, 10);
	Show_array(mass, 10);
    return 0;
}
