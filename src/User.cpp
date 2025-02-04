#include<iostream>
#include <vector>
#include "headers/User.h"
#include "headers/products.h"
#include "headers/Pool.h"
#include "headers/randomNum.h"
#define OWNER_ID_LEN 12

using namespace std;

    
    
    User::User(int startCash, string username){
        cash = startCash;
        name = username;
        ownerId = gen_random(OWNER_ID_LEN); 
    }
    // Add money to the current account. 
    void User::setCash(unsigned int value){
        if (value < 0){
            value = 0; 
        }
        cash += value;
        
        cout << "Cash balance is now equal to $" << cash << "." << endl;
    }
    // Empty all the monet from the account for a bid. 
    int User::allIn() {
        int fullCash = cash;
        cash = 0; 
        cout << "Going all in! Cash is amount is now 0" << endl;
        return fullCash;
    }
    // takes an int argument and removes said amount from the account. 
    int User::getCash(int value){

        if (value > cash){
            cout << "Cash value is greater than what is in the account. "; 
            return -1;
        }
        cash -= value;
        return value;
    }

    // Shows the amount of money in the account.
    int User::cashAmount(){
         return cash;
    }

    // Joins an auction pool 
    void User::joinPool(Pool * pool){
        currentPool = pool;
        cout << "Currently part of pool " << pool->poolName << "."<< endl;
    }

    
    // Leaves an auction pool
    void User::leavePool(){
        delete currentPool; 
        currentPool = nullptr;
        
    }
    // To do: create add product function and remove product and auction product
    Product* User::addProduct(string name, int price){
        Product* product = new Product(this);
        product->changeIdealPrice(price); //
        product->setProductName(name);
        products.push_back(product);
        int prodNum = products.size() - 1;

        product->setProductNumber(prodNum);
        return product;
    };

    void User::changeName(string name){
        this->name = name;
    }
    // Shows the name of the current user. 
    void User::showName(){
        cout << "Name is currently " << name << "." << endl; 
    };
    // Set type of the current user, 1 is for buyer, 2 is for auctioneer
    void User::setType(int type){
        if (!type == 1 || !type == 2)
        cout << "Not a valid type." << endl;
        else {
        userType = type;
        switch (userType) {
            case 1:
            cout << "Current type is now buyer." << endl; 
            break;
            case 2:
            cout << "Current type is now auctioneer." << endl; 
            break;
        };
        }
        
    };

    int User::getType(){
        return userType;
    }
            
    string User::getOwnerId(){
        return ownerId;
    }


Pool * User::getCurrentPool(){
    return currentPool;
}