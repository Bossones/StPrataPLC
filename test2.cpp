//prgramm from Steven Prata's book "Programming language C++"
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


const short SIZE = 300;

struct blago {
	string fullname;
	double summa;
};

int main() {
	unsigned short kol = 0;
	unsigned short count = 0;
	cout << "Enter mecenats: ";
	cin >> kol;
	cin.get();
	blago* mecens = new blago [kol];
	for (int i = 0; i < kol; i++) {
		cout << "Enter your name: ";
		getline(cin, mecens[i].fullname);
		cout << "Enter your blago: ";
		cin >> mecens[i].summa;
		cin.get();
	}

	cout << "\t\t\tGrand Patrons" << endl;
	for (int i = 0; i < kol; i++) {
		if (mecens[i].summa >= 10000) {
			cout << mecens[i].fullname << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "none" << endl;

	cout << "\t\t\tOthers" << endl;
	count = 0;
	for (int i =0; i < kol; i++) {
		if (mecens[i].summa < 10000) {
			cout << mecens[i].fullname << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "none" << endl;
    return 0;
}
