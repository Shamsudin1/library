#pragma once
#include <string>
#include <ostream>

class Book{
private:
    std::string nameBook;
    std::string AuthorBook;
    std::string YearOfPublication;
public:
    Book(const std::string& name, const std::string& author, const std::string& year);
    std::string getNameBook() const;
    std::string getAuthorBook() const;
    std::string getYearOfPublication() const;
};

std::ostream& operator<<(std::ostream& os, const Book& b);