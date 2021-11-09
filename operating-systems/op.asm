global _start

section .data
    menu: db "Escolha a operação.", 10, "(1) Soma", 10, "(2) Subtrai", 10, \
            "(Qualquer) Sair", 10, 0
    number1: db "Informe o 1º número: ", 0
    number2: db "Informe o 2º número: ", 0
    result: db "O resultado é ", 0
    crlf: db 10, 0

section .text
    _start:
        mov rdi, menu
        call print
        call read_num
        cmp rax, 0x1
        je sum_numbers
        cmp rax, 0x2
        je sub_numbers
        call exit

    exit:
        mov rax, 60     ; system call, exit
        mov rdi, 0      ; Valor de retorno da saída.
        syscall

    print:
        xor rdx, rdx    ; rdx = 0 ─ index

        .strlen:
            cmp byte[rdi + rdx], 0
            je .display
            inc rdx
            jmp .strlen

        .display:
            mov rsi, rdi    ; rsi, origem dos dados a serem escritos.
            mov rax, 0x1    ; syscall ─ write
            mov rdi, 0x1    ; descritor do arquivo para a saída padrão.
            syscall
            ret

    read_num:
        push rbx        ; Salvando o valor de rbx na pilha (para ser restaurado).
        sub rsp, 32     ; Subtraindo de rsp, estamos alocando 32B na pilha.
        mov rax, 0x0    ; Chamada de sistema ─ read.
        mov rdi, 0x0    ; Descritor 0, entrada padrão. De onde será lido.
        mov rdx, 31     ; Número de bytes a serem lidos.
        mov rsi, rsp    ; rsp, topo da pilha e buffer dos dados (32B).
        syscall         ; rcx e r11 são alterados, devido a syscall.
                        ; Read retorna em rax o número de bytes lidos.
        xor rax, rax    ; Zera o valor do registrador, rax.
        xor rbx, rbx    ; Zera o valor do registrador, rbx.
        xor rcx, rcx    ; Zera o valor do registrador, rcx.
        mov r8, 0xA     ; r8 = 10

        .loop:          ; Conversão de char para int
            ; bl é o último byte de rbx e rcx é o índice.
            ; typecast de char no indice rcx a partir da base, rsi
            mov bl, byte[rsi + rcx]
            cmp bl, 10  ; Se é igual ao fim 10 (\n).
            je .end     ; Então termina o loop.
            sub bl, 48  ; Transforma char em int da tabela ascii.
            xor rdx, rdx; rdx:rax funcionam como um registrador de 128bits.
                        ; devido a multiplação ou divisão ─ precisão.
            mul r8      ; Multiplacando rax por r8 (valor 10).
            add rax, rbx; Montando o número. (Como se tivesse concatenando).
            inc rcx     ; Avança uma posição no buffer.
            jmp .loop   ; Continua no loop.

        .end:
            add rsp, 32 ; Desalocando o buffer de 32B na pilha.
            pop rbx     ; Recupera rbx da pilha.
            ret

    sum_numbers:
        mov rdi, number1    ; Em rdi é atribuída a váriavel que vai ser 
        call print          ; passada para a função print.
        call read_num
        push rax            ; Salva no topo da pilha.
        mov rdi, number2
        call print
        call read_num
        pop rcx             ; Coloca o que está no topo da pilha.
        add rax, rcx
        push rax
        mov rdi, result
        call print
        pop rdi
        call print_number
        mov rdi, crlf
        call print
        mov rdi, crlf
        call print
        jmp _start

    sub_numbers:
        mov rdi, number1
        call print
        call read_num
        push rax        ; Salva no topo da pilha.
        mov rdi, number2
        call print
        call read_num
        pop rcx         ; Coloca o que está no topo da pilha.
        sub rcx, rax
        push rcx
        mov rdi, result
        call print
        pop rdi
        call print_number
        mov rdi, crlf
        call print
        mov rdi, crlf
        call print
        jmp _start

    print_number:
        mov rax, rdi    ; Copia rdi para rax
        xor rcx, rcx
        mov r8, 0xA
        sub rsp, 0x1
        mov byte[rsp], 0; Marca o fim da string (número).
        mov rcx, 0x1

        .loop:
            sub rsp, 1
            inc rcx
            xor rdx, rdx
            div r8      ; Divisão de rax por r8, rdx fica com o resto da div.
            add rdx, 48         ; 0 + 48 = char 0 a 9
            mov byte[rsp], dl   ; dl é o último byte de rdx.
            cmp rax, 0
            jne .loop

        mov rdi, rsp
        push rcx
        call print
        pop rcx
        add rsp, rcx
        ret
