#include <vector>
//tratar de mandar namespace y includes a main, u otro doc
using namespace std;

class Pagina {

    private:
        int proceso;
        int numPagina;
        int bitResidencia;
        int marcoPagina;
        int memoriaDisco;
    public:    
    Pagina(int proceso, int numPagina, int bitResidencia, int marcoPagina, int memoriaDisco) {
        this->proceso = proceso;
        this->numPagina = numPagina;
        this->bitResidencia = bitResidencia;
        this->marcoPagina = marcoPagina;
        this->memoriaDisco = memoriaDisco;
    }

    int getNumPagina(){
        return this->numPagina;    
    }

    int getMarcoPagina(){
        return this->marcoPagina;
    }

    bool isMemoriaReal(){
        return this->marcoPagina != -1;
    }

    bool isMemoriaDisco(){
        return this->memoriaDisco != -1;
    }
};