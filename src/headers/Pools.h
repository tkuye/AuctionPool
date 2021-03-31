#include <vector>
#include "Pool.h"
#include "User.h"
using namespace std;

class Pools {
    private:
    void addPool(Pool * pool); 
    public:
        vector <Pool*> pools;
        Pool * createPool(User * user, string name); 
        void destroyPool(int id); 
        void showPools(int current=0); 
        int getSize();
};
