//From Steven Prata's book "Programming language C++" 426.2
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

struct CandyBar {
	string name;
	float weigth;
	int kall;
};

void equalism(CandyBar & box, const char * name = "Millenium Munch", const double weight = 2.85, const int kall = 350) {
	box.name = name;
	box.weigth = weight;
	box.kall = kall;
}

void display(const CandyBar & box) {
	cout << box.name << endl;
	cout << box.weigth << endl;
	cout << box.kall << endl;
}

int main() {
	CandyBar box {};
	CandyBar box1 {};
	equalism(box);
	equalism(box1, "Shelupon", 5.5, 2500);
	display(box);
	display(box1);

    return 0;
}
