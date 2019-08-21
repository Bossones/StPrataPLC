#include "vintageport.hpp"

int main() {
    port one("Jameson", "white", 20);
    one.Show();
    one += 5;
    std::cout << one << std::endl;
    port * second = new vintageport("Jack", 50, "Frenk Spotti", 1888);
    second->Show();
    vintageport third("Whicks", 70, "francesco sota", 1790);
    std::cout << *second << std::endl;
    std::cout << third << std::endl;
    return 0;
}