#include "vintageport.hpp"
#include <cstring>

port::port(const char * br, const char * st, 
        int b) : bottles(b) {
    brand = new char[std::strlen(br) + 1];
    std::strcpy(brand, br);
    std::strcpy(style, st);
}

port::port(const port & p) : bottles(p.bottles) {
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
}

port & port::operator=(const port & p) {
    if (this == &p)
        return *this;
    delete [] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;
}

port & port::operator+=(int b) {
    bottles += b;
    return *this;
}

port & port::operator-=(int b) {
    bottles -= b;
    return *this;
}

void port::Show() const {
    using std::cout;
    using std::endl;

    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Botless: " << bottles << endl;
}

std::ostream & operator<<(std::ostream & os, const port & p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

//vintage functions

vintageport::vintageport(const char * br, int b, const char * nn, int y) : port(br, "vintage", b) {
    nickname = new char[std::strlen(nn) + 1];
    std::strcpy(nickname, nn);    
    year = y;
}

vintageport::vintageport() : year(0) {
    nickname = new char[1];
    nickname[0] = '\0';
}

vintageport::vintageport(const vintageport & vp) : port(vp) {
    nickname = new char[std::strlen(vp.nickname) + 1];
    nickname = std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

vintageport & vintageport::operator=(const vintageport & vp) {
    if (this == &vp)
        return *this;
    delete [] nickname;
    port::operator=(vp);
    nickname = new char[std::strlen(vp.nickname) + 1];
    nickname = std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

void vintageport::Show() const { //virtual from port
    port::Show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl;
}

std::ostream & operator<<(std::ostream & os, const vintageport & vp) { //friend function for vintage
    os << dynamic_cast<const port &>(vp);
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}