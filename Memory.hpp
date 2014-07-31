#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <vector>
#include "type.hpp"
#include "InstructionInfo.hpp"

using namespace std;

class Memory
{
    private:
        
    public:
        int Size, MaxAddress, IntOffset, FloatOffset;
        cpubasetype *intdata;
        double *floatdata;
        vector<InstructionInfo> program;
        Memory(int);
        ~Memory();
};

#endif //_MEMORY_H_
