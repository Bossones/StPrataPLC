#include "nmspc.hpp"

int main() {
	SALES::Sales s;
	double ar[4] {4.2, 5.6, 10.3, 18.9};
	SALES::setSales(s);
	SALES::showSales(s);
	SALES::setSales(s, ar, 4);
	SALES::showSales(s);
	return 0;
}