# Shop Network Management Application

A shop network management application created for the purpose of the EOOP university course. It functions as a database for a network of second-hand shops. Utilizes object-oriented programming concepts such as polymorphism, inheritance, and encapsulation.

## Overview of the Project

A data bank stores information about the crucial aspects of shop management. It contains a list of shops, their inventory, employees, and customers. It provides a wide range of functionality such as:

- Management of multiple shops
- Storing data specific to each category (money, names, IDs, salary)
- General operations (selling items, management of lists, modifying shop data)
- Various operations on employees (hiring, firing, raising salary, modifying personal information)
- Various operations on customers (adding, removing, modifying data)
- Various operations on the inventory (adding items, removing items, modifying data)
- Presenting all data

It is additionally equipped with preventative measures against illegal data operations.

## Memory Map
![Memory_map](https://github.com/user-attachments/assets/5a7f7048-60d2-48f4-8078-84e06b034923)

## Class and Data Structures Overview

There exist the following classes: `ShopNetwork`, `SecondHandShop`, `Person`, `Employee`, `Customer`, `Item`. There also exist two-directional lists which can store an unlimited amount of data. They correspond to each category of the `ShopNetwork` (`shopList`, `employeeList`, `customerList`, `inventory`).

### ShopNetwork

- It is the class which interacts with the user. It offers a wide range of operations on the other classes. It contains a list of all employees, customers, and shops in the network. It has the ability to modify these lists and pass data to the other classes. It offers a variety of printing operations. It also identifies and corrects incorrect arguments given by the user.

### SecondHandShop

- It serves as a way to navigate through all the functionality of a particular shop. It contains the lists specific to each shop: `customerList`, `employeeList`, and the `inventory`. It has the ability to add and remove elements from them. It can also perform operations such as modifying all the data within classes assigned to it and printing it. It additionally stores the name of the shop which serves as a way to identify it.

### Person

- It is the base class of `Employee` and `Customer`. It contains a name, `personID`, and a list of pointers to `SecondHandShop`. It is equipped with the ability to easily create unique IDs for those classes. The IDs are always incremented by 1. ID serves as a primary method of identification.

### Employee

- Inherited from the `Person` class. It adds salary to the arguments from the `Person` class. The `SecondHandShop` uses this class and data contained within to properly pay salaries. Such operations result in the reduction of a particular shop’s money. A single employee can be assigned to multiple shops.

### Customer

- Inherited from the `Person` class. It adds money to the arguments from the `Person` class. Customers can buy items contained in the inventory. Such operations have an effect on the money of the shop and the customer. A single customer can be assigned to multiple shops.

### Item

- It is the class which contains data about a particular item (`itemID`, `itemName`, `price`, `quantity`). The inventory (a list of `Item` objects) provides customers with the knowledge of items for purchase. This data is exclusive to every shop.

## Restrictions, Limits, Assumptions

1. Money, salary, and raise percentage cannot be lower than 0 or contain decimal digits lower than 0.01. Numbers that don’t meet the second condition are rounded to the closest viable number.
2. Operations which would result in a negative money balance are not carried out (e.g. paying salary, buying items).
3. Customers and employees always have unique IDs. Each consecutive ID is incremented by 1.
4. Shop names have to be unique.
5. Each employee can work at max 3 shops. It can be adjusted upon shop creation.
6. Customers can’t buy items from shops they are not assigned to.
7. Customers can’t buy items if there are no employees assigned to the shop.
8. Two items from the same shop can’t have the same `itemID`. Adding items with the same `itemID` and name results in the increase in quantity and change in price.
9. Item quantity can’t be lower than 0 (ignores operations which would result in such a state). If quantity drops to 0, the item is removed from the list.
10. Item price can’t be lower than 0.01 or contain decimal digits lower than 0.01.
