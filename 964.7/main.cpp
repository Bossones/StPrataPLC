#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> Lotto(const int & end, const int & sh) {
    std::vector<int> target(sh);
    std::random_device rd;
    std::mt19937 mersenne(rd());
    for(auto &elem : target)
        elem = mersenne() % end + 1;
    std::sort(target.begin(), target.end());
    return target;
}

int main() {
    std::vector<int> sek = Lotto(51, 6);
    for(const auto &elem: sek)
        std::cout << elem << " ";
    std::cout << std::endl;
    return 0;
}