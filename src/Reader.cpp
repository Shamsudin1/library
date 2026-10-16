#include <iostream>
#include "Reader.h"
#include <ostream>
#include <string>

Reader::Reader(std::string name, int number) : Reader_Name(name), Number_Bilet(number){}
std::string Reader::getReader_Name() const {return Reader_Name;}
int Reader::getNumber_Bilet() const {return Number_Bilet;}

std::ostream& operator<<(std::ostream& os, const Reader& r){
    os << "    ReaderInfo" << "\n"
    << "Reader_Name: " << r.getReader_Name() << "\n"
    << "Number_Bilet: " << r.getNumber_Bilet() << "\n";
    return os;
}