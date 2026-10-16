#pragma once
#include "Book.h"
#include <string>
#include <vector>
#include <optional>


class Libriary{
private:
    std::vector<Book> books;
public:
    void addBook(const Book& book);
    void printAllBooks() const;
    std::optional<Book> FindBookByName (const std::string& name_book) const;
    void showBook(const Libriary& lib, const std::string& name_book) const;
};
