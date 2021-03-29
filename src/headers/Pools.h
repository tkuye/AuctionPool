#include <vector>
#include "Pool.h"

using namespace std;

class Pools {
    private:
    void addPool(Pool * pool); 
    public:
        vector <Pool*> pools;
        Pool * createPool(string Auid); 
        void destroyPool(int id); 
        void showPools(int current); 
};
