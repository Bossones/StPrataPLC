//From Steven Prata's book "Programming language C++" 426.5
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

template <typename T>
T max5(const T * const max) {
	T maxim = max[0];
	for (int i = 1; i < 5; i++){
		if (maxim < max[i])
			maxim = max[i];
	}
	return maxim;
}

int main() {
	int max[5] {2, 3, 4, 7, 10};
	cout << max5(max) << endl;
    return 0;
}
