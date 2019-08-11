#include "string2.hpp"

String::String() : len(0) {
	sk = new char[1];
	sk[0] = '\0';
}

String::String(const char * str) : len(std::strlen(str)) {
	sk = new char[len + 1];
	std::strcpy(sk, str);
	sk[len] = '\0';
}

String::String(const String & str) : len(str.len) {
	sk = new char[len + 1];
	std::strcpy(sk, str.sk);
	sk[len] = '\0';
}

String::~String() {
	delete [] sk;
	sk = nullptr;
}

String & String::stringlow() {
	for (int i = 0; i <= len; i++) {
		sk[i] = std::tolower(sk[i]);
	}
	return *this;
}

String & String::stringup() {
	for (int i = 0; i <= len; i++) {
		sk[i] = std::toupper(sk[i]);
	}
	return *this;
}

unsigned int String::has(const char & ch) const {
	unsigned int count = 0;
	for (int i = 0; i < len + 1; i++) {
		if (sk[i] == ch)
			count++;
	}
	return count;
}

String & String::operator=(const char * str) {
	delete [] sk;
	len = std::strlen(str);
	sk = new char[len + 1];
	std::strcpy(sk, str);
	sk[len] = '\0';
	return *this;
}

String & String::operator=(const String & str) {
	if (this == &str)
		return *this;
	delete [] sk;
	len = str.len;
	sk = new char[len + 1];
	std::strcpy(sk, str.sk);
	sk[len] = '\0';
	return *this;
}

String String::operator+(const String & str) const {
	char temp[len + str.len + 1];
	std::strcpy(temp, sk);
	std::strcat(temp, str.sk);
	temp[len + str.len] = '\0';
	return String(temp);
}

String String::operator+(const char * str) const {
	char temp[len + std::strlen(str) + 1];
	std::strcpy(temp, sk);
	std::strcat(temp, str);
	temp[len + std::strlen(str)] = '\0';
	return String(temp);
}

char & String::operator[](int i) {
	return sk[i];
}

const char & String::operator[](int i) const {
	return sk[i];
}

std::ostream & operator<<(std::ostream & os, const String & str) {
	os << str.sk;
	return os;
}

std::istream & operator>>(std::istream & is, String & str) {
	char temp[200];
	char * mas = temp;
	char ch;
	bool flagfirst = false;
	is.get(ch);
	int i;
	for (i = 0; ch != '\n'; i++) {
		if (i == 199) {
			temp[i] = '\0';
			str = str + temp;
			i = -1;
		}
		else
			temp[i] = ch;
		is.get(ch);
		/*is.getline(mas, 199);
		if (flagfirst) 
			mas -= 1;
		str = str + mas;
		is.get(ch);
		if (ch == '\n')
			break;
		if (flagfirst) {
			mas[0] = ch;
			mas += 1;
		}
		if (!flagfirst)
			flagfirst = true;*/
	}
	if (i >= 0)
		temp[i] = '\0';
	str = str + temp;
	return is;
}

String operator+(const char * str, const String & sro) {
	char temp[std::strlen(str) + sro.len + 1];
	std::strcpy(temp, str);
	std::strcat(temp, sro.sk);
	temp[std::strlen(str) + sro.len] = '\0';
	return String(temp);
}

bool String::operator==(const String & str) const {
	return (std::strcmp(sk, str.sk));
}