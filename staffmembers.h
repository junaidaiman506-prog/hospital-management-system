#pragma once
#include <string>
#include "baseclass.h"

class Ward;

class StaffMember : public people {
protected:
   


public:
    

    StaffMember(std::string n, int i);
    virtual ~StaffMember() = default;

    virtual void performDuty() = 0;

    std::string getName() const;
    int getId() const;
    virtual void display() = 0;

    virtual double calculateBillingRate() = 0;
};

class GeneralPractitioner : public StaffMember {
public:
    GeneralPractitioner(std::string n, int i);
    void performDuty() override;
    void display() override;
    double calculateBillingRate() override;
};

class Surgeon : public StaffMember {
private:
    std::string specialization;

public:
    Surgeon(std::string n, int i, std::string spec);
    void performDuty() override;
    void display() override;
    double calculateBillingRate() override;

};

class Nurse : public StaffMember {
private:
    Ward* assignedWard;

public:
    Nurse(std::string n, int i);

    void assignWard(Ward* w);
    void performDuty() override;
    void display() override;
    double calculateBillingRate() override;
};