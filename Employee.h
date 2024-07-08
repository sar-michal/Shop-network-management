#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
//Employee data
class Employee: public Person{
    float salary;
     /*can't be lower than 0; only accepts values
       with decimal digits not lower than 0.01*/
public:
    Employee(string name, float salary=0);
     //constructor; salary=0 by default
    ~Employee();
     //destructor; checks validity, notifies user if not
    float getSalary() const;
     //returns salary
    void changeSalary(float newSalary);
     //changes salary
    int shopAmount();
    //returns the number of shops an employee is in
    void print();
     //prints employee data
};
#endif // EMPLOYEE_H
