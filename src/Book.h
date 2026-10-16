#pragma once
#include <string>
#include <ostream>

class Book{
private:
    std::string nameBook;
    std::string AuthorBook;
    std::string YearOfPublication;
public:
    Book(std::string name, std::string author, std::string year);
    std::string getNameBook() const;
    std::string getAuthorBook() const;
    std::string getYearOfPublication() const;
};

std::ostream& operator<<(std::ostream& os, const Book& b);