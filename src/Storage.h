#pragma once
#include "Book.h"
#include <vector>
#include <string>

class Storage{
private:
    std::string filename;
public:
    Storage(const std::string& fn);
    void saveBooks(const std::vector<Book>& books) const;
    std::vector<Book> loadBooks() const;
};