//From Steven Prata's book "Programming language C++" 426.1
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

void vivod (const string & str, int i = 0) {
	static unsigned short couti = 0;
	if (i == 0) {
		cout << str << endl;
	}
	else {
		for (int j = 1; j <= couti; j++)
			cout << str << endl;
	}
	couti++;
}

int main() {
	vivod("Yes of course");
	vivod("Here we go again");
	vivod("Okay, several strings", 10);

    return 0;
}
