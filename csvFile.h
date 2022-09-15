#ifndef CSVFile_H
#define CSVFile_H

#include <iostream>
#include <fstream>
#include <vector>

class CsvFile
{
private:
    std::string name;
    std::vector<std::string> lines;

public:
    CsvFile(const std::string &name);
    void WriteData(std::string filename, std::vector<std::string> report);
    void ReadData();
    void Close();

    std::vector<std::string> getLines();
    ~CsvFile();
};

#endif