#include <iostream>
#include <iomanip>

int main()
{
    __int32  iteration(0), one(1), two(2), k(0), x(0), NF(0);
    double rez(0), y(1), z(2), intermidiate_rez(0), accuracy(0);
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
        mov ECX, iteration

        count :
        finit
        xor EDX, EDX
            inc k
            mov EAX, k
            mul EAX
            mov EDX, 4
            mul EDX
            xor EDX, EDX
            sub EAX, 1
            mov EBX, k
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
            fstp rez
            fld rez
            fcom accuracy
            fstsw ax
            sahf 
            jae count
            mov EAX, k
            mov iteration, EAX


    }

    std::cout << std::setprecision(8) << iteration << rez << std::endl;
    return 0;
}


