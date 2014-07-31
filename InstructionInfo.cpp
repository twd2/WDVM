#include "InstructionInfo.hpp"

InstructionInfo::InstructionInfo()
{

}
InstructionInfo::~InstructionInfo()
{
    //printf("~II");
}
InstructionInfo InstructionInfo::Read(FILE *fd)
{
    InstructionInfo ii;
    ii.ID=bh_readuint16(fd);
    ii.pcount=bh_readbyte(fd);
    for(int i=0;i<ii.pcount;++i)
    {
        ii.pi.push_back(ParameterInfo::Read(fd));
    }
    return ii;
}
