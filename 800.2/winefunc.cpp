#include "wine.hpp"

Wine::Wine(const char * lab, const int & y, const int yr[], const int bot[]) : std::string(lab), years(y), Pair(ArrayInt(y), ArrayInt(y)) {
    
    ArrayInt & fst = Pair::first();
    ArrayInt & sec = Pair::second();
    
    for (int i = 0; i < years; ++i) {
        fst[i] = yr[i];
        sec[i] = bot[i];
    }
}

Wine::Wine(const char * lab, const int & y) : std::string(lab), Pair(ArrayInt(y), ArrayInt(y)), years(y) {}

void Wine::GetBottles() {
    using std::cout;
    using std::endl;
    using std::cin;

    ArrayInt & fst = Pair::first();
    ArrayInt & sec = Pair::second();

    cout << "Enter " << *((std::string *)this) << " data for " << years << " year(s):" << endl;
    for (int i = 0; i < years; ++i) {
        cout << "Enter year: ";
        cin >> fst[i];
        cout << "Enter bottles for that year: ";
        cin >> sec[i];
    }
}

void Wine::Show() const {
    using std::cout;
    using std::endl;

    const ArrayInt & fst = Pair::first();
    const ArrayInt & sec = Pair::second();
    cout << "Wine: " << *((std::string *)this) << endl;
    cout << "\tYear\tBottles" << endl;
    for (int i = 0; i < years; ++i) {
        cout << "\t" << fst[i] << "\t" << sec[i] << endl;
    }
}

int Wine::Sum() const {
    int sum = 0;
    const ArrayInt & sec = Pair::second();

    for (int i = 0; i < years; ++i)
        sum += sec[i];
    return sum;
}

std::string & Wine::Label() {
    return *(dynamic_cast<std::string *>(this));
} 