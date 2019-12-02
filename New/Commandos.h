#include <vector>
#include "Globals.h"
#include "Proceso.h"
//#include "Pagina.h"
//tratar de mandar namespace y includes a main, u otro doc
using namespace std;
using namespace globals;

class Commandos {

    private:

    public:
    
    Commandos () {}

    void P(int iN, int iP) {

        vector<Pagina*> paginasModificadas;
        //crear proceso P con n bytes
        Proceso proceso(iN, iP);
        //asignar proceso a MemporiaReal
        // si hay espacio, metelo
        if(tablaDePaginas.paginasVacias() < proceso.getNumPaginas()){
            if(algoritmo == FIFO){
            paginasModificadas = fifo.eliminarPaginas(proceso.getNumPaginas() - tablaDePaginas.paginasVacias());

            }else if(algoritmo == LRU){

                // LRU.swap() 
            }
        }
        
        int paginasAsignadas = 0;
        //inserta proceso
        for(int i = 0; i < TAMANO_TABLA_PAGINAS && paginasAsignadas < proceso.getNumPaginas(); i++){
            if(tablaDePaginas.paginaVacia(i)){

                //crea una pagina
                Pagina* pagina = new Pagina(proceso.getProceso(), paginasAsignadas+1, 1, i, -1);
                //updatear tabla de paginas
                tablaDePaginas.set(i, pagina);
                //agregar a paginas del proceso
                proceso.agregarPagina(*pagina);
                //Se manda la pagina a la queue
                queuePaginas.push(*pagina);
                paginasAsignadas++;
            }
        }

        //insertar proceso a lista de procesos
        listaProcesos.getProcesos().push_back(proceso);

        //imprimir la lista de paginas
        cout << "Lista de paginas: ";
        for(int i = 0; i < proceso.getNumPaginas(); i++){
            cout << proceso.getPagina(i).getMarcoPagina() << ", ";
        }
        cout << endl;

        if(paginasModificadas.size() > 0){
            cout << "Paginas reemplazadas:" << endl;
        }

        for(int i = 0; i < paginasModificadas.size(); i ++){
            cout << "proceso: " << paginasModificadas[i]->getProceso() << ", numero de pagina: " << paginasModificadas[i]->getNumPagina() << ", ubicacion en disco: " << paginasModificadas[i]->getMemoriaDisco() << endl;
        }

    }

    void A(int iD, int iP, int iM){
        
        int pagina = iD / TAMANO_PAGINA;
        int offset = iD % TAMANO_PAGINA;

        Proceso proceso = listaProcesos.getProceso(iP);

        if(proceso.getPagina(pagina).isMemoriaReal()){

            //si no es la ultima pagina
            if(proceso.getPagina(pagina).getNumPagina() < proceso.getNumPaginas()){
                int memoriaReal = proceso.getPagina(pagina).getMarcoPagina() * TAMANO_PAGINA + offset;
                cout << "La direccion de memoria real es: " << memoriaReal << endl; 
            }else{
                //validar el offset
                if(offset > proceso.getBytes() % TAMANO_PAGINA){
                    //error: Fragmentacion interna
                }else{
                    int memoriaReal = proceso.getPagina(pagina).getMarcoPagina() * TAMANO_PAGINA + offset;
                    cout << proceso.getPagina(pagina).getMarcoPagina() << " " << offset;
                    cout << "La direccion de memoria real es: " << memoriaReal << endl;
                }
            }
    
        }else{
            //donde estaba
            //donde quedo en memoriaReal
            //proceso y numPagina pertenecia, donde quedo en swapping
        }
        

    }



};