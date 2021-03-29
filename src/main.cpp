#include <iostream>
#include <map>

#include "headers/setAuction.h"
#include "headers/User.h"
#include "headers/products.h"
#include "headers/Pools.h"
#include "headers/Pool.h"

using namespace std;


int main(int argc, char *argv[]) {
Pools pools; 
string name = getName();
User * cashName = setupBuyer(name);
cashName->cashAmount();
cashName->setCash(24);
cashName->showName(); 
cashName->cashAmount();
cashName->setType(2);
cashName->getType();
pools.createPool(cashName, "toastclub");

pools.showPools(); 

return 0;
}
