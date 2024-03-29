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
    double tiempoCreado;
    double tiempoFinal;
    int bitModificacion;
    int numPaginas;
    vector<Pagina*> paginas;
    bool borrado;
public:
    
    Proceso();

    Proceso(int bytes, int numProceso, double tiempoCreado, double tiempoFinal, bool borrado);
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
    void setTiempoCreado(double tC);
    void setTiempoFinal(double tF);
    double calculaTurnaround();
    double getTiempoFinal();
    double getTiempoCreado();

    int getNumPaginas();
    /*
        setProceso method
    */
   bool getBorrado();

   bool setBorrado(int valor);

    void setProceso(int numProceso);
    /*
        setBytes methods
    */
    void setBytes(int bytes);

    void agregarPagina(Pagina* pagina);

    Pagina* getPagina(int pagina);

    void setPagina(int indice, Pagina* pagina);
};