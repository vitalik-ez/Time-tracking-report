#ifndef TIMETRACKING_H
#define TIMETRACKING_H

#include <map>
#include "csvFile.h"
#include "employee.h"

typedef std::map<std::string, std::map<std::string, int>> Report_t;

class TimeTracking
{
    int numberEmployees = 0;
    CsvFile *file;
    Employee **employees;
    Report_t report;

public:
    TimeTracking(const char *name);

    void createReport();
    void saveToFile(std::string fileName);
    void printReport();
    std::vector<std::string> convertReportToStrCSVFormat();

    ~TimeTracking();
};

#endif