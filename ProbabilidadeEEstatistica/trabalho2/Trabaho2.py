# Implementar as fórmulas para estimação pontual
#  e intervalor de parâmetros e para cálculo de erro de estimação de: 1) Média e 2) Proporção.

# OBS: Trabalho feito em duplas.

def Correcao(n, N):
    if (n/N) > 0.05 :
        return 1
    else : 
        return -1

def confianca(z):
    if(z == 90):
        return 1,65
    elif(z == 95):
        return 1.96
    elif (z == 99):
        return 2.58

def estpontual(x):
    return print("Média pontual =",X)

def estintervalar(N,x,z,s,n):
    if Correcao(n,N) == 1:
        Correcao1 = (((N-n)/(n-1))**(1/2))
        pos = x + (z * (s/(n**(1/2)))*Correcao1)
        neg = x - (z * (s/(n**(1/2)))*Correcao1)
        print("A media intervalar é {pos} e {neg}")
    else:
        pos = x + (z * (s/(n**(1/2))))
        neg = x - (z * (s/(n**(1/2))))
        print("A media intervalar é {pos} e {neg}")

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


while(True):
    try :
        op = int(input("1) Média e 2) Proporção"))
    except ValueError :
        print("Coloque um valor inteiro, 1 ou 2!!")
        continue
    break

match op:
    case 1 :

        while True :
            while(True):
                try :
                    opcase1 = int(input("Digite 1- Media Pontual, 2-Estimativa intervalar"))
                except ValueError :
                    print("Coloque um valor inteiro, 1 ou 2!!")
                    continue
            match opcase1:
                case 1:
            
                while(True):
                    try :
                        X = float(input("Digite a media amostral"))
                    except ValueError :
                        print("Coloque um valor válidos")
                        continue
                    break
            estpontual(X)
        if opcase1 == 0:
            break
            
    case 2:
        print("funfa 2")
        #funcao fd de proporcao
    case _:
        print("funfa nsei")
        #caso default foda tbm
        




