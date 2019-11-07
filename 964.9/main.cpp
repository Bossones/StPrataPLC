#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> vi0(1000000);
    std::vector<int> vi(1000000);
    std::list<int> li;
    std::srand(std::time(0));

    for(auto & x: vi0) {
        x = std::rand() % 10000000;
        li.push_back(x);
    }

    vi = vi0;
    
    clock_t begin_time = std::clock();
    std::sort(vi.begin(), vi.end());
    clock_t end_time = std::clock();

    std::cout << "Time of sort  by algorithm: "
        << (static_cast<double>((end_time - begin_time)) / CLOCKS_PER_SEC) << std::endl;

    begin_time = std::clock();
    li.sort();
    end_time = std::clock();

    std::cout << "Time of sort by method: "
        << (static_cast<double>((end_time - begin_time)) / CLOCKS_PER_SEC)
        << std::endl;

    std::copy(vi0.begin(), vi0.end(), li.begin());

    begin_time = std::clock();
    
    std::copy(li.begin(), li.end(), vi.begin());
    std::sort(vi.begin(), vi.end());
    std::copy(vi.begin(), vi.end(), li.begin());
    end_time = std::clock();

    std::cout << "All time with copy to vector: " << (static_cast<double>(end_time - begin_time) / CLOCKS_PER_SEC)
        << std::endl;
    return 0;
}