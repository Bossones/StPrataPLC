#ifndef STRING2_HPP__
#define STRING2_HPP__

#include <cctype>
#include <iostream>
#include <cstring>


class String {
public:
	String();
	String (const char * str);
	~String();
	String(const String & str);

	String & stringlow();
	String & stringup();
	unsigned int has(const char & ch) const;

	String & operator=(const char * str);
	String & operator=(const String & str);
	bool operator==(const String & str) const;
	String operator+(const String & str) const;
	String operator+(const char * str) const;
	char & operator[](int i);
	const char & operator[](int i) const;

	friend std::ostream & operator<<(std::ostream & os, const String & str);
	friend std::istream & operator>>(std::istream & is, String & str);
	friend String operator+(const char * str, const String & sro);
private:
	char * sk;
	unsigned int len;
};


#endif