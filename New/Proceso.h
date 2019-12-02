#pragma once
#include <cmath>
#include <vector>
/*
    Proceso Class
*/

class Proceso
{
private:
    int numProceso;
    int bytes;
    int bitModificacion;
    int numPaginas;
    vector<Pagina> paginas;
public:
    
    Proceso();
    
    Proceso(int bytes, int numProceso);
    /*
        getnumProceso method
        return proceso
    */
    int getProceso();
    /*
        getBytes method
        return bytes
    */
    int getBytes();

    int getNumPaginas();
    /*
        setProceso method
    */
    void setProceso(int numProceso);
    /*
        setBytes methods
    */
    void setBytes(int bytes);

    void agregarPagina(Pagina pagina);

    Pagina getPagina(int pagina);
};