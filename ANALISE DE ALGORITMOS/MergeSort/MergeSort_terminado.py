'''Codigo criado para Testar o algoritmo MergeSort,
com as opções de melhor,pior e caso medio em uma lista de 520mil posiçôes

#13 de jun 2019#

Augusto Savi
Arthur Neto Bem
Arthur Hassan Souki
'''

import random
import time

'''Função que Fara a ordenação'''
def merge_sort(lista):
    if len(lista) > 1:

        meio = len(lista) // 2
        # também é valido: meio = int(len(lista)/2)

        listaDaEsquerda = lista[:meio]
        listaDaDireita = lista[meio:]

        merge_sort(listaDaEsquerda)
        merge_sort(listaDaDireita)

        i = 0
        j = 0
        k = 0

        while i < len(listaDaEsquerda) and j < len(listaDaDireita):

            if listaDaEsquerda[i] < listaDaDireita[j]:
                lista[k] = listaDaEsquerda[i]
                i += 1
            else:
                lista[k] = listaDaDireita[j]
                j += 1
            k += 1

        while i < len(listaDaEsquerda):
            lista[k] = listaDaEsquerda[i]
            i += 1
            k += 1

        while j < len(listaDaDireita):
            lista[k] = listaDaDireita[j]
            j += 1
            k += 1

    return lista

def pior_caso(lista):

    print('inserindo os valores no vetor')
    for i in range(520000, -1, -1):
        lista.append(i)

    print('Terminou de inserir no vetor e vai começar a ordenar')
    inicio = time.time()
    lista = merge_sort(lista)
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

def melhor_caso(lista):
    for i in range(520000):
        lista.append(i)

    inicio = time.time()
    lista = merge_sort(lista)
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

def medio_caso(lista):
    for i  in range(520000):
        lista.append(random.randint(1,520000))

    inicio = time.time()
    lista = merge_sort(lista)
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

