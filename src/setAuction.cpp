#include<iostream>
#include<map>
#include "headers/setAuction.h"
#include "headers/newUser.h"
#include "headers/products.h"
using namespace std;


User setupBuyer(string name){
    
    User userCash(0, "none"); 
    unsigned int cash; 
    cout << "Hello " << name << ", Welcome to AuctionPool!" << endl;
    cout << "Please enter the amount of cash you wish to play with: "; 
    cin >> cash; 
    if (!cash > 0) {
        cout << "Sorry, that is not a valid cash amount!" << endl;
        return userCash;
    }

    cout << "You wish to play with $" << cash << "?" << endl;
    char confirm; 
    cout << "Confirm with y/n: ";

    bool confirmed = false;
    while (!confirmed){
        cin >> confirm;
        if (confirm == 'y') {
            cout << "Your amount of cash has been confirmed. Please continue to select a pool." << endl;
            confirmed = true;

        } else {
            cout << "Sorry, you must restart your setup process." << endl;
            return userCash;
        }
    }

    userCash.setCash(cash);
    userCash.changeName(name);
    return userCash;
}


string getName(){
    string name;
    cout << "Hello There, what is your name?: ";
    cin >> name;
    return name;
}

