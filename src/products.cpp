#include<iostream>
#include "headers/products.h"

using namespace std;

Product::Product(string id){
    ownerId = id; 
}

void Product::setOwnerId(string id){
    ownerId = id;
}

void Product::changeAuctionPrice(int price){
    auctionPrice = price;
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

