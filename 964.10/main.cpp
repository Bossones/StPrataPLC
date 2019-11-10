#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

struct Review {
    unsigned int price;
    std::string title;
    int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool worseThan(const Review & r1, const Review & r2);
bool worseThanli(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool priceThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(Review & rr);
void ShowReview(const std::shared_ptr<Review> & rr);

int main() {
    std::vector<std::shared_ptr<Review>> books;
    Review temp;
    while(FillReview(temp))
        books.push_back(std::make_shared<Review>(temp));
    if (books.size() > 0) {
        enum {raiting, title, price, quit};
        int sortMethod = 1;
        bool flag = false;
        while (!flag) {
            std::cout << "Enter sort mode:\n 0 - Raiting sort, 1 - title sort, 2 - price sort, 3 - quit: ";
            std::cin >> sortMethod;
            switch (sortMethod)
            {
            case raiting:
                std::sort(books.begin(), books.end(), worseThanli);
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            case title:
                std::sort(books.begin(), books.end());
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            case price:
                std::sort(books.begin(), books.end(), priceThan);
                std::for_each(books.begin(), books.end(), ShowReview);
                break;
            case quit:
                flag = true;
                std::cout << "Okay..." << std::endl;
                break;
            default:
                std::cout << "Wrong number. Try  again" << std::endl;
                break;
            }
        }
    } else
        std::cout << "No entries. ";
    std::cout << "Bye." << std::endl;
    return 0;
}

bool operator<(const Review & r1, const Review & r2) {
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool worseThan(const Review & r1, const Review & r2) {
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool worseThanli(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2) {
    return worseThan((*r1), (*r2));
}

bool priceThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2) {
    if(r1->price < r2->price)
        return true;
    return false;
}

bool FillReview(Review & rr) {
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    std::cout << "Enter book price: ";
    std::cin >> rr.price;
    if (!std::cin)
        return false;
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> & rr) {
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2) {
    return ((*r1) < (*r2));
}