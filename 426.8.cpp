//From Steven Prata's book "Programming language C++" 426.8
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

struct box {
	char marker[40];
	float height;
	float width;
	float length;
	float volume;
};

template <typename T>
void displayVolume(const T & kisa, const T & zal) {
	cout << "Yes of course" << endl;
}

template <> void displayVolume<box>(const box & kisa, const box & zal) {
	if (kisa.volume > zal.volume)
		cout << kisa.volume << endl;
	else
		cout << zal.volume << endl;
}

int main() {
	box kisa {"Zalupa", 24.3f, 2.7f, 60.2f};
	box zal {"Kisa", 25.0f, 1.3f, 12.2f, 1256.0f};
	displayVolume(kisa, zal);

    return 0;
}
