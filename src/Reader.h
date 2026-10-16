#pragma once
#include <string>
#include <ostream>

class Reader{
private:
    std::string Reader_Name;
    int Number_Bilet;
public:
    Reader(std::string name, int number);
    std::string getReader_Name() const;
    int getNumber_Bilet() const;
};

std::ostream& operator<<(std::ostream& os, const Reader& r);