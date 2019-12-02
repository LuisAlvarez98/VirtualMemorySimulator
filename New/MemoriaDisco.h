#include <vector>
#include "Globals.h"
//tratar de mandar namespace y includes a main, u otro doc
using namespace std;
using namespace globals;

class MemoriaDisco {

    private:
        vector<char> memoria;
    public:
    
    MemoriaDisco () {
        memoria = vector<char>(TAMANO_MEMORIA_DISCO, 0);
    }


};