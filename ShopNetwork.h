#ifndef SHOP_NETWORK_H
#define SHOP_NETWORK_H
#include <string>
#include <list>
class Employee;
class Customer;
class SecondHandShop;
using namespace std;
// the general class; responsible for the interaction with user
class ShopNetwork{
    int maximumShopsForEmployee;
    list<Employee*> employeeList;
     /*list of pointers to Employee class; unlimited list
       of all Employees in the network*/
    list<Customer*> customerList;
     /*list of pointers to Customer class; unlimited list
       of all Customers in the network*/
    list<SecondHandShop*> shopList;
     /*list of pointers to SecondHandShop class; unlimited list
       of all Shops in the network*/
    Customer* findCustomer(int customerID);
     /*checks if customer exists; if yes - returns a pointer to customer;
       if not - returns nullptr*/
    Employee* findEmployee(int employeeID);
     /*checks if employee exists; if yes - returns a pointer to employee;
      if not - returns nullptr*/
    SecondHandShop* findShop(string shopName);
     //checks if shop exists; if yes - returns a pointer to shop; if not - returns nullptr
    void fixMoney(float& money);
     /*a helping method - changes money to the correct amount if decimal digits
       are lower than 0.01 (rounded to the closest viable number);
       does nothing if it's already correct*/
public:
    ShopNetwork(int maximumShopsForEmployee=3);
     /*constructor; maximumShopsForEmployee is 3 by default
      -it's the number of shops an employee can be assigned to*/
    ~ShopNetwork();
     //destructor
    bool addShop(string shopName, float money=0);
     /*creates a shop and adds it to the shop list; money is 0 by default; uses fixMoney;
       if shop of this name already exists or money is lower than 0 it fails
       and notifies user; returns 1 if this method was successful and 0 if not*/
    bool removeShop(string shopName);
     /*removes a shop from the shop list and removes it and its inventory from memory;
       removes all pointers to this shop from customers and employees;
       fails and notifies user if shop doesn't exist;
       returns 1 if this method was successful and 0 if not*/
    int addEmployee(string name, float salary=0);
     /*Creates an Employee and adds it to the general employee list; returns id
       of the created employee; fails and notifies user if salary is lower than 0;
       uses fixMoney; salary=0 by default; Returns 0 if method was unsuccessful*/
    bool assignEmployee(string shopName, int employeeID);
     /*Assigns a previously created Employee to a shop; Employee can be in max 3 shops by default;
       if attempted to assign more, the operation fails and notifies user;
       the same happens if employee or shop doesn't exist*/
    bool unassignEmployee(string shopName, int employeeID);
     /*removes an employee from a shop employee list;
       fails and notifies user if parameters are wrong*/
    bool removeEmployee(int employeeID);
     /*removes an Employee from all Employee lists and removes from memory;
       fails and notifies user if employee doesn't exist
       returns 1 if this method was successful and 0 if not*/
    int addCustomer(string name, float money=0);
     /*creates a Customer and adds it to the general customer list; money defaults to 0;
       fails and notifies user if money is lower than 0; uses fixMoney
       returns id of the created customer. Returns 0 if method was unsuccessful*/
    bool assignCustomer(string shopName, int customerID);
     /*assigns a previously created customer to a shop;
       amount of shops assigned is unlimited;
       fails and notifies user if customer/shop doesn't exist*/
    bool unassignCustomer(string shopName, int customerID);
     /*removes a customer from a shop customer list;
       fails and notifies user if parameters are wrong;*/
    bool removeCustomer(int customerID);
     /*removes a customer from all customer lists and removes from memory;
       fails and notifies user if customer doesn't exist;
       returns 1 if this method was successful and 0 if not*/
    bool paySalary(string shopName);
     /*pays Salary to all employees of a certain shop;
       fails and notifies user if shop doesn't exist*/
    bool paySalary(string shopName, int employeeID);
     /*pays salary from a shop to an employee;
       fails and notifies user if parameters are wrong*/
    bool changeSalary(int employeeID, float newSalary);
     /*changes the salary of an employee to the new amount;
       fails and notifies user if number is negative;*/
    bool giveRaise(int employeeID, float percentage);
     /*gives a raise to a certain employee based on the given percentage;
      fails and notifies user if percentage is lower than 0;
      uses fixMoney on percentage and the resulting salary*/
    bool addItem(string shopName, int itemID, string itemName, float price, int quantity);
     /*adds an item to the inventory of a certain shop; fails and notifies user
       if itemID or quantity are invalid; uses fixMoney on price; itemID is unique;
       Adding items with the same itemID and name results in the increase in quantity
       and change in price; returns 1 if this method was successful and 0 if not*/
    bool removeItem(string shopName, int itemID, int quantity=1);
     /*removes an item from a certain shop; quantity is 1 by default, can't remove more
       than the current number, if attempted fails and notifies user;
       if quantity reaches 0, item gets removed from the list;
       returns 1 if this method was successful and 0 if not*/
    bool buyItem(string shopName, int customerID, int itemID, int quantity=1);
     /*lets a customer buy an item from a certain shop - deducts the item's price
       from customer's money; quantity is 1 by default, can't remove more
       than the current number, if attempted notifies user and stops;
       such an item has to exist in the Inventory of the given shop;
       at least one employee has to be assigned to the shop;
       fails and notifies user if given data is incorrect;
       returns 1 if this method was successful and 0 if not*/
    bool changeItemPrice(string shopName, int itemID, float newPrice);
     /*changes the item price in a certain shop; fails and notifies user if:
       newPrice is lower than 0.01 or item/shop doesn't exist; uses fixMoney*/
    bool changeMoney(int customerID, float newMoney);
     /*Changes the stored amount of customer's money; fails and notifies user if newMoney
       is lower than 0 or customer doesn't exist; uses fixMoney*/
    bool changeMoney(string shopName, float newMoney);
     /*Changes the stored amount of shop's money; notifies the user if newMoney
       is lower than 0 or customer doesn't exist and stops; uses fixMoney*/
    bool updateMoney(int customerID, float amount);
     /*Lowers or increases the customer's money based on the amount;
       amount can be negative; uses fixMoney; fails and notifies user
       if resulting money balance would be negative or customer doesn't exist*/
    bool updateMoney(string shopName, float amount);
     /*Lowers or increases the shop's money based on the amount;
       amount can be negative; uses fixMoney; fails and notifies user
       if resulting money balance would be negative or shop doesn't exist*/
    bool changeShopName(string shopName, string newShopName);
     /*changes the shop name; fails and notifies user
       if shop doesn't exist or name is already taken*/
    void printShopList();
     //prints the list of shops
    bool printShopListOfEmployee(int employeeID);
     /*prints the list of shops an employee belongs to;
      fails and notifies user if employee doesn't exist*/
    bool printShopListOfCustomer(int customerID);
     /*prints the list of shops a customer belongs to;
      fails and notifies user if customer doesn't exist*/
    void printEmployeeList();
     //prints the list of all employees in the network
    bool printEmployeeList(string shopName);
     /*prints the list of all employees in a particular shop;
      fails and notifies user if shop doesn't exist*/
    void printCustomerList();
     //prints the list of all customers in the network
    bool printCustomerList(string shopName);
     /*prints the list of all customers in a particular shop;
      fails and notifies user if shop doesn't exist*/
    bool printInventory(string shopName);
     //prints the inventory; fails and notifies user if shop doesn't exist
    void printAllShopData();
     //prints all shop data (all shops with their employees, customers and items)
    bool printAllShopData(string shopName);
     /*prints all shop data for a particular shop;
       fails and notifies user if shop doesn't exist*/
    void printAllNetworkData();
     //prints all network data (full list of employees, Customers and shops)
};
#endif // SHOP_NETWORK_H
