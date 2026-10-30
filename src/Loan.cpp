#include "Loan.h"
#include "Book.h"
#include "Reader.h"
#include <string>
#include <ostream>


Loan::Loan(const Book& b, const Reader& r, const std::string& d_of_is, const std::string& d_r) :
 book(b), reader(r), date_of_issue(d_of_is), date_return(d_r){}

Book Loan::getBook() const{return book;}
Reader Loan::getReader() const {return reader;}
std::string Loan::getDate_Of_Issue() const {return date_of_issue;}
std::string Loan::getDate_Return() const {return date_return;}

std::ostream& operator<<(std::ostream& os, const Loan& loan){
    os << "   Info about Loan:" << "\n"
    << loan.getBook() 
    << loan.getReader()
    << "Дата выдачи: " << loan.getDate_Of_Issue() << "\n"
    << "Дата возврата: " << loan.getDate_Return() << "\n";
    return os;
}