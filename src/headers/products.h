#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include "User.h"
using namespace std;

class User;
class Pool;

class Product {

    private:
    int idealPrice; 
    string productName;
    User * owner;
    int auctionPrice;
    int productNumber; 
    bool inAuction; 
    public:
    int sellPrice;
    Product(User * owner); 
    void getInAuction(bool status); 
    void changeOwner(User * owner);
    void setProductName(string name);
    string getProductName();
    int getIdealPrice();
    void changeIdealPrice(int price);
    void changeAuctionPrice(int price);
    int profitAmount(); 
    int setSellPrice();
    void setProductNumber(int location);
};


#endif