import math

def binomial_exato(n, p, x):
    return math.comb(n, x) * (p ** x) * ((1 - p) ** (n - x))


def binomial_menor_igual(n, p, x):
    probabilidade = 0

    for k in range(x + 1):
        probabilidade += math.comb(n, k) * (p ** k) * ((1 - p) ** (n - k))

    return probabilidade


n = 10
p = 0.5
x = 3

print("P(X = x):", binomial_exato(n, p, x))
print("P(X <= x):", binomial_menor_igual(n, p, x))
