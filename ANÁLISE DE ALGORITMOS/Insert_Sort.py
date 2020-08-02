import time
import random
print('-------------Insert Sort-------------')
tam = int(input('informe o tamanho do vetor a ser gerado:'))

lista=[]
inicio = time.time()

for aux in range(tam):
    lista.append(random.randint(0,1000))

print('vetor não ordenado:{}'.format(lista))

for i in range( 1, len( lista ) ):
    chave = lista[i]
    k = i
    while k > 0 and chave < lista[k - 1]:
        lista[k] = lista[k - 1]
        k -= 1
    lista[k] = chave

fim = time.time()

print('vetor ordenado:{}'.format(lista))

print('Tempo de execução:{}'.format(fim-inicio))

#Arthur Hassan Souki
#Arthur Neto Bem
#Augusto Savi
#04/04/2019