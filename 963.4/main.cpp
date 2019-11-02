#include <iostream>
#include <algorithm>

int reduce(long ar[], const int & n) {
    std::sort(ar, ar + n);
    return std::unique(ar, ar + n) - ar;
}

int main() {
    long ar[] {555, 234, 9, 555, 28, -40, 25, -20, 234};
    std::cout << reduce(ar, 9) << std::endl; 
    return 0;
}