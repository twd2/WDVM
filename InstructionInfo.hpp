#ifndef _INSTRUCTIONINFO_H_
#define _INSTRUCTIONINFO_H_

#include <vector>
#include "type.hpp"
#include "BinaryHelper.hpp"
#include "ParameterInfo.hpp"

using namespace std;

class InstructionInfo
{
    private:
        
    public:
        InstructionInfo();
        ~InstructionInfo();
        static InstructionInfo Read(FILE *);
        unsigned short ID;
        char pcount;
        vector<ParameterInfo> pi;
};

#endif
