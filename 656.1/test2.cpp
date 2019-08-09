#include "cow.hpp"

int main()
{
	Cow first("Petr", "Football", 63);
	first.ShowCow();
	Cow second(first);
	second.ShowCow();
	Cow third;
	third = first;
	third.ShowCow();
	return 0;
}