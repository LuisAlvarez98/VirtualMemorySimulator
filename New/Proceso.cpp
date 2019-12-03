Proceso::Proceso() {}
/*
    Constructor that recieves bytes and proceso
*/
Proceso::Proceso(int bytes, int numProceso, double tiempoCreado, double tiempoFinal, bool borrado)
{
    this->numProceso = numProceso;
    this->tiempoCreado = tiempoCreado;
    this->tiempoFinal = tiempoFinal;
    this->borrado = borrado;
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
void Proceso::setTiempoCreado(double tC){
    this->tiempoCreado = tC;
}
double Proceso::getTiempoFinal(){
    return this->tiempoFinal;
}
double Proceso::getTiempoCreado(){
    return this->tiempoCreado;
}
void Proceso::setTiempoFinal(double tF){
    this->tiempoFinal = tF;
}
double Proceso::calculaTurnaround(){
    return tiempoFinal - tiempoCreado;
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

bool Proceso::getBorrado(){
    return this->borrado;
}
/*
    setProceso method
*/
void Proceso::setProceso(int numProceso)
{
    this->numProceso = numProceso;
}

bool Proceso::setBorrado(int valor){
    this->borrado = valor;
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
void Proceso::setPagina(int indice, Pagina* pagina){
    this->paginas[indice] = pagina;
}