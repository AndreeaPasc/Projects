#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

/* Answer: */
union {
    struct {
        DWORD eax, ebx, ecx, edx;
    } dword;
    struct {
        WORD ax, ae, bx, be, cx, ce, dx, de;
    } word;
    struct {
        BYTE axl, axh, ael, aeh, bxl, bxh, bel, beh,
                cxl, cxh, cel, ceh, dxl, dxh, del, deh;
    } byte;
} regs;

int main(void)
{
    regs.word.ae = 0x1234;
    regs.word.ax = 0x5678;

    printf("EAX: %lx\n", regs.dword.eax);

    return 0;
}