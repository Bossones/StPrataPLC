#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>
#include <cmath>

namespace vec {
	class Vector {
	public:
		enum Mode {RET, POL};
		Vector();
		Vector(const double & num1, const double & num2, Mode form = RET);
		void reset(const double & num1, const double & num2, Mode form = RET);
		void change_mod(Mode form = RET);
		void show_vec() const;
		Vector operator+(const Vector & ves) const;
		Vector operator*(const double & chislo) const;
		Vector operator-() const;
		Vector operator-(const Vector & ves) const;
		void operator=(const Vector & ves);
		friend std::ostream & operator<<(std::ostream & os, const Vector & ves);
		friend std::ofstream & operator<<(std::ofstream & os, const Vector & ves);
		Vector::Mode get_mode() const;
		double get_mod() const {return mod;}
	private:
		const double PI = 3.14159265;
		void set_x();
		void set_y();
		void set_mod();
		void set_ang();
		double x, y;
		double ang, mod;
		Mode tob;
	};
}
#endif