#ifndef WINE_HPP__
#define WINE_HPP__

#include <iostream>
#include <valarray>

template <typename T1, typename T2>
class Pair {
private:
    T1 first_;
    T2 second_;
public:
    Pair() {}
    Pair(const T1 & first, const T2 & second) : first_(first), second_(second) {}
    Pair(const int & y);

    T1 & first() {
        return first_;
    }

    T2 & second() {
        return second_;
    }

    T1 first() const {
        return first_;
    }

    T2 second() const {
        return second_;
    }

};

/*template<typename T1, typename T2>
void Pair<T1, T2>::Show() const {
    using std::cout;
    using std::endl;
    cout << first_ << endl;
    cout << second_ << endl;
}

template <typename T1, typename T2>
void Pair<T1, T2>::Set() {
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter first object: ";
    cin >> first_;
    cout << "Enter second object: ";
    cin >> second_;
    while (cin.get() != '\n')
        continue;
}*/

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const int & y) : first_(y), second_(y) {}

/*template <>
Pair<std::valarray<int>, std::valarray<int>>::Pair(const int & y) {
    first_ = std::valarray<int>(y);
    second_ = std::valarray<int>(y);
}*/

/*template <>
void Pair<std::valarray<int>, std::valarray<int>>::Show() const {
    using std::cout;
    using std::endl;
    cout << "First array: " << endl;
    for (int i = 0; i < first_.size(); i++) {
        cout << i << ": " << first_[i] << endl;
    }
    cout << "Second array: " << endl;
    for (int i = 0; i < second_.size(); i++) {
        cout << i << ": " << second_[i] << endl;
    }
}

template <>
void Pair<std::valarray<int>, std::valarray<int>>::Set() {
    using std::cout;
    using std::cin;
    using std::endl;

    unsigned int SIZE = 0;
    cout << "Enter size of first array: ";
    cin >> SIZE;
    first_ = std::valarray<int>(SIZE);
    for (int i = 0; i < SIZE; i++)
        cin >> first_[i];
    cout << "Enter size of second array: ";
    cin >> SIZE;
    second_ = std::valarray<int>(SIZE);
    for (int i = 0; i < SIZE; i++)
        cin >> second_[i];
}*/

class Wine {
private:
    std::string nameOfWine;
    Pair<std::valarray<int>, std::valarray<int>> para;
    int years;
public:
    Wine(const char * lab, int y, const int yr[], const int bot[]);
    Wine(const char * lab = "NOPE", int y = 0);

    void GetBottles();
    std::string & Label();
    int sum();
    void Show() const;
};

#endif