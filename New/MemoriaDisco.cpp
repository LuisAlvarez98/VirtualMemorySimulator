MemoriaDisco::MemoriaDisco () {
    memoria = vector<Pagina*>(TAMANO_MEMORIA_DISCO / TAMANO_PAGINA, NULL);
}

bool MemoriaDisco::lugarVacio(int posicion){

    return memoria[posicion] == NULL;
}

vector<Pagina*>& MemoriaDisco::getMemoria() {

    return memoria;
}