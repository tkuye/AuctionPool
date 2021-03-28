#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>

using namespace std;

class Product {

    private:
    int idealPrice; 
    string productName;
    string ownerId;
    int auctionPrice;
    bool inAuction; 
    public:
    int sellPrice;
    Product(string id); 
    void getInAuction(bool status); 
    void setOwnerId(string id);
    void setProductName(string name);
    string getProductName();
    int getIdealPrice();
    void changeIdealPrice(int price);
    void changeAuctionPrice(int price);
    int profitAmount(); 
    int setSellPrice();
};


#endif