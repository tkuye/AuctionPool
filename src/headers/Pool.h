#ifndef POOL_H
#define POOL_H
#include <iostream>
#include <vector>
#include "User.h"
#include "products.h"


using namespace std;

class User;
class Product;

class Pool {
    
    public:
    int poolId; 
    User * auctioneer; 
    string poolName;
    int numberOfUsers;
    int numberOfProducts;
    int currentBid; 
    Product * currentProduct;
    vector<Product*> products;
    // Need to add timer function
    Pool(User * auctioneer, string name); 
    // Sets the current product and removes from the product vector
    void setCurrentProduct();
    void setCurrentBid(int bid);
    int getCurrentBid();
    Product * getCurrentProduct();
    void addUser();
    void removeUser();
    string getPoolName();
    void addAuctionProducts();
    void listProducts();
};

#endif