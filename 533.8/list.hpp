#ifndef LIST_HPP_
#define LIST_HPP_

#include <iostream>
#include <string>
#include <cstddef>

struct item {
	std::string name;
	int number;
	item * next;
};

void iitem(item * los);
void sitem(item * los);

class List {
public:
	List(const std::string & name, const int & number);
	List();
	~List();
	unsigned int howman() const;
	bool isempty() const;
	void visit(void (*pf)(item *));
	void push(const std::string & name, const int & number);
	void pop(item & los); 
	void showall() const;
private:
	void deleted(item * first_);
	item * los_;
	item * first_;
};
#endif