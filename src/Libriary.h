#pragma once
#include "Book.h"
#include "Loan.h"
#include <string>
#include <vector>
#include <optional>


class Libriary{
private:
    std::vector<Book> books;
    std::vector<Loan> loans;
public:
    bool addBook(const Book& book);
    void printAllBooks() const;
    std::optional<Book> FindBookByName (const std::string& name_book) const;
    void printBookByName(const std::string& name) const; 
    const std::vector<Book>& getBooks() const;
    const std::vector<Loan>& getLoans() const;
    bool addLoan(const Loan& loan);
    bool returnBook(const std::string& nameBook);
    bool removeBook(const std::string& nameBook);
    void printAllLoans() const;
};
