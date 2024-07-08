#include "SecondHandShop.h"

Customer* SecondHandShop::findCustomer(int customerID)
{
    for (list<Customer*>::iterator it=customerList.begin(); it!=customerList.end(); ++it)
    {
         if((*it)->getPersonID() == customerID)
         {
             return (*it);
         }
    }
    return nullptr;
}
/*checks if customer is assigned to this shop; if yes
 - returns a pointer to customer; if not - returns nullptr*/
Employee* SecondHandShop::findEmployee(int employeeID)
{
    for (list<Employee*>::iterator it=employeeList.begin(); it!=employeeList.end(); ++it)
    {
         if((*it)->getPersonID() == employeeID)
         {
             return (*it);
         }
    }
    return nullptr;
}
/*checks if employee is assigned to this shop; if yes
 - returns a pointer to employee; if not - returns nullptr*/
Item* SecondHandShop::findItem(int itemID)
{
    for (list<Item*>::iterator it=inventory.begin(); it!=inventory.end(); ++it)
    {
         if((*it)->getItemID() == itemID)
         {
             return (*it);
         }
    }
    return nullptr;
}
/*checks if item exists; if yes - returns a pointer to item;
if not - returns nullptr*/
SecondHandShop::SecondHandShop(string shopName, float money)
{
    this->shopName = shopName;
    this->money = money;
}
//constructor
SecondHandShop::~SecondHandShop()
{
    employeeList.clear();
    customerList.clear();
     for (list<Item*>::iterator it=inventory.begin(); it!=inventory.end(); ++it)
     {
         delete *it;
     }
    inventory.clear();
}
/*destructor; properly deallocates memory;*/
string SecondHandShop::getShopName() const
{
    return shopName;
}
//returns shopName
float SecondHandShop::getMoney() const
{
    return money;
}
//returns money
void SecondHandShop::changeShopName(string newShopName)
{
    shopName = newShopName;
}
//changes the shop name
void SecondHandShop::hireEmployee(Employee* emp)
{
    if(emp != nullptr)
    {
        employeeList.push_back(emp);
    }
}
/*adds an employee to the list of employees;
 does nothing if Employee* is nullptr*/
bool SecondHandShop::fireEmployee(int employeeID)
{
    int initialSize = employeeList.size();
    employeeList.remove_if([employeeID](Employee* ptr) { return ptr->getPersonID() == employeeID; });
    int finalSize = employeeList.size();
    return (initialSize - finalSize) > 0;
}
/*removes an employee from the list of employees;
 returns 0 if employee isn't in the list, 1 if successful*/
bool SecondHandShop::checkIfEmployeeAssigned(int employeeID)
{
    if(findEmployee(employeeID) != nullptr)
    {
        return 1;
    }
    return 0;
}
/*Checks if employee is assigned to the shop; return 1 if yes and 0 if not*/
bool SecondHandShop::checkIfAnyEmployees()
{
    if(employeeList.size() == 0)
    {
        return 0;
    }
    return 1;
}
/*checks if any employees are hired by the shop; return 1 if yes and 0 if not*/
bool SecondHandShop::paySalary()
{
    float finalMoney = money;
    for (list<Employee*>::iterator it=employeeList.begin(); it!=employeeList.end(); ++it)
    {
         finalMoney = finalMoney - (*it)->getSalary();
    }
    if(finalMoney<0)
    {
        return 0;
    }
    money = finalMoney;
    return 1;
}
/*pays salary to every shop employee; if this operation would result
  in negative money balance it fails and returns 0; returns 1 if successful*/
bool SecondHandShop::paySalary(int employeeID)
{
    Employee* eptr = findEmployee(employeeID);
    if(eptr == nullptr || money - (eptr->getSalary()) < 0)
    {
        return 0;
    }
    money = money - eptr->getSalary();
    return 1;
}
/*pays salary to a specific employee; if this operation would result
  in negative money balance or employee isn't in the list it fails and returns 0;
  returns 1 if successful*/
bool SecondHandShop::changeSalary(int employeeID, float newSalary)
{
    Employee* eptr = findEmployee(employeeID);
    if(eptr == nullptr)
    {
        return 0;
    }
    eptr->changeSalary(newSalary);
    return 1;
}
/*changes the salary for a specific employee; this method replaces the old salary
 with the new one; returns 0 if employee isn't in the list, 1 if successful*/
void SecondHandShop::addCustomer(Customer* cust)
{
    customerList.push_back(cust);
}
/*adds a customer to the list of customers; does nothing if Customer* is nullptr*/
bool SecondHandShop::removeCustomer(int customerID)
{
    int initialSize = customerList.size();
    customerList.remove_if([customerID](Customer* ptr) { return ptr->getPersonID() == customerID; });
    int finalSize = customerList.size();
    return (initialSize - finalSize) > 0;
}
/*removes a customer from the list of customers;
  returns 0 if customer isn't in the list, 1 if successful*/
bool SecondHandShop::checkIfCustomerAssigned(int customerID)
{
    if(findCustomer(customerID) != nullptr)
    {
        return 1;
    }
    return 0;
}
/*Checks if customer is assigned to the shop; return 1 if yes and 0 if not*/
bool SecondHandShop::addItem(int itemID, string itemName, float price, int quantity)
{
    Item* iptr = findItem(itemID);
    if(iptr != nullptr)
    {
        if(iptr->getItemName() == itemName)
        {
            iptr->updateQuantity(quantity);
            iptr->changePrice(price);
            return 1;
        }
        return 0;
    }
    Item* newItem = new Item(itemID, itemName, price, quantity);
    if(newItem == nullptr)
    {
        return 0;
    }
    inventory.push_back(newItem);
    return 1;
}
/*adds an item to the inventory; checks itemID if invalid returns 0;
  itemID is unique; Adding items with the same itemID and name results
  in the increase in quantity and change in price*/
bool SecondHandShop::removeItem(int itemID, int quantity /*=1*/)
{
    Item* iptr = findItem(itemID);
    if(iptr == nullptr)
    {
        return 0;
    }
    if(iptr->updateQuantity(-quantity))
    {
        if(iptr->getQuantity() == 0)
        {
            inventory.remove(iptr);
            delete iptr;
        }
        return 1;
    }
    return 0;
}
/*quantity is 1 by default, can't remove more than the current number,
  if attempted fails and returns 0; if quantity reaches 0, item gets removed
  from the list; returns 1 if method was successful;*/
float SecondHandShop::checkPrice(int itemID)
{
    Item* iptr = findItem(itemID);
    if(iptr == nullptr)
    {
        return 0;
    }
    return iptr->getPrice();
}
/*returns the price of a specific item; returns 0 if item doesn't exist*/
bool SecondHandShop::changePrice(int itemID, float newPrice)
{
    Item* iptr = findItem(itemID);
    if(iptr == nullptr)
    {
        return 0;
    }
    iptr->changePrice(newPrice);
    return 1;
}
/*changes the price of an item; returns 0 if item doesn't exist, 1 if successful*/
void SecondHandShop::changeMoney(float newMoney)
{
    money = newMoney;
}
//Changes the stored amount of money;
bool SecondHandShop::updateMoney(float amount)
{
    if(money + amount < 0)
    {
        return 0;
    }
    money += amount;
    return 1;
}
/*Lowers or increases the amount of money based on the amount;
  if this operation would result in negative money balance it fails
  and returns 0; returns 1 if successful*/
void SecondHandShop::printEmployeeList()
{
    for (list<Employee*>::iterator it=employeeList.begin(); it!=employeeList.end(); ++it)
    {
        (*it)->print();
    }
}
//prints the list of employees
void SecondHandShop::printCustomerList()
{
    for (list<Customer*>::iterator it=customerList.begin(); it!=customerList.end(); ++it)
    {
        (*it)->print();
    }
}
//prints the list of customers
void SecondHandShop::printInventory()
{
    for (list<Item*>::iterator it=inventory.begin(); it!=inventory.end(); ++it)
    {
        (*it)->print();
    }
}
//prints the inventory
void SecondHandShop::printAll()
{
    cout<<"List of Customers:"<<endl;
    printCustomerList();
    cout<<"List of Employees:"<<endl;
    printEmployeeList();
    cout<<"Inventory:"<<endl;
    printInventory();
}
//prints all data
