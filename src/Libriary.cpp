#include "Libriary.h"
#include "Book.h"
#include <iostream>
#include <vector>
#include <optional>
#include <fstream>
#include <string>

void Libriary::addBook(const Book& book){
    auto temp_book = FindBookByName(book.getNameBook());
    if(!temp_book.has_value()){
        books.push_back(book);
    }
    else{
        std::cerr << "Книга уже есть в библиотеке!\n";
    }
}
void Libriary::printAllBooks() const {
    for(const Book& b : books){
        std::cout << b << "\n";
    }
} 

std::optional<Book> Libriary::FindBookByName  (const std::string& name_book) const {
    for(const Book& b : books){
        if(b.getNameBook() == name_book){
            return b;
        }
        
    }
    return std::nullopt;
}


void Libriary::printBookByName(const std::string &name) const {
   auto temp_book = FindBookByName(name);
   if(temp_book.has_value()){
        std::cout << *temp_book;
   }
   else{std::cout << "Книга не найдена!\n";}
}

const std::vector<Book>& Libriary::getBooks() const {
    return books;
}
