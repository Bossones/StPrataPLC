#ifndef COMPLEXX_HPP_
#define COMPLEXX_HPP_

#include <iostream>

namespace com {
	class Complex {
	public:
		Complex(const double & RE = 0.0, const double & IM = 0.0);
		Complex operator+(const Complex & mnim) const;
		Complex operator-(const Complex & mnim) const;
		Complex operator*(const Complex & mnim) const;
		Complex operator*(const double & vesh) const;
		Complex operator~() const;
		friend std::ostream & operator<<(std::ostream & os, const Complex & mnim);
		friend std::istream & operator>>(std::istream & os, Complex & mnim);
		friend Complex operator*(const double & vesh, const Complex & mnim);
	private:
		double RE_;
		double IM_;
	};
}

#endif