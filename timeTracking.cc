#include <iostream>
#include "timeTracking.h"

TimeTracking::TimeTracking(const char *name)
{
    file = new CsvFile(name);
    file->ReadData();
    std::vector<std::string> lines = file->getLines();

    numberEmployees = lines.size() - 1;
    employees = new Employee *[numberEmployees];
    Employee::parsing(employees, lines);
}

void TimeTracking::createReport()
{
    Report_t::iterator itr;

    for (int i = 0; i < numberEmployees; i++)
    {
        itr = report.find(employees[i]->getName());
        if (itr != report.end())
        {
            auto innerIt = itr->second.find(employees[i]->getDate()->getMonthYear());
            if (innerIt != itr->second.end())
            {
                innerIt->second += employees[i]->getLoggedHours();
            }
            else
            {
                std::pair<std::string, int> info;
                info.first = employees[i]->getDate()->getMonthYear();
                info.second = employees[i]->getLoggedHours();
                report[itr->first].insert(info);
            }
            continue;
        }

        std::pair<std::string, int> info;
        info.first = employees[i]->getDate()->getMonthYear();
        info.second = employees[i]->getLoggedHours();

        std::pair<std::string, std::map<std::string, int>> employee;
        employee.first = employees[i]->getName();
        employee.second.insert(info);
        report.insert(employee);
    }
}

void TimeTracking::saveToFile(std::string fileName)
{
    file->WriteData(fileName, convertReportToStrCSVFormat());
}

void TimeTracking::printReport()
{
    std::vector<std::string> strReport = convertReportToStrCSVFormat();
    std::cout << "=====REPORT=====" << std::endl;
    for (const auto &employee : strReport)
    {
        std::cout << employee << std::endl;
    }
}

std::vector<std::string> TimeTracking::convertReportToStrCSVFormat()
{
    std::vector<std::string> strReport;
    strReport.push_back("Name;Month;Total hours");
    for (const auto &[name, value] : report)
    {
        for (const auto &[date, loggedHours] : value)
        {
            strReport.push_back(name + ";" + date + ";" + std::to_string(loggedHours));
        }
    }
    return strReport;
}

TimeTracking::~TimeTracking()
{
    for (int i = 0; i < numberEmployees; i++)
    {
        delete employees[i];
    }
    delete file;
}