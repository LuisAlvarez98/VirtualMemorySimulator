#include "TablaDePaginas.h"
#include "ListaProcesos.h"
//#include "Pagina.h"
#include "Fifo.h"
#include "MemoriaDisco.h"
using namespace std;

namespace globals {

    const static int TAMANO_PAGINA = 16;
    const int TAMANO_MEMORIA_REAL = 2048;
    const int TAMANO_MEMORIA_DISCO = 4096;
    const int TAMANO_TABLA_PAGINAS = 128;


    enum Algoritmo : int {FIFO, LRU} algoritmo;
    
    extern TablaDePaginas tablaDePaginas;
    extern queue<Pagina> queuePaginas;
    extern ListaProcesos listaProcesos;
    extern Fifo fifo;
    extern MemoriaDisco memoriaDisco;
};

