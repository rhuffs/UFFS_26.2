#primeira: 
addi x1, x0, 10

#segunda
addi x1, x0, 10
addi x2, x0, 20
add x3, x1, x2
#Terceira
addi x1, x0, 4
sw x1, 0(x0)
lw x2, 0(x0)
#Quarta
addi x1, x0, 5
addi x2, x0, 5 
beq x1, x2, label #brach equal- é um if que diz que
                  #Se x1==x2 pula para label                          
addi x3, x0, 10 # Esta instrução vai ser pulada
    label:
        addi x4, x0, 20