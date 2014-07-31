#include "main.hpp"

void OnInterrupt(void * obj)
{
    CPU& cpu=*(CPU *)obj;
    switch(cpu.InterruptId)
    {
        case 5:
            putchar(cpu.eax);
            break;
        case 9:
            cpu.eax=getchar();
            break;
        default:
            break;
    }
}

int main()
{
    Machine m;
    if(!m.load("a.bin"))
    {
        printf("Open Failed\n");
        return 1;
    }
    printf("Read succ\n");
    m.cpu.AddInterrupt(5, OnInterrupt);
    m.cpu.AddInterrupt(9, OnInterrupt);
    m.cpu.AddInterrupt(3, OnInterrupt);
    m.cpu.AddInterrupt(1, OnInterrupt);
    m.cpu.AddInterrupt(13,OnInterrupt);
    m.run();
    printf("Exit\n");
    return 0;
}
