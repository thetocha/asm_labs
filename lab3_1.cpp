#include <iostream>

int main(){
    __int32 a(0);
    std::cout << "Enter varible" << std::endl;
    std::cin >> a;
    __asm{
        mov EAX, a
        mov ECX, 11
        twelve_degree:
        imul a
        loop twelve_degree

        mov EBX, EAX

        mov EAX, a
        mov ECX, 7
        eight_degree:
        imul a
        loop eight_degree


        adc a, EAX
        adc a, EBX

    }
    std::cout << "The result is " << a << std::endl;

    return 0;
}
