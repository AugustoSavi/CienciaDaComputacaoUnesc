'''Codigo criado para Testar o algoritmo QuickSort,
com as opções de melhor,pior e caso medio em uma lista de 520mil posiçôes

#13 de jun 2019#

Augusto Savi
Arthur Neto Bem
Arthur Hassan Souki
'''

import random
import time

def particao(a, ini, fim):
    pivo = a[fim - 1]
    start = ini
    end = ini
    for i in range(ini, fim):
        if a[i] > pivo:
            end += 1
        else:
            end += 1
            start += 1
            aux = a[start - 1]
            a[start - 1] = a[i]
            a[i] = aux
    return start - 1


def quick_sort(a, ini, fim):
    if ini < fim:
        pp = randparticao(a, ini, fim)
        quick_sort(a, ini, pp)
        quick_sort(a, pp + 1, fim)
    return a


def randparticao(a, ini, fim):
    rand = random.randrange(ini, fim)
    aux = a[fim - 1]
    a[fim - 1] = a[rand]
    a[rand] = aux
    return particao(a, ini, fim)


def pior_caso(lista):

    print('inserindo os valores no vetor')
    for i in range(520000, -1, -1):
        lista.append(i)

    print('Terminou de inserir no vetor e vai começar a ordenar')
    n = len(lista)
    inicio = time.time()
    lista = quick_sort(lista,0, n)
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

def melhor_caso(lista):
    for i in range(520000):
        lista.append(i)


    n = len(lista)
    inicio = time.time()
    lista = quick_sort(lista, 0, n)
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

def medio_caso(lista):
    for i  in range(520000):
        lista.append(random.randint(1,520000))

    n=len(lista)
    inicio = time.time()
    lista = quick_sort(lista, 0, n )
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

print("1- Pior Caso")
print("2- Melhor Caso")
print("3- Caso Medio")

opcao = int(input("Informe a opção:"))
lista = []
if (opcao == 1):
    pior_caso(lista)

if (opcao == 2):
    melhor_caso(lista)

if (opcao == 3):
    medio_caso(lista)

