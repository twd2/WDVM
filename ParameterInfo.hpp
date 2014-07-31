#ifndef _PARAMETERINFO_H_
#define _PARAMETERINFO_H_

#include <cstdio>
#include "type.hpp"
#include "BinaryHelper.hpp"

#define Param_Register 0
#define Param_Int 1
#define Param_Float 2

class ParameterInfo
{
    private:
        
    public:
        ParameterInfo();
        ~ParameterInfo();
        int type;
        cpubasetype value;
        double value_float;
        static ParameterInfo Read(FILE *);
};

#endif //_PARAMETERINFO_H_
