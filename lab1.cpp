#include <iostream>

int main(){
    __int16 a = 2, b = -3;
    __asm{
        mov AX, a
        add AX, b
        mov a,AX
    }

    std::cout << a << std::endl;


    __int16 a3(4),a2(3),a1(2);
    __int16 b3(7),b2(-1),b1(5);
    __int16 c3(0),c2(0),c1(0);

    __asm{
        mov AX, a1
        adc AX, b1
        mov c1, AX

        mov AX, a2
        adc AX, b2
        mov c2, AX

        mov AX, a3
        adc AX, b3
        mov c3, Ax


    }

    std::cout.unsetf(std::ios::dec);
    std::cout.setf(std::ios::hex);

    std::cout << a3 << " " << a2 << " " << a1 << std::endl;
    std::cout << b3 << " " << b2 << " " << b1 << std::endl;
    std::cout << c3 << " " << c2 << " " << c1 << std::endl;

    std::cout.unsetf(std::ios::hex);
    std::cout.setf(std::ios::dec);

    std::cout << a3 << a2 << a1 << std::endl;
    std::cout << b3 << b2 << b1 << std::endl;
    std::cout << c3 << c2 << c1 << std::endl;



    return 0;
}
