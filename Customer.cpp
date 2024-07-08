#include "Customer.h"
#include "Person.h"
Customer::Customer(string name, float money /*=0*/): Person(name)
{
    this->money = money;
}
//constructor; money defaults to 0;
Customer::~Customer()
{
    for (list<SecondHandShop*>::iterator it=shopList.begin(); it!=shopList.end(); ++it)
    {
         (*it)->removeCustomer(getPersonID());
    }
}
//destructor
float Customer::getMoney() const
{
    return money;
}
//returns money
void Customer::changeMoney(float newMoney)
{
    this->money = newMoney;
}
/*Changes the stored amount of money;*/
bool Customer::updateMoney(float amount)
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
void Customer::print()
{
    Person::print();
    cout<<" | money: "<<money<<endl;
}
//prints customer data
