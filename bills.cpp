#include "bills.h"
#include <cmath>

Bill::Bill(double tCost, double wCost, double admin) {
    treatmentCost = tCost;
    wardCost = wCost;
    adminFee = admin;
}

double Bill::total() const {
    return treatmentCost + wardCost + adminFee;
}




Bill Bill::operator+(const Bill& other) const {
    return Bill(
        treatmentCost + other.treatmentCost,wardCost + other.wardCost,adminFee + other.adminFee
    );
}

bool Bill::operator==(const Bill& other) const {
    return std::abs(total() - other.total()) < 0.001;
}

std::ostream& operator<<(std::ostream& out, const Bill& b) {
    out << "Bill Summary :-\n";
    out << "Treatment Cost: PKR " << b.treatmentCost << "\n";
    out << "Ward Cost: PKR " << b.wardCost << "\n";
    out << "Admin Fee: PKR " << b.adminFee << "\n";
    out << "---------------------------------------------------------\n";
    out << "Total: PKR " << b.total() << "\n";
    return out;
}