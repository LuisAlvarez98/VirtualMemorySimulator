#pragma once
/*
    Process Class
*/
//max size 2048 bytes
class Process
{
private:
    int process;
    int r; //bit
    int bytes;
    int modifyBit;
    int numFrames;
    char dirSecMem;

public:
    /*
        Empty cons
    */
    Process() {}
    /*
        Constructor that recieves bytes and process
    */
    Process(int bytes, int process)
    {
        this->process = process;
        this->bytes = bytes;
        this->r = 0;
    }
    /*
        getProcess method
        return process
    */
    int getProcess()
    {
        return process;
    }
    /*
        getBytes method
        return bytes
    */
    int getBytes()
    {
        return bytes;
    }
    /*
        setProcess method
    */
    void setProcess(int process)
    {
        this->process = process;
    }
    /*
        setBytes methods
    */
    void setBytes(int bytes)
    {
        this->bytes = bytes;
    }
};