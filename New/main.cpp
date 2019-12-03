#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include "Files.h"
#include "Commandos.h"
#include "Proceso.cpp"
#include "TablaDePaginas.cpp"
#include "Fifo.cpp"
#include "MemoriaDisco.cpp"
using namespace std;

ListaProcesos globals::listaProcesos;
TablaDePaginas globals::tablaDePaginas;
queue<Pagina*> globals::queuePaginas;
Fifo globals::fifo;
MemoriaDisco globals::memoriaDisco;

Commandos commandos;

//Funciones para la llamadas de comandos
void caseP(int iN, int iP)
{
    cout << "P " << iN << " " << iP << endl;
    cout << "Asignar " << iN << " bytes al proceso " << iP << endl;
    commandos.P(iN, iP);
}

void caseA(int iD, int iP, int iM)
{
    cout << "A " << iD << " " << iP << " " << iM << endl;
    if (iM == 0)
    {
        cout << "Obtener la dirección real correspondiente a la dirección virtual " << iD << " del proceso " << iP << endl;
    }
    if (iM == 1)
    {
        cout << "Obtener la dirección real correspondiente a la dirección virtual " << iD << " del proceso " << iP << " y modificar dicha dirección" << endl;
        //cout << "Se modificó la dirección " << iD << " del proceso " << iP << endl;
    }
    commandos.A(iD, iP, iM);
}
void caseL(int iP){
    cout << "L " << iP << endl;
    cout << "Liberar los marcos de página ocupados por el proceso " << iP << endl;
    commandos.L(iP);
}
void readFile()
{
    Files flag;
    ifstream file;
    int del;
    int iD, iN, iP, iM;
    string sReplica;
    char cOpc;
    //vector<int> bytes;
    //vector<int> process;
    string archivo, line;
    cout << "Dame un archivo" << endl;
    cin >> archivo;
    //intenta abrir el archivo si no existe termina el programa
    if (!(flag.tryOpen(archivo, file)))
    {
        cout << "El archivo no existe o esta vacio" << endl;
        return;
    }

    while (file >> cOpc)
    {
        switch (cOpc)
        {
        //Comment case
        case 'C':
            getline(file, sReplica);
            cout << "C" << sReplica << endl;
            break;
        //Add process
        case 'P':
            file >> iN >> iP;
            caseP(iN, iP);
            break;
        //Access virtual memory
        case 'A':
            file >> iD >> iP >> iM;
            caseA(iD, iP, iN);
            break;
        //Free pages from process
        case 'L':
            file >> iP;
            caseL(iP);
            break;
        //End of commands
        case 'F':
            cout << 'F' << endl;
            break;
        //Exit
        case 'E':

            break;
        }
    }

}
void start()
{
    bool isTerminated = false;
    int option; 
    //Runs the menu until the user types any option
    while (!isTerminated)
    {
        cout << "Please select an option of the menu: " << endl;
        cout << "[1] FIFO" << endl;
        cout << "[2] LRU" << endl;
        cout << "[3] FIFO and LRU algorithms" << endl;
        cout << "[4] Exit" << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            algoritmo = FIFO;
            readFile();
            //runFifo();
            break;
        case 2:
            algoritmo = LRU;
            readFile();
            //runLRU();
            break;
        case 3:
            //run
            break;
        case 4:
            isTerminated = true;
            break;
        }
    }
}

int main(){

    
    start();

    return 0;
}