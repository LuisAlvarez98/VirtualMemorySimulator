vector<Pagina*> Fifo::eliminarPaginas(int cantidad){

    vector<Pagina*> paginasModificadas;

    for(int i = 0; i < cantidad; i ++){
        Pagina* pagina = queuePaginas.front();
        queuePaginas.pop();
        

        //tablaDePaginas en ese indice == NULL
        tablaDePaginas.set(pagina->getMarcoPagina(), NULL);
        //updatear contenido dentro de la misma pagina
        pagina->setMarcoPagina(-1);
        pagina->setBitResidencia(0);
        //mandar pagina a memoriaDisco
        bool asignada = false;
        for(int i = 0; i < memoriaDisco.getMemoria().size() && !asignada; i++){
            if(memoriaDisco.lugarVacio(i)){
                pagina->setMemoriaDisco(i);
                memoriaDisco.getMemoria()[i] = pagina;
                paginasModificadas.push_back(pagina);
                asignada = true;
                //Swap out
                countSwaps++;
                 //Timestamp
                timestamp++;
            }
        }
        //validar que disco no este lleno.
        if(!asignada){
            cout << "Error: Disco lleno." << endl;
        }

             
    }

    return paginasModificadas;
}