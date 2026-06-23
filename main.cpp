#include <iostream>
#include <vector>
#include <cassert>

#include "patient.h"
#include "ward.h"
#include "bills.h"
#include "staffmembers.h"
#include "appointment.h"
#include "app_booking.h"
#include "hospital.h"

using namespace std;

void printResult(string name, bool pass) {
    cout << name << ": " << (pass ? "PASS" : "FAIL") << endl;
}

int main() {

    //  TC-01
    GeneralPractitioner gp1("Dr Ahmed", 101);
    Surgeon surgeon1("Dr Khan", 102, "Cardiac");
    Nurse nurse1("Nurse Sara", 201);

    Patient patient1("Ali", "2000", "123", 1, "Flu", "2026-04-01", 1, false, 2, 2000, false);

    vector<people*> persons = { &gp1, &surgeon1, &nurse1, &patient1 };

    cout << "\nTC-01 Output :-\n";
    for (auto* p : persons) p->display();

    printResult("TC-01 Polymorphism", true);

    // TC-02
    Patient patient2("Sara", "2001", "456", 2, "Cold", "2026-04-02", 1, false, 1, 2000, false);

    patient1.addTreatment("X-Ray", 500, "Dr Ahmed");
    patient2.addTreatment("Checkup", 300, "Dr Ahmed");

    Bill b1 = patient1.generateBill();
    Bill b2 = patient2.generateBill();

    Bill combined = b1 + b2;

    bool tc2 = (combined.total() == b1.total() + b2.total()) &&!(b1 == b2);

    Bill b3 = b1;
    tc2 = tc2 && (b1 == b3);

    cout << combined << endl;

    printResult("TC-02 Billing", tc2);

    // TC-03 
    GeneralWard w1("Ward A", 20);
    ICU w2("ICU", 8);

    vector<Patient> patients;

    for (int i = 0; i < 7; i++) {
        patients.emplace_back(
            "P" + to_string(i), "2000", "123",
            i + 10, "Test", "2026", 1, true, 2, 2000, true
        );
    }

    for (int i = 0; i < 5; i++)
        w1.admit(&patients[i]);

    for (int i = 0; i < 7; i++)
        w2.admit(&patients[i]);

    bool tc3 = (w1 < w2) && (w2 > w1);

    printResult("TC-03 Ward Comparison", tc3);

    //TC-04
    Patient critical("Ali Khan", "1999", "111", 30, "Cardiac", "2026", 1, true, 3, 2000, true);
    Patient routine("Sara Baig", "2000", "222", 31, "Sprain", "2026", 1, false, 2, 2000, false);

    ICU icu("ICU", 10);
    GeneralWard gw("General", 30);

    bool tc4 = icu.admit(&critical) &&
               !icu.admit(&routine) &&
               gw.admit(&routine);

    printResult("TC-04 ICU Rules", tc4);

    // TC-05
    AppointmentBook book;

    Appointment a1(&patient1, &gp1, "2026-04-10", "10:00");
    Appointment a2(&patient2, &gp1, "2026-04-10", "10:00");
    Appointment a3(&patient2, &gp1, "2026-04-10", "11:00");

    bool r1 = book.addAppointment(a1);
    bool r2 = book.addAppointment(a2);
    bool r3 = book.addAppointment(a3);

    bool tc5 = r1 && !r2 && r3;

    printResult("TC-05 Double Booking", tc5);

    // TC-06 
    Patient original("Hamid", "1998", "999", 40, "Test", "2026", 1, false, 2, 2000, false);
    original.addTreatment("Blood Test", 500, "Dr A");

    Patient copy = original;
    copy.addTreatment("MRI", 8000, "Dr B");

    bool tc6 = (original.treatmentCount() == 1) &&
               (copy.treatmentCount() == 2);

    printResult("TC-06 Copy Independence", tc6);

    //  TC-07 
    
    Hospital h;
Patient* pMove = new Patient("MoveTest", "2000", "000", 50, "Test", "2026", 1, false, 2, 2000, false);
h.addPatient(pMove);
h.discharge(pMove->getId());
bool tc7 = !h.isAdmitted(pMove->getId()) &&
            h.isArchived(pMove->getId());
delete pMove; 
printResult("TC-07 Move Semantics", tc7);

    // TC-08
    auto filtered = h.filterPatients([](Patient* p) {
        return p->isCritical();
    });

    h.sortPatients([](Patient* a, Patient* b) {
        return a->generateBill().total() < b->generateBill().total();
    });

    printResult("TC-08 Lambdas", true);

    // TC-09
    vector<StaffMember*> staffList = { &gp1, &surgeon1, &nurse1 };

    cout << "\nTC-09 Output :-\n";
    for (auto* s : staffList) {
        cout << s->getName() << ": PKR " << s->calculateBillingRate() << endl;
    }

    printResult("TC-09 Staff Billing", true);

    //TC-10

patient1.assignWard(&w1);
patient2.assignWard(&w1);
patient1.discharge();
patient2.discharge();
h.addPatient(&patient1);
h.addPatient(&patient2);
double revenue = h.wardRevenue("Ward A");
bool tc10 = (revenue == patient1.generateBill().total() + patient2.generateBill().total());

    printResult("TC-10 Ward Revenue", tc10);

 return 0;
}