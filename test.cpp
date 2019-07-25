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

struct bop {
	string fullname;
	string title;
	string bopname;
	short preference;
};

void showmenu() {
	cout << "please, choose yor choise: " << endl;
	cout << "a. display by name        b. display by title" << endl;
	cout << "c. display by bopname     d. display by preference" << endl;
	cout << "q. quit" << endl;
}

int main() {
	bop hui[3];
	char ch;
	for (int i = 0; i < 3; i++){
		cout << "Please, enter fullname: ";
		getline(cin, hui[i].fullname);
		cout << "Please, enter title: ";
		getline(cin, hui[i].title);
		cout << "Please, enter bopname: ";
		getline(cin, hui[i].bopname);
		cout << "Please, enter preference 1 or 2 or 3: ";
		cin >> hui[i].preference;
		cin.get();
	}
	showmenu();
	while (cin.get(ch)) {
		if (ch == 'a')
			for (int i = 0; i < 3; i++) {cout << hui[i].fullname << endl;}
		else if (ch == 'b')
			for (int i = 0; i < 3; i++) {cout << hui[i].title << endl;}
		else if (ch == 'c')
			for (int i = 0; i < 3; i++) {cout << hui[i].bopname << endl;}
		else if (ch == 'd') {
			for (int i = 0; i < 3; i++) {
				if (hui[i].preference == 0)
					cout << hui[i].fullname << endl;
				else if (hui[i].preference == 1)
					cout << hui[i].title << endl;
				else
					cout << hui[i].bopname << endl;
			}
		}
		else if (ch == 'q') {
			cout << "Thanks for using this shit" << endl;
			break;
		}
		if (ch != '\n') {
			cout << "Try again :)" << endl;
			showmenu();
		}
	}
    return 0;
}