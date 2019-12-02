#include <vector>
//tratar de mandar namespace y includes a main, u otro doc
using namespace std;
using namespace globals;

class TablaDePaginas {

    private:
        vector<int > tabla;
    public:
    
    TablaDePaginas () {
        tabla = vector<int>(TAMANO_TABLA_PAGINAS, -1);
    }

    int paginasVacias(){

        int paginasVacias = 0;

        for(int i = 0; i < TAMANO_TABLA_PAGINAS; i++){
            if(tabla[i] == -1) paginasVacias++;
        }

        return paginasVacias;
    }

};