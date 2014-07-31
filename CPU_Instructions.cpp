#include "CPU.hpp"

#define CPU_Ins_nop 0
#define CPU_Ins_hlt 1
#define CPU_Ins_ldri 2
#define CPU_Ins_ldrf 3
#define CPU_Ins_stri 4
#define CPU_Ins_strf 5
#define CPU_Ins_popi 6
#define CPU_Ins_pushi 7
#define CPU_Ins_popf 8
#define CPU_Ins_pushf 9
#define CPU_Ins_itof 10
#define CPU_Ins_ftoi 11
#define CPU_Ins_and 12
#define CPU_Ins_or 13
#define CPU_Ins_xor 14
#define CPU_Ins_not 15
#define CPU_Ins_addi 16
#define CPU_Ins_subi 17
#define CPU_Ins_muli 18
#define CPU_Ins_divi 19
#define CPU_Ins_negi 20
#define CPU_Ins_inci 21
#define CPU_Ins_deci 22
#define CPU_Ins_addf 23
#define CPU_Ins_subf 24
#define CPU_Ins_mulf 25
#define CPU_Ins_divf 26
#define CPU_Ins_negf 27
#define CPU_Ins_incf 28
#define CPU_Ins_decf 29
#define CPU_Ins_gti 30
#define CPU_Ins_gtei 31
#define CPU_Ins_lti 32
#define CPU_Ins_ltei 33
#define CPU_Ins_eqi 34
#define CPU_Ins_neqi 35
#define CPU_Ins_gtf 36
#define CPU_Ins_gtef 37
#define CPU_Ins_ltf 38
#define CPU_Ins_ltef 39
#define CPU_Ins_eqf 40
#define CPU_Ins_neqf 41
#define CPU_Ins_shl 42
#define CPU_Ins_shr 43
#define CPU_Ins_jmp 44
#define CPU_Ins_jt 45
#define CPU_Ins_jf 46
#define CPU_Ins_call 47
#define CPU_Ins_ret 48
#define CPU_Ins_pushreg 49
#define CPU_Ins_popreg 50
#define CPU_Ins_randi 51
#define CPU_Ins_randf 52
#define CPU_Ins_cli 53
#define CPU_Ins_sei 54
#define CPU_Ins_int 55
#define CPU_Ins_jint 56
#define CPU_Ins_rdtsc 57

void CPU::executeInstruction(InstructionInfo& ii)
{
    if (ii.ID <= CPU_Ins_incf)
    {
        if (ii.ID <= CPU_Ins_xor)
        {
            if (ii.ID <= CPU_Ins_pushi)
            {
                if (ii.ID <= CPU_Ins_ldrf)
                {
                    if (ii.ID <= CPU_Ins_hlt)
                    {
                        if (ii.ID <= CPU_Ins_nop)
                        {
                            //CPU_Ins_nop
                            //nop~
                        }
                        else
                        {
                            //CPU_Ins_hlt
                            halt();
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_ldri)
                        {
                            //CPU_Ins_ldri
                            cpubasetype addr=popi();
                            if (addr>=memory.FloatOffset) //load float as int
                            {
                                pushi(*(cpubasetype *)(&memory.floatdata[addr-memory.FloatOffset]));
                            }
                            else
                            {
                                pushi(memory.intdata[addr]);
                            }
                        }
                        else
                        {
                            //CPU_Ins_ldrf
                            cpubasetype addr=popi();
                            if (addr<memory.FloatOffset) //load int as float
                            {
                                pushf(*(double *)(&memory.intdata[addr]));
                            }
                            else
                            {
                                pushf(memory.floatdata[addr-memory.FloatOffset]);
                            }
                        }
                    }
                }
                else
                {
                    if (ii.ID <= CPU_Ins_strf)
                    {
                        if (ii.ID <= CPU_Ins_stri)
                        {
                            //CPU_Ins_stri
                            cpubasetype data=popi();
                            cpubasetype addr=popi();
                            if (addr>=memory.FloatOffset) //set int as float
                            {
                                
                                memory.floatdata[addr-memory.FloatOffset]=*(double *)(&data);
                            }
                            else
                            {
                                memory.intdata[addr]=data;
                            }
                        }
                        else
                        {
                            //CPU_Ins_strf
                            double data=popf();
                            cpubasetype addr=popi();
                            if (addr<memory.FloatOffset) //set float as int
                            {
                                
                                memory.intdata[addr]=*(cpubasetype *)(&data);
                            }
                            else
                            {
                                memory.floatdata[addr-memory.FloatOffset]=data;
                            }
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_popi)
                        {
                            //CPU_Ins_popi
                            if (ii.pi.size()>0)
                            {
                                setIntRegisterValue(ii.pi[0].value, popi());
                            }
                            else
                            {
                                popi();
                            }
                        }
                        else
                        {
                            //CPU_Ins_pushi
                            pushi(getIntValue(ii.pi[0]));
                        }
                    }
                }
            }
            else
            {
                if (ii.ID <= CPU_Ins_ftoi)
                {
                    if (ii.ID <= CPU_Ins_pushf)
                    {
                        if (ii.ID <= CPU_Ins_popf)
                        {
                            //CPU_Ins_popf
                            if (ii.pi.size()>0)
                            {
                                setFloatRegisterValue(ii.pi[0].value, popf());
                            }
                            else
                            {
                                popf();
                            }
                        }
                        else
                        {
                            //CPU_Ins_pushf
                            pushi(getFloatValue(ii.pi[0]));
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_itof)
                        {
                            //CPU_Ins_itof
                            pushf((double)popi());
                        }
                        else
                        {
                            //CPU_Ins_ftoi
                            pushi((cpubasetype)popf());
                        }
                    }
                }
                else
                {
                    if (ii.ID <= CPU_Ins_or)
                    {
                        if (ii.ID <= CPU_Ins_and)
                        {
                            //CPU_Ins_and
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(a&b);
                        }
                        else
                        {
                            //CPU_Ins_or
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(a|b);
                        }
                    }
                    else
                    {
                        //CPU_Ins_xor
                        cpubasetype a, b;
                        a = popi();
                        b = popi();
                        pushi(a^b);
                    }
                }
            }
        }
        else
        {
            if (ii.ID <= CPU_Ins_inci)
            {
                if (ii.ID <= CPU_Ins_muli)
                {
                    if (ii.ID <= CPU_Ins_addi)
                    {
                        if (ii.ID <= CPU_Ins_not)
                        {
                            //CPU_Ins_not
                            pushi(~popi());
                        }
                        else
                        {
                            //CPU_Ins_addi
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(a+b);
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_subi)
                        {
                            //CPU_Ins_subi
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(b-a);
                        }
                        else
                        {
                            //CPU_Ins_muli
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(a*b);
                        }
                    }
                }
                else
                {
                    if (ii.ID <= CPU_Ins_negi)
                    {
                        if (ii.ID <= CPU_Ins_divi)
                        {
                            //CPU_Ins_divi
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            if (a==0) //a==0
                            {
                                pushi(0);
                                pushi(0);
                                Interrupt(0); //div
                            }
                            else
                            {
                                pushi(b%a);
                                pushi(b/a);
                            }
                        }
                        else
                        {
                            //CPU_Ins_negi
                            pushi(-popi());
                        }
                    }
                    else
                    {
                        //CPU_Ins_inci
                        pushi(popi()+1);
                    }
                }
            }
            else
            {
                if (ii.ID <= CPU_Ins_mulf)
                {
                    if (ii.ID <= CPU_Ins_addf)
                    {
                        if (ii.ID <= CPU_Ins_deci)
                        {
                            //CPU_Ins_deci
                            pushi(popi()-1);
                        }
                        else
                        {
                            //CPU_Ins_addf
                            double a, b;
                            a = popf();
                            b = popf();
                            pushf(a+b);
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_subf)
                        {
                            //CPU_Ins_subf
                            double a, b;
                            a = popf();
                            b = popf();
                            pushf(b-a);
                        }
                        else
                        {
                            //CPU_Ins_mulf
                            double a, b;
                            a = popf();
                            b = popf();
                            pushf(a*b);
                        }
                    }
                }
                else
                {
                    if (ii.ID <= CPU_Ins_negf)
                    {
                        if (ii.ID <= CPU_Ins_divf)
                        {
                            //CPU_Ins_divf
                            double a, b;
                            a = popf();
                            b = popf();
                            pushf(b/a);
                        }
                        else
                        {
                            //CPU_Ins_negf
                            pushf(-popf());
                        }
                    }
                    else
                    {
                        //CPU_Ins_incf
                        pushf(popf()+1);
                    }
                }
            }
        }
    }
    else
    {
        if (ii.ID <= CPU_Ins_shr)
        {
            if (ii.ID <= CPU_Ins_gtf)
            {
                if (ii.ID <= CPU_Ins_lti)
                {
                    if (ii.ID <= CPU_Ins_gti)
                    {
                        if (ii.ID <= CPU_Ins_decf)
                        {
                            //CPU_Ins_decf
                            pushf(popf()-1);
                        }
                        else
                        {
                            //CPU_Ins_gti
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(b>a);
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_gtei)
                        {
                            //CPU_Ins_gtei
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(b>=a);
                        }
                        else
                        {
                            //CPU_Ins_lti
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(b<a);
                        }
                    }
                }
                else
                {
                    if (ii.ID <= CPU_Ins_eqi)
                    {
                        if (ii.ID <= CPU_Ins_ltei)
                        {
                            //CPU_Ins_ltei
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(b<=a);
                        }
                        else
                        {
                            //CPU_Ins_eqi
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(b==a);
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_neqi)
                        {
                            //CPU_Ins_neqi
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(b!=a);
                        }
                        else
                        {
                            //CPU_Ins_gtf
                            double a, b;
                            a = popf();
                            b = popf();
                            pushi(b>a);
                        }
                    }
                }
            }
            else
            {
                if (ii.ID <= CPU_Ins_eqf)
                {
                    if (ii.ID <= CPU_Ins_ltf)
                    {
                        if (ii.ID <= CPU_Ins_gtef)
                        {
                            //CPU_Ins_gtef
                            double a, b;
                            a = popf();
                            b = popf();
                            pushi(b>=a);
                        }
                        else
                        {
                            //CPU_Ins_ltf
                            double a, b;
                            a = popf();
                            b = popf();
                            pushi(b<a);
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_ltef)
                        {
                            //CPU_Ins_ltef
                            double a, b;
                            a = popf();
                            b = popf();
                            pushi(b<=a);
                        }
                        else
                        {
                            //CPU_Ins_eqf
                            double a, b;
                            a = popf();
                            b = popf();
                            pushi(b==a);
                        }
                    }
                }
                else
                {
                    if (ii.ID <= CPU_Ins_shl)
                    {
                        if (ii.ID <= CPU_Ins_neqf)
                        {
                            //CPU_Ins_neqf
                            double a, b;
                            a = popf();
                            b = popf();
                            pushi(b!=a);
                        }
                        else
                        {
                            //CPU_Ins_shl
                            cpubasetype a, b;
                            a = popi();
                            b = popi();
                            pushi(b<<a);
                        }
                    }
                    else
                    {
                        //CPU_Ins_shr
                        cpubasetype a, b;
                        a = popi();
                        b = popi();
                        pushi(b>>a);
                    }
                }
            }
        }
        else
        {
            if (ii.ID <= CPU_Ins_popreg)
            {
                if (ii.ID <= CPU_Ins_call)
                {
                    if (ii.ID <= CPU_Ins_jt)
                    {
                        if (ii.ID <= CPU_Ins_jmp)
                        {
                            //CPU_Ins_jmp
                            eip = getIntValue(ii.pi[0]);
                        }
                        else
                        {
                            //CPU_Ins_jt
                            if (popi()&1) eip = getIntValue(ii.pi[0]);
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_jf)
                        {
                            //CPU_Ins_jf
                            if (!(popi()&1)) eip = getIntValue(ii.pi[0]);
                        }
                        else
                        {
                            //CPU_Ins_call
                            pushi(eip);
                            eip = getIntValue(ii.pi[0]);
                        }
                    }
                }
                else
                {
                    if (ii.ID <= CPU_Ins_pushreg)
                    {
                        if (ii.ID <= CPU_Ins_ret)
                        {
                            //CPU_Ins_ret
                            eip = popi();
                        }
                        else
                        {
                            //CPU_Ins_pushreg
                            pushreg();
                        }
                    }
                    else
                    {
                        //CPU_Ins_popreg
                        popreg();
                    }
                }
            }
            else
            {
                if (ii.ID <= CPU_Ins_sei)
                {
                    if (ii.ID <= CPU_Ins_randf)
                    {
                        if (ii.ID <= CPU_Ins_randi)
                        {
                            //CPU_Ins_randi
                            //TODO
                            pushi(0);
                        }
                        else
                        {
                            //CPU_Ins_randf
                            //TODO
                            pushf(0);
                        }
                    }
                    else
                    {
                        if (ii.ID <= CPU_Ins_cli)
                        {
                            //CPU_Ins_cli
                            InterruptEnable=false;
                        }
                        else
                        {
                            //CPU_Ins_sei
                            InterruptEnable=true;
                        }
                    }
                }
                else
                {
                    if (ii.ID <= CPU_Ins_jint)
                    {
                        if (ii.ID <= CPU_Ins_int)
                        {
                            //CPU_Ins_int
                            Interrupt(getIntValue(ii.pi[0]));
                        }
                        else
                        {
                            //CPU_Ins_jint
                            cpubasetype id=popi();
                            InterruptVector[id].type=Interrupt_Inner;
                            InterruptVector[id].inner_address=getIntValue(ii.pi[0]);
                        }
                    }
                    else
                    {
                        //CPU_Ins_rdtsc
                        pushi(RanCount);
                    }
                }
            }
        }
    }
}
