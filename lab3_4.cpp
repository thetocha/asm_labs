#include <iostream>

int main(){
    __int32 numerator(0), denominator(0), devider(1);
    std::cout << "Enter numerator" << std::endl;
    std::cin >> numerator;

    std::cout << "Enter denominator" << std::endl;
    std::cin >> denominator;
    int deviders1[100];

    __asm {
    mov EAX, denominator
    mov ECX, EAX
    xor EDX, EDX
    mov ESI, 0

    denominators_dividers:
    xor EDX, EDX
    cmp ECX, 0
    je GCD
    div ECX
    mov EAX, denominator
    cmp EDX, 0
    je is_diveder
    loop denominators_dividers

    is_diveder :
    mov deviders1[4 * ESI], ECX
    inc ESI
    dec ECX
    jmp denominators_dividers

    GCD :
    mov ECX, ESI
    mov ESI, 0
    xor EAX, EAX
    xor EDX, EDX
    mov EAX, numerator
    find :
    cmp ECX, 0
    je end
    xor EDX, EDX
    mov EBX, deviders1[4 * ESI]
    idiv EBX
    mov EAX, numerator
    inc ESI
    cmp EDX, 0
    je is_GSD
    loop find

    is_GSD :
    mov devider, EBX
    jmp end


    end :
    mov EAX, numerator
    idiv devider
    mov numerator, EAX
    mov EAX, denominator
    div devider
    mov denominator, EAX

    }

    std::cout << " Reduced fraction is " << numerator << "/" << denominator << std::endl;
    return 0;
}
