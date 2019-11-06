#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
    std::set<std::string> Mat;
    std::set<std::string> Pet;
    std::set<std::string> MatPet;
    std::string name;

    std::cout << "Enter Mat's friends: (q to quit) ";
    std::cin >> name;

    while (name != "q"){
        Mat.insert(name);
        std::cin >> name;
    }

    std::cout << "Enter Pet's friends: (q to quit) ";
    std::cin >> name;

    while (name != "q"){
        Pet.insert(name);
        std::cin >> name;
    }
    std::set_union(Mat.begin(), Mat.end(), Pet.begin(), Pet.end(), std::insert_iterator<std::set<std::string>>(MatPet, MatPet.begin()));
    std::copy(MatPet.begin(), MatPet.end(), std::ostream_iterator<std::string>(std::cout, " "));

    return 0;
}