//From Steven Prata's book "Programming language C++" 363.9
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

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n) {
	cout << "Enter your data: " << endl;
	int entered = 0;
	for (int i = 0; i < n; i++) {
		cout << "Enter full name: ";
		cin.getline(pa[i].fullname, SLEN);
		if ( strlen(pa[i].fullname) == 0) {
			cout << "Thats all" << endl;
			break;
		}
		cout << "Enter hobby: ";
		cin >> pa[i].hobby;
		cout << "Enter ooplevel: ";
		cin >> pa[i].ooplevel;
		cin.get();
		entered++;
	}
	return entered;
}

void display1(student st) {
	cout << "Fullname: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "ooplevel: " << st.ooplevel << endl;
}

void display2(const student* ps) {
	cout << "Fullname: " << ps->fullname << endl;
	cout << "Hobby: " << ps->hobby << endl;
	cout << "ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n) {
	for (int i = 0 ; i < n; i ++) {
		display1(pa[i]);
	}
}


int main() {
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i ++) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done" << endl;
    return 0;
}
