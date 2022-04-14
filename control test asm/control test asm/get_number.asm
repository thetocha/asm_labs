.model flat, C
.code 
real_number_proc PROC, a:dword
  mov eax, a
   
   mov eax, a

   SHR eax, 7
   mov EBX, EAX

   SHR eax, 8
   SHL eax, 6

   SHL EBX, 26
   SHR EBX, 26
   OR  EAX, EBX

   mov a, EAX

   ret 
real_number_proc ENDP
end