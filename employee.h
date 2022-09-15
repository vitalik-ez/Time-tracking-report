#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "date.h"
#include <vector>

class Employee
{
private:
    std::string name;
    std::string email;
    std::string department;
    std::string position;
    std::string project;
    std::string task;
    Date *date;
    int loggedHours;

public:
    Employee();
    void initDate(const std::string &strDate);

    std::string getName();
    std::string getEmail();
    std::string getDepartment();
    std::string getPosition();
    std::string getProject();
    std::string getTask();
    Date *getDate();
    int getLoggedHours();

    void setName(std::string name);
    void setEmail(std::string email);
    void setDepartment(std::string department);
    void setPosition(std::string position);
    void setProject(std::string project);
    void setTask(std::string task);
    void setDate(Date *date);
    void setLoggedHours(int loggedHours);
    
    ~Employee();

    static void parsing(Employee **employees, std::vector<std::string> lines);
    
};


#endif