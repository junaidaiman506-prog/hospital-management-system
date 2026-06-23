#include "staffmembers.h"
#include "ward.h"
#include "baseclass.h"
#include <iostream>

using namespace std;



StaffMember::StaffMember(string n, int i) : people(n, "N/A", "N/A", i)
{
}


string StaffMember::getName() const {
    return people::name;
}

int StaffMember::getId() const {
    return people::id;
}


GeneralPractitioner::GeneralPractitioner(string n, int i): StaffMember(n, i) {}

void GeneralPractitioner::performDuty() {
    cout << getName() << " is consulting patients and writing prescriptions.\n";
}

double GeneralPractitioner::calculateBillingRate() {
    return 1000;
}

void GeneralPractitioner::display() {
    


cout << "General Practitioner: " << getName() << " (ID: " << getId() << ")\n";}


Surgeon::Surgeon(string n, int i, string spec): StaffMember(n, i) {
    specialization = spec;
}

void Surgeon::performDuty() {
    cout << getName() << " is performing " << specialization << " surgery.\n";
}

double Surgeon::calculateBillingRate() {
    return 5000;
}

void Surgeon::display() {
    cout << "Surgeon: " << getName() << " (ID: " << getId() << "), Specialization: " << specialization << "\n";
}

Nurse::Nurse(string n, int i)
    : StaffMember(n, i) {
    assignedWard = nullptr;
}

void Nurse::assignWard(Ward* w) {
    assignedWard = w;
}

void Nurse::performDuty() {
    if (assignedWard)
        cout << getName() << " is taking care of patients in ward "
             << assignedWard->getName() << ".\n";
    else
        cout << getName() << " is not assigned to any ward.\n";
}

double Nurse::calculateBillingRate() {
    return 500;
}

void Nurse::display() {
    cout << "Nurse: " << getName() << " (ID: " << getId() << ")";
    
    if (assignedWard)
        cout << ", Assigned Ward: " << assignedWard->getName();
    cout << "\n";
}