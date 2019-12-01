/*
    C++ File used to declare util functions
*/
#include <iostream>
#include "../Headers/Files.h"
#include <fstream>
#include <climits>
#include <vector>
#include <string>
#include "../Headers/Process.h"
#include "../Headers/PhysicalMemory.h"
#include <unordered_map>
using namespace std;

class Util
{
    //instance variables
private:
    int option;                //option is used to set an option in the menu
    bool isTerminated = false; //determines if the app isTerminated

    vector<Process> processes;

    PhysicalMemory physicalMemory;

    unordered_map<int, pair<int, int>> LRUMap;
    int swa[256] = {0};
    int mp[128] = {0};
    int iPageFaults = 0;
    int iTimeStamp = 0;
    int iLibre = 128;
    int iSwaps = 0;
    int iC = 0;
    int iTime = 0;

public:
    //Funciones para imprimir resultados
    void imprimirArreglo()
    {
        cout << "--ARREGLO--" << endl;
        for (int i = 0; i < 128; i++)
        {
            cout << " " << mp[i] << endl;
        }
    }

    void imprimirSwap()
    {
        cout << "--SWAP ARRAY--" << endl;
        for (int i = 0; i < 256; i++)
        {
            cout << " " << swa[i] << endl;
        }
    }

    void imprimirMapa()
    {
        cout << "--MAPA--" << endl;
        for (auto it = LRUMap.begin(); it != LRUMap.end(); ++it)
        {
            cout << " " << it->first << ":" << it->second.first << "-" << it->second.second << endl;
        }
    }

    //Funcion para mostrar la direccion real, dada la direccion virtual
    int mostrarDireccionReal(int iP, int iD)
    {
        int iContR = 0;
        int iContP = 0;
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                if (iContP == iD)
                {
                    return iContR;
                }
                iContR++;
                if (mp[i] == iP)
                {
                    iContP++;
                }
            }
        }
        return 0;
    }

    //Funcion para liberar un proceso
    void liberaProceso(int iP)
    {
        int temp = -1;
        int mayor = -1;
        int iC = 0;
        int iC2 = 0;
        int j;
        for (j = 0; j < 128; j++)
        {
            if (mp[j] == iP)
            {
                if (iC == 0)
                {
                    temp = j;
                    iC++;
                }
                if (mp[j + 1] != iP)
                {
                    if (iC2 == 0)
                    {
                        mayor = j;
                        iC2++;
                    }
                }
            }
        }
        if (temp != -1)
        {
            cout << "Se liberan los marcos de página de memoria real: " << temp << " - " << mayor << endl;
        }

        //Elimina proceso del arreglo
        for (int i = 0; i < 128; i++)
        {
            if (mp[i] == iP)
            {
                iLibre++;
                mp[i] = 0;
                LRUMap.erase(i);
            }
        }

        temp = -1;
        mayor = -1;
        iC = 0;
        iC2 = 0;

        //Se liberan marcos de página del arreglo de swapping en caso de que el proceso se encuentre ahí
        for (j = 0; j < 96; j++)
        {
            if (swa[j] == iP)
            {
                if (iC == 0)
                {
                    temp = j;
                    iC++;
                }
                if (swa[j + 1] != iP)
                {
                    if (iC2 == 0)
                    {
                        mayor = j;
                        iC2++;
                    }
                }
            }
        }
        if (temp != -1)
        {
            cout << "Se liberan los marcos " << temp << " - " << mayor << " del área de swapping" << endl;
        }

        for (int i = 0; i < 96; i++)
        {
            if (swa[i] == iP)
            {
                swa[i] = 0;
            }
        }
    }

    //Funciona para realizar el swap con LRU
    void swapLru(int iN, int iP)
    {
        int index = 0;
        int temp3 = 0;

        iC = ceil(iN / 16.0);
        int iMin = INT_MAX;
        for (int i = 0; i < iC; i++)
        {
            //Trae la última posición del mapa
            unordered_map<int, pair<int, int>>::iterator lastElement;
            for (auto it = LRUMap.begin(); it != LRUMap.end(); ++it)
            {
                if (it->second.second < iMin)
                {
                    lastElement = it;
                    iMin = it->second.second;
                }
            }

            //Swap
            swa[lastElement->first] = lastElement->second.first;
            mp[lastElement->first] = iP;
            LRUMap.erase(lastElement->first);
            LRUMap.insert(make_pair(lastElement->first, make_pair(iP, iTime)));
            iSwaps++;
        }
    }

    bool procesoEnMemoria(int iP)
    {
        for (auto it = LRUMap.begin(); it != LRUMap.end(); ++it)
        {
            if (it->second.first == iP)
            {
                it->second.second = iTime;
                return false;
            }
        }
        return true;
    }

    //Funcion para colocar un proceso
    void colocarProceso(int iN, int iP)
    {
        iC = ceil(iN / 16.0);
        iTimeStamp += iC;
        int n = iN;

        //Si hay espacio libre en el arreglo para colocar el proceso
        if (iLibre >= iC)
        {
            iLibre -= iC;
            for (int i = 0; i < 128; i++)
            {
                if (mp[i] == 0 && iC > 0)
                {
                    mp[i] = iP;
                    LRUMap.insert(make_pair(i, make_pair(iP, iTime)));
                    iC--;
                }
            }

            int temp = -1, mayor = -1;
            int iC = 0;
            int iC2 = 0;
            int j;
            for (j = 0; j < 128; j++)
            {
                if (mp[j] == iP)
                {
                    if (iC == 0)
                    {
                        temp = j;
                        iC++;
                    }
                    if (mp[j + 1] != iP)
                    {
                        if (iC2 == 0)
                        {
                            mayor = j;
                            iC2++;
                        }
                    }
                }
            }
            cout << "Se asignaron los marcos de página " << temp << " - " << mayor << " al proceso " << iP << endl;
        }
        //Si no hay espacio libre en el arreglo para colocar el proceso, se utiliza LRU
        else
        {
            swapLru(iN, iP);
        }
    }

    //Funciones para la llamadas de comandos
    void caseP(int iN, int iP)
    {
        cout << "P " << iN << " " << iP << endl;
        cout << "Asignar " << iN << " bytes al proceso " << iP << endl;
        if (procesoEnMemoria(iP))
        {
            colocarProceso(iN, iP);
        }
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
            cout << "Se modificó la dirección " << iD << " del proceso " << iP << endl;
        }
        int result = mostrarDireccionReal(iP, iD);
        cout << "Dirección virtual: " << iD << " Direccion real: " << result << endl;
        iTimeStamp++;
    }

    void caseL(int iP)
    {
        cout << "L " << iP << endl;
        cout << "Liberar los marcos de página ocupados por el proceso " << iP << endl;
        iTimeStamp++;
        liberaProceso(iP);
    }
    /*
        start method:
        runs the main menu
    */
    void start()
    {
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
                //runFifo();
                readFile(option);
                break;
            case 2:
                //runLRU();
                readFile(option);
                break;
            case 3:
                readFile(option);
                //runBoth();
                //run
                break;
            case 4:
                isTerminated = true;
                break;
            }
        }
    }
    /*
     Read file method
    */
    int readFile(int option)
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
            return 0;
        }

        while (file >> cOpc)
        {
            switch (cOpc)
            {
            //Comment case
            case 'C':
                getline(file, sReplica);
                cout << sReplica << endl;
                iTimeStamp++;
                break;
            //Add process
            case 'P':
                file >> iN >> iP;
                if (option == 1)
                {
                }
                else if (option == 2)
                {
                    caseP(iN, iP);
                }
                else
                {
                }
                iTime++;
                break;
            //Access virtual memory
            case 'A':
                file >> iD >> iP >> iM;
                if (option == 1)
                {
                }
                else if (option == 2)
                {
                    caseA(iD, iP, iM);
                }
                else
                {
                }
                break;
            //Free pages from process
            case 'L':
                file >> iP;
                if (option == 1)
                {
                }
                else if (option == 2)
                {
                    caseL(iP);
                }
                else
                {
                }
                break;
            //End of commands
            case 'F':
                cout << 'F' << endl;
                break;
            //Exit
            case 'E':
                if (option == 1)
                {
                }
                else if (option == 2)
                {
                    imprimirArreglo();
                    imprimirMapa();
                    imprimirSwap();
                }
                else
                {
                }

                break;
            }
        }
    };
};