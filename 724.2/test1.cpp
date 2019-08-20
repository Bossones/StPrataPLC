#include "classic.hpp"
#include <cstring>

//cd methods

cd::cd(const char * s1, const char * s2,
        int n, double x) : selections(n), playtime(x) {
    performers = new char[std::strlen(s1) + 1];
    std::strcpy(performers, s1);
    label = new char[std::strlen(s2) + 1];
    std::strcpy(label, s2);
}
    
cd::cd(const cd & d) : selections(d.selections), playtime(d.playtime) {
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
}

cd::cd() : selections(0), playtime(0.0) {
    performers = new char[1];
    performers[0] = '\0';
    label = new char[1];
    label[0] = '\0';
}

cd::~cd() {
    delete [] performers;
    delete [] label;
}

void cd::Report() const {
    using std::cout;
    using std::endl;

    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

cd & cd::operator=(const cd & d) {
    if (this == &d)
        return *this;
    delete [] performers;
    delete [] label;
    performers = new char[std::strlen(d.performers) + 1];
    std::strcpy(performers, d.performers);
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}


//classic methods

classic::classic(const char * name_, const char * s1, const char * s2, 
        int n, double x) : cd(s1, s2, n, x) {
    name_of_song = new char[std::strlen(name_) + 1];
    std::strcpy(name_of_song, name_);
}

classic::classic() : cd() {
    name_of_song = new char[1];
    name_of_song[0] = '\0';
}

classic::classic(const classic & d) : cd(d) {
    name_of_song = new char[std::strlen(d.name_of_song) + 1];
    std::strcpy(name_of_song, d.name_of_song);
}

classic::~classic() {
    delete [] name_of_song;
}

void classic::Report() const {
    using std::cout;
    using std::endl;

    cd::Report();
    cout << "Name of song: " << name_of_song << endl;
}

classic & classic::operator=(const classic & d) {
    if (this == &d)
        return *this;
    cd::operator=(d);
    delete [] name_of_song;
    name_of_song = new char[std::strlen(d.name_of_song) + 1];
    std::strcpy(name_of_song, d.name_of_song);
}