#ifndef _CPU_H_
#define _CPU_H_

#include "type.hpp"
#include "Memory.hpp"
#include "InterruptInfo.hpp"

#define InterruptCount 256

class CPU
{
    private:
        
    public:
        bool InterruptEnable, isRunning;
        InterruptInfo InterruptVector[InterruptCount];
        int RanCount, InterruptId;
        cpubasetype eax, ebx, ecx, edx, ebp, esp, ebfp, esfp, eip;
        cpubasetype r0, r1, r2, r3, r4, r5, r6, r7;
        double f0, f1, f2, f3, f4, f5, f6, f7;
        Memory& memory;
        CPU(Memory&);
        ~CPU();
        void start();
        void halt();
        void ClockTick();
        void execute();
        void executeInstruction(InstructionInfo&);
        void AddInterrupt(int, pInterruptCallback);
        void Interrupt(int);
        void pushi(cpubasetype);
        cpubasetype popi();
        void pushf(double);
        void pushreg();
        void popreg();
        double popf();
        cpubasetype getIntValue(ParameterInfo&);
        double getFloatValue(ParameterInfo&);
        cpubasetype getIntRegisterValue(cpubasetype);
        double getFloatRegisterValue(cpubasetype);
        void setIntRegisterValue(cpubasetype, cpubasetype);
        void setFloatRegisterValue(cpubasetype, double);
};

#endif
