#include <iostream>
#include "Book.h"
#include "Reader.h"

int main(){
    Book book1("Flowers", "Pushkin", "1964");
    Reader reader1("Alex", 101);
    std::cout << book1 << reader1;
    
}