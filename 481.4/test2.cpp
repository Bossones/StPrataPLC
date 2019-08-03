#include "nmspc.hpp"

void SALES::setSales(SALES::Sales & s, const double ar[], int n) {
	double min = ar[0];
	double max = ar[0];
	double average = ar[0];
	for (int i = 1; i < n; i++) {
		if (min > ar[i])
			min = ar[i];
		if (max < ar[i])
			max = ar[i];
		average += ar[i];
	}
	average /= n;
	s.sales[0] = min;
	s.sales[1] = max;
	s.sales[2] = average;
	s.sales[3] = 0;
	s.min = min;
	s.max = max;
	s.average = average;
}

void SALES::setSales(SALES::Sales & s) {
	double ar[4] {};
	for (int i = 0; i < SALES::QUARTERS; i++) {
		std::cout << "Enter number " << i + 1 << " ";
		std::cin >> ar[i];
	}
		double min = ar[0];
	double max = ar[0];
	double average = ar[0];
	for (int i = 1; i < SALES::QUARTERS; i++) {
		if (min > ar[i])
			min = ar[i];
		if (max < ar[i])
			max = ar[i];
		average += ar[i];
	}
	average /= SALES::QUARTERS;
	s.sales[0] = min;
	s.sales[1] = max;
	s.sales[2] = average;
	s.sales[3] = 0;
	s.min = min;
	s.max = max;
	s.average = average;
}

void SALES::showSales(const SALES::Sales & s) {
	std::cout << "Massive is: ";
	for (int i = 0; i < SALES::QUARTERS; i++) {
		std::cout << s.sales[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Min is: " << s.min << std::endl;
	std::cout << "Max is: " << s.max << std::endl;
	std::cout << "Average is: " << s.average << std::endl;
}