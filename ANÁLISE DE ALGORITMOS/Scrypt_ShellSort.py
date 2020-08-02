'''Shell sort

Criado por Donald Shell em 1959,publicado pela Universidade de Cincinnati,
Shell sort é o mais eficiente algoritmo de classificação dentre os de complexidade quadrática.
É um refinamento do método de inserção direta.
O algoritmo difere do método de inserção direta pelo fato de no lugar de considerar o array
a ser ordenado como um único segmento,
ele considera vários segmentos sendo aplicado o método de inserção direta em cada um deles.
Basicamente o algoritmo passa várias vezes pela lista dividindo o grupo maior em menores.
Nos grupos menores é aplicado o método da ordenação por inserção.'''
import random
import time
tam = int(input("informe o tamanho do vetor que deseja:"))
vet = []

#criando vetor desordenado com numeros aleatorios
for aux in range(tam):
    vet.append(random.randint(0,(tam)))

print("vetor desordenado:{}".format(vet))

#shellSort
inicio= time.time()

h = 1
n = len(vet)
while h > 0:
    for i in range(h, n):
        c = vet[i]
        j = i
        while j >= h and c < vet[j - h]:
            vet[j] = vet[j - h]
            j = j - h
            vet[j] = c
    h = int(h / 2.2)

fim =time.time()

print("O vetor demorou {} segundos para ser ordenado:{}".format((fim-inicio),vet))

