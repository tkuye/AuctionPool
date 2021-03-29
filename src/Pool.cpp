#include "headers/Pool.h"
#include "headers/products.h"

#include <iostream>

Pool::Pool(string id) {
    auctioneerId = id;
    
}


void Pool::setCurrentProduct(Product* product){
     currentProduct = product;
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
