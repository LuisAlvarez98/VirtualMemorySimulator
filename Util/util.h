/*
    C++ File used to declare util functions
*/
#include <iostream>
#include "../Headers/Files.h"
#include <fstream>
#include <vector>
#include <string>
#include "../Headers/Process.h"
using namespace std;

class Util{
    //instance variables
    private:
       int option; //option is used to set an option in the menu
       bool isTerminated = false; //determines if the app isTerminated

       vector<Process> processes;

    public:
    /*
        start method:
        runs the main menu
    */
    void start(){
       //Runs the menu until the user types any option 
       while(!isTerminated){
           cout << "Please select an option of the menu: " << endl;
           cout << "[1] FIFO" << endl;
           cout << "[2] LRU" << endl;
           cout << "[3] FIFO and LRU algorithms" << endl;
           cout << "[4] Exit" << endl;

           cin >> option;
           switch(option){
               case 1:
                //runFifo();
               readFile();
               break;   
               case 2:
               //runLRU();
               break;   
               case 3:
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
    int readFile(){
        Files flag;
        ifstream file;
        int del;

      //  vector<int> bytes;
        //vector<int> process;
        string archivo, line;
        cout << "Dame un archivo" << endl;
        cin >> archivo;
        //intenta abrir el archivo si no existe termina el programa
        if(!(flag.tryOpen(archivo, file))){
            cout << "El archivo no existe o esta vacio" << endl;    
            return 0;
        }
        //va leyendo los datos del txt; checa que lo primero tenga una P
        //haciendo referencia al Proceso, la segunda parte hace referencia a los bytes
        //la tercera parte hace referencia al proceso y los mete a cada uno en vectores separados
        // *hace falta realizar verificacion de que lo que se mete al vector es realmente un numero entero
        // *para prevenir fallas
        while(getline(file, line) ) {
            Process process;
            if(line.find("P") != std::string::npos) {
                del = line.find("P");
            }
            line.erase(0,del+2);
            process.setBytes(stoi(line));
            if(line.find(" ") != std::string::npos) {
                del = line.find(" ");
            }
            line.erase(0, del+1);
            process.setProcess(stoi(line));

            processes.push_back(process);
        }
      
      for(int i = 0; i < processes.size();i++){
          cout << processes[i].getProcess() << "\n";
      }
    };
};