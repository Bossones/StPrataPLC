#include <iostream>

#include "remote.hpp"

int main() {
    Remote pult;
    TV telek;
    bool check;
    check = pult.tv_on(telek);
    std::cout << check << std::endl;
    pult.chanup(telek);
    pult.re_connection(telek);
    pult.set_channel(telek, 25);
    pult.set_volume(telek, 30);
    check = pult.volup(telek);
    std::cout << check << std::endl;
    return 0;
}