import time
from time import strftime,gmtime #importando as funções necessarias

def Calc_temp():

    inicio = time.time() #utlizando a função time.time() para receber o time inicial
    i=0

    while i<1000000:
        i=i+1

    fim=time.time(); #recebe o time novamente,depois de terminar o laço 
    print('tempo de execução:{}'.format((fim-inicio)))#(fim-inicio)=tempo de execução
    print("Data:{}".format(strftime("%a,%d %b %Y")))#função que retorna o dia,mes e ano

if __name__==Calc_temp():
    Calc_temp()
