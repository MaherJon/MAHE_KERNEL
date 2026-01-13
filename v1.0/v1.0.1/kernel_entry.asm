; kernel_entry.asm - 内核入口
BITS 16

global _start
extern kmain

_start:
    mov ax, cs
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    mov ax, 0x0003
    int 0x10

    call kmain

    cli
.hang:
    hlt
    jmp .hang