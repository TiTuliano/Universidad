
.MODEL SMALL
.CODE
org 100h

Programa_Int:

    JMP Reside

    ticks   DW 0
    secs    DW 0
    mins    DW 0

Rutina_Servicio PROC 
    
    CLI  
    
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    PUSH SI
    PUSH DI
    PUSH ES
    PUSH DS

    
    
    MOV AX, CS
    MOV DS, AX

   
    INC ticks
    MOV AX, ticks
    CMP AX, 18
    JB Restaurar  

    MOV ticks, 0

    INC secs
    CMP secs, 60
    JB Mostrar

    MOV secs, 0
    INC mins
    JMP Mostrar



Mostrar:

    MOV AX, 0B800h
    MOV ES, AX

    MOV DI, 0           

  
    MOV AX, mins
    MOV BX, 10
    XOR DX, DX           
    DIV BX               

 
    ADD AL, '0'
    MOV AH, 07h
    MOV ES:[DI], AX
    ADD DI, 2

   
    MOV AL, DL
    ADD AL, '0'
    MOV AH, 07h
    MOV ES:[DI], AX
    ADD DI, 2

    MOV AL, ':'
    MOV AH, 07h
    MOV ES:[DI], AX
    ADD DI, 2

  
    MOV AX, secs
    MOV BX, 10
    XOR DX, DX
    DIV BX              
  
  
    ADD AL, '0'
    MOV AH, 07h
    MOV ES:[DI], AX
    ADD DI, 2

    
    MOV AL, DL
    ADD AL, '0'
    MOV AH, 07h
    MOV ES:[DI], AX
    ADD DI, 2


Restaurar: 

    POP DS
    POP ES
    POP DI
    POP SI
    POP DX
    POP CX
    POP BX
    POP AX

    STI    
    IRET   
    
Rutina_Servicio ENDP

Reside:   

    MOV DX, offset Rutina_Servicio
    MOV AX, 0
    MOV ES, AX
    MOV SI, 1Ch * 4     

    CLI
    MOV ES:[SI], DX
    MOV ES:[SI+2], CS
    STI

    MOV DX, offset Reside
    INT 27h

END Programa_Int

