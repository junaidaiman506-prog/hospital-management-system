#include "patient.h"
#include "bills.h"
#include <iostream>
#include <utility>
#include "ward.h"

using namespace std;

Patient::Patient(string n, string d, string c, int i, string diag, string admit, int ward, bool crit, int days, double rate, bool op)
    : people(n, d, c, i)
{
    diagnoses = diag;
    admit_date = admit;
    ward_no = ward;
    critical_patient = crit;
    discharged = false;

    daysAdmitted = days;
    wardRate = rate;
    assignedWard = nullptr;
    hasOperation = op;
}


void Patient::addTreatment(string t_name, double t_cost, string staff) {
    treatments.push_back({t_name, t_cost, staff});
}


void Patient::discharge() {
    discharged = true;
}

Bill Patient::generateBill() const {
    double tCost = 0;

    for (const auto& t : treatments)
        tCost += t.cost;

    double wCost = 0;
    if (assignedWard != nullptr)
        wCost = daysAdmitted * assignedWard->getDailyRate();

    return Bill(tCost, wCost, 500);
}


void Patient::display() {
    cout << "Patient ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Diagnosis: " << diagnoses << endl;
    cout << "Admission Date: " << admit_date << endl;
    cout << "Ward No: " << ward_no << endl;
    cout << "Critical: " << (critical_patient ? "Yes" : "No") << endl;
    cout << "Discharged: " << (discharged ? "Yes" : "No") << endl;

    cout << generateBill();
}


Patient::Patient(const Patient& other) : people(other) {
    diagnoses = other.diagnoses;
    admit_date = other.admit_date;
    ward_no = other.ward_no;
    treatments = other.treatments;
    discharged = other.discharged;
    critical_patient = other.critical_patient;
    daysAdmitted = other.daysAdmitted;
    wardRate = other.wardRate;
    assignedWard = other.assignedWard;
}


Patient::Patient(Patient&& other) noexcept : people(std::move(other)) {
    diagnoses = std::move(other.diagnoses);
    admit_date = std::move(other.admit_date);
    ward_no = other.ward_no;
    treatments = std::move(other.treatments);
    discharged = other.discharged;
    critical_patient = other.critical_patient;

    daysAdmitted = other.daysAdmitted;
    wardRate = other.wardRate;
    assignedWard = other.assignedWard;
    hasOperation = other.hasOperation;

    other.ward_no = 0;
    other.discharged = false;
    other.critical_patient = false;
    other.daysAdmitted = 0;
    other.wardRate = 0;
    other.assignedWard = nullptr;
    other.hasOperation = false;
}


bool Patient::treatedBy(std::string staffName) const {
    for (const auto& t : treatments) {
        if (t.staff_member == staffName)
            return true;
    }
    return false;
}



bool Patient::isCritical() const {
    return critical_patient;
}

int Patient::treatmentCount() const {
    return treatments.size();
}


void Patient::assignWard(Ward* w) {
    assignedWard = w;
}

std::string Patient::getName() const { return name; }
bool Patient::isDischarged() const { return discharged; }
std::string Patient::getDiagnosis() const { return diagnoses; }
std::string Patient::getWardName() const { return assignedWard ? assignedWard->getName() : ""; }
int Patient::getWardNo() const { return ward_no; }


bool Patient::hasScheduledOperation() const {
    return hasOperation;
}

int Patient::getId() const {
    return id;
}

