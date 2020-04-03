section .rodata
    three dd 3.0
    two dd 2.0

section .text
global f1
f1:
    push ebp
    mov ebp, esp
    finit
    fld dword[ebp+8]
    fldl2e
    fmul
    fld st0
    frndint
    fsub st1, st0
    fxch st1
    f2xm1
    fld1
    fadd
    fscale
    fld1
    fxch
    fdivp
    fld dword[three]
    fadd
    leave
    xor eax, eax
    ret

global f2
f2: 
    ; y = 2x-2
    push ebp
    mov ebp, esp 
    finit
    fld dword[ebp + 8]
    fld dword[ebp + 8]
    faddp
    fld dword[two]
    fsubp
    leave 
    xor eax, eax 
    ret

global f3
f3: 
    ; y = 1/x
    push ebp 
    mov ebp, esp 
    finit
    fld1
    fld dword[ebp + 8] 
    fdivp
    leave 
    xor eax, eax 
    ret 