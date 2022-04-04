#include <iostream>
#include <iomanip>

int main()
{
    __int32  iteration(0), one(1), two(2), x(0), NF(0);
    double rez(0), intermidiate_rez(0), accuracy(0);
    std::cout << "Enter required accuracy" << std::endl;
    std::cin >> x;
    switch (x) {
    case 1:
        accuracy = 0.00001;
        break;
    case 2:
        accuracy = 0.0000001;
        break;
    default:
        std::cout << "You have to choose between 1 & 2";
        exit(1);
        break;
    }
    __asm {

        count :
        finit
        xor EDX, EDX
            inc iteration
            mov EAX, iteration
            mul EAX
            mov EDX, 4
            mul EDX
            xor EDX, EDX
            sub EAX, 1
            mov EBX, iteration
            mul EBX
            mov x, EAX


            fld one
            fdiv x
            fadd intermidiate_rez
            fstp intermidiate_rez
            

            
            fild one
            fadd intermidiate_rez
            fidiv two
            fstp rez

            fld rez
            fldln2
            fsub
            fabs
            fcom accuracy
            fstsw ax
            sahf 
            jae count



    }

    std::cout << "It needs " << iteration << " of itertion to get this accuracy" << std::endl;
    return 0;
}


