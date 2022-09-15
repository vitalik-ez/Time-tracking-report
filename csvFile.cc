#include "csvFile.h"
#include "employee.h"
#include <filesystem>
#include <fstream>
#include <cstring>

CsvFile::CsvFile(const std::string &name)
{
    this->name = name;
}

void CsvFile::WriteData(std::string filename, std::vector<std::string> report)
{
    std::ofstream file(filename);
     if (!file.is_open())
    {
        std::cout << "File " << name << "could not be opened" << std::endl;
        exit(1);
    }
    for (size_t i = 0; i < report.size(); ++i)
    {
        file << report[i] << std::endl;
    }
    file.close();
}

void CsvFile::ReadData()
{   
    std::ifstream file(name);
    if (!file.is_open())
    {
        std::cout << "File " << name << "could not be opened" << std::endl;
        exit(1);
    }

    if (file.good())
    {
        std::string line;
        while (std::getline(file, line))
            lines.push_back(line);
    }
    else
    {
        std::cout << "Error reading file.";
    }
    file.close();
}

std::vector<std::string> CsvFile::getLines()
{
    return lines;
}

CsvFile::~CsvFile() {}