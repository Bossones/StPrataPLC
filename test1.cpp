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

double calcZp(int zp) {
	double nalog = 0;
	if ((zp - 10000) > 0) {
		nalog = 10000 * 0.10;
	}
	else if ((zp - 5000) > 0){
		nalog += (zp - 5000) * 0.10;
	}
	if ((zp - 20000) > 0) {
		nalog += 20000 * 0.15;
	}
	else if ((zp - 10000) > 0)
		nalog += (zp - 10000)  * 0.15;
	if ((zp - 35000) > 0)
		nalog += (zp - 35000) * 0.20;
	return nalog;
}

int main() {
	int zp;
	cout << "Enter yor seles: ";
	while(cin >> zp) {
		if (zp < 0) {
			break;
		}
		cout << calcZp(zp) << endl;
	}
    return 0;
}