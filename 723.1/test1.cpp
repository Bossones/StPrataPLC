#include "classic.hpp"
#include <cstring>

Cd::Cd(const char * s1, const char * s2, const int & n, const double & x) 
        : selections(n), playtime(x) {
    std::strcpy(performers, s1);
    std::strcpy(label, s2);
}

Cd::Cd(const Cd & d) : selections(d.selections), playtime(d.playtime) {
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);

}

Cd::Cd() : selections(0), playtime(0.0) {
    performers[0] = '\0';
    label[0] = '\0';
}

Cd::~Cd() {}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d)
        return *this;
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

void Cd::Report() const {
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}

Classic::Classic(const char * name_, const char * s1,
        const char * s2, const int & n, const double & x) : Cd(s1, s2, n, x) {
    std::strcpy(name_of_song, name_);
}

Classic::Classic() {
    name_of_song[0] = '\0';
}

Classic::Classic(const Classic & tresk) : Cd(tresk) {
    std::strcpy(name_of_song, tresk.name_of_song);
}

Classic::~Classic() {}

void Classic::Report() const {
    Cd::Report();
    std::cout << "Name of song: " << name_of_song << std::endl;
}

Classic & Classic::operator=(const Classic & tresk) {
    if (this == &tresk)
        return *this;
    Cd::operator=(tresk);
    std::strcpy(name_of_song, tresk.name_of_song);
    return *this;
}


