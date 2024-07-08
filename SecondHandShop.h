#ifndef SECOND_HAND_SHOP_H
#define SECOND_HAND_SHOP_H
#include <string>
#include <list>
using namespace std;
class Employee;
class Customer;
class Item;
//shop data

class SecondHandShop{
    string shopName;
     //Name used as identification; unique
    float money;
     //cannot be lower than 0 or contain decimal digits lower than 0.01;
    list<Employee*> employeeList;
     //list of pointers to Employee class
    list<Customer*> customerList;
     //list of pointers to Customer class
    list<Item*> inventory;
     //list of pointers to Item class
    Customer* findCustomer(int customerID);
     /*checks if customer is assigned to this shop; if yes
      - returns a pointer to customer; if not - returns nullptr*/
    Employee* findEmployee(int employeeID);
     /*checks if employee is assigned to this shop; if yes
      - returns a pointer to employee; if not - returns nullptr*/
    Item* findItem(int itemID);
     /*checks if item exists; if yes - returns a pointer to item;
      if not - returns nullptr*/
public:
    SecondHandShop(string shopName, float money);
     //constructor
    ~SecondHandShop();
     /*destructor; properly deallocates memory;*/
    string getShopName() const;
     //returns shopName
    float getMoney() const;
     //returns money
    void changeShopName(string newShopName);
     //changes the shop name
    void hireEmployee(Employee* emp);
     /*adds an employee to the list of employees;
      does nothing if Employee* is nullptr*/
    bool fireEmployee(int employeeID);
     /*removes an employee from the list of employees;
      returns 0 if employee isn't in the list, 1 if successful*/
    bool checkIfEmployeeAssigned(int employeeID);
    /*Checks if employee is assigned to the shop; return 1 if yes and 0 if not*/
    bool checkIfAnyEmployees();
     /*checks if any employees are hired by the shop; return 1 if yes and 0 if not*/
    bool paySalary();
     /*pays salary to every shop employee; if this operation would result
       in negative money balance it fails and returns 0; returns 1 if successful*/
    bool paySalary(int employeeID);
     /*pays salary to a specific employee; if this operation would result
       in negative money balance or employee isn't in the list it fails and returns 0;
       returns 1 if successful*/
    bool changeSalary(int employeeID, float newSalary);
     /*changes the salary for a specific employee; this method replaces the old salary
      with the new one; returns 0 if employee isn't in the list, 1 if successful*/
    void addCustomer(Customer* cust);
     /*adds a customer to the list of customers; does nothing if Customer* is nullptr*/
    bool removeCustomer(int customerID);
     /*removes a customer from the list of customers;
       returns 0 if customer isn't in the list, 1 if successful*/
    bool checkIfCustomerAssigned(int customerID);
     /*Checks if customer is assigned to the shop; return 1 if yes and 0 if not*/
    bool addItem(int itemID, string itemName, float price, int quantity);
     /*adds an item to the inventory; checks itemID if invalid returns 0;
       itemID is unique; Adding items with the same itemID and name results
       in the increase in quantity and change in price*/
    bool removeItem(int itemID, int quantity=1);
     /*quantity is 1 by default, can't remove more than the current number,
       if attempted fails and returns 0; if quantity reaches 0, item gets removed
       from the list; returns 1 if method was successful;*/
    float checkPrice(int itemID);
     /*returns the price of a specific item; returns 0 if item doesn't exist*/
    bool changePrice(int itemID, float newPrice);
     /*changes the price of an item; returns 0 if item doesn't exist, 1 if successful*/
    void changeMoney(float newMoney);
     //Changes the stored amount of money;
    bool updateMoney(float amount);
     /*Lowers or increases the amount of money based on the amount;
       if this operation would result in negative money balance it fails
       and returns 0; returns 1 if successful*/
    void printEmployeeList();
     //prints the list of employees
    void printCustomerList();
     //prints the list of customers
    void printInventory();
     //prints the inventory
    void printAll();
     //prints all data
};
#endif // SECOND_HAND_SHOP_H
