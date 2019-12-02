#include <vector>
#include "Globals.h"
#include "Proceso.h"

//tratar de mandar namespace y includes a main, u otro doc
using namespace std;
using namespace globals;

class Commandos {

    private:

    public:
    
    Commandos () {}

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
        
        int paginasAsignadas = 0;
        //inserta proceso
        for(int i = 0; i < TAMANO_TABLA_PAGINAS && paginasAsignadas < proceso.getNumPaginas(); i++){
            if(tablaDePaginas.paginaVacia(i)){
                //updatear tabla de paginas
                tablaDePaginas.set(i, i* TAMANO_PAGINA);
                //agregar a paginas del proceso
                proceso.agregarPagina(i);
                //Se manda la pagina a la queue
                queueMarcoPaginas.push(i);
                paginasAsignadas++;
            }
        }

        //insertar proceso a lista de procesos
        //ListaProcesos.push_back(proceso)
        

        //imprimir la lista de paginas
        cout << "Lista de paginas: ";
        for(int i = 0; i < proceso.getNumPaginas(); i++){
            cout << proceso.get(i) << ', ';
        }
        cout << endl;
        //imprimir lista paginas swappeadas
        // a que proceso y numero de pagina pertenecia
        //donde quedo en el area de swapping


    }



};