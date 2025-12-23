.model small    
.stack 100h

.data
    cadena db 5,0,0,0,0,0,0
    peso db 8,4,2,1
    valor_CO1 db 0
    valor_CO2 db 0
    signo db '+'
    
.code
    mov ax, seg cadena
    mov ds, ax
    
    mov dx, offset cadena
    mov ah, 0ah
    int 21h
    
    sub cadena[2], 48
    sub cadena[3], 48
    sub cadena[4], 48
    sub cadena[5], 48

    mov al, cadena[2]
    cmp al,0
    je es_positivo
       
    mov signo, '-'
    jmp signo_listo

es_positivo:
    jmp no_cambio

signo_listo:   

    mov bl,0
    
    mov al, cadena[3]
    not al
    and al,00000001b
    mov cadena[3],al
    mul peso[1]
    add bl,al
    
    mov al, cadena[4]
    not al
    and al,00000001b
    mov cadena[4],al
    mul peso[2]
    add bl,al
    
    mov al, cadena[5]
    not al
    and al,00000001b
    mov cadena[5],al 
    mul peso[3]
    add bl,al   

    mov valor_CO1, bl

    mov al, valor_CO1
    inc al
    mov valor_CO2, al 
    
    jmp calculo_listo
    
no_cambio:

    mov bl,0
    
    mov al, cadena[3]
    mov cadena[3],al
    mul peso[1]
    add bl,al  
      
    mov al, cadena[4]
    mov cadena[4],al
    mul peso[2]
    add bl,al
      
    mov al, cadena[5]
    mov cadena[5],al
    mul peso[3]
    add bl,al    
      
    mov valor_CO1, bl

    mov al, valor_CO1
    mov valor_CO2, al

calculo_listo:
    
    mov ax, 0b800h
    mov es, ax
    mov di, 0
    
    mov ah, 00001111b
    mov al, 'C'
    mov es:[di], ax
    add di, 2
    mov al, 'O'
    mov es:[di], ax
    add di, 2
    mov al, '1'
    mov es:[di], ax
    add di, 2
    mov al, ':'
    mov es:[di], ax
    add di, 2
    mov al, ' '
    mov es:[di], ax
    add di, 2
    
    mov ah, 00001111b
    mov al, signo
    mov es:[di], ax
    add di, 2
    
    mov al, valor_CO1
    mov bl, 10
    mov ah, 0
    div bl
    mov cl, ah
    
    add al, 48
    mov dl, al
    mov ah, 00001111b
    mov al, dl
    mov es:[di], ax
    add di, 2
    
    mov al, cl
    add al, 48
    mov ah, 00001111b
    mov es:[di], ax
    add di, 2
    
    mov al, ' '
    mov es:[di], ax
    add di, 2
    mov al, ' '
    mov es:[di], ax
    add di, 2
    
    mov al, 'C'
    mov es:[di], ax
    add di, 2
    mov al, 'O'
    mov es:[di], ax
    add di, 2
    mov al, '2'
    mov es:[di], ax
    add di, 2
    mov al, ':'
    mov es:[di], ax
    add di, 2
    mov al, ' '
    mov es:[di], ax
    add di, 2
    
    mov ah, 00001111b
    mov al, signo
    mov es:[di], ax
    add di, 2

    mov al, valor_CO2
    mov bl, 10
    mov ah, 0
    div bl
    mov cl, ah
    
    add al, 48
    mov dl, al
    mov ah, 00001111b
    mov al, dl
    mov es:[di], ax
    add di, 2
    
    mov al, cl
    add al, 48
    mov ah, 00001111b
    mov es:[di], ax
    
    mov ah, 00h
    int 16h
    
fin:
    mov ah, 4ch
    int 21h
end



