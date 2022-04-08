#include <iostream>

int main()
{
    double a(0), b(0), c(0), x(0), intermidiate_rezult(0), root(0), higher_boder(10), lower_boder(-10), middle(0), zero(0);
    __int32 noRoots(0), two(2);
    std::cout << "Enter coeficient a" << std::endl;
    std::cin >> a;

    std::cout << "Enter coeficient b" << std::endl;
    std::cin >> b;

    std::cout << "Enter coeficient c" << std::endl;
    std::cin >> c;

    __asm {
    counting:
        finit
            fld higher_boder
            fst x

            fmul x
            fmul x
            fstp intermidiate_rezult
            fld x
            fmul x
            fmul a
            fadd intermidiate_rezult
            fstp intermidiate_rezult
            fld x
            fmul b
            fadd intermidiate_rezult
            fadd c
            fst intermidiate_rezult



            fcom zero
            fstsw ax
            sahf
            je is_root




            fld lower_boder
            fst x

            fmul x
            fmul x
            fstp intermidiate_rezult
            fld x
            fmul x
            fmul a
            fadd intermidiate_rezult
            fstp intermidiate_rezult
            fld x
            fmul b
            fadd intermidiate_rezult
            fadd c
            fst intermidiate_rezult



            fcom zero
            fstsw ax
            sahf
            je is_root


            fmul ST, ST(1)
            fst root
            fcom zero
            fstsw ax
            sahf
            ja no_roots



            fld higher_boder
            fadd lower_boder
            fidiv two
            fst middle
            fst x

            fmul x
            fmul x
            fstp intermidiate_rezult
            fld x
            fmul x
            fmul a
            fadd intermidiate_rezult
            fstp intermidiate_rezult
            fld x
            fmul b
            fadd intermidiate_rezult
            fadd c
            fst intermidiate_rezult





            fcom zero
            fstsw ax
            sahf
            je is_root

            fld intermidiate_rezult

            fcom zero
            fstsw ax
            sahf
            ja change_higher_boder


            fld intermidiate_rezult

            fcom zero
            fstsw ax
            sahf
            jb change_lower_boder



        change_higher_boder:
        fld middle
            fstp higher_boder
            jmp counting



        change_lower_boder:
        fld middle
            fstp lower_boder
            jmp counting



        is_root:
        fld x
            fstp root
            jmp end

            no_roots :
        inc noRoots
            jmp end

            end :



    }

    if (noRoots == 1)
    {
        std::cout << " no roots " << std::endl;
    }
    else
    {
        std::cout << root << std::endl;
    }




    return 0;
}


