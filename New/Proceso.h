#include <cmath>
#include <vector>
#include "Globals.h"
#pragma once
/*
    Proceso Class
*/

using namespace globals;

class Proceso
{
private:
    int numProceso;
    int bitResidencia;
    int bytes;
    int bitModificacion;
    int numPaginas;
    vector<int> paginas;
public:
    
    Proceso() {}
    /*
        Constructor that recieves bytes and proceso
    */
    Proceso(int bytes, int numProceso)
    {
        this->numProceso = numProceso;
        setBytes(bytes);
        this->bitResidencia = 0;
    }
    /*
        getnumProceso method
        return proceso
    */
    int getProceso()
    {
        return numProceso;
    }
    /*
        getBytes method
        return bytes
    */
    int getBytes()
    {
        return bytes;
    }

    int getNumPaginas(){
        return numPaginas;
    }
    /*
        setProceso method
    */
    void setProceso(int numProceso)
    {
        this->numProceso = numProceso;
    }
    /*
        setBytes methods
    */
    void setBytes(int bytes)
    {
        this->bytes = bytes;
        this->numPaginas = ceil(bytes * 1.0/TAMANO_PAGINA);
    }

    void agregarPagina(int pagina){

        this->paginas.push_back(pagina);
    }

    int get(int pagina){
        return this->paginas[pagina];
    }
};