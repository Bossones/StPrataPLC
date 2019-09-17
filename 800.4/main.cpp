#include "person.hpp"

int main() {
    Person * f1 = new PokerPlayer("Timur Harlamov");
    Person * f2 = new Gunslinger("Steven Harrison", 5.5, 10);
    Person * f3 = new BadDude("Vladimir Putin", 1000.2, 1234);
    f1->Show();
    std::cout << std::endl;
    f2->Show();
    std::cout << std::endl;
    f3->Show();
    std::cout << std::endl;
    delete f3;
    delete f2;
    delete f1;
    return 0;
}