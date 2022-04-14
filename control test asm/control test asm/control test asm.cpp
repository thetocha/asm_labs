#include <iostream>

extern "C" int real_number_proc(int);

int main()
{
    __int32 a = (123456789);

    unsigned int  arr[4] = { 268500992, 536903680, 1073742336, 2147483776 };
    __asm {
        mov ECX, 4
       


        sorting:
        mov ESI, 0
        dec ECX
        mov EDX, ECX
        sub EDX, 1
        

        sorting_loop:
        
        mov EBX, arr[ESI*4]
        push EBX
        call real_number_proc
        mov EBX, EAX
        mov EAX, arr[(ESI*4)+4]
        push EAX
        call real_number_proc
        
        cmp EAX, EBX
        ja change
        pop EAX
        pop EBX
 

        

        change:
        pop EAX
        pop EBX
        mov EAX, arr[ESI * 4]
        mov EBX, arr[(ESI * 4) + 4]
        mov arr[ESI*4], EBX
        mov arr[(ESI * 4) +4], EAX

            cmp EDX, 0
            je end

        cmp ESI, EDX 
        je sorting
        inc ESI
        jmp sorting_loop

            end:
 
    }

    //std::cout << real_number_proc(a) << std::endl;


    for (int  i = 0; i < 4; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}
