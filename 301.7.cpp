//From Steven Prata's book "Programming language C++" 301.7
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



int main() {
	string word;
	cout << "Enter your word" << endl;
	unsigned short count1, count2, others;
	count1 = count2 = others = 0;

	while (cin >> word) {
		cout << "Your word is: " << word << endl;
		if (word[0] == 'q' && word[1] == '\0')
		{
			cout << "Thanks dor using" << endl;
			break;
		}
		if (islower(word[0]))
			count1++;
		else if (isupper(word[0]))
			count2++;
		else
			others++;

	}
	cout << count1 << " words by small letter" << endl;
	cout << count2 << " words by big letter" << endl;
	cout << others << " symbols by others" << endl;
    return 0;
}