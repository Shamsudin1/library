#include <iostream>
#include "Book.h"
#include "Reader.h"
#include "Libriary.h"

int main(){
    Book book1("Flowers", "Pushkin", "1964");
    Reader reader1("Alex", 101);
    std::cout << book1 << reader1;

    Libriary lib;
    Book book2("Brain", "Kornelli", "1999");
    Book book3("Gays", "Lincoln", "1895");
    Book book4("Kills", "Kenedi", "2001");
    lib.addBook(book2);
    lib.addBook(book3);
    lib.addBook(book4);
    lib.printAllBooks();
    lib.showBook(lib, "Brain");
    lib.showBook(lib, "sdsd");
}