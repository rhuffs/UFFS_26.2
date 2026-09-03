import math

#Probabilidade binomial individual
def probaindividual(n, x, p):
    q = 1 - p
    combinacao = math.comb(n,x)

    probabilidade = combinacao * (p ** x) * (q ** (n - x))
    return probabilidade

#Probabilidade binomial acumultativa
def probaacumulada(n,x,p):
    probabilidade = 0
    for i in range(x + 1):
        probabilidade += probaindividual(n, i, p)
    return probabilidade

#main
print("\033[3;31;31m========= DISTRIBUIÇÃO BINOMIAL =========\033[m")

n = int(input("Digite o Número de tentativas (N): "))
p = int(input("Digide o Número de probabilidade de sucesso (P): "))

print("\nEscolha o tipo de probabilidade:")
print("\033[2;34m1 - Probabilidade Binomial Individual (P = x)")
print("2 - Probabilidade Binomial Acumulada (P <= x)\033[m")

opcao = int(input("Digite a opção: "))

x = int(input("\nDigite o número de sucessos (x): "))

if(opcao == 1):
    resultado = probaindividual(n, x, p)


    print("\033[0;32m\nProbabilidade Binomial Individual:")
    print(f"P(X = {x}) = {resultado:.6f}")
    print(f"P(X = {x}) = {resultado * 100:.2f}%")
elif(opcao == 2):
    resultado = probaacumulada(n,x,p)
    print("\nProbabilidade Binomial acumulada:")
    print(f"P(X = {x}) = {resultado:.6f}")
    print(f"P(X = {x}) = {resultado * 100:.2f}%")
else:
    print("\033[1;31;47m\n== OPÇÃO INVÁLIDA ==\n")
