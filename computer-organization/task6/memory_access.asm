; (x86)
; Programa para simular E/S na RAM
; via MMU.
; A RAM é a variável RAM, e a MMU
; é o procedimento mmu.

;; Constantes:
SYS_EXIT 	equ 1		; cód. de saída 	 (Linux x86)
SYS_WRITE 	equ 4		; cód. de escrita	 (Linux x86)
MEM_SIZE 	equ 1024	; Tamanho da memória
MREAD 		equ 0		; Leitura da memória (modo)
MWRITE		equ 1		; Escrita na memória (modo)


;; Subprograma principal:
section .text
	global _start
_start


;; Outros subprogramas:
; Controlador da memória (MMU)
mmu:
	ret

; Imprime o pente de memória (tabela com seus elementos)
printRAMCard:
	ret


;; Seções de declaração variáveis
section .data
	RAM times MEM_SIZE dw 0 ; Memória zerada

section .bss
	; Argumentos do procedimento mmu:
	mmuArg0 resb	; Modo
	mmuArg1 resw	; Endereço de memória
	mmuArg3 resw	; Dado
