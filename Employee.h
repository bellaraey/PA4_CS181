#ifndef EMPLOYEE_H 
#define EMPLOYEE_H 
class Employee 
{ 
protected: 
string name; 
double wage; 
double hours; 
public: 
// Create a new employee 
Employee (string theName, double theWage, double theHours); 
// Calculate the employee’s pay. 
double calcPay() const; 
string getName () const; 
}; 
#endif // EMPLOYEE_H 
