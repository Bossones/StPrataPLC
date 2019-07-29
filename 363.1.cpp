//From Steven Prata's book "Programming language C++" 363.1
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

void sred(short x, short y) {
	cout <<  static_cast<double>(2 * x * y) / (x + y) << endl;
}

int main() {

	short x, y;
	while (cin >> x >> y)
	{
		if ( x == 0 || y == 0)
			break;
		sred(x, y);
	}

    return 0;
}
