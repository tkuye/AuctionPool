#ifndef NEW_USER_H
#define NEW_USER_H

#include<iostream>
#include <vector>

using namespace std;

class User{
    private:
    int cash;
    string name;
    int * currentPool; 
    vector <string*> products; 
    public:
    User(int startCash, string username); 
    void setCash(unsigned int value);
    int allIn(); 
    int getCash(int value);
    void cashAmount();
    void joinPool(int pool);
    void leavePool();
    void changeName(string name);
    void showName(); 
};

#endif