Proceso::Proceso() {}
/*
    Constructor that recieves bytes and proceso
*/
Proceso::Proceso(int bytes, int numProceso)
{
    this->numProceso = numProceso;
    setBytes(bytes);
}
/*
    getnumProceso method
    return proceso
*/
int Proceso::getProceso()
{
    return numProceso;
}
/*
    getBytes method
    return bytes
*/
int Proceso::getBytes()
{
    return bytes;
}

int Proceso::getNumPaginas(){
    return numPaginas;
}
/*
    setProceso method
*/
void Proceso::setProceso(int numProceso)
{
    this->numProceso = numProceso;
}
/*
    setBytes methods
*/
void Proceso::setBytes(int bytes)
{
    this->bytes = bytes;
    this->numPaginas = ceil(bytes * 1.0/TAMANO_PAGINA);
}

void Proceso::agregarPagina(Pagina* pagina){

    this->paginas.push_back(pagina);
}

Pagina* Proceso::getPagina(int pagina){
    return this->paginas[pagina];
}