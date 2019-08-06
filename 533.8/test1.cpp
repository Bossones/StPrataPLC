#include "list.hpp"


List::List() {
	los_ = nullptr;
	first_= nullptr;
}

List::List(const std::string & name, const int & number) {
	los_ = new item;
	los_->name = name;
	los_->number = number;
	los_->next = nullptr;
	first_ = los_;
}

List::~List() {
	if (first_ != nullptr)
		deleted(first_);
	first_ = nullptr;
	los_ = nullptr;
}

inline bool List::isempty() const {
	if (first_ == nullptr)
		return true;
	else 
		return false;
}

unsigned int List::howman() const {
	item * forthis = first_;
	unsigned int count = 0;
	while(forthis != nullptr) {
		count++;
		forthis = forthis->next;
	}
	return count;
}

void List::push(const std::string & name, const int & number) {
	if (los_ != nullptr) {
		los_->next = new item;
		los_ = los_->next;
		los_->name = name;
		los_->number = number;
		los_->next = nullptr;
	}
	else {
		los_ = new item;
		los_->name = name;
		los_->number = number;
		los_->next = nullptr;
		first_ = los_;
	}
}

void List::pop(item & los) {
	los.name = los_->name;
	los.number = los_->number;
	los.next = nullptr;
	item * forthis = first_;
	if (forthis->next == nullptr) {
		forthis == nullptr;
		first_ = nullptr;
		delete los_;
		los_ = nullptr;
	}
	else {
		while (forthis->next != los_) {
			forthis = forthis->next;
		}
		delete los_;
		los_ = forthis;
		los_->next = nullptr;
		forthis = nullptr;
	}
}

void List::showall() const {
	using std::cout;
	using std::endl;
	item * forthis = first_;
	while(forthis != nullptr) {
		cout << "Current item: " << endl;
		cout << "Name: " << forthis->name << " number: " << forthis->number << endl;
		forthis = forthis->next;
	}
	cout << "End of showing" << endl;
}

void List::deleted(item * first_) {
	using std::cout;
	using std::endl;
	if (first_->next != nullptr)
		deleted(first_->next);
	else
		delete first_;
}

void iitem(item * los) {
	los->number++;
}

void sitem(item * los) {
	std::string s = " Sobaka";
	los->name = los->name + s;
}

void List::visit(void (*pf)(item *)) {
	item * forthis = first_;
	while(forthis != nullptr) {
		pf(forthis);
		forthis = forthis->next;
	}
}