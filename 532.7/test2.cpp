#include "nmspc.hpp"

int main()
{
	Plorg sect;
	Plorg tegt {"Bitumil", 400};
	sect.changeCI(120);
	sect.showplorg();
	tegt.showplorg();
	return 0;
}