#include <string> 
#include <cstdlib> 
using namespace std; 
#include "Employee.h" 
Employee::Employee (string theName, double theWage, double theHours) 
{ 
name = theName; 
wage = theWage; 
hours = theHours; 
} 
double Employee::calcPay() const 
{ 
return wage * hours; 
} 
string Employee::getName () const 
{ 
return name; 
}
