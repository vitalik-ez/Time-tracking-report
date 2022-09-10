#include <iostream>
#include <fstream>
#include "database.h"
//using namespace std;

class TimeTracking{
    private:
        std::string name;
        CsvFile *   file;
    public:

        TimeTracking(const std::string &name) {
            this->name = name;
            file = new CsvFile(name);
        }

};



int main() {

    const char *name = "database.csv";
    IDatabase *db = new CsvFile(name);
    db->Open();


    /*
    cout << "" << endl;

    
    std::ifstream file("filename");

    if (!file) {
        // file is not open
    }

    if (is_empty(file)) {
        // file is empty
    }

    // file is open and not empty
    */

    delete db;

    return 0;
}