#include "appointment.h"
#include "patient.h"
#include "staffmembers.h"
#include <iostream>

using namespace std;

Appointment::Appointment(Patient* p, StaffMember* d, string dt, string tm) {
    patient = p;
    doctor = d;
    date = dt;
    time = tm;
}

void Appointment::display() const {
    cout << "Appointment Details:\n";
    cout << "Patient: " << patient->getName() << endl;
    cout << "Doctor: " << doctor->getName() << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
}

Patient* Appointment::getPatient() const {
    return patient;
}

StaffMember* Appointment::getDoctor() const {
    return doctor;
}



std::string Appointment::getDate() const {
    return date;
}

std::string Appointment::getTime() const {
    return time;
}