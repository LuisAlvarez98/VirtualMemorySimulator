#include <vector>
#include "Globals.h"
//tratar de mandar namespace y includes a main, u otro doc
using namespace std;
using namespace globals;
/*
struct MemoriaReal {

    char memoria;

    struct MemoriaReal* siguiente;

};
*/
class MemoriaReal {

    private:
        vector<char> memoria;
    public:
    
    MemoriaReal () {
        memoria = vector<char>(TAMANO_MEMORIA_REAL, 0);
    }


};