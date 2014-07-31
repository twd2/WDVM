#include "Memory.hpp"

Memory::Memory(int size) : Size(size)
{
    MaxAddress=Size*2;
    intdata = new cpubasetype[Size];
    floatdata = new double[Size];
    IntOffset=0;
    FloatOffset=Size;
}
Memory::~Memory()
{
    //printf("~Memory\n");
    if (intdata!=NULL)
    {
        //delete [] intdata;
        intdata=NULL;
    }
    if (floatdata!=NULL)
    {
        //delete [] floatdata;
        floatdata=NULL;
    }
    //printf("~Memory.\n");
}
