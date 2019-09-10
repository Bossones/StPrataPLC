#ifndef PAIR_HPP__
#define PAIR_HPP__

template <typename T1, typename T2>
class Pair {
private:
    T1 first_;
    T2 second_;
public:
    Pair(const T1 & first, const T2 & second) : first_(first), second_(second) {}
    Pair(const int & y) : first_(y), second_(y) {}
    Pair() {}

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

#endif