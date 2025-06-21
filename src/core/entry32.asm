[BITS 32]

global _entry32
global kernel_registers

extern kmain

CODE_SEG equ 0x08
DATA_SEG equ 0x10

_entry32:
	mov ax, DATA_SEG
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax
  mov ebp, 0x00200000
  mov esp, ebp

	; Remap the master PIC
  mov al, 0x11
  out 0x20, al ; Tell master PIC
	out 0xA0, al

  mov al, 0x20 ; Interrupt 0x20 is where master ISR should start
  out 0x21, al

	mov al, 0x28
	out 0xA1, al

  mov al, 0x04 ; ICW3
  out 0x21, al

	mov al, 0x02
	out 0xA1, al

  mov al, 0x01
  out 0x21, al
	out 0xA1, al

  jmp CODE_SEG:kmain

	cli
	hlt
	jmp $

kernel_registers:
  mov ax, DATA_SEG
  mov ds, ax
  mov es, ax
  mov gs, ax
  mov fs, ax
  ret

times	512-($ - $$) db 0
