#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "baseclass.h"
#include "bills.h"

class Ward;

class Patient : public people {
private:
    std::string diagnoses;
    std::string admit_date;
    int ward_no;
    bool critical_patient;
    bool discharged;
    int daysAdmitted;
    double wardRate;

    bool hasOperation;

    Ward* assignedWard;

    struct treatment {
        std::string name;
        double cost;
        std::string staff_member;
    };

    std::vector<treatment> treatments;

public:
    Patient(std::string n, std::string d, std::string c, int i,
            std::string diag, std::string admit, int ward, bool crit,
            int days, double rate, bool op);

    void addTreatment(std::string t_name, double t_cost, std::string staff);
    void discharge();
    Bill generateBill() const;
    void display() override;

    Patient(const Patient& other);
    Patient(Patient&& other) noexcept;

    bool isCritical() const;
    int treatmentCount() const;

    

    void assignWard(Ward* w); 

    int getWardNo() const;
std::string getWardName() const;
std::string getDiagnosis() const;
bool isDischarged() const;
std::string getName() const;
bool treatedBy(std::string staffName) const;

bool hasScheduledOperation() const;


int getId() const;




};