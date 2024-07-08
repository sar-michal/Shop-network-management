#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <list>
using namespace std;
//Item data;items are exclusive to every shop
class Item{
    int itemID;
     //can't be lower than 1; unique to a specific shop
    string itemName;
    float price;
     //can't be lower than 0.01; can't contain decimal digits lower than 0.01
    int quantity;
     //can't be lower than 1; if set to 0 then Item is removed
public:
    Item(int itemID, string itemName, float price, int quantity);
     //constructor
    ~Item();
     //destructor
    int getItemID() const;
     //returns itemID
    string getItemName() const;
     //returns itemName
    float getPrice() const;
     //returns price
    int getQuantity() const;
     //returns quantity
    void changePrice(float newPrice);
     //changes price;
    void changeQuantity(int quantity);
     //changes quantity
    bool updateQuantity(int amount);
     /*Lowers or increases quantity based on the amount; returns 0 if
      this operation would result in negative quantity; returns 1 if successful*/
    void print();
     //prints item data
};
#endif // ITEM_H
