#include <iostream>

int main(){

    __int32 x1(0), rez1(0), flag1(0);
    std::cout << "Enter variable for first problem" << std::endl;
    std::cin >> x1;
    __asm {
    mov EAX, x1
    mov EBX, 2
    mov ECX, 0
    mov EDX, 0

    imul EAX
    sub EAX, 4
    imul EBX
    mov EDX, EAX

    mov EAX, x1
    imul x1
    imul x1
    mov ECX, EAX

    imul x1
    imul x1


    add EAX, EDX
    add EAX, x1

    cmp ECX, 0
    jne if_not_zero1

    cmp ECX, 0
    je if_zero1

    if_zero1:
        jmp end1

    if_not_zero1:
        idiv ECX
        mov rez1, EAX
        mov flag1, 1
        jmp end1

    end1:

    }

    int rezC1 = (pow(x1,5) + 2*(pow(x1,2) - 4) + x1) / pow(x1,3);
    if(flag1){
        std::cout << "Result by asm " << rez1 << std::endl;
        std::cout << "Resukt by C++ "  << rezC1 << std::endl;
    }else{
        std::cout << "You divide by zero, try other variable" << std::endl;
    }

    __int32 x2(0), rez2(0), flag2(0), two(2);
    std::cout << "Enter variable for second problem" << std::endl;
    std::cin >> x2;
    __asm {
    mov EAX, x2
    mov EBX, 0
    mov ECX, 0
    mov EDX, 0


    mov EAX, x2
    imul two
    mov ECX, EAX


    cmp ECX, 0
    jne if_not_zero2

    cmp ECX, 0
    je if_zero2

    if_zero2 :
        jmp end2

    if_not_zero2 :
    mov EAX, x2
    imul two
    add EAX, 1
    mov EBX, EAX

    mov EAX, x2
    imul two
    sub EAX, 1

    mov EDX, x2
    add EDX, 3

    imul EDX
    imul EBX
    idiv ECX

    mov rez2, EAX
    mov flag2, 1
    jmp end2

    end2 :

    }

    int rezC2 = ((2*x2 + 1)*(2*x2 - 1)*(x2 + 3))/(2*x2);
    if (flag2) {
        std::cout << "Result by asm " << rez2 << std::endl;
        std::cout << "Resukt by C++ "  << rezC2 << std::endl;
    }
    else {
        std::cout << "You divide by zero, try other variable" << std::endl;
    }

    __int32 x3(0),rez3(0), flag3(0);
    std::cout << "Enter variable for third problem" << std::endl;
    std::cin >> x3;
    __asm{
        mov EAX, x3
        mov EBX, 0
        mov ECX, 4

        imul ECX
        mov EBX, EAX

        add EAX, 1
        sub EBX,1

        imul EBX
        idiv ECX

        mov rez3, EAX
    }

    int rezC3 = ((4*x3 + 1)*(4*x3 +-1))/4;

    std::cout << "Result by asm " << rez3 << std::endl;
    std::cout << "Resukt by C++ "  << rezC3 << std::endl;




    return 0;
}
