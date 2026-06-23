#include "hospital.h"
#include <algorithm>
#include <numeric>

void Hospital::addPatient(Patient* p) {
    patients.push_back(p);
}

void Hospital::addStaff(StaffMember* s) {
    staff.push_back(s);
}

void Hospital::addWard(Ward* w) {
    wards.push_back(w);
}

void Hospital::addAppointment(const Appointment& a) {
    appointments.push_back(a);
}

std::vector<Patient*> Hospital::filterPatients(std::function<bool(Patient*)> func) {
    std::vector<Patient*> result;

    std::copy_if(patients.begin(), patients.end(), std::back_inserter(result), func);

    return result;
}

void Hospital::sortPatients(std::function<bool(Patient*, Patient*)> comp) {
    std::sort(patients.begin(), patients.end(), comp);
}

std::vector<StaffMember*> Hospital::filterStaff(std::function<bool(StaffMember*)> func) {
    std::vector<StaffMember*> result;

    std::copy_if(staff.begin(), staff.end(), std::back_inserter(result), func);

    return result;
}



double Hospital::wardRevenue(std::string wardName) {
    double total = 0.0;
    std::for_each(patients.begin(), patients.end(), [&](Patient* p) {
        if (p->isDischarged() && p->getWardName() == wardName)
            total += p->generateBill().total();
    });
    return total;
}

std::vector<Patient*> Hospital::patientsByStaff(std::string staffName) {
    std::vector<Patient*> result;

    std::copy_if(patients.begin(), patients.end(), std::back_inserter(result),
        [staffName](Patient* p) {
            return p->treatedBy(staffName);
        });

    return result;
}




void Hospital::discharge(int id) {
    auto it = std::find_if(patients.begin(), patients.end(),
        [id](Patient* p) {
            return p->getId() == id;
        });

    if (it != patients.end()) {
        (*it)->discharge();
    }
}

bool Hospital::isAdmitted(int id) {
    return std::any_of(patients.begin(), patients.end(),
        [id](Patient* p) {
            return p->getId() == id && !p->isDischarged();
        });
}

bool Hospital::isArchived(int id) {
    return std::any_of(patients.begin(), patients.end(),
        [id](Patient* p) {
            return p->getId() == id && p->isDischarged();
        });
}