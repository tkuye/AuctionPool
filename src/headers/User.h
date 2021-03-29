#ifndef NEW_USER_H
#define NEW_USER_H

#include "products.h"
#include "Pool.h"
#include<iostream>
#include <vector>

using namespace std;

class User{
    private:
    int cash;
    string name;
    Pool * currentPool; 
    string ownerId; 
    // Type 1 is for buyer, Type 2 is for Seller
    int userType; 
    vector <Product*> products; 
    public:
    
    User(int startCash, string username); 
    void setCash(unsigned int value);
    int allIn(); 
    int getCash(int value);
    void cashAmount();
    void joinPool(Pool * pool);
    void leavePool();
    void changeName(string name);
    void showName(); 
    void setType(int type);
    int getType();
    Product* addProduct(string name, int price);
};

#endif