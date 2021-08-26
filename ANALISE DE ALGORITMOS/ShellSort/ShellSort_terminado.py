'''Codigo criado para Testar o algoritmo de ShellSort,
com as opções de melhor,pior e caso medio em uma lista de 520mil posiçôes

#13 de jun 2019#

Augusto Savi
Arthur Neto Bem
Arthur Hassan Souki
'''

import random
import time

'''Função que Fara a ordenação'''
def shell_sort(lista):
    h = 1
    n = len(lista)
    while h > 0:
        for i in range(h, n):
            c = lista[i]
            j = i
            while j >= h and c < lista[j - h]:
                lista[j] = lista[j - h]
                j = j - h
                lista[j] = c
        h = int(h / 2.2)
    return lista

def pior_caso(lista):

    print('inserindo os valores no vetor')
    for i in range(520000, -1, -1):
        lista.append(i)

    print('Terminou de inserir no vetor e vai começar a ordenar')
    inicio = time.time()
    lista = shell_sort(lista)
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

def melhor_caso(lista):
    for i in range(520000):
        lista.append(i)

    inicio = time.time()
    lista = shell_sort(lista)
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

def medio_caso(lista):
    for i  in range(520000):
        lista.append(random.randint(1,520000))

    inicio = time.time()
    lista = shell_sort(lista)
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

