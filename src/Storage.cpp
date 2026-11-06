#include "Storage.h"
#include "Book.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

Storage::Storage(const std::string& fn) : filename(fn){}

void Storage::saveBooks(const std::vector<Book>& books) const {
    std::ofstream fout(filename);
    if(fout.is_open()){
        for(const Book& b : books){
            fout << b.getNameBook() << "|" << b.getAuthorBook() << "|" << b.getYearOfPublication() << "\n";
        }
        
    }
    else{
        std::cerr << "File dont opened!\n";
    }
    fout.close();
}

std::vector<Book> Storage::loadBooks() const {
    std::vector<Book> st;
    std::ifstream fin(filename);
    if(fin.is_open()){
        std::string line;
        while(std::getline(fin, line)){
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            if(pos1 == std::string::npos || pos2 == std::string::npos){
                std::cerr << "Битая строка!\n";
                continue;
             }
            std::string temp_nameBook = line.substr(0, pos1);
            std::string temp_AuthorBook = line.substr(pos1+1, pos2 - pos1 - 1);
            std::string temp_YearOfPublication = line.substr(pos2 + 1);
            Book temp_book(temp_nameBook, temp_AuthorBook, temp_YearOfPublication);
            st.push_back(temp_book);
            
        }
    }
    return st;
}