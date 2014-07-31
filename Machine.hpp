#ifndef _MACHINE_H_
#define _MACHINE_H_

#include <cstdio>
#include "type.hpp"
#include "CPU.hpp"
#include "Memory.hpp"

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?(-(a)):(a))

class Machine
{
    private:
        
    public:
        bool isRunning;
        int DebugLevel;
        Memory memory;
        CPU cpu;
        FILE *hdd;
        Machine();
        Machine(int);
        Machine(Memory& );
        Machine(CPU& , Memory& );
        ~Machine();
        void load(FILE *);
        bool load(const char *);
        void run();
        //void AddInterrupt();
        //void OnInterrupt(int);
};

#endif //_MACHINE_H_

