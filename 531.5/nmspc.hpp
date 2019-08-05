#ifndef NMSPC_HPP_
#define NMSPC_HPP_
#include <iostream>

struct customer {
	char fullname[35];
	double payment;
};
typedef customer Item;

class Stack {
private:
	enum {MAX = 10};
	Item items[MAX];
	int top;
	int count;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool pop(Item & item);
	bool push(const Item & item);
	void showall() const;
};
#endif