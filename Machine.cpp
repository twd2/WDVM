#include "Machine.hpp"

Machine::Machine() : memory(2*1024), cpu(memory)
{

}
Machine::Machine(Memory& memory) : cpu(memory), memory(memory)
{
}
Machine::Machine(CPU& cpu, Memory& memory) : cpu(cpu), memory(memory)
{
}
Machine::~Machine()
{
}

void Machine::load(FILE *fd)
{
    int icount=bh_readint32(fd);
    for(int i=0;i<icount;++i)
    {
        //printf("R%d\n", i);
        memory.program.push_back(InstructionInfo::Read(fd));
        //printf("INS%d ", memory.program[i].ID);
    }
}
bool Machine::load(const char *fn)
{
    FILE *fd;
    if(!(fd=fopen(fn,"rb")))
    {
        return false;
    }
    load(fd);
    fclose(fd);
    return true;
}

void Machine::run()
{
    isRunning=true;
    cpu.start();
    while(isRunning && cpu.isRunning)
    {
        cpu.ClockTick();
    }
}
/*
void Machine::AddInterrupt()
{
    cpu.AddInterrupt(5, OnInterrupt);
    cpu.AddInterrupt(9, OnInterrupt);
    cpu.AddInterrupt(3, OnInterrupt);
    cpu.AddInterrupt(1, OnInterrupt);
    cpu.AddInterrupt(13,OnInterrupt);
}

void Machine::OnInterrupt(int id)
{
    switch(id)
    {
        case 5:
            putchar(cpu.eax);
        default:
            break;
    }
}
*/
