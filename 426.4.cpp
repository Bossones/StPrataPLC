//From Steven Prata's book "Programming language C++" 426.4
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

struct stringy {
	char * str;
	int ct;
};

void set(stringy & str, const char * src) {
	str.str = new char[strlen(src) + 1];
	strcpy(str.str, src);
	str.ct = strlen(src);
}

void show(const stringy & str, int i = 1) {
	for (int j = 0; j < i; j++)
		cout << str.str << endl;
}

void show(const char * str, int i = 1) {
	for (int j = 0; j < i; j++)
		cout << str << endl;
}

int main() {
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done");
	delete [] beany.str;
    return 0;
}
