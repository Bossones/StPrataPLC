#include "wine.hpp"

Wine::Wine(const char * lab, int y, const int yr[], const int bot[]) :
        nameOfWine(lab), para(y), years(y) {

    std::valarray<int> & fst = para.first();
    std::valarray<int> & sec = para.second();

    for (int i = 0; i < years; ++i) {
        fst[i] = yr[i];
        sec[i] = bot[i];
    } 
}

Wine::Wine(const char * lab, int y) : nameOfWine(lab), para(y), years(y) {}

void Wine::GetBottles() {
    using std::cout;
    using std::endl;
    using std::cin;

    std::valarray<int> & fst = para.first();
    std::valarray<int> & sec = para.second();

    cout << "Enter " << nameOfWine << " data for " << years << " year(s):" << endl;
    for (int i = 0; i < years; ++i) {
        cout << "Enter year: ";
        cin >> fst[i];
        cout << "Enter bottles for that year: ";
        cin >> sec[i];
    }
}

std::string & Wine::Label() {
    return nameOfWine;
}

int Wine::sum() {
    int sum = 0;
    std::valarray<int> sec = para.second();

    for (int i = 0; i < years; ++i)
        sum += sec[i];
    return sum;
}

void Wine::Show() const {
    using std::cout;
    using std::endl;

    const std::valarray<int> & fst = para.first();
    const std::valarray<int> & sec = para.second();
    cout << "Wine: " << nameOfWine << endl;
    cout << "\tYear\tBottles" << endl;
    for (int i = 0; i < years; ++i) {
        cout << "\t" << fst[i] << "\t" << sec[i] << endl;
    }
}
