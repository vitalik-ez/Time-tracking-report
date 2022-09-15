#include <sstream>
#include <memory>
#include "employee.h"

Employee::Employee()
{
    date = nullptr;
    loggedHours = 0;
}

void Employee::initDate(const std::string &strDate)
{
    date = new Date;
    date->extractDate(strDate);
}

std::string Employee::getName()
{
    return name;
}

std::string Employee::getEmail()
{
    return email;
}

std::string Employee::getDepartment()
{
    return department;
}

std::string Employee::getPosition()
{
    return position;
}

std::string Employee::getProject()
{
    return project;
}

std::string Employee::getTask()
{
    return task;
}

Date *Employee::getDate()
{
    return date;
}

int Employee::getLoggedHours()
{
    return loggedHours;
}

void Employee::setName(std::string name)
{
    this->name = name;
}

void Employee::setEmail(std::string email)
{
    this->email = email;
}

void Employee::setDepartment(std::string department)
{
    this->department = department;
}

void Employee::setPosition(std::string position)
{
    this->position = position;
}

void Employee::setProject(std::string project)
{
    this->project = project;
}

void Employee::setTask(std::string task)
{
    this->task = task;
}

void Employee::setDate(Date *date)
{
    this->date = date;
}

void Employee::setLoggedHours(int loggedHours)
{
    this->loggedHours = loggedHours;
}

Employee::~Employee()
{
    delete date;
}

enum EmployeesField
{
    NAME,
    EMAIL,
    DEPARTMENT,
    POSITION,
    PROJECT,
    TASK,
    DATE,
    LOGGEDHOURS
};

void Employee::parsing(Employee **employees, std::vector<std::string> lines)
{
    int count = 0;
    for (std::vector<std::string>::iterator i = lines.begin() + 1; i != lines.end(); ++i)
    {
        Employee *tmp = new Employee;
        std::stringstream ss;
        ss << *i;
        std::string data;
        int index = EmployeesField::NAME;

        while (std::getline(ss, data, ';') && index != EmployeesField::LOGGEDHOURS + 1)
        {
            switch (index)
            {
            case EmployeesField::NAME:
                tmp->setName(data);
                break;
            case EmployeesField::EMAIL:
                tmp->setEmail(data);
                break;
            case EmployeesField::DEPARTMENT:
                tmp->setDepartment(data);
                break;
            case EmployeesField::POSITION:
                tmp->setPosition(data);
                break;
            case EmployeesField::PROJECT:
                tmp->setProject(data);
                break;
            case EmployeesField::TASK:
                tmp->setTask(data);
                break;
            case EmployeesField::DATE:
                tmp->initDate(data);
                break;
            case EmployeesField::LOGGEDHOURS:
                tmp->setLoggedHours(std::stoi(data));
                break;
            default:
                std::cout << "DEFAULT "
                          << "\n";
                break;
            }
            index++;
        }
        employees[count] = tmp;
        count++;
    }
}