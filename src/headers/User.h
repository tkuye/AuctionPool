#ifndef NEW_USER_H
#define NEW_USER_H
#include <vector>
#include "products.h"
#include "Pool.h"
#include<iostream>

class Pool;
class Product;
using namespace std;

class User{
    private:
    int cash;
    string name;
    Pool * currentPool; 
    string ownerId; 
    // Type 1 is for buyer, Type 2 is for Seller
    int userType; 
    static User * user; 
    public:
    vector <Product*> products; 
    User(int startCash, string username); 
    void setCash(unsigned int value);
    int allIn(); 
    int getCash(int value);
    int cashAmount();
    void joinPool(Pool * pool);
    void leavePool();
    void changeName(string name);
    void showName(); 
    void setType(int type);
    int getType();
    Pool * getCurrentPool();
    string getOwnerId();
    Product* addProduct(string name, int price);
    
};

#endif