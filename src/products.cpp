#include<iostream>
#include "headers/products.h"
#include "headers/User.h"
using namespace std;

Product::Product(User * owner){
    this->owner = owner; 
}

void Product::changeOwner(User * owner){
    this->owner = owner;
}

void Product::changeAuctionPrice(int price){
    auctionPrice = price;
}

void Product::setProductName(string name){
    productName = name;
}

string Product::getProductName(){
    return productName;
}

int Product::getIdealPrice() {
    return idealPrice;
}

void Product::changeIdealPrice(int price){
    idealPrice = price;
}

void Product::getInAuction(bool status){
    inAuction = status;
}

int Product::profitAmount(){
    int profit; 
    profit = auctionPrice - sellPrice;
    return profit;
}

int Product::setSellPrice(){
    if (!inAuction){
        sellPrice = auctionPrice; 
        return sellPrice;
    }
    else {
        cout << "Cannot set sell price when " << productName << " is in auction."; 
        return -1;
    }
}

 void Product::setProductNumber(int location){
     productNumber = location;
 }

