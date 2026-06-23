#pragma once
#include <string>

class Patient;
class StaffMember;

class Appointment {
private:
    Patient* patient;
    StaffMember* doctor;
    std::string date;
    std::string time;

public:
    Appointment(Patient* p, StaffMember* d, std::string dt, std::string tm);

    void display() const;

    Patient* getPatient() const;
    StaffMember* getDoctor() const;

    std::string getDate() const;
std::string getTime() const;
};