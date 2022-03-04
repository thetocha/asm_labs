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

    mul EAX
    sub EAX, 4
    mul EBX
    mov EDX, EAX

    mov EAX, x1
    mul x1
    mul x1
    mov ECX, EAX

    mul x1
    mul x1


    add EAX, EDX
    add EAX, x1

    cmp ECX, 0
    jne if_not_zero

    cmp ECX, 0
    je if_zero

    if_zero:
        jmp end

    if_not_zero:
        div ECX
        mov rez1, EAX
        mov flag1, 1
        jmp end

    end:

    }

    if(flag1){
        std::cout << rez1 << std::endl;
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
    mul two
    mov ECX, EAX


    cmp ECX, 0
    jne if_not_zero

    cmp ECX, 0
    je if_zero

    if_zero :
        jmp end

    if_not_zero :
    mov EAX, x2
    mul two
    add EAX, 1
    mov EBX, EAX

    mov EAX, x2
    mul two
    sub EAX, 1

    mov EDX, x2
    add EDX, 3

    mul EDX
    mul EBX
    div ECX

    mov rez2, EAX
    mov flag2, 1
    jmp end

    end :

    }

    if (flag2) {
        std::cout << rez2 << std::endl;
    }
    else {
        std::cout << "You divide by zero, try other variable" << std::endl;
    }

    __int32 x3(0),rez3(0);
    std::cout << "Enter variable for third problem" << std::endl;
    std::cin >> x3;
    __asm{
        mov EAX, x3
        mov EBX, 0
        mov ECX, 4

        mul ECX
        mov EBX, EAX

        add EAX, 1
        sub EBX,1

        mul EBX
        div ECX

        mov rez3, EAX
    }

    std::cout << rez3 <<  std::endl;



    return 0;
}
