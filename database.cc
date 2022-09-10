#include "database.h"
#include <filesystem>


CsvFile::CsvFile(const std::string &name) {
    this->name = name;
}

void CsvFile::Open() {
    
    file.open(name.c_str(), std::ios::app);
    if (! file.is_open()) {
        std::cout << "File " << name << "could not be opened" << std::endl;
        exit(1);
    }
    if (IsEmpty()) {
        std::cout << "File " << name << " is empty" << std::endl;
        WriteColumn();
    }
    
}

void CsvFile::WriteData() {
    std::cout << "WriteData " << std::endl;
}

void CsvFile::ReadData() {
    std::cout << "ReadData " << std::endl;
}

void CsvFile::Close() {
    std::cout << "Close " << std::endl;
    file.close();
}


void CsvFile::WriteColumn() {
    const std::string columns[]{"Name", "email", "department", "position", 
                         "project", "task", "date", "logged hours"};
    size_t length = sizeof(columns) / sizeof(columns[0]);
    for (size_t i = 0; i < length; ++i)
    {   
        file << columns[i];
        if (i < length - 1) file << ";";

    }
    

    std::cout << "WriteColumn " << std::endl;
}


bool CsvFile::IsEmpty(){
    return std::filesystem::is_empty(name);
    //return file.peek() == std::ifstream::traits_type::eof();
}


CsvFile::~CsvFile(){
    std::cout << "destructor" << std::endl;
    Close();
    //return file.peek() == std::ifstream::traits_type::eof();
}