#include "string2.hpp"

using namespace std;

int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << endl;
	s2 = s2 + s1;
	s2.stringup();
	cout << "The string " << endl << s2 << "\ncontains " << s2.has('A')
		 << " 'A' characters in it.\n";
	s1 = "red";
	String rgb[3] = {String(s1), String("green"), String("blue")};
	cout << "enter rhe name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans) {
		ans.stringlow();
		for(int i = 0; i < 3; i++) {
			if (ans == rgb[i]) {
				cout << "That's right!" << endl;
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try Again!" << endl;
	}
	cout << "Bye!" << endl;
	return 0;
}