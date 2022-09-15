#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date
{
    int day;
    int month;
    int year;

public:

    bool extractDate(const std::string &str_date);

    int getDay();
    int getMonth();
    int getYear();

    std::string getMonthYear();


};

#endif