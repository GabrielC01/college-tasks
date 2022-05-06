; (x86)
; Programa para simular E/S na RAM
; + acesso via MMU

; A RAM é a variável RAM, e a MMU
; é o procedimento mmu.

; Constantes:
SYS_EXIT 	equ 1		; cód. de saída
SYS_READ 	equ 3		; cód. de leitura
SYS_WRITE 	equ 4		; cód. de escrita
MEM_SIZE 	equ 1024	; Tamanho da memória
MREAD 		equ 0		; Leitura da memória (modo)
MWRITE		equ 1		; Escrita na memória (modo)
