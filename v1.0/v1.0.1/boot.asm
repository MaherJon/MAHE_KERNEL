BITS 16
ORG 0x7C00

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    sti

    mov ah, 0x02    
    mov al, 4       
    mov ch, 0      
    mov cl, 2       
    mov dh, 0       
    mov bx, 0x1000  
    int 0x13

    jmp 0x1000:0x0000

times 510-($-$$) db 0
dw 0xAA55