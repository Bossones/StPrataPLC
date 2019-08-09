#include "cow.hpp"

Cow::Cow() {
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt) : weight(wt) {
	std::strcpy(name, nm);
	hobby = new char[std::strlen(ho) + 1];
	std::strcpy(hobby, ho);
	hobby[std::strlen(ho) + 1] = '\0';
}

Cow::Cow(const Cow & c) {
	std::strcpy(name, c.name);
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	hobby[std::strlen(c.hobby) + 1] = '\0';
	weight = c.weight;
}

Cow::~Cow() {
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c) {
	if (this == &c)
		return *this;
	delete [] hobby;
	std::strcpy(name, c.name);
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	hobby[std::strlen(c.hobby) + 1] = '\0';
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Hobby: " << hobby << std::endl;
	std::cout << "Weight: " << weight << std::endl;
}