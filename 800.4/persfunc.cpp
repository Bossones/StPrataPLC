#include "person.hpp"

//Person::

void Person::Data() const {
    std::cout << "Fullname is: " << fullname << std::endl;
}

//Gunslinger::

void Gunslinger::Data() const {
    std::cout << "Time is: " << time_ << std::endl;
    std::cout << "Nasechki is: " << nas_ << std::endl;
}

double Gunslinger::Draw() {
    return time_;
}

void Gunslinger::Show() const {
    Person::Data();
    this->Data();
}

//Card::

std::ostream & operator<<(std::ostream & os, const Card & cd) {
    std::cout << "Znach is: " << cd.znach_ << std::endl;
    std::cout << "Mas is: " << cd.mas_;
    return os;
}

//PokerPlayer::

void PokerPlayer::Data() const {
    std::cout << cd << std::endl;
}

Card PokerPlayer::Draw() {
    return cd;
}

void PokerPlayer::Show() const {
    Person::Data();
    this->Data();
}

//BadDude::

void BadDude::Data() const{
    std::cout << "Time to fire is: " << timeToFire_ << std::endl;
    std::cout << "Next Card is: " << std::endl << nextCd << std::endl;
}

double BadDude::Gdraw() {
    return timeToFire_;
}

void BadDude::Show() const {
    Person::Data();
    Gunslinger::Data();
    PokerPlayer::Data();
    this->Data();
}