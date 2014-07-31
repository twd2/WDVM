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
        case 13:
            //TODO
            break;
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    char defaultFilename[]="a.bin";
    const int defaultMemorysize=2*1024;
    int Memorysize=defaultMemorysize;
    char *Filename=defaultFilename;
    
    if (argc<=1)
    {
        printf("Usage: wdvm filename [memorysize]\n");
        return 1;
    }
    
    if (argc>1)
    {
        //printf("File: %s\n", argv[1]);
        Filename=argv[1];
    }
    
    if(argc>2)
    {
        sscanf(argv[2], "%d", &Memorysize);
        //printf("Memory size: %d\n", Memorysize);
    }
    
    Machine m(Memorysize);
    if(!m.load(Filename))
    {
        printf("Open Failed\n");
        return 1;
    }
    //printf("Read succ\n");
    m.cpu.AddInterrupt(5, OnInterrupt);
    m.cpu.AddInterrupt(9, OnInterrupt);
    //m.cpu.AddInterrupt(3, OnInterrupt);
    //m.cpu.AddInterrupt(1, OnInterrupt);
    m.cpu.AddInterrupt(13,OnInterrupt);
    m.run();
    //printf("Exit\n");
    return 0;
}
