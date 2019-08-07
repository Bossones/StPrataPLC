#include "vector.hpp"
#include <fstream>

namespace vec {

	Vector::Vector (const double & num1, const double & num2, Mode form) {
		if (form == RET) {
			x = num1;
			y = num2;
			set_mod();
			set_ang();
			tob = RET;
		}
		else if (form == POL) {
			mod = num1;
			ang = num2;
			set_x();
			set_y();
			tob = POL;
		}
		else {
			std::cout << "Incorrect modification for vector" << std::endl;
			std::cout << "This vector set as 0" << std::endl;
			std::cout << "Mod is RET" << std::endl;
			mod = ang = x = y = 0;
			tob = RET;
		}
	}

	Vector::Vector() {
		mod = ang = x = y = 0;
		tob = RET;
	}

	void Vector::reset(const double & num1, const double & num2, Mode form) {
		if (form == RET) {
			x = num1;
			y = num2;
			set_mod();
			set_ang();
			tob = RET;
		}
		else if (form == POL) {
			mod = num1;
			ang = num2;
			set_x();
			set_y();
			tob = POL;
		}
		else {
			std::cout << "Incorrect modification for vector" << std::endl;
			std::cout << "This vector set as 0" << std::endl;
			std::cout << "Mod is RET" << std::endl;
			mod = ang = x = y = 0;
			tob = RET;
		}
	}

	void Vector::change_mod(Mode form) {
		if (form == RET)
			tob = RET;
		else if (form == POL)
			tob = POL;
		else {
			std::cout << "Incorrect modification for vector" << std::endl;
			std::cout << "Current modification still saving" << std::endl;
		}
	}

	void Vector::show_vec() const {
		if (tob == RET) {
			std::cout << "Vector:" << std::endl;
			std::cout << "x: " << x << " y: " << y << std::endl;
		}
		else if (tob == POL) {
			std::cout << "Vector: " << std::endl;
			std::cout << "mod: " << mod << ", ang: " << ang << std::endl;
		}
	}

	void Vector::set_x() {
		x = mod * std::cos(ang * PI / 180);
	}

	void Vector::set_y() {
		y = mod * std::sin(ang * PI / 180);
	}

	void Vector::set_mod() {
		mod = std::sqrt(x * x + y * y);
	}

	void Vector::set_ang() {
		ang = std::atan(y / x) * 180 / PI;
	}

	Vector Vector::operator+(const Vector & ves) const {
		return Vector(x + ves.x, y + ves.y);
	}

	Vector Vector::operator*(const double & chislo) const {
		return Vector(x * chislo, y * chislo);
	}

	Vector Vector::operator-(const Vector & ves) const {
		return Vector(x - ves.x, y - ves.y);
	}

	Vector Vector::operator-() const {
		return Vector(-x, -y);
	}

	Vector::Mode Vector::get_mode() const {
		return tob;
	}

	std::ostream & operator<<(std::ostream & os, const Vector & ves) {
		if (ves.get_mode() == Vector::RET)
			os << "(x,y) = (" << ves.x << ", " << ves.y << ")";
		else if (ves.get_mode() == Vector::POL)
			os << "(mod, ang) = (" << ves.mod << ", " << ves.ang << ")";
		return os; 
	}

	std::ofstream & operator<<(std::ofstream & os, const Vector & ves) {
		if (ves.tob == Vector::RET)
			os << "(x,y) = (" << ves.x << ", " << ves.y << ")";
		else if (ves.tob == Vector::POL)
			os << "(mod, ang) = (" << ves.mod << ", " << ves.ang << ")";
		return os; 
	}

	void Vector::operator=(const Vector & ves) {
		x = ves.x;
		y = ves.y;
		mod = ves.mod;
		ang = ves.ang;
		tob = ves.tob;
	}
}