#pragma once
#include <vector>
#include "appointment.h"

class AppointmentBook {
private:
    std::vector<Appointment> appointments;

public:
    bool addAppointment(const Appointment& a);
    void cancelAppointment(Patient* p, std::string date, std::string time);

    std::vector<Appointment> getByStaff(StaffMember* s, std::string date);
    std::vector<Appointment> getByPatient(Patient* p);
};