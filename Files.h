#ifndef Files_h
#define Files_h
#include <string.h>
#include <fstream>
using namespace std;

 class Files {
 public:
        Files() {}

        // Intenta abrir un archivo
        bool tryOpen(string filename, ifstream &file) {
            file.open(filename);
            if (file.is_open()) {
                return true;
            }
             if(file.peek() == ifstream::traits_type::eof()){
                //el archivo esta vacio
                return false;
    }
            return false;
        }
        //Lee los datos del archivo y los va guardando
 };

#endif