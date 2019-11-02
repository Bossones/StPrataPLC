#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

int main() {
    std::ifstream FWordList;
    std::string text;
    std::string target;
    std::string current;
    std::vector<std::string> wordlist;
    int errors;
    std::string::size_type position;
    char play;
    char symbol;
    
    FWordList.open("wordlist.txt"); // open worldlist
    while(!FWordList.eof()) {
        FWordList >> text;
        wordlist.push_back(text);
    }
    FWordList.close();

    std::cout << "Do you want play? Y/n "; // beginning of the game
    std::cin >> play;
    play = std::tolower(play);
    std::srand(std::time(0));
    
    while(play == 'y') {
        target = wordlist[std::rand() % static_cast<int>(wordlist.size())];
        current.assign(target.size(), '-');
        errors = target.size() - 0.45 * target.size();
        while (errors && (current.find('-') != std::string::npos)) { // check errors and correct word
            std::cout << "----------------------------------------" << std::endl;
            std::cout << "You have " << errors << " errors." << std::endl;
            std::cout << "Your word has " << target.size() << " symbols." << std::endl;
            std::cout << "Current: " << current << std::endl;
            std::cout << "Enter symbol: ";
            std::cin >> symbol;
            position = target.find(symbol);
            if (position == std::string::npos) {
                std::cout << "Error. This symbol doesn't exist." << std::endl;
                --errors;
                continue;
            }
            std::cout << "Yes, correct!" << std::endl;
            while (position != std::string::npos) {
                current[position] = target[position];
                position = target.find(symbol, position + 1);
            }
        }
        if(!errors) {
            std::cout << "Sorry, you losed. Do you want to play again? Y/N? ";
            std::cin >> play;
            play = std::tolower(play);
            continue;
        }
        std::cout << "Oooh yes. You won. Your word is: " << target << std::endl;
        std::cout << "Do you want to play again? Y/N? ";
        std::cin >> play;
        play = std::tolower(play);
    }

    return 0;
}