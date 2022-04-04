#include <iostream>
#include <iomanip>


int main()
{
    __int32  iteration(0), one(1), k(0), x(0), NF(0);
    double intermediat_rez(0), rez(0), accuracy(0), zx(0);
    std::cout << "Enter required ouccuracy " << std::endl;
    std::cin >> x;
    switch (x) {
    case 1: 
        accuracy = 0.00001;
        break;
    case 2: 
        accuracy = 0.00000001;
        break;
    case 3: 
        accuracy = 0.0000000001;
        break;
    default:
        std::cout << "You have 3 option: 1,2 or 3. Choose wisely " << std::endl;
        exit(1);
    }
    __asm {
        

    count:
        finit
        xor EDX, EDX
        inc k
        mov EAX, k
        mul EAX
        push EAX
        xor EDX, EDX
        mov EAX, k
        mov EBX, 2
        div EBX
        pop x
        cmp EDX, 0
        jne pos_
        inc NF
        pos_:
        
        fld one
        fdiv x
        cmp NF, 0
        je not_neg_
        dec NF
        fchs
        not_neg_:
        fadd intermediat_rez
        fstp intermediat_rez
       
        

        mov x, 12
        fld intermediat_rez
        fimul x
        fsqrt
        
        fldpi
        fsub
        fabs
        fstp zx
        fld zx

        fcom accuracy

        fstsw ax
        sahf
        jnc count
        mov EAX, k
        mov iteration, EAX
}
     
    std::cout << std::setprecision(10) << iteration << std::endl;

    return 0;
}

