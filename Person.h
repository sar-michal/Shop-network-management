#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <list>
using namespace std;
class SecondHandShop;
class Person{
    static int id;
     //serves as a counter for personID; increments by 1 after Person creation
    int personID;
     //ID of a person; unique - increments of 1; serves as a way to identify
    string name;
     //the name of the person; not unique
protected:
    list<SecondHandShop*> shopList;
     //list of pointers to the SecondHandShop class
public:
    Person(string name);
     //constructor;
    ~Person();
     //destructor
    int getPersonID() const;
     //returns personID
    string getName() const;
     //returns name
    void updateName(string newName);
     //updates the name
    void joinShop(SecondHandShop* shop);
     //adds a pointer to shop; does nothing if shop=nullptr
    void leaveShop(SecondHandShop* shop /*string shopName*/);
     //removes a pointer to shop; does nothing if shop doesn't exist
    void print();
     //prints person data
    void printShopNames();
     //prints names of all shops person belongs to
};
#endif // PERSON_H
