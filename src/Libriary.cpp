#include "Libriary.h"
#include "Book.h"
#include <iostream>
#include <vector>
#include <optional>

void Libriary::addBook(const Book& book){
    books.push_back(book);
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

void Libriary::showBook(const Libriary& lib, const std::string& name) const {
    auto result = lib.FindBookByName(name);
    if(result.has_value()){
        std::cout << *result << "\n";
    }
    else{
        std::cout << "Книга не найдена\n";
    }
}

void Libriary::printBookByName(const std::string &name) const {
   for(const Book& t_b : books){
    if(name == t_b.getNameBook()){
        std::cout << t_b << "\n"; 
        
    }
   }
   if(!FindBookByName(name)){
    std::cout << "not founded!";
   }
}