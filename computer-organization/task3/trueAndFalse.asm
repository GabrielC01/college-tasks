; Program to print true and false, 
; alternately, during ten seconds

SYS_EXIT 		equ 1		    ; sys_exit
SYS_WRITE 	    equ 4			; sys_write
SYS_NANOSLEEP   equ 162			; sys_nanosleep

section .data
	bit db 1				    ; starts as true
	strTrue	db "true "
	lenStrTrue equ $- strTrue
	strFalse	db "false "
	lenStrFalse equ $- strFalse
	oneSec dq 1, 10000          ; 1 sec

section .text
	global _start

; Linker entry point
_start:
	mov ecx, 10            ; Start counter at 10
	call _l1               ; Enter loop
	call _exit

; Loop
_l1:
	push ecx
	cmp [bit], byte 1
	je true
	jne false
true:
	call _printTrue
	call _sleepOneSec
	dec byte [bit]
	pop ecx
	loop _l1
false:
	call _printFalse
	call _sleepOneSec
	inc byte [bit]
	pop ecx
	loop _l1

; Wait a second
_sleepOneSec:
	mov eax, SYS_NANOSLEEP
	mov ebx, oneSec
	mov ecx, 0				; Not needed, set to 0
	int 0x80
	ret

; Print true
_printTrue:
	mov eax, 4
	mov ebx, 1
	mov ecx, strTrue
	mov edx, lenStrTrue
	int 0x80
	ret

_printFalse:
	mov eax, 4
	mov ebx, 1
	mov ecx, strFalse
	mov edx, lenStrFalse
	int 0x80
	ret

; End program
_exit:
	mov eax, SYS_EXIT
	mov ebx, 0					; No error
	int 0x80
	ret
