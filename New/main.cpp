#include "Globals.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Files.h"

using namespace std;
using namespace globals;

bool isTerminated = false;
int option; 

int readFile()
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
            break;
        //Add process
        case 'P':
            file >> iN >> iP;
            cout << iN << endl;
            break;
        //Access virtual memory
        case 'A':
            file >> iD >> iP >> iM;

            break;
        //Free pages from process
        case 'L':
            file >> iP;

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
            readFile();
            //runFifo();
            break;
        case 2:
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