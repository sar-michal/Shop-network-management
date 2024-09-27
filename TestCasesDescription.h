#include <iostream>
#include <string>
#include <list>

using namespace std;

class ShopNetwork{
    int maximumShopsForEmployee=3;
    list<Employee*> employeeList;
     // list of pointers to Employee class; list of all Employees in the network
    list<Customer*> customerList;
     // list of pointers to Customer class; list of all Customers in the network
    list<SecondHandShop*> shopList;
     // list of pointers to SecondHandShop class; list of all Shops in the network
    Customer* findCustomer(int customerID);
     //checks if customer exists; if yes - returns a pointer to customer if; if not - returns nullptr
    Employee* findEmployee(int employeeID);
     //checks if employee exists; if yes - returns a pointer to employee if; if not - returns nullptr
public:
    bool addShop(string shopName, float money=0);
     /*
     adding a shop when:
     -everything is correct
     -R1: money is negative
     -R1: money decimal digits are lower than 0.01
     -R4: shop with this name already exists
     -adding multiple shops
     -adding a shop after removal
     */
    bool removeShop(string shopName);
     /*
     -removing a shop
     -removing a shop which doesn't exist
     -removing a shop twice
     -removing a shop which has Employees, Customers and Items assigned
     */
    int addEmployee(string name, float salary);
     /*
     -adding an employee
     -adding multiple employees
     -adding after removal
     -R1: salary is negative
     -R1: salary decimal digits are lower than 0.01
     */
    void assignEmployee(string shopName, int  employeeID);
     /*
     -assigning an employee to a shop
     -assigning to a shop which doesn't exist
     -assigning to multiple shops
     -assigning to a shop already assigned (should do nothing)
     -R5: assigning an employee to a 4th shop
     */
    void unassignEmployee(string shopName, int employeeID)
     /*
     -unassigning an employee
     -unassigning an employee twice
     -unassigning an employee who doesn't exist
     -unassigning an employee who's not assigned to the shop
     -unassigning an employee from a shop which doesn't exist
     -unassigning when employee nor shop exist
     */
    bool removeEmployee(int employeeID);
     /*
     removing when:
     -employee exists
     -employee doesn't exist
     -R3: employee twice
     -employee is assigned to a shop
     -employee is assigned to multiple shops
     */
    int addCustomer(string name, float money);
     /*
     adding when:
     -no customers exist
     -multiple customers exist
     -after removal
     -R1: money is negative
     -R1: money contains decimal digits which are lower than 0.01
     */
    void assignCustomer(string shopName, int customerID);
     /*
     assigning when:
     -everything correct
     -shop doesn't exist
     -customer does't exist
     -shop and customer don't exist
     -customer already assigned to a shop
     -customer already assigned to multiple shops
     -customer already assigned to the shop we try to assign to
     -after unassigning
     */
    void unassignCustomer(string shopName, int customerID);
     /*
     unassign when:
     -everything correct
     -shop doesn't exist
     -customer does't exist
     -shop and customer don't exist
     -customer not assigned
     -customer assigned to a different shop
     -unassigning twice
     */
    bool removeCustomer(int customerID);
     /*
     remove a customer when:
     -everything correct
     -customer doesn't exist
     -R3: customer twice
     -customer is assigned to a shop
     -customer is assigned to multiple shops
     */
    void paySalary(string shopName);
     /*
     Paying salary when:
     -everything correct
     -shop doesn't exist
     -shop has no employees
     -shop has 1 employee
     -shop has multiple employees
     -R2: operation would result in a negative money balance
     */
    void paySalary(string shopName, int employeeID);
     /*
     Pay salary when:
     -everything correct
     -shop doesn't exist
     -employee doesn't exist
     -shop has no employees
     -shop has multiple employees
     -R2: operation would result in a negative money balance
     */
    void changeSalary(int employeeID, int newSalary);
     /*
     changing salary when:
     -everything is correct
     -employee doesn't exist
     -R1: salary lower than 0
     -R1: salary has a decimal digit lower than 0.01
     */
    void giveRaise(int employeeID, float percentage);
     /*
     Giving a raise when:
     -everything is correct
     -employee doesn't exist
     -R1: percentage lower than 0
     -R1: percentage has a decimal digit lower than 0.01
     */
    bool addItem(string shopName, int itemID, string itemName, float price, int quantity);
     /*
     adding an item when:
     -everything is correct
     -shop doesn't exist
     -after removal
     -R10: price is lower than 0.01
     -R10: price has a decimal digit lower than 0.01
     -R9: quantity is lower than 1
     -R8: itemID is already in the list, itemName is different
     -R8: itemId is already in the list, itemName is the same
     */
    bool removeItem(string shopName, int itemID, int quantity);
     /*
     removing an item when:
     -everything is correct
     -shop doesn't exist
     -removing twice
     -item doesn't exist
     -quantity is lower than 1
     -R9: operation would result in quantity lower than 0
     -R9: operation would result in quantity equal to 0
     */
    bool buyItem(string shopName, int itemID, int quantity, int customerID);
     /*
     Buying an item when:
     -everything is correct
     -shop doesn't exist
     -item doesn't exist
     -customer doesn't exist
     -buying twice
     -R6: customer isn't assigned to the shop
     -R7: There are no employees assigned to the shop
     -quantity is lower than 1
     -R9: operation would result in quantity lower than 0
     -R9: operation would result in quantity equal to 0
     -R2: operation would result in a negative money balance
     */
    void changeItemPrice(string shopName, int itemID, float newPrice)
     /*
     changing item price when:
     -everything is correct
     -shop doesn't exist
     -shop doesn't contain the item
     -R10: newPrice is lower than 0.01
     -R10: newPrice has a decimal digit lower than 0.01
     */
    void changeMoney(int customerID, float newMoney);
     /*
     changing money when:
     -everything is correct
     -customer doesn't exist
     -R1: newMoney is negative
     -R1: newMoney decimal digits are lower than 0.01
     */
    void changeMoney(string shopName, float newMoney);
     /*
     changing money when:
     -everything is correct
     -shop doesn't exist
     -R1: newMoney is negative
     -R1: newMoney decimal digits are lower than 0.01
     */
    void updateMoney(int customerID, float amount);
     /*
     updating money when:
     -everything is correct, amount is positive
     -customer doesn't exist
     -amount is negative and balance doesn't end up negative (should work)
     -R2: amount is negative and balance would end up negative
     -R1: amount decimal digits are lower than 0.01
     */
    void updateMoney(string shopName, float amount);
     /*
     updating money when:
     -everything is correct, amount is positive
     -shop doesn't exist
     -amount is negative and balance doesn't end up negative (should work)
     -R2: amount is negative and balance would end up negative
     -R1: amount decimal digits are lower than 0.01
     */
    void changeShopName(string shopName, string newShopName);
     /*
     changing shopName when:
     -everything is correct
     -shop doesn't exist
     -new name is already taken
     */
    void printShopList();
     /*
     printing when:
     -no shops
     -one shop
     -multiple shops
     -after shop removal
     */
    void printShopListOfEmployee(int employeeID);
     /*
     printing when:
     -employee exists
     -employee doesn't exist
     -no shops assigned
     -one shop assigned
     -multiple shops assigned
     -after unassigning a shop
     */
    void printShopListOfCustomer(int customerID);
     /*
     printing when:
     -customer exists
     -customer doesn't exist
     -no shops assigned
     -one shop assigned
     -multiple shops assigned
     -after unassigning a shop
     */
    void printEmployeeList();
     /*
     printing when:
     -no employees
     -one employee
     -multiple employees
     -after employee removal
     */
    void printEmployeeList(string shopName);
     /*
     printing when:
     -no employees assigned
     -one employee assigned
     -multiple employees assigned
     -after unassigning an employee
     */
    void printCustomerList();
     /*
     printing when:
     -no customers
     -one customer
     -multiple customers
     -after customer removal
     */
    void printCustomerList(string shopName);
     /*
     printing when:
     -no customers assigned
     -one customer assigned
     -multiple customers assigned
     -after unassigning a customer
     */
    void printInventory(string shopName);
     /*
     printing when:
     -no items
     -one item
     -multiple items
     -after item removal
     */
    void printAllShopData();
     /*
     -printing (it utilizes previous methods)
     */
    void printAllShopData(string shopName);
     /*
     -shop doesn't exist
     -shop exists (it utilizes previous methods)
     */
    void printAllNetworkData();
     /*
     -printing (it utilizes previous methods)
     */
};
