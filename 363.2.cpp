//From Steven Prata's book "Programming language C++" 363.2
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

void vvod(short* mass) {

	for (int i = 0; i < 10; i++) {
		cout << "Enter numbers of mass or press q to exit: ";
		cin >> mass[i];
		if (cin.fail()) 
		{
			cin.clear();
			while(cin.get() != '\n') {
				continue;
			}
			cout << "Okay you've entered all numbers" << endl;
			break;
		}
	}

}

void vivod(short* mass) {

	cout << "This is youre entered massive" << endl;
	for (int i = 0; i < 10; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

void sred(short* mass) {

	int sum = 0;
	for (int i = 0; i < 10; i ++) {
		sum += mass[i];
	}
	cout << "Median value of this massive is: " << static_cast<double>(sum) / 10 << endl;
}

int main() {
	short mass[10] {};
	vvod(mass);
	vivod(mass);
	sred(mass);
    return 0;
}
