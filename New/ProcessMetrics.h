class ProcessMetrics{
    private:
    int timestamp;
    int process;
    int turnaround;
    int pagefaults;
    int frames;
    public:
    ProcessMetrics(){
        timestamp = 0;
        process = 0;
        frames = 0;
        turnaround = 0;
        pagefaults = 0;
    }
    int getProcess(){
        return this->process;
    }
    int getTurnaround(){
        return this->turnaround;
    }
     int getFrames(){
        return this->frames;
    }

    int getPageFaults(){
        return this->pagefaults;
    }
    void setFrames(int frames){
        this->frames = frames;
    }
    void setProcess(int process){
        this->process = process;
    }
    void setTurnaround(int turnaround){
        this->turnaround = turnaround;
    }
    void setPageFaults(int pagefaults){
        this->pagefaults = pagefaults;
    }
};