#include "Person.h"
#include "SecondHandShop.h"
int Person::id = 0;
Person::Person(string name)
{
    this->name = name;
    personID = ++id;
}
//constructor;
Person::~Person()
{
    shopList.clear();
}
//destructor
int Person::getPersonID() const
{
    return personID;
}
//returns personID
string Person::getName() const
{
    return name;
}
//returns name
void Person::updateName(string newName)
{
    name = newName;
}
//updates the name
void Person::joinShop(SecondHandShop* shop)
{
    if (shop!=nullptr)
    {
        shopList.push_back(shop);
    }
}
//adds a pointer to shop; does nothing if shop=nullptr
void Person::leaveShop(SecondHandShop* shop /*string shopName*/)
{
    //shopList.remove_if([shopName](SecondHandShop* ptr) { return ptr->getShopName() == shopName; });
    shopList.remove(shop);
}
//removes a pointer to shop; does nothing if shop doesn't exist
void Person::print()
{
    cout<<"> "<<personID<<" "<<name;
}
//prints person data
void Person::printShopNames()
{
    for (list<SecondHandShop*>::iterator it=shopList.begin(); it!=shopList.end(); ++it)
        cout <<"> "<<(*it)->getShopName()<<endl;
}
//prints names of all shops person belongs to
