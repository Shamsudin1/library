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
    void addBook(const Book& book);
    void printAllBooks() const;
    std::optional<Book> FindBookByName (const std::string& name_book) const;
    void printBookByName(const std::string& name) const; 
    const std::vector<Book>& getBooks() const;
    void addLoan(const Loan& loan);
};
