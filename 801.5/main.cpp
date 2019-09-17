#include <iostream>
#include "emp.hpp"

using namespace std;

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll ();
    fink fi("Matt", "Oggs", "Oiler", "JunoBarr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew"); // укомплектовано?
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    // Нажать любую клавишу для следующей фазы
    while(cin.get() != '\n')
        continue;
    highfink hf2;
    hf2.SetAll();
    cout << "Using an abstr_emp * pointer:\n";
    // Использование указателя abstr_emp *
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();
    return 0;
}