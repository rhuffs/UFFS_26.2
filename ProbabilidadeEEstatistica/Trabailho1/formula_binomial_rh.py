import math

def bi_Individual(n, p, x):
    q = 1 - p
    combinacao = math.comb(n, x)
    probabilidade = combinacao * (p ** x) * (q ** (n - x))
    return probabilidade


def binomial_Acu(n, p, x):
    probabilidade = 0
    for k in range(x + 1):
        probabilidade += bi_Individual(n, p, k)
    return probabilidade




n = int(input("Digite o número de tentativas (n): "))
p = float(input("Digite a probabilidade de sucesso (p): "))
x = int(input("Digite o número de sucessos (x): "))

print()
print("Escolha o tipo de probabilidade:")
print("1 - P(X = x)")
print("2 - P(X <= x)")

opcao = input("Digite sua opção: ")

print()


if opcao == "1":
    resultado = bi_Individual(n, p, x)
    print(f"P(X = {x}) = {resultado:.6f}")

elif opcao == "2":
    resultado = binomial_Acu(n, p, x)
    print(f"P(X <= {x}) = {resultado:.6f}")

else:
    print("Opção inválida!")