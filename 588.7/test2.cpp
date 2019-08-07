#include "complexx.hpp"

int main()
{
	using std::cout;
	using std::cin;
	using com::Complex;
	Complex a(3.0, 4.0);
	Complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c) {
		cout << "c is " << c << "\n";
		cout << "Complex conjugate is " << ~c << std::endl;
		cout << "a is " << a << std::endl;
		cout << "a + c is " << a + c << std::endl;
		cout << "a - c is " << a - c << std::endl;
		cout << "a * c is " << a * c << std::endl;
		cout << "2 * c is " << 2 * c << std::endl;
		cout << "Enter a complex number (q to quit):" << std::endl;
	}
	cout << "Done!" << std::endl;
	return 0;
}