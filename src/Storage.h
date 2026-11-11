#pragma once
#include "Book.h"
#include "Loan.h"
#include <vector>
#include <string>

class Storage{
private:
    std::string filename_books;
    std::string filename_loans;
public:
    Storage(const std::string& fn_b, const std::string fn_l);
    void saveBooks(const std::vector<Book>& books) const;
    std::vector<Book> loadBooks() const;
    void saveLoans(const std::vector<Loan>& loans) const;
    std::vector<Loan> loadLoans() const;
};