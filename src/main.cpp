#include<iostream>
#include "headers/setAuction.h"
#include <map>
#include "headers/newUser.h"
#include "headers/products.h"
using namespace std;



int main(int argc, char *argv[]) 
{
User cashName(0, "none"); 
string name = getName();
cashName = setupBuyer(name);
cashName.cashAmount();
cashName.setCash(24);
cashName.showName(); 
cashName.cashAmount();
cashName.setType(1);
cashName.getType();
return 0;
}
