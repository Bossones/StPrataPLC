#include "nmspc.hpp"

Stack::Stack() {
	for (int i = 0; i < MAX; i++) {
		items[i].fullname[0] = '\0';
		items[i].payment = 0;
	}
	top = 0;
	count = 0;
}

bool Stack::isempty() const {
	if (top == 0)
		return true;
	else 
		return false;
}

bool Stack::isfull() const {
	if (top == MAX)
		return true;
	else
		return false;
}

bool Stack::pop(Item & item) {
	if (top == 0)
		return false;
	else {
		item = items[--top];
		return true;
	}
}

bool Stack::push(const Item & item) {
	if (top == MAX)
		return false;
	else {
		items[top++] = item;
		count++;
		return true;
	}
}

void Stack::showall() const {
	using std::cout;
	using std::endl;
	for(int i = 0; i < count; i++) {
		cout << items[i].fullname << endl;
		cout << items[i].payment << endl;
	}
	cout << "Top is " << top << endl;
}