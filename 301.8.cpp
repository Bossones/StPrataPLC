//From Steven Prata's book "Programming language C++" 301.8
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

int main() {
	ifstream FileIn;
	ofstream FileOut;
	char filename[200];
	char c;
	unsigned short count = 0;
	cout << "Enter filename: ";
	cin >> filename;
	FileIn.open(filename);
	if (!FileIn.is_open()) exit(EXIT_FAILURE);
	while (!FileIn.fail()) {
		if (FileIn.get() != '\0')
			count++;
		cout << "Symbols " << count << endl;
	}
	FileIn.close();
	FileOut.open("zal.txt");
	FileOut << count << endl;
	FileOut.close();

    return 0;
}