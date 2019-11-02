#include <iostream>
#include <string>
#include <algorithm>

template <typename Type>
int reduce(Type ar[], const int & n) {
    std::sort(ar, ar + n);
    return std::unique(ar, ar + n) - ar;
}

template<> int reduce<>(std::string ar[], const int & n) {
    std::sort(ar->begin(), ar->end());
    ar->erase(std::unique(ar->begin(), ar->end()), ar->end());
    return ar->size();
}

int main() {
    long arl[] {555, 234, -40, 23, 67, 555, 234, 78, -200, -100};
    char arc[] = "kollabokcich";
    std::string str = "savetheworldbabyiamtryed";
    std::cout << reduce(arl, 10) << " char: " << reduce(arc, 13) << " string: " << reduce(&str, 25) << std::endl;

    return 0;
}