//From Steven Prata's book "Programming language C++" 363.3
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

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void vivod(box vree) {
	cout << vree.maker << endl;
	cout << vree.height << endl << vree.width << endl;
	cout << vree.length << endl << vree.volume << endl;
}

void volume(box* vree) {
	vree->volume = vree->height * vree->length * vree->width;
	cout << "Volume is " << vree->volume << endl;
}

int main() {
	box zal {"Zalupa", 10, 2, 3, 4};
	vivod(zal);
	volume(&zal);
    return 0;
}
