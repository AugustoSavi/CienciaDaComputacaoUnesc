#include <string>
#include <iostream>

using namespace std;

//declara��o da classe pessoa
class pessoa{
   private:
      int codigo,parcelas;
      string nome;
      float valor_emprestado;


   public:
      pessoa();
      pessoa(int codigo, string nome, float valor_emprestado, int parcelas);
      ~pessoa();

      int getcodigo();
      void setcodigo(int codigo);

      string getnome();
      void setnome(string nome);

      void setvalor_emprestado(float valor_emprestado);
      float getvalor_emprestado();

      void setparcelas(int parcelas);
      int getparcelas();

      void imprimir();

};

//implementação das funçoes da classe pessoa
pessoa::pessoa(){}

pessoa::pessoa(int codigo, string nome, float valor_emprestado, int parcelas){
  this->codigo = codigo;
  this->nome = nome;
  this->valor_emprestado = valor_emprestado;
  this->parcelas = parcelas;
}

pessoa::~pessoa(){}

int pessoa::getcodigo(){
  return codigo;
}
void pessoa::setcodigo(int codigo){
   this->codigo = codigo;
}


string pessoa::getnome(){
   return nome;
}
void pessoa::setnome(string nome){
   this->nome = nome;
}


void pessoa::setvalor_emprestado(float valor_emprestado){
    this->valor_emprestado = valor_emprestado;
}
float pessoa::getvalor_emprestado(){
    return valor_emprestado;
}


void pessoa::setparcelas(int parcelas){
  this->parcelas = parcelas;
}
int pessoa::getparcelas(){
  return parcelas;
}

//apresenta os dados da pessoa no console
void pessoa::imprimir(){
  cout << "Codigo: " << codigo << " Nome: " << nome << endl;
}
