#include <iostream>

int main(){
        __int32 x(0), counter(0);
        int fibonacci_numbers[49];

        __asm {
        mov EAX, 1
        mov EBX, 0
        mov EDX, 0
        mov fibonacci_numbers[0], 0
        mov fibonacci_numbers[4], 1
        mov ESI, 2

        fibonacci_loop:
        mov EDX, EAX
        add EAX, EBX
        mov EBX, EDX
        mov fibonacci_numbers[4*ESI], EAX
        inc ESI
        jc end_fibonacci_loop
        loop fibonacci_loop


        end_fibonacci_loop :
        mov x, EAX
        mov counter, ESI
        }
        for (int i = 0; i < counter; ++i) {
            std::cout << fibonacci_numbers[i] << " ";
        }
        std::cout << std::endl;
        return 0;
}
