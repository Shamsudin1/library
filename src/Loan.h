#pragma once
#include "Book.h"
#include "Reader.h"
#include <string>
#include <ostream>


class Loan {
private:
    Book book;
    Reader reader;
    std::string date_of_issue;
    std::string date_return;
public:
    Loan(const Book& b, const Reader& r, const std::string& d_of_is, const std::string& d_r);
    Book getBook() const;
    Reader getReader() const;
    std::string getDate_Of_Issue() const;
    std::string getDate_Return() const;
};

std::ostream& operator<<(std::ostream& os, const Loan& loan);