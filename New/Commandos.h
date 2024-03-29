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

        if(iN > 2048){
            cout << "Tamano de proceso demasiado grande." << endl;
            return;
        }


        vector<Pagina*> paginasModificadas;
        //crear proceso P con n bytes
        Proceso* proceso = new Proceso(iN, iP, timestamp,-1, 0);
        //asignar proceso a MemporiaReal
        // si hay espacio, metelo
        if(tablaDePaginas.paginasVacias() < proceso->getNumPaginas()){
            if(algoritmo == FIFO){
            paginasModificadas = fifo.eliminarPaginas(proceso->getNumPaginas() - tablaDePaginas.paginasVacias());
                
            }else if(algoritmo == LRU){

                // LRU.swap() 
            }
        }
        
        int paginasAsignadas = 0;
        //inserta proceso
        for(int i = 0; i < TAMANO_TABLA_PAGINAS && paginasAsignadas < proceso->getNumPaginas(); i++){
            if(tablaDePaginas.paginaVacia(i)){
                
                //crea una pagina
                Pagina* pagina = new Pagina(proceso->getProceso(), paginasAsignadas+1, 1, i, -1);
                //updatear tabla de paginas
                tablaDePaginas.set(i, pagina);
                //agregar a paginas del proceso
                proceso->agregarPagina(pagina);
                //Se manda la pagina a la queue
                queuePaginas.push(pagina);
                paginasAsignadas++;
                //Timestamp
                timestamp++;
                //Swap in
                countSwaps++;
            }
        }

        //insertar proceso a lista de procesos
        listaProcesos.getProcesos().push_back(proceso);

        //imprimir la lista de paginas
        cout << "Lista de paginas: ";
        for(int i = 0; i < proceso->getNumPaginas(); i++){
            cout << proceso->getPagina(i)->getMarcoPagina() << ", ";
        }
        cout << endl;

        if(paginasModificadas.size() > 0){
            cout << "Paginas reemplazadas:" << endl;
        }

        for(int i = 0; i < paginasModificadas.size(); i ++){
            countSwaps++;
             //Timestamp
            timestamp++;
            cout << "proceso: " << paginasModificadas[i]->getProceso() << ", numero de pagina: " << paginasModificadas[i]->getNumPagina() << ", ubicacion en disco: " << paginasModificadas[i]->getMemoriaDisco() << endl;
        }

    }

    void A(int iD, int iP, int iM){
        
        int pagina = iD / TAMANO_PAGINA;
        int offset = iD % TAMANO_PAGINA;
        Proceso* proceso = listaProcesos.getProceso(iP);
        if(proceso == NULL){
            cout << "No existe el proceso requerido." << endl;
            return;
        }
        if(proceso->getPagina(pagina)->isMemoriaReal()){

            //si no es la ultima pagina
            if(proceso->getPagina(pagina)->getNumPagina() < proceso->getNumPaginas()){
                int memoriaReal = proceso->getPagina(pagina)->getMarcoPagina() * TAMANO_PAGINA + offset;
                cout << "La direccion de memoria real es: " << memoriaReal << endl; 
            }else{
                //validar el offset
                if(offset > proceso->getBytes() % TAMANO_PAGINA){
                    //error: Fragmentacion interna
                    cout << "Error: la direccion virtual es incorrecta (Fragmentacion Interna)" << endl;
                }else{
                    int memoriaReal = proceso->getPagina(pagina)->getMarcoPagina() * TAMANO_PAGINA + offset;
                    cout << proceso->getPagina(pagina)->getMarcoPagina() << " " << offset;
                    cout << "La direccion de memoria real es: " << memoriaReal << endl;
                }
            }
    
        }else{
            vector<Pagina*> paginasModificadas;
           Pagina* aptPagina = proceso->getPagina(pagina);

            if(algoritmo == FIFO){
                if(tablaDePaginas.paginasVacias() == 0){
                    paginasModificadas = fifo.eliminarPaginas(1);
                }

            }else if(algoritmo == LRU){


            }

            for(int i = 0; i < TAMANO_TABLA_PAGINAS; i++){
                if(tablaDePaginas.paginaVacia(i)){
                    aptPagina->setMarcoPagina(i);
                    aptPagina->setBitResidencia(1);
                    //updatear tabla de paginas
                    tablaDePaginas.set(i, aptPagina);
                    //Se manda la pagina a la queue
                    queuePaginas.push(aptPagina);
                    //Timestamp
                    timestamp++;
                    //Swap in
                    countSwaps++;
                }
            }
            //donde estaba
            cout << "Ubicacion de la pagina en el disco: " << aptPagina->getMemoriaDisco() << endl;
            
            //eliminarla del disco
            memoriaDisco.getMemoria()[aptPagina->getMemoriaDisco()] = NULL;
            
            aptPagina->setMemoriaDisco(-1);

            //donde quedo en memoriaReal
            cout << "Ahora se encuentra en el marco de pagina: " << aptPagina->getMarcoPagina() << endl;
            //proceso y numPagina pertenecia, donde quedo en swapping
            if(paginasModificadas.size() > 0){
                cout << "Se ha swappeado por la pagina " << paginasModificadas[0]->getNumPagina() << " del proceso " << paginasModificadas[0]->getProceso() << "." << endl;
                //Contar swaps
                cout << "Esta pagina ahora se encuentra en el disco, en el marco: " << paginasModificadas[0]->getMemoriaDisco() << endl;
            }

            
        }
        

    }

    void L(int iP){
        Proceso* proceso;
        vector<int> paginasMod;
        vector<int> paginasModDisco;
        proceso = listaProcesos.getProceso(iP);

        if(proceso->getBorrado()){
            cout << "Este proceso ya fue borrado." << endl;
            return;
        }

        for(int i = 0; i < proceso->getNumPaginas(); i++){
            if(proceso->getPagina(i)->isMemoriaReal()) {
                paginasMod.push_back(proceso->getPagina(i)->getMarcoPagina());
                tablaDePaginas.set(proceso->getPagina(i)->getMarcoPagina(), NULL);
                proceso->setPagina(i,NULL);
                timestamp+=0.1;
                //ver si podemos borrar la queue
            } else {
                paginasModDisco.push_back(proceso->getPagina(i)->getMemoriaDisco());
                memoriaDisco.getMemoria()[proceso->getPagina(i)->getMemoriaDisco()] = NULL;
                proceso->setPagina(i,NULL);
                timestamp+=0.1;
            }
        }
        proceso->setBorrado(1);
        proceso->setTiempoFinal(timestamp);

        if(paginasMod.size() > 0) {
            cout << "Las paginas eliminadas en memoria real fueron :" << endl;
            for(int i = 0; i < paginasMod.size(); i++){
                cout << paginasMod[i] << ", ";
            }
            cout << endl;
        }
        if(paginasModDisco.size() > 0){
            cout << "Las paginas eliminadas en disco fueron :" << endl;
            for(int i = 0; i < paginasModDisco.size(); i++){
                cout << paginasModDisco[i] << ", ";
            }
            cout << endl;
        }
    }

};