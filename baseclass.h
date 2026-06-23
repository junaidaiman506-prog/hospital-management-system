#pragma once
#include <string>
using namespace std;

class people {
protected:
    string name;
    string dob;
    string cellno;
    int id;

public:
    people(string n, string d, string c, int i);

    virtual void display() = 0;
    virtual ~people() = default;

    string getName() const { return name; }
    int getId() const { return id; }
    string getDob() const { return dob; }
    string getCellNo() const { return cellno; }

    
};

