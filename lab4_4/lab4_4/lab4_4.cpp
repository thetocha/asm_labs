#include <iostream>

int main()
{
    __int32 x(0);
    std::cout << "Enter x" << std::endl;
    std::cin >> x;
     double a(0.5), one(1);

     __asm {
         fild x
         fld a
         FYL2X
         fld one
         FSCALE
         fst a
     }

     std::cout << a << std::endl;

     return 0;
}

