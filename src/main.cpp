#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <fstream>
#include "Book.h"
#include "Reader.h"
#include "Libriary.h"
#include "Loan.h"
#include "Storage.h"

int main(){
    Libriary lib;
    Storage storage("Books.txt", "Loans.txt");

    for(const Book& b : storage.loadBooks() ){
        lib.addBook(b);
    }
    for(const Loan& l : storage.loadLoans() ){
        lib.addLoan(l);
    }

    std::cout << "Выберите один из пунктов: \n";
    std::cout << "1. Добавить книгу\n";
    std::cout << "2. Показать все книги\n";
    std::cout << "3. Найти книгу по названию\n";
    std::cout << "4. Выдать книгу\n";
    std::cout << "5. Возврат книги\n";
    std::cout << "6. Удалить книгу из библиотеки\n";
    std::cout << "7. Показать все выдачи\n";
    std::cout << "0. Выход\n";

    int a;
    do{
        std::cout << "Напишите номер пункта и нажмите return: ";
        std::cin >> a;
        if(!std::cin.good()){
            break;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        
        if(a == 1){
            std::string temp_nameBook;
            std::string temp_AuthorBook;
            std::string temp_YearOfPublication;

            std::cout << "Напишите название книги: ";
            std::getline(std::cin, temp_nameBook);
            std::cout << "Напишите автора книги: ";
            std::getline(std::cin, temp_AuthorBook);
            std::cout << "Напишите год публикации книги: ";
            std::getline(std::cin, temp_YearOfPublication);
            Book temp_book(temp_nameBook, temp_AuthorBook, temp_YearOfPublication);
            bool success = lib.addBook(temp_book);
            if(success){
                std::cout << "Книга добавлена в библиотеку!\n";
            }
            else{
                std::cerr << "Книга уже есть в библиотеке!\n";
            }
            storage.saveBooks(lib.getBooks());
        }
        else if(a == 2){
            lib.printAllBooks();
        }
        else if(a == 3){
            std::string temp_name;
            std::cout << "Введите название книги для поиска в библиотеке: ";
            std::getline(std::cin, temp_name);
            lib.printBookByName(temp_name);
        }
        else if(a == 4){
            std::string temp_name;
            std::cout << "Напишите название книги которую нужно выдать: ";
            std::getline(std::cin, temp_name);
            auto found = lib.FindBookByName(temp_name);
            if(found.has_value()){
                std::string temp_nameReader;
                int temp_NumberBilet;
                std::cout << "Напишите имя читателя: ";
                std::getline(std::cin, temp_nameReader);
                std::cout << "Напишите номер билета: ";
                std::cin >> temp_NumberBilet;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                Reader reader(temp_nameReader, temp_NumberBilet);
                std::string temp_date_of_issue;
                std::string temp_date_return;
                std::cout << "Напишите дату выдачи: ";
                std::getline(std::cin, temp_date_of_issue);
                std::cout << "Напишите дату возврата: ";
                std::getline(std::cin, temp_date_return);
                Loan loan(*found, reader, temp_date_of_issue, temp_date_return);
                bool success = lib.addLoan(loan);
                if(success){
                    std::cout << "Книга успешно выдана!\n"; 
                }
                else{std::cerr << "Книга уже была выдана другому человеку!\n";}
                storage.saveLoans(lib.getLoans());
            }
            else{std::cout << "Книга не найдена!\n";}
        }
        else if(a == 5){
            std::string n;
            std::cout << "Напишите название книги которое хотите вернуть: ";
            std::getline(std::cin, n);
            bool success = lib.returnBook(n);
            if(success){std::cout << "Книга успешно возвращена!\n";}
            else{std::cerr << "Книга не найдена!\n";}
            storage.saveLoans(lib.getLoans());
        }
        else if(a == 6){
            std::string n;
            std::cout << "Напишите название книги которое хотите удалить: ";
            std::getline(std::cin, n);
            bool success = lib.removeBook(n);
            if(success){std::cout << "Книга успешно удалена!\n";}
            else{std::cerr << "Книга не найдена!\n";}
            lib.returnBook(n);
            storage.saveBooks(lib.getBooks());
            storage.saveLoans(lib.getLoans());
        }
        else if(a == 7){
            lib.printAllLoans();
        }

    }while(a != 0);

   
} 