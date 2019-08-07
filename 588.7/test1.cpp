#include "complexx.hpp"

namespace com {

		Complex::Complex(const double & RE, const double & IM) {
			RE_ = RE;
			IM_ = IM;
		}

		Complex Complex::operator+(const Complex & mnim) const {
			return Complex(RE_ + mnim.RE_, IM_ + mnim.IM_);
		}

		Complex Complex::operator-(const Complex & mnim) const {
			return Complex(RE_ - mnim.RE_, IM_ - mnim.IM_);
		}

		Complex Complex::operator*(const Complex & mnim) const {
			return Complex(RE_ * mnim.RE_ - IM_ * mnim.IM_, RE_ * mnim.IM_ + IM_ * mnim.RE_);
		}

		Complex Complex::operator*(const double & vesh) const {
			return Complex(RE_ * vesh, IM_ * vesh);
		}

		Complex Complex::operator~() const {
			return Complex(RE_, -IM_);
		}

		std::ostream & operator<<(std::ostream & os, const Complex & mnim) {
			os << "(" << mnim.RE_ << "," << mnim.IM_ << "i)";
			return os;
		}

		std::istream & operator>>(std::istream & os, Complex & mnim) {
			std::cout << "real: ";
			os >> mnim.RE_;
			std::cout << "imaginary: ";
			os >> mnim.IM_;
			return os;
		}

		Complex operator*(const double & vesh, const Complex & mnim) {
			return mnim * 2;
		}
}