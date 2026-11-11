#include "Libriary.h"
#include "Book.h"
#include <iostream>
#include <vector>
#include <optional>
#include <fstream>
#include <string>

bool Libriary::addBook(const Book& book){
    auto temp_book = FindBookByName(book.getNameBook());
    if(!temp_book.has_value()){
        books.push_back(book);
        return true;
    }
    return false;
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
const std::vector<Loan>& Libriary::getLoans() const {
    return loans;
}

bool Libriary::addLoan(const Loan& loan){
    std::string book_nm = loan.getBook().getNameBook();
    for(const Loan& ln : loans){
        std::string bk = ln.getBook().getNameBook();
        if(book_nm == bk){
            return false;
        }
    }
    loans.push_back(loan);
    return true;
}

bool Libriary::returnBook(const std::string& nameBook){
    for(auto l = loans.begin(); l != loans.end(); ++l){
        if(l->getBook().getNameBook() == nameBook){
            loans.erase(l);
            return true;
        }
    }
    return false;
}

bool Libriary::removeBook(const std::string& nameBook){
    for(auto b = books.begin(); b != books.end(); ++b){
        if(b->getNameBook() == nameBook){
            books.erase(b);
            return true;
        }
    }
    return false;
}

void Libriary::printAllLoans() const {
    for(const Loan& l : loans){
        std::cout << l << "\n";
    }
}