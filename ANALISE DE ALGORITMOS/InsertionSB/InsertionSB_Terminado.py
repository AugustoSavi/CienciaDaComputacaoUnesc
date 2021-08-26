'''Codigo criado para Testar o algoritmo de Inserção direta com Busca Binaria,
com as opções de melhor,pior e caso medio em uma lista de 520mil posiçôes

#13 de jun 2019#

Augusto Savi
Arthur Neto Bem
Arthur Hassan Souki
'''

import random
import time

'''Python não tem por padrão a função de busca binaria 
    então é necessario codificar ela Tmbm'''
def binary_search(vetor, valor, comeco, final):

    if comeco == final:
        if vetor[comeco] > valor:
            return comeco
        else:
            return comeco + 1

    if comeco > final:
        return comeco

    meio = (comeco + final) // 2
    if vetor[meio] < valor:
        return binary_search(vetor, valor, meio + 1, final)
    elif vetor[meio] > valor:
        return binary_search(vetor, valor, comeco, meio - 1)
    else:
        return meio

'''Função que Fara a ordenação'''

def insertion_sort(vetor):
    for i in range(1, len(vetor)):
        valor = vetor[i]
        j = binary_search(vetor, valor, 0, i - 1)
        vetor = vetor[:j] + [valor] + vetor[j:i] + vetor[i + 1:]
    return vetor

def pior_caso(lista):

    print('inserindo os valores no vetor')
    for i in range(52000, -1, -1):
        lista.append(i)

    print('Terminou de inserir no vetor e vai começar a ordenar')
    inicio = time.time()
    lista = insertion_sort(lista)
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

def melhor_caso(lista):
    for i in range(520000):
        lista.append(i)

    inicio = time.time()
    lista = insertion_sort(lista)
    fim = time.time()
    print('Tempo de execução:{}'.format(fim - inicio))
    print(lista)

def medio_caso(lista):
    for i  in range(520000):
        lista.append(random.randint(1,520000))

    inicio = time.time()
    lista = insertion_sort(lista)
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

