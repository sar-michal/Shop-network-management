#include "ShopNetwork.h"

Customer* ShopNetwork::findCustomer(int customerID)
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
/*checks if customer exists; if yes - returns a pointer to customer;
  if not - returns nullptr*/
Employee* ShopNetwork::findEmployee(int employeeID)
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
/*checks if employee exists; if yes - returns a pointer to employee;
 if not - returns nullptr*/
SecondHandShop* ShopNetwork::findShop(string shopName)
{
    for (list<SecondHandShop*>::iterator it=shopList.begin(); it!=shopList.end(); ++it)
    {
        if((*it)->getShopName() == shopName)
        {
            return (*it);
        }
    }
    return nullptr;
}
//checks if shop exists; if yes - returns a pointer to shop; if not - returns nullptr
void ShopNetwork::fixMoney(float& money)
{
    money = round(money * 100.0) / 100.0;
}
/*a helping method - changes money to the correct amount if decimal digits
  are lower than 0.01 (rounded to the closest viable number);
  does nothing if it's already correct*/
ShopNetwork::ShopNetwork(int maximumShopsForEmployee /*=3*/)
{
    this->maximumShopsForEmployee = maximumShopsForEmployee;
}
/*constructor; maximumShopsForEmployee is 3 by default
 -it's the number of shops an employee can be assigned to*/
ShopNetwork::~ShopNetwork()
{
    for (list<Employee*>::iterator it=employeeList.begin(); it!=employeeList.end(); ++it)
    {
        delete *it;
    }
    employeeList.clear();
    for (list<Customer*>::iterator it=customerList.begin(); it!=customerList.end(); ++it)
    {
        delete *it;
    }
    customerList.clear();
    for (list<SecondHandShop*>::iterator it=shopList.begin(); it!=shopList.end(); ++it)
    {
        delete *it;
    }
    shopList.clear();
}
//destructor
bool ShopNetwork::addShop(string shopName, float money /*=0*/)
{
    if(money < 0)
    {
        cout<<"Money lower than 0"<<endl;
        return 0;
    }
    if(findShop(shopName) != nullptr)
    {
        cout<<"Shop already exists"<<endl;
        return 0;
    }
    fixMoney(money);
    SecondHandShop* newShop = new SecondHandShop(shopName, money);
    if(newShop == nullptr)
    {
        return 0;
    }
    shopList.push_back(newShop);
    return 1;
}
/*creates a shop and adds it to the shop list; money is 0 by default; uses fixMoney;
  if shop of this name already exists or money is lower than 0 it fails
  and notifies user; returns 1 if this method was successful and 0 if not*/
bool ShopNetwork::removeShop(string shopName)
{
    SecondHandShop* sptr = findShop(shopName);
    if (sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    for (list<Employee*>::iterator it=employeeList.begin(); it!=employeeList.end(); ++it)
    {
        (*it)->leaveShop(sptr);
    }
    for (list<Customer*>::iterator it=customerList.begin(); it!=customerList.end(); ++it)
    {
        (*it)->leaveShop(sptr);
    }
    shopList.remove(sptr);
    delete sptr;
    return 1;
}
/*removes a shop from the shop list and removes it and its inventory from memory;
  removes all pointers to this shop from customers and employees;
  fails and notifies user if shop doesn't exist;
  returns 1 if this method was successful and 0 if not*/
int ShopNetwork::addEmployee(string name, float salary /*=0*/)
{
    if(salary < 0)
    {
        cout<<"Salary lower than 0"<<endl;
        return 0;
    }
    fixMoney(salary);
    Employee* newEmployee = new Employee(name, salary);
    employeeList.push_back(newEmployee);
    return newEmployee->getPersonID();
}
/*Creates an Employee and adds it to the general employee list; returns id
  of the created employee; fails and notifies user if salary is lower than 0;
  uses fixMoney; salary=0 by default; Returns 0 if method was unsuccessful*/
bool ShopNetwork::assignEmployee(string shopName, int employeeID)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    Employee* eptr = findEmployee(employeeID);
    if(eptr == nullptr)
    {
        cout<<"Employee doesn't exist"<<endl;
        return 0;
    }
    if(sptr->checkIfEmployeeAssigned(employeeID) == 1)
    {
        cout<<"Employee is already assigned to this shop"<<endl;
        return 0;
    }
    if(eptr->shopAmount() >= maximumShopsForEmployee)
    {
        cout<<"Employee can't exceed the limit of "<<eptr->shopAmount()<<" assigned shops"<<endl;
        return 0;
    }
    sptr->hireEmployee(eptr);
    eptr->joinShop(sptr);
    return 1;
}
/*Assigns a previously created Employee to a shop; Employee can be in max 3 shops by default;
  if attempted to assign more, the operation fails and notifies user;
  the same happens if employee or shop doesn't exist*/
bool ShopNetwork::unassignEmployee(string shopName, int employeeID)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    Employee* eptr = findEmployee(employeeID);
    if(eptr == nullptr)
    {
        cout<<"Employee doesn't exist"<<endl;
        return 0;
    }
    if(sptr->fireEmployee(employeeID) == 0)
    {
        cout<<"Employee isn't assigned to this shop"<<endl;
        return 0;
    }
    eptr->leaveShop(sptr);
    return 1;
}
/*removes an employee from a shop employee list;
  fails and notifies user if parameters are wrong*/
bool ShopNetwork::removeEmployee(int employeeID)
{
    Employee* eptr = findEmployee(employeeID);
    if(eptr == nullptr)
    {
        cout<<"Employee doesn't exist"<<endl;
        return 0;
    }
    employeeList.remove(eptr);
    delete eptr;
    return 1;
}
/*removes an Employee from all Employee lists and removes from memory;
  fails and notifies user if employee doesn't exist
  returns 1 if this method was successful and 0 if not*/
int ShopNetwork::addCustomer(string name, float money /*=0*/)
{
    if(money < 0)
    {
        cout<<"Money lower than 0"<<endl;
        return 0;
    }
    fixMoney(money);
    Customer* newCustomer = new Customer(name, money);
    customerList.push_back(newCustomer);
    return newCustomer->getPersonID();
}
/*creates a Customer and adds it to the general customer list; money defaults to 0;
  fails and notifies user if money is lower than 0; uses fixMoney
  returns id of the created customer. Returns 0 if method was unsuccessful*/
bool ShopNetwork::assignCustomer(string shopName, int customerID)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    Customer* cptr = findCustomer(customerID);
    if(cptr == nullptr)
    {
        cout<<"Customer doesn't exist"<<endl;
        return 0;
    }
    if(sptr->checkIfCustomerAssigned(customerID) == 1)
    {
        cout<<"Customer is already assigned to this shop"<<endl;
        return 0;
    }
    sptr->addCustomer(cptr);
    cptr->joinShop(sptr);
    return 1;
}
/*assigns a previously created customer to a shop;
  amount of shops assigned is unlimited;
  fails and notifies user if customer/shop doesn't exist*/
bool ShopNetwork::unassignCustomer(string shopName, int customerID)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    Customer* cptr = findCustomer(customerID);
    if(cptr == nullptr)
    {
        cout<<"Customer doesn't exist"<<endl;
        return 0;
    }
    if(sptr->removeCustomer(customerID) == 0)
    {
        cout<<"Customer isn't assigned to this shop"<<endl;
        return 0;
    }
    cptr->leaveShop(sptr);
    return 1;
}
/*removes a customer from a shop customer list;
  fails and notifies user if parameters are wrong;*/
bool ShopNetwork::removeCustomer(int customerID)
{
    Customer* cptr = findCustomer(customerID);
    if(cptr == nullptr)
    {
        cout<<"Customer doesn't exist"<<endl;
        return 0;
    }
    customerList.remove(cptr);
    delete cptr;
    return 1;
}
/*removes a customer from all customer lists and removes from memory;
  fails and notifies user if customer doesn't exist;
  returns 1 if this method was successful and 0 if not*/
bool ShopNetwork::paySalary(string shopName)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    if(sptr->paySalary() == 0)
    {
        cout<<"This operation would result in negative money balance"<<endl;
        return 0;
    }
    return 1;
}
/*pays Salary to all employees of a certain shop;
  fails and notifies user if shop doesn't exist*/
bool ShopNetwork::paySalary(string shopName, int employeeID)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    if(findEmployee(employeeID) == nullptr)
    {
        cout<<"Employee doesn't exist"<<endl;
        return 0;
    }
    if(sptr->paySalary(employeeID) == 0)
    {
        cout<<"Employee isn't assigned to the shop or this operation would result in negative money balance"<<endl;
        return 0;
    }
    return 1;
}
/*pays salary from a shop to an employee;
  fails and notifies user if parameters are wrong*/
bool ShopNetwork::changeSalary(int employeeID, float newSalary)
{
    Employee* eptr = findEmployee(employeeID);
    if(eptr == nullptr)
    {
        cout<<"Employee doesn't exist"<<endl;
        return 0;
    }
    if(newSalary < 0)
    {
        cout<<"Salary lower than 0"<<endl;
        return 0;
    }
    fixMoney(newSalary);
    eptr->changeSalary(newSalary);
    return 1;
}
/*changes the salary of an employee to the new amount;
  fails and notifies user if number is negative; uses fixMoney*/
bool ShopNetwork::giveRaise(int employeeID, float percentage)
{
    Employee* eptr = findEmployee(employeeID);
    if(eptr == nullptr)
    {
        cout<<"Employee doesn't exist"<<endl;
        return 0;
    }
    if(percentage < 0)
    {
        cout<<"Percentage lower than 0"<<endl;
        return 0;
    }
    if(percentage == 0)
    {
        return 1;
    }
    fixMoney(percentage);
    float newSalary = (eptr->getSalary()*(100 + percentage)/100);
    fixMoney(newSalary);
    eptr->changeSalary(newSalary);
    return 1;
}
/*gives a raise to a certain employee based on the given percentage;
 fails and notifies user if percentage is lower than 0;
 uses fixMoney on percentage and the resulting salary*/
bool ShopNetwork::addItem(string shopName, int itemID, string itemName, float price, int quantity)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    if(price < 0.01)
    {
        cout<<"Price lower than 0.01"<<endl;
        return 0;
    }
    if(quantity < 1)
    {
        cout<<"Quantity lower than 1"<<endl;
        return 0;
    }
    fixMoney(price);
    if(sptr->addItem(itemID, itemName, price, quantity) == 0)
    {
        cout<<"Item with the same ID and different name already exists"<<endl;
        return 0;
    }
    return 1;
}
/*adds an item to the inventory of a certain shop; fails and notifies user
  if itemID or quantity are invalid; uses fixMoney on price; itemID is unique;
  Adding items with the same itemID and name results in the increase in quantity
  and change in price; returns 1 if this method was successful and 0 if not*/
bool ShopNetwork::removeItem(string shopName, int itemID, int quantity /*=1*/)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    if(quantity < 1)
    {
        cout<<"Quantity lower than 1"<<endl;
        return 0;
    }
    if(sptr->removeItem(itemID, quantity) == 0)
    {
        cout<<"Item doesn't exist or quantity would be negative"<<endl;
        return 0;
    }
    return 1;
}
/*removes an item from a certain shop; quantity is 1 by default, can't remove more
  than the current number, if attempted fails and notifies user;
  if quantity reaches 0, item gets removed from the list;
  returns 1 if this method was successful and 0 if not*/
bool ShopNetwork::buyItem(string shopName, int customerID, int itemID, int quantity /*=1*/)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    Customer* cptr = findCustomer(customerID);
    if(cptr == nullptr)
    {
        cout<<"Customer doesn't exist"<<endl;
        return 0;
    }
    if(quantity < 1)
    {
        cout<<"Quantity lower than 1"<<endl;
        return 0;
    }
    if(sptr->checkIfCustomerAssigned(customerID) == 0)
    {
        cout<<"The customer is not assigned to the shop"<<endl;
        return 0;
    }
    if(sptr->checkIfAnyEmployees() == 0)
    {
        cout<<"There are no employees assigned to the shop"<<endl;
        return 0;
    }
    float itemPrice = sptr->checkPrice(itemID);
    if(itemPrice == 0)
    {
        cout<<"Item doesn't exist"<<endl;
        return 0;
    }
    if(cptr->getMoney() - (itemPrice * quantity) < 0)
    {
        cout<<"Customer's money would be negative"<<endl;
        return 0;
    }
    if(sptr->removeItem(itemID, quantity) == 0)
    {
        cout<<"Quantity would be negative"<<endl;
        return 0;
    }
    cptr->updateMoney(-(itemPrice * quantity));
    sptr->updateMoney(itemPrice * quantity);
    return 1;
}
/*lets a customer buy an item from a certain shop - deducts the item's price
  from customer's money; quantity is 1 by default, can't remove more
  than the current number, if attempted notifies user and stops;
  such an item has to exist in the Inventory of the given shop;
  at least one employee has to be assigned to the shop;
  fails and notifies user if given data is incorrect;
  returns 1 if this method was successful and 0 if not*/
bool ShopNetwork::changeItemPrice(string shopName, int itemID, float newPrice)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    if(newPrice < 0.01)
    {
        cout<<"New price lower than 0.01"<<endl;
        return 0;
    }
    fixMoney(newPrice);
    if(sptr->changePrice(itemID, newPrice) == 0)
    {
        cout<<"Item doesn't exist"<<endl;
        return 0;
    }
    return 1;
}
/*changes the item price in a certain shop; fails and notifies user if:
  newPrice is lower than 0.01 or item/shop doesn't exist; uses fixMoney*/
bool ShopNetwork::changeMoney(int customerID, float newMoney)
{
    Customer* cptr = findCustomer(customerID);
    if(cptr == nullptr)
    {
        cout<<"Customer doesn't exist"<<endl;
        return 0;
    }
    if(newMoney < 0)
    {
        cout<<"Money lower than 0"<<endl;
        return 0;
    }
    fixMoney(newMoney);
    cptr->changeMoney(newMoney);
    return 1;
}
/*Changes the stored amount of customer's money; fails and notifies user if newMoney
  is lower than 0 or customer doesn't exist; uses fixMoney*/
bool ShopNetwork::changeMoney(string shopName, float newMoney)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    if(newMoney < 0)
    {
        cout<<"Money lower than 0"<<endl;
        return 0;
    }
    fixMoney(newMoney);
    sptr->changeMoney(newMoney);
    return 1;
}
/*Changes the stored amount of shop's money; notifies the user if newMoney
  is lower than 0 or customer doesn't exist and stops; uses fixMoney*/
bool ShopNetwork::updateMoney(int customerID, float amount)
{
    Customer* cptr = findCustomer(customerID);
    if(cptr == nullptr)
    {
        cout<<"Customer doesn't exist"<<endl;
        return 0;
    }
    if(amount == 0)
    {
        return 1;
    }
    fixMoney(amount);
    if(cptr->updateMoney(amount) == 0)
    {
        cout<<"Customer's money would be negative"<<endl;
        return 0;
    }
    return 1;
}
/*Lowers or increases the customer's money based on the amount;
  amount can be negative; uses fixMoney; fails and notifies user
  if resulting money balance would be negative or customer doesn't exist*/
bool ShopNetwork::updateMoney(string shopName, float amount)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    if(amount == 0)
    {
        return 1;
    }
    fixMoney(amount);
    if(sptr->updateMoney(amount) == 0)
    {
        cout<<"Shops's money would be negative"<<endl;
        return 0;
    }
    return 1;
}
/*Lowers or increases the shop's money based on the amount;
  amount can be negative; uses fixMoney; fails and notifies user
  if resulting money balance would be negative or shop doesn't exist*/
bool ShopNetwork::changeShopName(string shopName, string newShopName)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    if(findShop(newShopName) != nullptr)
    {
        cout<<"Shop with the same name already exists"<<endl;
        return 0;
    }
    sptr->changeShopName(newShopName);
    return 1;
}
/*changes the shop name; fails and notifies user
  if shop doesn't exist or name is already taken*/
void ShopNetwork::printShopList()
{
    cout<<"-- Shops in the network --"<<endl;
    for (list<SecondHandShop*>::iterator it=shopList.begin(); it!=shopList.end(); ++it)
    {
        cout<<"> "<<(*it)->getShopName()<<" "<<(*it)->getMoney()<<endl;
    }
    cout<<endl;
}
//prints the list of shops
bool ShopNetwork::printShopListOfEmployee(int employeeID)
{
    Employee* eptr = findEmployee(employeeID);
    if(eptr == nullptr)
    {
        cout<<"Employee doesn't exist"<<endl;
        return 0;
    }
    cout<<"-- Shop list of employee: ["<<eptr->getPersonID()<<" "<<eptr->getName()<<"] --"<<endl;
    eptr->printShopNames();
    cout<<endl;
    return 1;
}
/*prints the list of shops an employee belongs to;
 fails and notifies user if employee doesn't exist*/
bool ShopNetwork::printShopListOfCustomer(int customerID)
{
    Customer* cptr = findCustomer(customerID);
    if(cptr == nullptr)
    {
        cout<<"Customer doesn't exist"<<endl;
        return 0;
    }
    cout<<"-- Shop list of customer: ["<<cptr->getPersonID()<<" "<<cptr->getName()<<"] --"<<endl;
    cptr->printShopNames();
    cout<<endl;
    return 1;
}
/*prints the list of shops a customer belongs to;
 fails and notifies user if customer doesn't exist*/
void ShopNetwork::printEmployeeList()
{
    cout<<"-- Employees in the network --"<<endl;
    for (list<Employee*>::iterator it=employeeList.begin(); it!=employeeList.end(); ++it)
    {
        (*it)->print();
    }
    cout<<endl;
}
//prints the list of all employees in the network
bool ShopNetwork::printEmployeeList(string shopName)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    cout<<"-- Employees of shop: ["<<sptr->getShopName()<<"] --"<<endl;
    sptr->printEmployeeList();
    cout<<endl;
    return 1;
}
/*prints the list of all employees in a particular shop;
 fails and notifies user if shop doesn't exist*/
void ShopNetwork::printCustomerList()
{
    cout<<"-- Customers in the network --"<<endl;
    for (list<Customer*>::iterator it=customerList.begin(); it!=customerList.end(); ++it)
    {
        (*it)->print();
    }
    cout<<endl;
}
//prints the list of all customers in the network
bool ShopNetwork::printCustomerList(string shopName)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    cout<<"-- Customers of shop: ["<<sptr->getShopName()<<"] --"<<endl;
    sptr->printCustomerList();
    cout<<endl;
    return 1;
}
/*prints the list of all customers in a particular shop;
 fails and notifies user if shop doesn't exist*/
bool ShopNetwork::printInventory(string shopName)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    cout<<"-- Inventory of shop: ["<<sptr->getShopName()<<"] --"<<endl;
    sptr->printInventory();
    cout<<endl;
    return 1;
}
//prints the inventory; fails and notifies user if shop doesn't exist
void ShopNetwork::printAllShopData()
{
    cout<<'\t'<<"--- All Shop Data ---"<<endl<<endl;
    for (list<SecondHandShop*>::iterator it=shopList.begin(); it!=shopList.end(); ++it)
    {
        cout<<"-- ["<<(*it)->getShopName()<<"] --"<<endl<<"  Money: "<<(*it)->getMoney()<<endl;
        cout<<"  <Employees>"<<endl;
        (*it)->printEmployeeList();
        cout<<"  <Customers>"<<endl;
        (*it)->printCustomerList();
        cout<<"  <Inventory>"<<endl;
        (*it)->printInventory();
        cout<<endl;
    }
    cout<<endl;

}
//prints all shop data (all shops with their employees, customers and items)
bool ShopNetwork::printAllShopData(string shopName)
{
    SecondHandShop* sptr = findShop(shopName);
    if(sptr == nullptr)
    {
        cout<<"Shop doesn't exist"<<endl;
        return 0;
    }
    cout<<"-- All Data of Shop: ["<<sptr->getShopName()<<"] --"<<endl<<"  Money: "<<sptr->getMoney()<<endl;
    cout<<"  <Employees>"<<endl;
    sptr->printEmployeeList();
    cout<<"  <Customers>"<<endl;
    sptr->printCustomerList();
    cout<<"  <Inventory>"<<endl;
    sptr->printInventory();
    cout<<endl;
    return 1;
}
/*prints all shop data for a particular shop;
  fails and notifies user if shop doesn't exist*/
void ShopNetwork::printAllNetworkData()
{
    cout<<'\t'<<"--- All network data ---"<<endl<<endl;
    printShopList();
    printEmployeeList();
    printCustomerList();
}
//prints all network data (full list of employees, Customers and shops)

