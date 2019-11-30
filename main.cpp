    #include <iostream>
    #include "Headers/Files.h"
    #include <fstream>
    #include <vector>
    #include <string>
    #include "Util/util.h"

    using namespace std;
    int main() 
    {
       //Declaration of util Class to use the util functions 
       Util util;
       //Menu Init
       int option;
       bool isTerminated = false;
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
               util.readFile();
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
        return 0;
    }