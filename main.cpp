#include <iostream>
#include <string>
#include <vector> // Include vector header for dynamic array usage
#include "Employee.h"

using namespace std;

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string theName, double theWage, double theHours, double theBonus)
        : Employee(theName, theWage, theHours), bonus(theBonus) {}

    double calcPay() const {
        return Employee::calcPay() + bonus;
    }
};

int main() {
    int numManagers;
    cout << "Enter number of managers: ";
    cin >> numManagers;

    vector<Manager*> managers; // Use vector for dynamic array

    for (int i = 0; i < numManagers; ++i) {
        string name;
        double wage, hours, bonus;

        cout << "Enter manager " << i << " name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter manager " << i << " hourly wage: ";
        cin >> wage;

        cout << "Enter manager " << i << " hours worked: ";
        cin >> hours;

        cout << "Enter manager " << i << " bonus: ";
        cin >> bonus;

        managers.push_back(new Manager(name, wage, hours, bonus)); // Add Manager pointer to vector
    }

    double highestPay = 0.0;
    Manager* highestPaidManager = nullptr;
    double totalPay = 0.0;

    for (int i = 0; i < numManagers; ++i) {
        double pay = managers[i]->calcPay();
        totalPay += pay;

        if (pay > highestPay) {
            highestPay = pay;
            highestPaidManager = managers[i];
        }
    }

    cout << "Highest paid manager is " << highestPaidManager->getName() << " who is paid $" << highestPay << endl;
    cout << "Average pay is $" << (totalPay / numManagers) << endl;

    // Deallocate dynamically allocated memory
    for (int i = 0; i < numManagers; ++i) {
        delete managers[i];
    }

    return 0;
}
