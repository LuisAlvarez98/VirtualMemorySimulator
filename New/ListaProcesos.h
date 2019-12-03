#include <vector>
#include "Proceso.h"
//tratar de mandar namespace y includes a main, u otro doc
using namespace std;

class ListaProcesos {

    private:
        vector<Proceso*> procesos;
    public:    
    ListaProcesos () {
        procesos = vector<Proceso*>();
    }

    Proceso* getProceso(int numProceso){

        for(int i = 0; i < procesos.size(); i++){

            if(procesos[i]->getProceso() == numProceso){
                return procesos[i];
            }
        }

    }

    vector<Proceso*>& getProcesos(){
        return procesos;
    }

};