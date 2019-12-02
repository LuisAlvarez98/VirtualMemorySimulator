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

    int getProceso(){
        return this->proceso;
    }
    int getNumPagina(){
        return this->numPagina;    
    }

    int getMarcoPagina(){
        return this->marcoPagina;
    }

    void setMarcoPagina(int marcoPagina){
        this->marcoPagina = marcoPagina;
    }

    bool isMemoriaReal(){
        return this->bitResidencia;
    }

    bool isMemoriaDisco(){
        return !this->bitResidencia;
    }

    void setBitResidencia(int bit){
        this->bitResidencia = bit;
    }

    void setMemoriaDisco(int lugar){
        this->memoriaDisco = lugar;
    }
};