#ifndef USER_HOME_H
#define USER_HOME_H
#include<map>
#include<iostream>
#include "headers/User.h"
#include "headers/Pool.h"
#include "headers/setAuction.h"
#include "headers/Pools.h"
using namespace std;

// Function to determine os to clear screen on boot
void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

// Function for setting up the user home page
void createHome() {
    // Create Main Header
    Clear(); 
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl; 
    cout << "|                  AUCTION POOL                   | " << endl; 
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl; 
    Pools pools; 
    string name = getName();
    User * user = setupBuyer(name);
    // Create Function While Loop 
    bool current = false; 
    int userInput; 
    while (!current){
        
        cout << "\n************************************" << endl; 
        cout << "Welcome to your dashboard " << name << "!" << endl; 
        cout << "************************************" << endl; 
        cout << "What would you like to do?: " << endl;
        if (user->getType() == 2){
        cout << "1. Create a new pool" << endl; 
        
        }

        else if (user->getType() == 1){
        cout << "1. Join a pool" << endl; 
        }
        cout << "2. View my current products" << endl; 
        cout << "3. Switch my type" << endl; 
        cout << "4. View current pools" << endl; 
        cout << "5. Add money to your account" << endl; 
        cout << "6. View current account balance" << endl; 
        if (user->getType()== 2) 
        cout << "7. Add products\n8. Start auction" << endl; 
        if (user->getType()== 1) 
        cout << "7. Join auction" << endl; 
        cout << "> "; 
        cin.clear(); 
        cin >> userInput; 
        cout << "\n"; 
        bool buyer = false; 
        switch (userInput){

            case 1:
                if (user->getType() == 1){
                    //joinAPool(); 
                    buyer = true; 
                }
                else if (user->getType() == 2){
                    //createAPool(); 
                    
                    string poolName; 
                    cout << "What would you like to name your pool?: ";
                    cin >> poolName; 
                    pools.createPool(user, poolName);
                    buyer = false; 
                    cin.get(); 
                }
                break; 
            case 2:
                
                cout << "Here are your current products: " << endl; 
                for (Product * p : user->products ){
                    cout << "Product name: " << p->getProductName() << endl; 
                    cout << "Product ideal price: " << p->getIdealPrice() << endl; 
                }
                cin.get(); 
                break;
            case 3:
            
                cout << "Switching type!" << endl;
                
                if (user->getType()  == 1){
                    user->setType(user->getType() + 1);
                }
                else{
                    user->setType(user->getType()-1);
                };
                cin.get(); 
                break;
            case 4:
                
                pools.showPools(); 
                cin.get(); 
                break; 
            case 5:
           
            int accountAdd; 
                cout << "How much money would you like to add to your account?: "; 
                cin >> accountAdd; 
                if (!accountAdd || accountAdd < 0){
                    cout << "Not a valid amount!" << endl; 
                }
                else{
                    user->setCash(accountAdd);
                }
                cin.get(); 
                break; 
            case 6:
                
                cout << "Your current account balance is: $" << user->cashAmount() << "."  << endl; 
                cin.get(); 
                break; 
            default:
                cout << "Not a valid input. " << endl; 
                break; 

        }


        
        
    }
    


}

#endif 