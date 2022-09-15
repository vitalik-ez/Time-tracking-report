#include "date.h"
#include <ctime>
#include <sstream>

bool Date::extractDate(const std::string &str_date)
{
    std::istringstream is(str_date);
    char delimiter;
    if (is >> year >> delimiter >> month >> delimiter >> day)
    {
        struct tm t = {0};
        t.tm_mday = day;
        t.tm_mon = month - 1;
        t.tm_year = year - 1900;
        t.tm_isdst = -1;

        time_t when = mktime(&t);
        const struct tm *norm = localtime(&when);

        return (norm->tm_mday == day &&
                norm->tm_mon == month - 1 &&
                norm->tm_year == year - 1900);
    }
    std::cout << "Date must be in YYYY-MM-DD format." << std::endl;
    return false;
}


int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

std::string Date::getMonthYear() {
    std::string months[] = {"January", "February", "March", 
                            "April", "May", "June", "July", 
                            "August", "September", "October", 
                            "November", "December"};

    if (month < 1 || month > 12) return "Incorrect month number";

    return months[month-1] + " " + std::to_string(year);
}

