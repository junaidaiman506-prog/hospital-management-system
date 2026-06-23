#pragma once
#include <vector>
#include <functional>
#include "patient.h"
#include "staffmembers.h"
#include "ward.h"
#include "appointment.h"

class Hospital {
private:
    std::vector<Patient*> patients;
    std::vector<StaffMember*> staff;
    std::vector<Ward*> wards;
    std::vector<Appointment> appointments;

public:
    void addPatient(Patient* p);
    void addStaff(StaffMember* s);
    void addWard(Ward* w);
    void addAppointment(const Appointment& a);

    std::vector<Patient*> filterPatients(std::function<bool(Patient*)> func);

    void sortPatients(std::function<bool(Patient*, Patient*)> comp);

    std::vector<StaffMember*> filterStaff(std::function<bool(StaffMember*)> func);

    double wardRevenue(std::string wardName);

    std::vector<Patient*> patientsByStaff(std::string staffName);

    void discharge(int id);
bool isAdmitted(int id);
bool isArchived(int id);
};