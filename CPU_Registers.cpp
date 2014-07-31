#include "CPU.hpp"

#define CPU_Reg_eax 0
#define CPU_Reg_ax 1
#define CPU_Reg_al 2
#define CPU_Reg_ah 3
#define CPU_Reg_ebx 4
#define CPU_Reg_bx 5
#define CPU_Reg_bl 6
#define CPU_Reg_bh 7
#define CPU_Reg_ecx 8
#define CPU_Reg_cx 9
#define CPU_Reg_cl 10
#define CPU_Reg_ch 11
#define CPU_Reg_edx 12
#define CPU_Reg_dx 13
#define CPU_Reg_dl 14
#define CPU_Reg_dh 15
#define CPU_Reg_esp 16
#define CPU_Reg_sp 17
#define CPU_Reg_ebp 18
#define CPU_Reg_bp 19
#define CPU_Reg_esfp 20
#define CPU_Reg_sfp 21
#define CPU_Reg_ebfp 22
#define CPU_Reg_bfp 23
#define CPU_Reg_eip 24
#define CPU_Reg_ip 25
#define CPU_Reg_r0 26
#define CPU_Reg_r1 27
#define CPU_Reg_r2 28
#define CPU_Reg_r3 29
#define CPU_Reg_r4 30
#define CPU_Reg_r5 31
#define CPU_Reg_r6 32
#define CPU_Reg_r7 33
#define CPU_Reg_f0 34
#define CPU_Reg_f1 35
#define CPU_Reg_f2 36
#define CPU_Reg_f3 37
#define CPU_Reg_f4 38
#define CPU_Reg_f5 39
#define CPU_Reg_f6 40
#define CPU_Reg_f7 41

cpubasetype CPU::getIntRegisterValue(cpubasetype id)
{
    if (id > CPU_Reg_r7) return -222; //is float reg
    if (id == CPU_Reg_ebp) return ebp;
    if (id == CPU_Reg_esp) return esp;
    if (id <= CPU_Reg_esfp)
    {
        if (id <= CPU_Reg_cl)
        {
            if (id <= CPU_Reg_bx)
            {
                if (id <= CPU_Reg_al)
                {
                    if (id <= CPU_Reg_ax)
                    {
                        if (id <= CPU_Reg_eax)
                        {
                            //CPU_Reg_eax
                            return eax;
                        }
                        else
                        {
                            //CPU_Reg_ax
                            return eax&0xFFFF;
                        }
                    }
                    else
                    {
                        //CPU_Reg_al
                        return eax&0xFF;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_ebx)
                    {
                        if (id <= CPU_Reg_ah)
                        {
                            //CPU_Reg_ah
                            return (eax&0xFF00)>>8;
                        }
                        else
                        {
                            //CPU_Reg_ebx
                            return ebx;
                        }
                    }
                    else
                    {
                        //CPU_Reg_bx
                        return ebx&0xFFFF;
                    }
                }
            }
            else
            {
                if (id <= CPU_Reg_ecx)
                {
                    if (id <= CPU_Reg_bh)
                    {
                        if (id <= CPU_Reg_bl)
                        {
                            //CPU_Reg_bl
                            return ebx&0xFF;
                        }
                        else
                        {
                            //CPU_Reg_bh
                            return (ebx&0xFF00)>>8;
                        }
                    }
                    else
                    {
                        //CPU_Reg_ecx
                        return ecx;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_cx)
                    {
                        //CPU_Reg_cx
                        return ecx&0xFFFF;
                    }
                    else
                    {
                        //CPU_Reg_cl
                        return ecx&0xFF;
                    }
                }
            }
        }
        else
        {
            if (id <= CPU_Reg_dh)
            {
                if (id <= CPU_Reg_dx)
                {
                    if (id <= CPU_Reg_edx)
                    {
                        if (id <= CPU_Reg_ch)
                        {
                            //CPU_Reg_ch
                            return (ecx&0xFF00)>>8;
                        }
                        else
                        {
                            //CPU_Reg_edx
                            return edx;
                        }
                    }
                    else
                    {
                        //CPU_Reg_dx
                        return edx&0xFFFF;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_dl)
                    {
                        //CPU_Reg_dl
                        return edx&0xFF;
                    }
                    else
                    {
                        //CPU_Reg_dh
                        return (edx&0xFF00)>>8;
                    }
                }
            }
            else
            {
                if (id <= CPU_Reg_ebp)
                {
                    if (id <= CPU_Reg_sp)
                    {
                        if (id <= CPU_Reg_esp)
                        {
                            //CPU_Reg_esp
                            return esp;
                        }
                        else
                        {
                            //CPU_Reg_sp
                            return esp&0xFFFF;
                        }
                    }
                    else
                    {
                        //CPU_Reg_ebp
                        return ebp;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_bp)
                    {
                        //CPU_Reg_bp
                        return ebp&0xFFFF;
                    }
                    else
                    {
                        //CPU_Reg_esfp
                        return esfp;
                    }
                }
            }
        }
    }
    else
    {
        if (id <= CPU_Reg_r5)
        {
            if (id <= CPU_Reg_r0)
            {
                if (id <= CPU_Reg_bfp)
                {
                    if (id <= CPU_Reg_ebfp)
                    {
                        if (id <= CPU_Reg_sfp)
                        {
                            //CPU_Reg_sfp
                            return esfp&0xFFFF;
                        }
                        else
                        {
                            //CPU_Reg_ebfp
                            return ebfp;
                        }
                    }
                    else
                    {
                        //CPU_Reg_bfp
                        return ebfp&0xFFFF;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_ip)
                    {
                        if (id <= CPU_Reg_eip)
                        {
                            //CPU_Reg_eip
                            return eip;
                        }
                        else
                        {
                            //CPU_Reg_ip
                            return eip&0xFFFF;
                        }
                    }
                    else
                    {
                        //CPU_Reg_r0
                        return r0;
                    }
                }
            }
            else
            {
                if (id <= CPU_Reg_r3)
                {
                    if (id <= CPU_Reg_r2)
                    {
                        if (id <= CPU_Reg_r1)
                        {
                            //CPU_Reg_r1
                            return r1;
                        }
                        else
                        {
                            //CPU_Reg_r2
                            return r2;
                        }
                    }
                    else
                    {
                        //CPU_Reg_r3
                        return r3;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_r4)
                    {
                        //CPU_Reg_r4
                        return r4;
                    }
                    else
                    {
                        //CPU_Reg_r5
                        return r5;
                    }
                }
            }
        }
        else
        {
            if (id <= CPU_Reg_f2)
            {
                if (id <= CPU_Reg_f0)
                {
                    if (id <= CPU_Reg_r7)
                    {
                        if (id <= CPU_Reg_r6)
                        {
                            //CPU_Reg_r6
                            return r6;
                        }
                        else
                        {
                            //CPU_Reg_r7
                            return r7;
                        }
                    }
                    else
                    {
                        //is float reg
                        return 0;
                    }
                }
                else
                {
                    //is float reg
                    return 0;
                }
            }
            else
            {
                //is float reg
                return 0;
            }
        }
    }
    return -222;
}

double CPU::getFloatRegisterValue(cpubasetype id)
{
    if (id < CPU_Reg_f0) return -222.0; //is int reg
            if (id <= CPU_Reg_f2)
            {
                if (id <= CPU_Reg_f0)
                {
                    if (id <= CPU_Reg_r7)
                    {
                        //is int reg
                        return 0.0;
                    }
                    else
                    {
                        //CPU_Reg_f0
                        return f0;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_f1)
                    {
                        //CPU_Reg_f1
                        return f1;
                    }
                    else
                    {
                        //CPU_Reg_f2
                        return f2;
                    }
                }
            }
            else
            {
                if (id <= CPU_Reg_f5)
                {
                    if (id <= CPU_Reg_f4)
                    {
                        if (id <= CPU_Reg_f3)
                        {
                            //CPU_Reg_f3
                            return f3;
                        }
                        else
                        {
                            //CPU_Reg_f4
                            return f4;
                        }
                    }
                    else
                    {
                        //CPU_Reg_f5
                        return f5;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_f6)
                    {
                        //CPU_Reg_f6
                        return f6;
                    }
                    else
                    {
                        //CPU_Reg_f7
                        return f7;
                    }
                }
            }
            return -222.0;
}

void CPU::setIntRegisterValue(cpubasetype id, cpubasetype data)
{
    if (id > CPU_Reg_r7) return; //is float reg
    if (id == CPU_Reg_ebp)
    {
        ebp=data;
        return;
    }
    if (id == CPU_Reg_esp)
    {
        esp=data;
        return;
    }
    if (id <= CPU_Reg_esfp)
    {
        if (id <= CPU_Reg_cl)
        {
            if (id <= CPU_Reg_bx)
            {
                if (id <= CPU_Reg_al)
                {
                    if (id <= CPU_Reg_ax)
                    {
                        if (id <= CPU_Reg_eax)
                        {
                            //CPU_Reg_eax
                            eax=data;
                        }
                        else
                        {
                            //CPU_Reg_ax
                            eax = (eax&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                        }
                    }
                    else
                    {
                        //CPU_Reg_al
                        eax = (eax&0xFFFFFFFFFFFFFF00) | (data&0xFF);
                    }
                }
                else
                {
                    if (id <= CPU_Reg_ebx)
                    {
                        if (id <= CPU_Reg_ah)
                        {
                            //CPU_Reg_ah
                            eax = (eax&0xFFFFFFFFFFFF00FF) | ((data&0xFF)<<8);
                        }
                        else
                        {
                            //CPU_Reg_ebx
                            ebx=data;
                        }
                    }
                    else
                    {
                        //CPU_Reg_bx
                        ebx = (ebx&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                    }
                }
            }
            else
            {
                if (id <= CPU_Reg_ecx)
                {
                    if (id <= CPU_Reg_bh)
                    {
                        if (id <= CPU_Reg_bl)
                        {
                            //CPU_Reg_bl
                            ebx = (ebx&0xFFFFFFFFFFFFFF00) | (data&0xFF);
                        }
                        else
                        {
                            //CPU_Reg_bh
                            ebx = (ebx&0xFFFFFFFFFFFF00FF) | ((data&0xFF)<<8);
                        }
                    }
                    else
                    {
                        //CPU_Reg_ecx
                        ecx=data;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_cx)
                    {
                        //CPU_Reg_cx
                        ecx = (ecx&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                    }
                    else
                    {
                        //CPU_Reg_cl
                        ecx = (ecx&0xFFFFFFFFFFFFFF00) | (data&0xFF);
                    }
                }
            }
        }
        else
        {
            if (id <= CPU_Reg_dh)
            {
                if (id <= CPU_Reg_dx)
                {
                    if (id <= CPU_Reg_edx)
                    {
                        if (id <= CPU_Reg_ch)
                        {
                            //CPU_Reg_ch
                            ecx = (ecx&0xFFFFFFFFFFFF00FF) | ((data&0xFF)<<8);
                        }
                        else
                        {
                            //CPU_Reg_edx
                            edx=data;
                        }
                    }
                    else
                    {
                        //CPU_Reg_dx
                        edx = (edx&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                    }
                }
                else
                {
                    if (id <= CPU_Reg_dl)
                    {
                        //CPU_Reg_dl
                        edx = (edx&0xFFFFFFFFFFFFFF00) | (data&0xFF);
                    }
                    else
                    {
                        //CPU_Reg_dh
                        edx = (edx&0xFFFFFFFFFFFF00FF) | ((data&0xFF)<<8);
                    }
                }
            }
            else
            {
                if (id <= CPU_Reg_ebp)
                {
                    if (id <= CPU_Reg_sp)
                    {
                        if (id <= CPU_Reg_esp)
                        {
                            //CPU_Reg_esp
                            esp=data;
                        }
                        else
                        {
                            //CPU_Reg_sp
                            esp = (esp&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                        }
                    }
                    else
                    {
                        //CPU_Reg_ebp
                        ebp=data;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_bp)
                    {
                        //CPU_Reg_bp
                        ebp = (ebp&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                    }
                    else
                    {
                        //CPU_Reg_esfp
                        esfp=data;
                    }
                }
            }
        }
    }
    else
    {
        if (id <= CPU_Reg_r5)
        {
            if (id <= CPU_Reg_r0)
            {
                if (id <= CPU_Reg_bfp)
                {
                    if (id <= CPU_Reg_ebfp)
                    {
                        if (id <= CPU_Reg_sfp)
                        {
                            //CPU_Reg_sfp
                            esfp = (esfp&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                        }
                        else
                        {
                            //CPU_Reg_ebfp
                            ebfp=data;
                        }
                    }
                    else
                    {
                        //CPU_Reg_bfp
                        ebfp = (ebfp&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                    }
                }
                else
                {
                    if (id <= CPU_Reg_ip)
                    {
                        if (id <= CPU_Reg_eip)
                        {
                            //CPU_Reg_eip
                            eip=data;
                        }
                        else
                        {
                            //CPU_Reg_ip
                            eip = (eip&0xFFFFFFFFFFFF0000) | (data&0xFFFF);
                        }
                    }
                    else
                    {
                        //CPU_Reg_r0
                        r0=data;
                    }
                }
            }
            else
            {
                if (id <= CPU_Reg_r3)
                {
                    if (id <= CPU_Reg_r2)
                    {
                        if (id <= CPU_Reg_r1)
                        {
                            //CPU_Reg_r1
                            r1=data;
                        }
                        else
                        {
                            //CPU_Reg_r2
                            r2=data;
                        }
                    }
                    else
                    {
                        //CPU_Reg_r3
                        r3=data;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_r4)
                    {
                        //CPU_Reg_r4
                        r4=data;
                    }
                    else
                    {
                        //CPU_Reg_r5
                        r5=data;
                    }
                }
            }
        }
        else
        {
            if (id <= CPU_Reg_f2)
            {
                if (id <= CPU_Reg_f0)
                {
                    if (id <= CPU_Reg_r7)
                    {
                        if (id <= CPU_Reg_r6)
                        {
                            //CPU_Reg_r6
                            r6=data;
                        }
                        else
                        {
                            //CPU_Reg_r7
                            r7=data;
                        }
                    }
                    else
                    {
                        //is float reg
                        return;
                    }
                }
                else
                {
                    //is float reg
                    return;
                }
            }
            else
            {
                //is float reg
                return;
            }
        }
    }
}

void CPU::setFloatRegisterValue(cpubasetype id, double data)
{
    if (id < CPU_Reg_f0) return; //is int reg
            if (id <= CPU_Reg_f2)
            {
                if (id <= CPU_Reg_f0)
                {
                    if (id <= CPU_Reg_r7)
                    {
                        //is int reg
                        return;
                    }
                    else
                    {
                        //CPU_Reg_f0
                        f0=data;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_f1)
                    {
                        //CPU_Reg_f1
                        f1=data;
                    }
                    else
                    {
                        //CPU_Reg_f2
                        f2=data;
                    }
                }
            }
            else
            {
                if (id <= CPU_Reg_f5)
                {
                    if (id <= CPU_Reg_f4)
                    {
                        if (id <= CPU_Reg_f3)
                        {
                            //CPU_Reg_f3
                            f3=data;
                        }
                        else
                        {
                            //CPU_Reg_f4
                            f4=data;
                        }
                    }
                    else
                    {
                        //CPU_Reg_f5
                        f5=data;
                    }
                }
                else
                {
                    if (id <= CPU_Reg_f6)
                    {
                        //CPU_Reg_f6
                        f6=data;
                    }
                    else
                    {
                        //CPU_Reg_f7
                        f7=data;
                    }
                }
            }
}
