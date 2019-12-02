#include <vector>
//tratar de mandar namespace y includes a main, u otro doc

class MemoriaDisco {

    private:
        vector<Pagina*> memoria;
    public:
    MemoriaDisco ();
    bool lugarVacio(int posicion); 
    vector<Pagina*>& getMemoria();
};