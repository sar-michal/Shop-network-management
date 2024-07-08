#include "Employee.h"

Employee::Employee(string name, float salary /*=0*/): Person(name)
{
    this->salary = salary;
}
//constructor; salary=0 by default
Employee::~Employee()
{
    for (list<SecondHandShop*>::iterator it=shopList.begin(); it!=shopList.end(); ++it)
    {
         (*it)->fireEmployee(getPersonID());
    }
}
//destructor; checks validity, notifies user if not
float Employee::getSalary() const
{
    return salary;
}
//returns salary
void Employee::changeSalary(float newSalary)
{
    salary = newSalary;
}
//changes salary
int Employee::shopAmount()
{
    return shopList.size();
}
//returns the number of shops an employee is in
void Employee::print()
{
    Person::print();
    cout<<" | salary: "<<salary<<endl;
}
//prints employee data
