#ifndef POOL_H
#define POOL_H
#include <iostream>
#include "products.h"
using namespace std;

class Pool {
    
    public:
    int poolId; 
    string auctioneerId; 
    string poolName;
    int numberOfUsers;
    int numberOfProducts;
    int currentBid; 
    Product * currentProduct;
    // Need to add timer function
    Pool(string id); 
    //void destroyPool(); //
    void setCurrentProduct(Product * product);
    void setCurrentBid(int bid);
    int getCurrentBid();
    Product * getCurrentProduct();
};

#endif