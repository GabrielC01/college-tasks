; (x86)
; Programa para simular E/S na RAM
; via MMU.
; A RAM é a variável RAM, e a MMU
; é o procedimento mmu.

;; Constantes:
SYS_EXIT 	equ 1		; cód. de saída 	 	(Linux x86)
SYS_WRITE 	equ 4		; cód. de escrita	 	(Linux x86)
STD_OUT		equ 1		; cód. da saída padrão	(Linux x86)
MEM_SIZE 	equ 16		; Tamanho da memória
MREAD 		equ 0		; Leitura da memória 	(modo)
MWRITE		equ 1		; Escrita na memória 	(modo)


;; Subprograma principal:
section .text
	global _start
_start:
    call print_RAM_card

    mov eax, SYS_EXIT
    mov ebx, 0
    int 0x80


;; Outros subprogramas:
; Controlador da memória (MMU)
mmu:
    cmp mmuArg0, MREAD
    je read
    read:
    mov eax, 
	ret

; Imprime o pente de memória (tabela com seus elementos)
print_RAM_card:
    mov eax, 4
    mov ebx, STD_OUT
    mov ecx, '['
    mov edx, 1
    int 0x80
    
    mov eax, MEM_SIZE
    mov ecx, RAM
    print_elements:
        push eax
        mov eax, 4
        mov ebx, STD_OUT
        mov edx, 1
        int 0x80
        add ecx, 1
        pop eax
        dec eax
        jnz print_elements
        
    mov eax, 4
    mov ebx, STD_OUT
    mov ecx, ']'
    mov edx, 1
    int 0x80
	ret


;; Seções de declaração de variáveis
section .data
	RAM times MEM_SIZE db '0' ; Memória zerada
	msg db 'something'

section .bss
	; Argumentos do procedimento mmu:
	mmuArg0 resb 1	; Modo
	mmuArg1 resw 1	; Endereço de memória
	mmuArg3 resw 1	; Dado
