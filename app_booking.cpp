#include "app_booking.h"
#include <algorithm>

bool AppointmentBook::addAppointment(const Appointment& a) {

    auto it = std::find_if(appointments.begin(), appointments.end(),
        [&a](const Appointment& existing) {
            return existing.getDoctor() == a.getDoctor() &&
                   existing.getDate() == a.getDate() &&
                   existing.getTime() == a.getTime();
        });

    if (it != appointments.end()) {
        return false;
    }

    appointments.push_back(a);
    return true;
}


void AppointmentBook::cancelAppointment(Patient* p, std::string date, std::string time) {

    appointments.erase(
        std::remove_if(appointments.begin(), appointments.end(),
            [p, date, time](const Appointment& a) {
                return a.getPatient() == p &&
                       a.getDate() == date &&
                       a.getTime() == time;
            }),
        appointments.end()
    );
}


std::vector<Appointment> AppointmentBook::getByStaff(StaffMember* s, std::string date) {
    std::vector<Appointment> result;

    std::copy_if(appointments.begin(), appointments.end(), std::back_inserter(result),
        [s, date](const Appointment& a) {
            return a.getDoctor() == s && a.getDate() == date;
        });

    return result;
}


std::vector<Appointment> AppointmentBook::getByPatient(Patient* p) {
    std::vector<Appointment> result;

    std::copy_if(appointments.begin(), appointments.end(), std::back_inserter(result),
        [p](const Appointment& a) {
            return a.getPatient() == p;
        });

    return result;
}