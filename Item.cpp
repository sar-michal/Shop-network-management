#include "Item.h"
Item::Item(int itemID, string itemName, float price, int quantity)
{
    this->itemID = itemID;
    this->itemName = itemName;
    this->price = price;
    this->quantity = quantity;
}
//constructor
Item::~Item()
{

}
//destructor
int Item::getItemID() const
{
    return itemID;
}
//returns itemID
string Item::getItemName() const
{
    return itemName;
}
//returns itemName
float Item::getPrice() const
{
    return price;
}
//returns price
int Item::getQuantity() const
{
    return quantity;
}
//returns quantity
void Item::changePrice(float newPrice)
{
    price = newPrice;
}
//changes price;
void Item::changeQuantity(int quantity)
{
    this->quantity = quantity;
}
//changes quantity
bool Item::updateQuantity(int amount)
{
    if(quantity + amount >= 0)
    {
        quantity = quantity + amount;
        return 1;
    }
    return 0;
}
/*Lowers or increases quantity based on the amount; returns 0 if
 this operation would result in negative quantity; returns 1 if successful*/
void Item::print()
{
    cout<<"> "<<itemID<<" "<<itemName<<" | price: "<<price<<" | quantity: "<<quantity<<endl;
}
//prints item data
