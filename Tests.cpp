#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <assert.h>
using namespace std;
#include "Item.cpp"
#include "Person.cpp"
#include "Employee.cpp"
#include "Customer.cpp"
#include "SecondHandShop.cpp"
#include "ShopNetwork.cpp"

int main()
{
    ShopNetwork* network = new ShopNetwork();
    /*
    network->addShop("Fortune");
    network->addShop("Plenty");
    network->printShopList();
    network->addEmployee("John");
    network->assignEmployee("Fortune", 1);
    network->printShopListOfEmployee(1);
    network->addCustomer("Anna");
    network->assignCustomer("Fortune", 2);
    network->printShopListOfCustomer(2);
    network->printEmployeeList();
    network->printEmployeeList("Fortune");
    network->printCustomerList();
    network->printCustomerList("Fortune");
    network->addItem("Fortune", 1, "Book", 20, 1);
    network->addItem("Fortune", 2, "Computer", 2000, 1);
    network->printInventory("Fortune");
    network->printAllShopData();
    network->printAllShopData("Fortune");
    network->printAllNetworkData();
    */
    cout<<'\t'<<"*TESTS FOR ALL PRINTING METHODS*"<<endl;
    network->printShopList();
    assert (network->printShopListOfEmployee(999)==0);
    assert (network->printShopListOfCustomer(999)==0);
    network->printEmployeeList();
    assert (network->printEmployeeList("VOID")==0);
    network->printCustomerList();
    assert (network->printCustomerList("VOID")==0);
    assert (network->printInventory("VOID")==0);
    network->printAllShopData();
    network->printAllNetworkData();
    
    cout<<'\t'<<"*TESTS FOR ADDSHOP*"<<endl;
    assert (network->addShop("Alfa")==1);
    assert (network->addShop("Alfa")==0);
    assert (network->addShop("Beta", -200)==0);
    assert (network->addShop("Beta", 300.0001)==1);
    assert (network->addShop("Gamma", 3200)==1);
    assert (network->removeShop("Gamma")==1);
    assert (network->addShop("Omega", 8400.25)==1);
    assert (network->addShop("Delta", 6454.20)==1);
    assert (network->addShop("Epsilon", 100000)==1);
    network->printShopList();

    cout<<'\t'<<"*TESTS FOR REMOVESHOP*"<<endl;
    assert (network->removeShop("Omega")==1);
    assert (network->removeShop("Zeta")==0);
    assert (network->removeShop("Omega")==0);
    assert (network->addShop("TEST", 100000)==1);
    assert (network->assignCustomer("TEST", network->addCustomer("Andrew"))==1);
    assert (network->assignEmployee("TEST", network->addEmployee("Bob", 200))==1);
    assert (network->addItem("TEST", 1, "TestItem", 200.77, 2)==1);
    assert (network->printAllShopData("TEST")==1);
    assert (network->removeShop("TEST")==1);
    network->printAllNetworkData();
    
    cout<<'\t'<<"*TESTS FOR ADDEMPLOYEE*"<<endl;
    assert (network->addEmployee("Cole A", 622.1222)!=0);
    assert (network->addEmployee("Cole B", 100)!=0);
    assert (network->addEmployee("Dave", -7077)==0);
    network->printEmployeeList();
    assert (network->removeEmployee(3)==1);
    assert (network->addEmployee("Dave", 7077)!=0);
    network->printEmployeeList();
    
    cout<<'\t'<<"*TESTS FOR ASSIGNEMPLOYEE*"<<endl;
    assert (network->assignEmployee("Alfa", 2)==1);
    assert (network->assignEmployee("VOID", 2)==0);
    assert (network->assignEmployee("Beta", 2)==1);
    assert (network->assignEmployee("Beta", 2)==0);
    assert (network->assignEmployee("Delta", 2)==1);
    assert (network->assignEmployee("Zeta", 2)==0);
    assert (network->printShopListOfEmployee(2)==1);

    cout<<'\t'<<"*TESTS FOR UNASSIGNEMPLOYEE*"<<endl;
    assert (network->unassignEmployee("Delta", 2)==1);
    assert (network->unassignEmployee("Delta", 2)==0);
    assert (network->unassignEmployee("Delta", 999)==0);
    assert (network->unassignEmployee("Delta", 4)==0);
    assert (network->unassignEmployee("VOID", 2)==0);
    assert (network->printShopListOfEmployee(2));

    cout<<'\t'<<"*TESTS FOR REMOVEEMPLOYEE*"<<endl;
    assert (network->removeEmployee(network->addEmployee("Edward", 7077))==1);
    assert (network->removeEmployee(999)==0);
    assert (network->removeEmployee(6)==0);
    assert (network->removeEmployee(2)==1);
    network->printAllNetworkData();

    cout<<'\t'<<"*TESTS FOR ADDCUSTOMER*"<<endl;
    assert (network->addCustomer("Fiona", 622.1222)!=0);
    assert (network->addCustomer("Geralt")!=0);
    assert (network->addCustomer("SB", -7077)==0);
    network->printCustomerList();
    assert (network->removeCustomer((network->addCustomer("SB")))==1);
    assert (network->addCustomer("Hermiona", 7077)!=0);
    network->printCustomerList();
    
    cout<<'\t'<<"*TESTS FOR ASSIGNCUSTOMER*"<<endl;
    assert (network->assignCustomer("Alfa", 8)==1);
    assert (network->assignCustomer("VOID", 8)==0);
    assert (network->assignCustomer("Beta", 8)==1);
    assert (network->assignCustomer("Beta", 8)==0);
    assert (network->assignCustomer("Delta", 8)==1);
    assert (network->unassignCustomer("Delta", 8)==1);
    assert (network->assignCustomer("Delta", 8)==1);
    assert (network->printShopListOfCustomer(8)==1);

    cout<<'\t'<<"*TESTS FOR UNASSIGNCUSTOMER*"<<endl;
    assert (network->unassignCustomer("Delta", 8)==1);
    assert (network->unassignCustomer("Delta", 8)==0);
    assert (network->unassignCustomer("Delta", 999)==0);
    assert (network->unassignCustomer("Delta", 10)==0);
    assert (network->unassignCustomer("VOID", 8)==0);
    assert (network->printShopListOfCustomer(8));

    cout<<'\t'<<"*TESTS FOR REMOVECUSTOMER*"<<endl;
    assert (network->removeCustomer(network->addCustomer("SB", 7077))==1);
    assert (network->removeCustomer(999)==0);
    assert (network->removeCustomer(11)==0);
    assert (network->removeCustomer(8)==1);
    network->printAllNetworkData();

    cout<<'\t'<<"*TESTS FOR PAYSALARY1*"<<endl;
    assert (network->assignEmployee("Epsilon", 4));
    assert (network->paySalary("Epsilon")==1);
    assert (network->assignEmployee("Epsilon", 5));
    assert (network->paySalary("Epsilon")==1);
    network->printAllShopData("Epsilon");
    assert (network->paySalary("VOID")==0);
    assert (network->paySalary("Alfa")==1);
    assert (network->changeSalary(4, 100000)==1);
    assert (network->paySalary("Epsilon")==0);
    network->printAllShopData("Alfa");

    cout<<'\t'<<"*TESTS FOR PAYSALARY2*"<<endl;
    assert (network->paySalary("Epsilon", 5)==1);
    assert (network->paySalary("VOID", 5)==0);
    assert (network->paySalary("Alfa", 5)==0);
    assert (network->paySalary("Epsilon", 4)==0);
    network->printAllShopData("Epsilon");

    cout<<'\t'<<"*TESTS FOR CHANGESALARY*"<<endl;
    assert (network->changeSalary(4, 10)==1);
    assert (network->changeSalary(999, 100000)==0);
    assert (network->changeSalary(4, -220)==0);
    assert (network->changeSalary(5, 1000.7777)==1);
    network->printEmployeeList();

    cout<<'\t'<<"*TESTS FOR GIVERAISE*"<<endl;
    assert (network->giveRaise(4, 50)==1);
    assert (network->giveRaise(999, 50)==0);
    assert (network->giveRaise(4, -50)==0);
    assert (network->giveRaise(5, 10.111)==1);
    network->printEmployeeList();

    cout<<'\t'<<"*TESTS FOR ADDITEM*"<<endl;
    assert (network->addItem("Epsilon", 1, "Bottle", 2.99, 3)==1);
    assert (network->addItem("Epsilon", 2, "Chair", 100, 1)==1);
    assert (network->addItem("Void", 10, "Bottle", 2.99, 3)==0);
    assert (network->printInventory("Epsilon")==1);
    assert (network->removeItem("Epsilon", 2, 1)==1);
    assert (network->addItem("Epsilon", 3, "Sth", 0, 3)==0);
    assert (network->addItem("Epsilon", 3, "Drill", 150.888, 4)==1);
    assert (network->addItem("Epsilon", 65, "Sth", 888, -11)==0);
    assert (network->printInventory("Epsilon")==1);
    assert (network->addItem("Epsilon", 1, "DIFFERENT", 2.99, 3)==0);
    assert (network->addItem("Epsilon", 1, "Bottle", 7.99, 3)==1);
    assert (network->printInventory("Epsilon")==1);

    cout<<'\t'<<"*TESTS FOR REMOVEITEM*"<<endl;
    assert (network->removeItem("Epsilon", 1)==1);
    assert (network->removeItem("VOID", 1)==0);
    assert (network->removeItem("Epsilon", 1)==1);
    assert (network->removeItem("Epsilon", 999)==0);
    assert (network->removeItem("Epsilon", 1, 0)==0);
    assert (network->removeItem("Epsilon", 1, 999)==0);
    assert (network->printInventory("Epsilon")==1);
    assert (network->removeItem("Epsilon", 1, 4)==1);
    assert (network->printInventory("Epsilon")==1);

    cout<<'\t'<<"*TESTS FOR BUYITEM*"<<endl;
    network->printCustomerList();
    assert (network->buyItem("Epsilon", 10, 3)==0);
    assert (network->buyItem("VOID", 10, 3)==0);
    assert (network->assignCustomer("Epsilon", 10)==1);
    network->printAllShopData("Epsilon");
    assert (network->buyItem("Epsilon", 10, 3, 2)==1);
    assert (network->buyItem("Epsilon", 10, 3)==1);
    assert (network->buyItem("Epsilon", 10, 999)==0);
    assert (network->buyItem("Epsilon", 999, 3)==0);
    assert (network->buyItem("Epsilon", 10, 3, 0)==0);
    assert (network->buyItem("Epsilon", 10, 3, 1)==1);
    network->printAllShopData("Epsilon");
    assert (network->assignCustomer("Alfa", 10)==1);
    assert (network->addItem("Alfa", 1, "Keyboard", 199.99, 2)==1);
    assert (network->buyItem("Alfa", 10, 1, 1)==0);
    assert (network->addItem("Epsilon", 4, "Golden statue", 9999, 1)==1);
    assert (network->buyItem("Epsilon", 10, 4, 1)==0);
    network->printAllShopData("Epsilon");

    cout<<'\t'<<"*TESTS FOR CHANGEITEMPRICE*"<<endl;
    assert (network->changeItemPrice("Alfa", 1, 300.1111)==1);
    assert (network->changeItemPrice("VOID", 1, 999)==0);
    assert (network->changeItemPrice("Alfa", 999, 1)==0);
    assert (network->changeItemPrice("Alfa", 1, 0)==0);
    network->printInventory("Alfa");

    cout<<'\t'<<"*TESTS FOR CHANGEMONEY1*"<<endl;
    assert (network->changeMoney(10, 880.7676)==1);
    assert (network->changeMoney(999, 880)==0);
    assert (network->changeMoney(10, -880)==0);
    network->printCustomerList();

    cout<<'\t'<<"*TESTS FOR CHANGEMONEY2*"<<endl;
    assert (network->changeMoney("Alfa", 20)==1);
    assert (network->changeMoney("VOID", 880)==0);
    assert (network->changeMoney("Alfa", -880)==0);
    network->printShopList();

    cout<<'\t'<<"*TESTS FOR UPDATEMONEY1*"<<endl;
    assert (network->updateMoney(10, 1000.8888)==1);
    assert (network->updateMoney(999, 880)==0);
    assert (network->updateMoney(10, -500)==1);
    assert (network->updateMoney(10, -50000)==0);
    network->printCustomerList();

    cout<<'\t'<<"*TESTS FOR UPDATEMONEY2*"<<endl;
    assert (network->updateMoney("Alfa", 1000.8888)==1);
    assert (network->updateMoney("VOID", 880)==0);
    assert (network->updateMoney("Alfa", -500)==1);
    assert (network->updateMoney("Alfa", -50000)==0);
    network->printShopList();

    cout<<'\t'<<"*TESTS FOR CHANGESHOPNAME*"<<endl;
    assert(network->changeShopName("Alfa", "NewAlfa")==1);
    assert(network->changeShopName("VOID", "NewVOID")==0);
    assert(network->changeShopName("NewAlfa", "Epsilon")==0);
    network->printShopList();

    cout<<'\t'<<"*TESTS FOR ALL PRINTING METHODS*"<<endl;
    network->printShopList();
    assert (network->printShopListOfEmployee(4)==1);
    assert (network->printShopListOfEmployee(999)==0);
    assert (network->printShopListOfCustomer(10)==1);
    assert (network->printShopListOfCustomer(999)==0);
    network->printEmployeeList();
    assert (network->printEmployeeList("Epsilon")==1);
    assert (network->printEmployeeList("VOID")==0);
    network->printCustomerList();
    assert (network->printCustomerList("Epsilon")==1);
    assert (network->printCustomerList("VOID")==0);
    assert (network->printInventory("Epsilon")==1);
    assert (network->printInventory("VOID")==0);
    network->printAllShopData();
    assert (network->printAllShopData("Epsilon")==1);
    network->printAllNetworkData();
    


    cout<<"All tests passed"<<endl;
    return 0;
}
