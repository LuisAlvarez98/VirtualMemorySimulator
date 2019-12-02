#include "TablaDePaginas.h"
#include <queue>

using namespace std;

namespace globals {

    const static int TAMANO_PAGINA = 16;
    const int TAMANO_MEMORIA_REAL = 2048;
    const int TAMANO_MEMORIA_DISCO = 4096;
    const int TAMANO_TABLA_PAGINAS = 128;


    enum Algoritmo : int {FIFO, LRU} algoritmo;
    
    TablaDePaginas tablaDePaginas();
    queue<int> queueMarcoPaginas();
};

