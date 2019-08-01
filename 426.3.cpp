//From Steven Prata's book "Programming language C++" 426.3
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

void top(string & str) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = toupper(str[i]);
	}
}

int main() {
	string str;
	while(!cin.fail()) {
		cout << "Enter string: (q to exit) ";
		getline(cin, str);
		if (str == "q") {
			cout << "Bye" << endl;
			break;
		}
		top(str);
		cout << str << endl;
	}

    return 0;
}
