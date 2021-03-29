#include <vector>
#include "headers/Pool.h"
#include "headers/Pools.h"
#include "headers/User.h"
using namespace std;

void Pools::addPool(Pool * pool) {
    pools.push_back(pool);
}

Pool * Pools::createPool(User * user, string name){
    Pool * pool = new Pool(user, name);
    addPool(pool);
    pool->addUser();
    user->joinPool(pool);
    return pool;
}

void Pools::destroyPool(int id){
    int i; 
    for (Pool * pool : pools){
        if (pool->poolId == id){
            pools.erase(pools.begin() + i);  
            delete pool;
            pool = nullptr;
            break;
        }
        i++; 
    }
}

// current args is to filter to only show pools within a certain price range
void Pools::showPools(int current){
    if (current == 0){
    for (Pool * pool : pools){
        cout << "Pool Name: " << pool->poolName << endl;
        cout << "Number of Users in Pool: "<< pool->numberOfUsers << endl;
        cout << "Numbe of Products in Pool: " << pool->numberOfProducts << endl;
    }
    }
    else {
        for (Pool * pool : pools){
        if (pool->currentBid < current){
            cout << "Pool Name: " << pool->poolName << endl;
            cout << "Number of Users in Pool: "<< pool->numberOfUsers << endl;
            cout << "Numbe of Products in Pool: " << pool->numberOfProducts << endl;
        }
    }
    }; 
}
