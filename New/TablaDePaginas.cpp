TablaDePaginas::TablaDePaginas () {
    tabla = vector<Pagina*>(TAMANO_TABLA_PAGINAS, NULL);
}

int TablaDePaginas::paginasVacias(){

    int paginasVacias = 0;

    for(int i = 0; i < TAMANO_TABLA_PAGINAS; i++){
        if(tabla[i] == NULL) paginasVacias++;
    }

    return paginasVacias;
}

bool TablaDePaginas::paginaVacia(int pagina){

    return this->tabla[pagina] == NULL;
}

void TablaDePaginas::set(int indice, Pagina* pagina){

    this->tabla[indice] = pagina;
}