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
        cout << "Welcome to your Dashboard " << name << "!" << endl; 
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
        cout << "7. Add products\n8. Start auction\n9. Add products to pool" << endl; 
        if (user->getType()== 1) 
        cout << "7. Join auction" << endl; 
        
        cout << "Enter 999 to Quit" << endl;
        cout << "> "; 
        cin.clear(); 
        cin >> userInput; 
        cout << "\n"; 
        bool buyer = false; 

        string poolName; 
        int accountAdd; 
        int productCount; 
        string prodName; 
        int prodPrice; 
        
        switch (userInput){

            case 1:
                if (user->getType() == 1){
                    //joinAPool(); 
                    if (pools.getSize() == 0){
                        cout << "Sorry, there are no pools available to join. ";
                    }
                    else {
                        
                        cout << "Which pool would you like to join?" << endl; 
                        pools.showPools(user->cashAmount()); 
                        cout << "\n"; 
                        
                        cout << "Type the pool name you would like to join > "; 
                        cin >> poolName; 
                        bool foundPool = false;
                        if (poolName == user->getCurrentPool()->getPoolName()){
                            cout << "You are already apart of the pool " << poolName << "." << endl; 
                        }
                        else{

                        
                        for (Pool * pool : pools.pools){
                            if (pool->getPoolName() == poolName){
                                user->joinPool(pool);
                                pool->addUser();
                                foundPool = true; 
                                break;
                            }

                        }
                        if (!foundPool) {
                            cout << "There is no pool with the name " << poolName << endl; 
                        }
                        }

                    }   
                    buyer = true; 
                }
                else if (user->getType() == 2){
                    //createAPool(); 
                    
                   
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
                    cout << "Product ideal price: $" << p->getIdealPrice() << endl; 
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
             
            case 7:
                
                productCount = 1;
                cout << "How many products would you like to add? > "; 
                if (!productCount || productCount < 0){
                    cout << "Not a valid amount!" << endl; 
                    break; 
                }
                cin >> productCount;
                
                
                for (int i = 0; i < productCount; i++){
                    cout << "Please enter the product name > "; 
                    cin >> prodName; 
                    cout << endl; 

                    cout << "Please enter the product's ideal selling price > "; 
                    cin >> prodPrice; 
                    if (!prodPrice || prodPrice < 0){
                        cout << "Not a valid price! Cannot add product" << endl;
                        
                    }
                    else{
                        user->addProduct(prodName, prodPrice); 
                        cout << "Added your product: " << prodName << endl; 
                    }
                   
                }

                break; 
            
            case 9:
            if (!user->getCurrentPool())
                break;

                user->getCurrentPool()->addAuctionProducts(); 
                cout << "Added products to the pool." << endl; 
                break;
            case 999:
                current = true; 
                cout << "Goodbye for now!" << endl; 
                break; 
            default:
                cout << "Not a valid input. " << endl; 
                break;
        }


        
        
    }
    


}

#endif 