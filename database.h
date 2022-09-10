#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include "idatabase.h"

class CsvFile : public IDatabase {
    private:
        std::fstream file;
        std::string name;
    public:
        CsvFile(const std::string &name);
        void Open() override;
        void WriteData() override;
        void ReadData() override;
        void Close() override;

        void WriteColumn();
        bool IsEmpty();
        virtual ~CsvFile();
};

#endif