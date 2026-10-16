# Implementar as fórmulas para estimação pontual
#  e intervalor de parâmetros e para cálculo de erro de estimação de: 1) Média e 2) Proporção.

# OBS: Trabalho feito em duplas.
#função para fazer a checagem se foi digitado número
def isvariable(Mensagem, i):
    if i == 1:
        while(True):
            try :
                X = float(input(Mensagem))
                return X
            except ValueError :
                print("Valor(es) inválido(s)\n insíra apenas números sem nenhum caractere ou letras")
                continue
    elif i ==2:
        while(True):
            try :
                X = int(input(Mensagem))
                return X
            except ValueError :
                print("Valor(es) inválido(s)\n insíra apenas números sem nenhum caractere ou letras")
                continue

#caso para utilizar coreção

def Correcao(n, N):
    if N <= 1 or n <= 0 or n > N:
        raise ValueError(
            "A população deve ser maior que 1 e "
            "a amostra deve estar entre 1 e N."
        )

    if (n / N) > 0.05:
        return 1
    else:
        return -1

#caso para grau de confiança
def confianca():
    while(True):
        z = isvariable("Digite o grau de confiança obtidos na tabela (sem %): ", 2)
        if(z == 90):
            return 1.65
        elif(z == 95):
            return 1.96
        elif (z == 99):
            return 2.58
        else:
            print("\nOs números só podem ser 90, 95 e 99 exclusivamente!\n")
            continue

#estimativa pontual
def estpontual(x):
    return print("Média pontual =",x)

#estimativa intervalar
def estintervalar(N,x,z,s,n):
    if Correcao(n,N) == 1:
        Correcao1 = (((N-n)/(N-1))**(1/2))
        pos = x + (z * (s/(n**(1/2)))*Correcao1)
        neg = x - (z * (s/(n**(1/2)))*Correcao1)
        print(f"\nA media intervalar é {neg:.2f} e {pos:.2f}\n")
    else:
        pos = x + (z * (s/(n**(1/2))))
        neg = x - (z * (s/(n**(1/2))))
        print(f"\nA media intervalar é {neg:.2f} e {pos:.2f}\n")


def erro(N, z, s, n):
    erroVal = z * (s / (n ** 0.5))

    if Correcao(n, N) == 1:
        erroVal *= ((N - n) / (N - 1)) ** 0.5

    return erroVal

#estimativa pontual:
#   M = X
# M->média 
# x -> média amostral
# estimativa intervalar:
#     M = X +- Z* (S/(raizN))-> sem correção
#     M = X +- Z* (S/(raizN)) * raiz(N- m/(N-1))->com correção
# Z-> Desvio padrão normal
# S->desvio padrão/
# (**N)->Tam da amostra

#Proporção
#estimativa pontual



#escolher entre média e proporção
while True:
    print("-> Calculadoura de Média e Proporção\n")
    op = isvariable("Digite:\n1) Média; \n2) Proporção;\n3) Encerrar.\n>", 2)
    print("\nOBS: para casos depois da vírgula, utiliza-se caractere\n. (ponto) para números com vírgula em casos que precisa!\n EX.:\n" \
    "1.90 ->(não 1,90)\n")

    match op:
        #média
        case 1 :

            while True :
                opcase1 = isvariable("Digite: \n 1- Media Pontual;\n 2-Estimativa intervalar.\n 3-Voltar\n> ", 2)
                
                match opcase1:
                    case 1:
                        #Média pontual
                        X = isvariable("\nDigite a Média amostral: ", 1)
                        estpontual(X)

                    case 2:
                        #Média proporcional
                        # x -> média amostral 
                        n = isvariable("\nDigite o nº de elementos da amostra: ", 2)
                        N = isvariable("Digite o nº de elementos da população: ", 2)
                        X = isvariable("Digite a Média amostral:", 1)
                        print("OBS:\n Para desvio padrão normal precisa de seu grau de confiança: \n " \
                        "\033[4mgrau de confiança|    Z \n\033[0m" \
                        "       90%        |  1,65 \n" \
                        "       95%        |  1,96 \n" \
                        "       99%        |  2,58 \n")
                        Z = confianca()
                        S = isvariable("Digite o desvio padrão amostral: ",1)
                        if N <= 1 or n <= 0 or n > N:
                            print("Valores invalidos!")
                        else:
                            estintervalar(N, X, Z, S, n)
                            e= erro(N,Z,S,n)
                            print("O erro de estimacação é de{e:.2f}")

                        
                    case 3:
                        break
                    case _:
                        print("opção inválida")

        #proporção
        case 2:
            while True :
                opcase2 = isvariable("Digite: \n 1- Media Pontual;\n 2-Estimativa intervalar.\n 3-Voltar\n> ", 2)
                
                match opcase1:
                    case 1:
                        #Média pontual
                        X = isvariable("\nDigite a Média amostral: ", 1)
                        estpontual(X)

                    case 2:
                        #Média proporcional
                        # x -> média amostral 
                        n = isvariable("\nDigite o nº de elementos da amostra: ", 2)
                        N = isvariable("Digite o nº de elementos da população: ", 2)
                        X = isvariable("Digite a Média amostral:", 1)
                        print("OBS:\n Para desvio padrão normal precisa de seu grau de confiança: \n " \
                        "\033[4mgrau de confiança|    Z \n\033[0m" \
                        "       90%        |  1,65 \n" \
                        "       95%        |  1,96 \n" \
                        "       99%        |  2,58 \n")
                        Z = confianca()
                        S = isvariable("Digite o desvio padrão amostral: ",1)
                        if N <= 1 or n <= 0 or n > N:
                            print("Valores invalidos!")
                        else:
                            estintervalar(N, X, Z, S, n)
                    case 3:
                        break
                    case _:
                        print("opção inválida")

        case 3:
            break
        case _:
            print("funfa nsei")
            #caso default foda tbm