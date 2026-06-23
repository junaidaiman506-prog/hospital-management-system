#pragma once
#include <iostream>

class Bill {
private:
    double treatmentCost;
    double wardCost;
    double adminFee;

public:
    Bill(double tCost = 0, double wCost = 0, double admin = 500);

    double total() const;

    Bill operator+(const Bill& other) const;
    bool operator==(const Bill& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Bill& b);
};