#include "Storage.h"
#include "Book.h"
#include "Loan.h"
#include "Reader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

Storage::Storage(const std::string& fn_b, const std::string fn_l) : filename_books(fn_b), filename_loans(fn_l){}

void Storage::saveBooks(const std::vector<Book>& books) const {
    std::ofstream fout(filename_books);
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
    std::ifstream fin(filename_books);
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

void Storage::saveLoans(const std::vector<Loan>& loans) const {
    std::ofstream fout(filename_loans);
    if(fout.is_open()){
        for(const Loan& l : loans){
            fout << l.getBook().getNameBook() << "|" << l.getBook().getAuthorBook() << "|" << l.getBook().getYearOfPublication() << "|" << l.getReader().getReader_Name() << "|" << l.getReader().getNumber_Bilet() << "|" << l.getDate_Of_Issue() << "|" << l.getDate_Return() <<"\n";
        }
    }
    else{
        std::cerr << "File not founded!\n";
    }
    fout.close();
}

std::vector<Loan> Storage::loadLoans() const {
    std::vector<Loan> ln;
    std::ifstream fin(filename_loans);
    if(fin.is_open()){
        std::string line;
        while(std::getline(fin, line)){
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            size_t pos3 = line.find('|', pos2 + 1);
            size_t pos4 = line.find('|', pos3 + 1);
            size_t pos5 = line.find('|', pos4 + 1);
            size_t pos6 = line.find('|', pos5 + 1);
            if(pos1 == std::string::npos || pos2 == std::string::npos || pos3 == std::string::npos || pos4 == std::string::npos || pos5 == std::string::npos || pos6 == std::string::npos){
                std::cerr << "Битая строка\n";
                continue;
            }
            std::string temp_nameBook = line.substr(0, pos1);
            std::string temp_AuthorBook = line.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string temp_YearOfPublication = line.substr(pos2 + 1, pos3 - pos2 - 1);
            std::string temp_Reader_Name = line.substr(pos3 + 1, pos4 - pos3 - 1);
            int temp_Number_Bilet = std::stoi(line.substr(pos4 + 1, pos5 - pos4 - 1));
            std::string temp_date_of_issue = line.substr(pos5 + 1, pos6 - pos5 - 1);
            std::string temp_date_return = line.substr(pos6 + 1);

            Book temp_book(temp_nameBook, temp_AuthorBook, temp_YearOfPublication);
            Reader temp_reader(temp_Reader_Name, temp_Number_Bilet);

            Loan temp_loan(temp_book, temp_reader, temp_date_of_issue, temp_date_return);
            ln.push_back(temp_loan);
        }
    }
    return ln;
}