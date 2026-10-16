#include "Book.h"
#include <string>
#include <ostream>

Book::Book(std::string name, std::string author, std::string year) : 
nameBook(name), AuthorBook(author), YearOfPublication(year){}

std::string Book::getNameBook() const {return nameBook;}
std::string Book::getAuthorBook() const {return AuthorBook;}
std::string Book::getYearOfPublication() const {return YearOfPublication;}

std::ostream& operator<<(std::ostream& os, const Book& b){
    os << "     BookInfo:\n"
    << "Book_Name: " << b.getNameBook() << "\n"
    << "Book_Author: " << b.getAuthorBook() << "\n"
    << "Book_Year_Of_Publication: " << b.getYearOfPublication() << "\n";
    return os;
}