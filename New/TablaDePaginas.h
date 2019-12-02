#include <vector>
#include "Pagina.h"
//tratar de mandar namespace y includes a main, u otro doc

class TablaDePaginas {

    private:
        vector<Pagina*> tabla;
    public:
    
    TablaDePaginas ();
    int paginasVacias();
    bool paginaVacia(int pagina);
    void set(int indice, Pagina* pagina);
};