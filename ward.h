#pragma once
#include <string>
#include <vector>

class Patient;

class Ward {
protected:
    std::string name;
    int capacity;
    std::vector<Patient*> residents;
     

public:
    Ward(std::string n, int cap);
    virtual ~Ward();

    virtual bool admit(Patient* p) = 0;
    virtual double getDailyRate() const = 0;

    std::string getName() const;
    double occupancy() const;

    bool operator<(const Ward& other) const;
    bool operator>(const Ward& other) const;
};

//derived wards 
class GeneralWard : public Ward {
public:
    GeneralWard(std::string n, int cap);

    bool admit(Patient* p) override;
    double getDailyRate() const override;
};

class ICU : public Ward {
public:
    ICU(std::string n, int cap);

    bool admit(Patient* p) override;
    double getDailyRate() const override;
};

class SurgicalWard : public Ward {
public:
    SurgicalWard(std::string n, int cap);

    bool admit(Patient* p) override;
    double getDailyRate() const override;
};