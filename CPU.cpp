#include "CPU.hpp"

CPU::CPU(Memory& mem) : memory(mem)
{
    eax=ebx=ecx=edx=ebp=esp=ebfp=esfp=eip=0;
    r0=r1=r2=r3=r4=r5=r6=r7=0;
    f0=f1=f2=f3=f4=f5=f6=f7=0.0;
    RanCount=0;
    for(int i=0;i<InterruptCount;++i)
    {
        InterruptVector[i].type=Interrupt_Outer;
        InterruptVector[i].outer_callback=NULL;
    }
}

CPU::~CPU()
{
    //printf("~CPU\n");
}

void CPU::start()
{
    isRunning=true;
    printf("CPU start\n");
}

void CPU::halt()
{
    isRunning=false;
}

void CPU::ClockTick()
{
    if(isRunning) execute();
}

void CPU::execute()
{
    InstructionInfo& ii=memory.program[eip];
    ++eip;
    
    executeInstruction(ii);
    
    ++RanCount;
    //printf("e\n");
}

cpubasetype CPU::getIntValue(ParameterInfo& pi)
{
    if (pi.type==Param_Int)
    {
        return pi.value;
    }
    else
    {
        return getIntRegisterValue(pi.value);
    }
}

double CPU::getFloatValue(ParameterInfo& pi)
{
    if (pi.type==Param_Float)
    {
        return pi.value_float;
    }
    else
    {
        return getFloatRegisterValue(pi.value);
    }
}

void CPU::pushi(cpubasetype num)
{
    ++esp;
    memory.intdata[esp]=num;
}

cpubasetype CPU::popi()
{
    cpubasetype num;
    num=memory.intdata[esp];
    --esp;
    return num;
}

void CPU::pushf(double num)
{
    ++esfp;
    memory.floatdata[esfp]=num;
}

double CPU::popf()
{
    double num;
    num=memory.floatdata[esfp];
    --esfp;
    return num;
}

void CPU::pushreg()
{
    pushi(eax);
    pushi(ebx);
    pushi(ecx);
    pushi(edx);
    pushi(esp);
    pushi(esfp);
    pushi(eip);
    pushi(r0);
    pushi(r1);
    pushi(r2);
    pushi(r3);
    pushi(r4);
    pushi(r5);
    pushi(r6);
    pushi(r7);
    pushf(f0);
    pushf(f1);
    pushf(f2);
    pushf(f3);
    pushf(f4);
    pushf(f5);
    pushf(f6);
    pushf(f7);
}

void CPU::popreg()
{
    f7 = popf();
    f6 = popf();
    f5 = popf();
    f4 = popf();
    f3 = popf();
    f2 = popf();
    f1 = popf();
    f0 = popf();
    r7 = popi();
    r6 = popi();
    r5 = popi();
    r4 = popi();
    r3 = popi();
    r2 = popi();
    r1 = popi();
    r0 = popi();
    eip = popi();
    esfp = popi();
    esp = popi();
    edx = popi();
    ecx = popi();
    ebx = popi();
    eax = popi();
}

void CPU::AddInterrupt(int id, pInterruptCallback pic)
{
    InterruptInfo& ii=InterruptVector[id];
    ii.type=Interrupt_Outer;
    ii.outer_callback=pic;
}

void CPU::Interrupt(int id)
{
    if (!InterruptEnable) return;
    InterruptId=id;
    InterruptInfo& ii=InterruptVector[id];
    if (ii.type==Interrupt_Inner)
    {
        pushi(eip);
        eip=ii.inner_address;
    }
    else
    {
        if (ii.outer_callback != NULL) ii.outer_callback(this);
    }
}
