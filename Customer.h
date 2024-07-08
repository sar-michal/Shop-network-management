#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"
//customer data;
class Customer: public Person{
    float money;
     //can't be lower than 0; decimal digits can't be lower than 0.01
public:
    Customer(string name, float money=0);
     //constructor; money defaults to 0;
    ~Customer();
     //destructor
    float getMoney() const;
     //returns money
    void changeMoney(float newMoney);
     /*Changes the stored amount of money;*/
    bool updateMoney(float amount);
     /*Lowers or increases the amount of money based on the amount;
       if this operation would result in negative money balance it fails
       and returns 0; returns 1 if successful*/
    void print();
     //prints customer data
};
#endif // CUSTOMER_H
