#pragma once
#include <vector>
#include<cmath>
#include <iostream>

#include "Process.h"
#include<queue>
#include <string>

using namespace std;

class PhysicalMemory{

    private:
    int frames = 128;// 2048 bytes
    queue<Process> processesInMemory;

    public:
    //Asign
    //Replace
    //Show

    void assignProcessFifo(Process process){
        int processFrames = ceil(process.getBytes()/16);
        if(processFrames > 128){
            cout << process.getProcess()  << " Process too large!" << endl;
        }else{
            if(frames - processFrames >= 0){
                processesInMemory.push(process);
                cout << process.getProcess() << " Added to memory!" << endl;
                frames-= processFrames;
            }else{
                 cout << process.getProcess()  << " Does not fit, replacement policy on the way" << endl;
                 Process aux = processesInMemory.front();
                 int auxFrames = ceil(aux.getBytes()/16);
                 int procFrames = ceil(process.getBytes()/16);

                 //35 <= 31
                if(procFrames <= auxFrames){
                    processesInMemory.pop();
                    frames+= auxFrames;  
                    frames-= ceil(process.getBytes()/16);
                    processesInMemory.push(process);
                    cout << process.getProcess() << " Added to memory!" << endl;
                }else{
                    bool flag = true;
                    while(flag){
                        cout << processesInMemory.front().getProcess() << " Removed!" << endl;
                        processesInMemory.pop();
                        aux = processesInMemory.front();
                        auxFrames += ceil(aux.getBytes()/16);
                        if(!(auxFrames < procFrames)){
                            cout << processesInMemory.front().getProcess() << " Removed!" << endl;
                            processesInMemory.pop();
                            flag = false;
                        }
                         
                    }

                    frames = frames + auxFrames;
                    frames = frames - ceil(process.getBytes()/16);
                    processesInMemory.push(process);

                    cout << process.getProcess() << " Added to memory!" << endl;
                }
            }
        }


    }

    void showProcessesFifo(){
        cout << "Process in list " << endl;
        while(!processesInMemory.empty()){
            cout << "("<<processesInMemory.front().getProcess() <<")" << "(" << ceil(processesInMemory.front().getBytes()/16) << " frames used" << ")"<<  endl;
            processesInMemory.pop();
        }

        cout << "Frames: " << frames << endl;
    }

};