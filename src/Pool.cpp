#include "headers/Pool.h"
#include "headers/products.h"

#include <iostream>

Pool::Pool(User *auctioneer, string name) {
    this->auctioneer = auctioneer;
    poolName = name;
}


void Pool::setCurrentProduct(){
     currentProduct = products.back();
     products.pop_back();
}

void Pool::setCurrentBid(int bid){
    if (bid <= currentBid){
        cout << "Cannot set bid to equal lower than current bid" << endl; 
    }
    else {
        currentBid = bid;
    }
}

Product* Pool::getCurrentProduct(){
    return currentProduct; 
}

int Pool::getCurrentBid(){
    return currentBid;
}

void Pool::addUser(){
    numberOfUsers++; 
}

void Pool::removeUser(){
    numberOfUsers--; 
}

string Pool::getPoolName(){
    return poolName;
}

void Pool::addAuctionProducts(){
    for(vector<Product *>::iterator it = auctioneer->products.begin(); it != auctioneer->products.end(); ++it) {
        this->products.push_back(*it);
        numberOfProducts++; 
}
}


void Pool::listProducts(){
    unsigned int i = 0;
    for(vector<Product *>::iterator it = this->products.begin(); it != this->products.end(); ++it) {
        cout << ++i << ". " << (*it)->getProductName() << endl;
    }
}