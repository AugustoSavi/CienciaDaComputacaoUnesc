#include <stdio.h>

float calculo(int numero1, int numero2)
{
  int diferenca;
  float resultado;
  diferenca = numero1 - numero2;
  resultado = numero1 / diferenca;
  return resultado;
}

int main(int argc, char *argv[])
{
  int valor, divisor, i;
  float resultado, total;
  valor = 10.1;
  divisor = 6;
  total = 0;
  for (i = 0; i < 10; i++)
  {
    resultado = calculo(valor, divisor);
    total += resultado;
    printf("%d  dividido por %d  é %f. A soma dos resultados é %f. \n", valor, valor - divisor, resultado, total);
    divisor++;
    valor--;
  }
  return 0;
}
