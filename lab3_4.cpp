#include <iostream>

int main(){
    __int32 numerator(0), denominator(0), counter(1), NF(0);



    std::cout << "Enter numerator" << std::endl;
    std::cin >> numerator;

    std::cout << "Enter denominator" << std::endl;
    std::cin >> denominator;
    int deviders1[100];

    __asm {


    xor EDX, EDX
    mov ESI, 0
    mov EAX, denominator
    mov ECX, EAX
    mov EAX, numerator
    cmp EAX, 0
    jl is_negative
    jg denominators_dividers



    is_negative :
    mov NF, 1
    mov EAX, numerator
    mov EBX, -1
    imul EBX
    mov numerator, EAX
    jmp denominators_dividers



    denominators_dividers:
    mov EAX, denominator
    xor EDX, EDX
    cmp ECX, 0
    je GCD
    div ECX
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
    mov EBX, 1
    mov EAX, numerator
    find :
    cmp ECX, 0
    je end_for_numerator
    xor EDX, EDX
    mov EBX, deviders1[4 * ESI]
    div EBX
    mov EAX, numerator
    inc ESI
    cmp EDX, 0
    je is_GSD
    loop find

    is_GSD :
    mov counter, EBX
    jmp end_for_numerator


    end_for_numerator :
    mov EAX, numerator
    div counter
    xor EDX, EDX
    mov numerator, EAX


    cmp NF, 1
    je make_negative_again
    jne end_for_denominator



    make_negative_again :
    mov EBX, -1
    xor EDX, EDX
    imul EBX
    mov NF, 0
    xor EDX, EDX
    mov numerator, EAX
    jmp end_for_denominator


    end_for_denominator :
    mov EAX, denominator
    div counter
    mov denominator, EAX

    }

    std::cout << " Reduced fraction is " << numerator << "/" << denominator << std::endl;




    return 0;
}
