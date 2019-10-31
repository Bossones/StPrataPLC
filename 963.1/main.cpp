#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool ISALPH(const char & ch) {
    if(!std::isalpha(ch))
        return true;
    return false;
}

bool isPalindrom(std::string & str) {
    str.erase(std::remove_if(str.begin(), str.end(), ISALPH), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    int sz = str.size();
    std::cout << sz << std::endl;
    for(int i = 0; i < sz - i; ++i) {
        if (str[i] != str[sz - i - 1])
            return false;
    }
    return true;
}

int main() {
    using std::cout;
    using std::cin;
    using std::string;
    string polindrom;
    std::getline(cin, polindrom);
    cout << isPalindrom(polindrom) << std::endl;
    return 0;
}