#include "ward.h"
#include "patient.h"

Ward::Ward(std::string n, int cap) {
    name = n;
    capacity = cap;
   
}

Ward::~Ward() {}


std::string Ward::getName() const {
    return name;
}

double Ward::occupancy() const {
    if (capacity == 0) return 0;
    return (double)(int)residents.size() / capacity;
}

bool Ward::operator<(const Ward& other) const {
    return occupancy() < other.occupancy();
}


bool Ward::operator>(const Ward& other) const {
    return occupancy() > other.occupancy();
}


GeneralWard::GeneralWard(std::string n, int cap)
    : Ward(n, cap) {}

bool GeneralWard::admit(Patient* p) {
    if ( (int)residents.size() < capacity) {
        residents.push_back(p);
        return true;
    }
    return false;
}

double GeneralWard::getDailyRate() const {
    return 2000.0;
}


ICU::ICU(std::string n, int cap)
    : Ward(n, cap) {}

bool ICU::admit(Patient* p) {
    if ((int)residents.size() < capacity && p->isCritical()) {
        residents.push_back(p);
        return true;
    }
    return false;
}

double ICU::getDailyRate() const {
    return 10000.0;
}


SurgicalWard::SurgicalWard(std::string n, int cap)
    : Ward(n, cap) {}

bool SurgicalWard::admit(Patient* p) {
    if ((int)residents.size() < capacity && p->hasScheduledOperation()) {
        residents.push_back(p);
        return true;
    }
    return false;
}

double SurgicalWard::getDailyRate() const {
    return 5000.0;
}

