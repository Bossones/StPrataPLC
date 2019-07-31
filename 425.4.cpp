//From Steven Prata's book "Programming language C++" 363.10
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

void display(const box & kisa) {
	cout << kisa.marker << endl;
	cout << kisa.height << endl;
	cout << kisa.width << endl;
	cout << kisa.length << endl;
	cout << kisa.volume << endl;
}

void volume(box & kisa) {
	kisa.volume = kisa.height * kisa.length * kisa.width;
}

int main() {
	box kisa {"Zalupa", 24.3f, 2.7f, 60.2f};
	display(kisa);
	volume(kisa);
	display(kisa);

    return 0;
}
