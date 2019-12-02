#include "TablaDePaginas.h"
#include "Globals.h"

using namespace globals;

 TablaDePaginas::TablaDePaginas () {
    tabla = vector<int>(TAMANO_TABLA_PAGINAS, -1);
}

int TablaDePaginas::paginasVacias(){

    int paginasVacias = 0;

    for(int i = 0; i < TAMANO_TABLA_PAGINAS; i++){
        if(tabla[i] == -1) paginasVacias++;
    }

    return paginasVacias;
}

bool TablaDePaginas::paginaVacia(int pagina){

    return this->tabla[pagina] == -1;
}