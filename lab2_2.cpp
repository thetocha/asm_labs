#include <iostream>

int main(){
    __int32 x(0), rez(0);
    std::cin >> x;

    __asm{
        mov EAX, x
        mov EBX, 1
        mov EDX, 0

        count:
        SHR EAX, 1
        inc EDX
        cmp EAX, 0
        je count_end
        loop count


        count_end:
        mov rez, EDX
    }

     std::cout << rez << std::endl;
    return 0;
}
