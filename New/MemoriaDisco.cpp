MemoriaDisco::MemoriaDisco () {
    memoria = vector<Pagina*>(TAMANO_MEMORIA_DISCO / TAMANO_PAGINA, NULL);
}

bool MemoriaDisco::lugarVacio(int posicion){

    return memoria[posicion] == NULL;
}
void MemoriaDisco::empty(){
     while(!memoria.empty()){
            memoria.pop_back();
        }
}
vector<Pagina*>& MemoriaDisco::getMemoria() {

    return memoria;
}