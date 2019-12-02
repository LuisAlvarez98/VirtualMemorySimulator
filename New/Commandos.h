#include <vector>
#include "Globals.h"
#include "Proceso.h"

//tratar de mandar namespace y includes a main, u otro doc
using namespace std;
using namespace globals;

class Commandos {

    private:

    public:
    
    Commandos () {

    }

    void P(int iN, int iP) {

        //crear proceso P con n bytes
        Proceso proceso(iN, iP);
        //asignar proceso a MemporiaReal
        // si hay espacio, metelo
        if(tablaDePaginas.paginasVacias() < proceso.getNumPaginas()){
            if(algoritmo == FIFO){

            //FiFo.swap(proceso.getNumPaginas() - tablaDePaginas.paginasVacias()); elimina paginas de acuerdo al algoritmo
            //FIFO.swap()

            }else if(algoritmo == LRU){

                // LRU.swap() 
            }
        }
        
        //inserta proceso

        queueMarcoPaginas.push(numMarcoPagina);


    }



};