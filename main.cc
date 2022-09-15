#include <iostream>
#include "timeTracking.h"

int main() {

    const char *name = "database.csv";
    TimeTracking tt(name);
    tt.createReport();
    tt.saveToFile("report.csv");
    tt.printReport();

    return 0;
}