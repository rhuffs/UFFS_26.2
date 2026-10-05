# ============================================================
# Trabalho 1 - Organização de Computadores
# Lista Encadeada + Merge Sort
# Arquitetura: RISC-V
# Ambiente: Venus
#
# Requisitos atendidos:
# - Lista encadeada
# - Alocação dinâmica no heap (sbrk)
# - Merge Sort
# - Uso de jal
# - Uso de jalr
# - Uso da stack para salvar/restaurar registradores
# ============================================================


.data

# Valores usados para criar a lista
valores:
    .word 38, 12, 45, 7, 23, 4, 19, 31

quantidade:
    .word 8

msg_original:
    .asciiz "Lista original: "

msg_ordenada:
    .asciiz "Lista ordenada: "

espaco:
    .asciiz " "

quebra:
    .asciiz "\n"


.text
.globl main


# ============================================================
# MAIN
# ============================================================

main:

    # --------------------------------------------------------
    # Criar lista vazia
    #
    # s0 = inicio da lista
    # s1 = quantidade de elementos
    # --------------------------------------------------------

    li s0, 0

    la t0, quantidade
    lw s1, 0(t0)


    # --------------------------------------------------------
    # Inserir os elementos na lista
    # --------------------------------------------------------

    la t0, valores

    li t1, 0


loop_insercao:

    bge t1, s1, fim_insercao

    lw a0, 0(t0)

    # Chamada direta usando jal
    jal ra, inserir_fim

    # Próximo elemento do vetor
    addi t0, t0, 4
    addi t1, t1, 1

    j loop_insercao


fim_insercao:

    # --------------------------------------------------------
    # Mostrar lista original
    # --------------------------------------------------------

    la a0, msg_original
    jal ra, imprimir_string

    mv a0, s0

    # Demonstração de chamada indireta usando jalr
    # t0 recebe o endereço da função imprimir_lista
    la t0, imprimir_lista
    jalr ra, 0(t0)

    la a0, quebra
    jal ra, imprimir_string


    # --------------------------------------------------------
    # Ordenar lista com Merge Sort
    # --------------------------------------------------------

    mv a0, s0

    jal ra, merge_sort

    # Retorno:
    # a0 = novo início da lista ordenada

    mv s0, a0


    # --------------------------------------------------------
    # Mostrar lista ordenada
    # --------------------------------------------------------

    la a0, msg_ordenada
    jal ra, imprimir_string

    mv a0, s0
    jal ra, imprimir_lista

    la a0, quebra
    jal ra, imprimir_string


    # --------------------------------------------------------
    # Encerrar programa
    # --------------------------------------------------------

    li a0, 10
    ecall



# ============================================================
# inserir_fim
#
# Entrada:
#   a0 = valor a ser inserido
#   s0 = início da lista
#
# Node:
#
#   +0 = valor
#   +4 = próximo
#
# Retorno:
#   s0 = início da lista
# ============================================================

inserir_fim:

    # --------------------------------------------------------
    # Salvar registradores na stack
    # --------------------------------------------------------

    addi sp, sp, -16

    sw ra, 12(sp)
    sw s1, 8(sp)
    sw s2, 4(sp)
    sw s3, 0(sp)


    mv s1, a0


    # --------------------------------------------------------
    # Alocar memória para um novo nó
    #
    # Cada nó possui 2 words:
    #
    # 4 bytes -> valor
    # 4 bytes -> ponteiro next
    #
    # Total = 8 bytes
    # --------------------------------------------------------

    li a0, 9
    li a1, 8
    ecall

    # a0 = endereço do novo nó

    mv s2, a0


    # Guardar valor
    sw s1, 0(s2)

    # next = NULL
    sw zero, 4(s2)


    # --------------------------------------------------------
    # Se a lista estiver vazia
    # --------------------------------------------------------

    beq s0, zero, lista_vazia


    # --------------------------------------------------------
    # Procurar último nó
    # --------------------------------------------------------

    mv s3, s0


procura_fim:

    lw t0, 4(s3)

    beq t0, zero, encontrou_fim

    mv s3, t0

    j procura_fim


encontrou_fim:

    # último->next = novo
    sw s2, 4(s3)

    j fim_inserir


lista_vazia:

    # O novo nó vira o primeiro
    mv s0, s2


fim_inserir:

    # Restaurar registradores

    lw s3, 0(sp)
    lw s2, 4(sp)
    lw s1, 8(sp)
    lw ra, 12(sp)

    addi sp, sp, 16

    ret



# ============================================================
# merge_sort
#
# Entrada:
#   a0 = início da lista
#
# Retorno:
#   a0 = início da lista ordenada
#
# Implementação recursiva
# ============================================================

merge_sort:

    addi sp, sp, -24

    sw ra, 20(sp)
    sw s0, 16(sp)
    sw s1, 12(sp)
    sw s2, 8(sp)
    sw s3, 4(sp)
    sw s4, 0(sp)


    mv s0, a0


    # --------------------------------------------------------
    # Caso base
    #
    # Lista vazia:
    #   return NULL
    #
    # Apenas um elemento:
    #   return lista
    # --------------------------------------------------------

    beq s0, zero, merge_retorno

    lw t0, 4(s0)

    beq t0, zero, merge_retorno


    # --------------------------------------------------------
    # Encontrar o meio da lista
    #
    # Usamos dois ponteiros:
    #
    # lento -> anda 1 posição
    # rapido -> anda 2 posições
    # --------------------------------------------------------

    mv s1, s0
    mv s2, s0


encontra_meio:

    lw t0, 4(s2)

    beq t0, zero, meio_encontrado

    lw t1, 4(t0)

    beq t1, zero, meio_encontrado

    # lento = lento->next
    lw s1, 4(s1)

    # rápido = rápido->next->next
    lw s2, 4(t0)

    j encontra_meio


meio_encontrado:

    # --------------------------------------------------------
    # s1 está próximo do meio.
    #
    # s3 = início da segunda metade
    # --------------------------------------------------------

    lw s3, 4(s1)

    # Cortar a lista em duas partes
    sw zero, 4(s1)


    # --------------------------------------------------------
    # Ordenar primeira metade
    # --------------------------------------------------------

    mv a0, s0

    jal ra, merge_sort

    mv s0, a0


    # --------------------------------------------------------
    # Ordenar segunda metade
    # --------------------------------------------------------

    mv a0, s3

    jal ra, merge_sort

    mv s3, a0


    # --------------------------------------------------------
    # Intercalar as duas listas
    # --------------------------------------------------------

    mv a0, s0
    mv a1, s3

    jal ra, merge

    mv s4, a0


    # --------------------------------------------------------
    # Retornar resultado
    # --------------------------------------------------------

    mv a0, s4


merge_retorno:

    lw s4, 0(sp)
    lw s3, 4(sp)
    lw s2, 8(sp)
    lw s1, 12(sp)
    lw s0, 16(sp)
    lw ra, 20(sp)

    addi sp, sp, 24

    ret



# ============================================================
# merge
#
# Entrada:
#   a0 = primeira lista ordenada
#   a1 = segunda lista ordenada
#
# Retorno:
#   a0 = lista resultante
#
# Não cria novos nós.
# Apenas altera os ponteiros next.
# ============================================================

merge:

    addi sp, sp, -24

    sw ra, 20(sp)
    sw s0, 16(sp)
    sw s1, 12(sp)
    sw s2, 8(sp)
    sw s3, 4(sp)
    sw s4, 0(sp)


    mv s0, a0
    mv s1, a1


    # --------------------------------------------------------
    # Verificar listas vazias
    # --------------------------------------------------------

    beq s0, zero, primeira_vazia

    beq s1, zero, segunda_vazia


    # --------------------------------------------------------
    # Escolher o primeiro nó
    # --------------------------------------------------------

    lw t0, 0(s0)
    lw t1, 0(s1)

    ble t0, t1, primeira_menor


    # Segunda lista começa primeiro
    mv s2, s1
    lw s1, 4(s1)

    j inicio_merge


primeira_menor:

    mv s2, s0
    lw s0, 4(s0)


inicio_merge:

    # s2 = primeiro nó da lista resultante
    # s3 = último nó da lista resultante

    mv s3, s2


# ------------------------------------------------------------
# Loop principal do merge
# ------------------------------------------------------------

merge_loop:

    beq s0, zero, adiciona_segunda

    beq s1, zero, adiciona_primeira


    lw t0, 0(s0)
    lw t1, 0(s1)


    # Comparar valores

    ble t0, t1, pega_primeira


    # --------------------------------------------------------
    # Pegar nó da segunda lista
    # --------------------------------------------------------

    sw s1, 4(s3)

    mv s3, s1

    lw s1, 4(s1)

    j merge_loop


pega_primeira:

    # --------------------------------------------------------
    # Pegar nó da primeira lista
    # --------------------------------------------------------

    sw s0, 4(s3)

    mv s3, s0

    lw s0, 4(s0)

    j merge_loop


# ------------------------------------------------------------
# Primeira lista acabou
# ------------------------------------------------------------

adiciona_segunda:

    sw s1, 4(s3)

    j merge_fim


# ------------------------------------------------------------
# Segunda lista acabou
# ------------------------------------------------------------

adiciona_primeira:

    sw s0, 4(s3)


merge_fim:

    mv a0, s2


    lw s4, 0(sp)
    lw s3, 4(sp)
    lw s2, 8(sp)
    lw s1, 12(sp)
    lw s0, 16(sp)
    lw ra, 20(sp)

    addi sp, sp, 24

    ret



# ============================================================
# imprimir_lista
#
# Entrada:
#   a0 = início da lista
# ============================================================

imprimir_lista:

    addi sp, sp, -16

    sw ra, 12(sp)
    sw s0, 8(sp)
    sw s1, 4(sp)
    sw s2, 0(sp)


    mv s0, a0


imprimir_loop:

    beq s0, zero, imprimir_fim


    # Imprimir valor

    lw a1, 0(s0)

    li a0, 1
    ecall


    # Imprimir espaço

    la a1, espaco

    li a0, 4
    ecall


    # Próximo nó

    lw s0, 4(s0)

    j imprimir_loop


imprimir_fim:

    lw s2, 0(sp)
    lw s1, 4(sp)
    lw s0, 8(sp)
    lw ra, 12(sp)

    addi sp, sp, 16

    ret



# ============================================================
# imprimir_string
#
# Entrada:
#   a0 = endereço da string
# ============================================================

imprimir_string:

    # O endereço recebido está em a0.
    # Venus espera:
    #
    # a0 = 4 -> imprimir string
    # a1 = endereço da string

    mv a1, a0

    li a0, 4

    ecall


    r