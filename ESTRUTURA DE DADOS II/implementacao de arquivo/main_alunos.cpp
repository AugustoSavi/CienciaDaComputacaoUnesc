#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <map>

//utilizado para manipula��o de arquivos
#include <fstream>

#include "func_pessoa.h"

using namespace std;

//GRAVAR_PESSOAS
int gravar_pessoa(){

    //solicita os dados para o usu�rio
    vector<pessoa> vetor;
    int codigo,parcelas,aux;
    float valor_emprestado;
    string nome;
      map<int,pessoa,less<int>> map;

    while (true) {
        cout << "Nome: ";
        cin >> nome;
        cout<<"valor_emprestado: ";
        cin>>valor_emprestado;
        cout<<"quantidade de parcelas:";
        cin>>parcelas;

        map.insert(make_pair(codigo,pessoa(codigo, nome, valor_emprestado, parcelas)));

        vetor.push_back(pessoa(codigo,nome,valor_emprestado,parcelas));
      cout << "deseja continuar a gravar? \n 1->Sim,2->Não \n >>";
        cin>>aux;
        if (aux==2) {
          break;
        }
        codigo++;
      }

    //grava o conte�do em disco
    fstream arq;

    arq.open("dados_pessoa.txt",ios::app | ios :: out );
    cout << "Gravando..." << endl;

    for(int i = 0; i < vetor.size(); i++){

      arq<<vetor[i].getcodigo()<<"\t"<<vetor[i].getnome()<<"\t"<<vetor[i].getvalor_emprestado()<<"\t"<<vetor[i].getparcelas()<<"\n";


    }
    cout << "Dados gravados com sucesso..." << endl;
    cout <<"--------------------------"<<endl;

    arq.close();//fecha o arquivo
    return vetor.size();//retorna o tamanho do vetor para poder usar no ler_pessoa
}

int ler_pessoa(int tam_vetor){
    float valor_emprestado;
    int codigo,parcelas;
    string nome;

    fstream arq ("dados_pessoa.txt",ios :: app | ios::in);

    if(arq.fail() == 1){
      cout << "O arquivo a ser lido nao esta gravado em disco" << endl;
      return 0;
    }

    //int i = 0;
      while (!arq.eof()) {

        arq>> codigo >> nome >> valor_emprestado >> parcelas;
        cout << "codigo:"<<codigo<<endl;
        cout << "nome: "<<nome<<endl;
        cout << "valor_emprestado: "<<valor_emprestado<<endl;
        cout << "parcelas:"<< parcelas<<endl;
        cout<<"---------------------------"<<endl;

      }
    arq.close();

    return 1;
}

void limpar_txt(){

  fstream arq ("dados_pessoa.txt",ios :: trunc);

    remove("dados_pessoa.txt");

  arq.close();

}
void calcular_valor_parcelas(int tam_vetor){
  float valor_emprestado,valor_parcelas;
  int codigo,parcelas;
  string nome;
  //map<int,pessoa,less<int>> map;

  fstream arq ("dados_pessoa.txt",ios::in|ios :: out);

  if(arq.fail() == 1){
    cout << "O arquivo a ser lido nao esta gravado em disco" << endl;
  }

  else{
        while (!arq.eof()) {
          arq>> codigo >> nome >> valor_emprestado >> parcelas;
          cout << "codigo:"<<codigo<<endl;
          cout << "nome: "<<nome<<endl;
          cout << "valor_emprestado: "<<valor_emprestado<<endl;
          cout << "parcelas:"<< parcelas<<endl;
          cout << "valor de cada parcela: " << (valor_emprestado/parcelas)<<endl;

          //pessoa(int codigo, string nome, float valor_emprestado, int parcelas);

        //  map.insert(make_pair(codigo,pessoa(codigo, nome, valor_emprestado, valor_parcelas)));

          cout<<"---------------------------"<<endl;
        }
    }
}

/*void valor_parcelas_por_map(){
  map<int, pessoa, less<int>>::iterator it;

if(!map.empty()){
   for(it = map.begin(); it != map.end(); it++){
      cout << "-----------------" << endl;
      cout << "Chave: " << it->first << endl;
      cout << "nome: " << it->second.getnome() << endl;
      it->second.imprimir();
   }
 }
}*/ //essa parte eu não consegui fazer,seria uma busca no map pelo codigo;

int main(){
      int tam_vetor=0,opcao;
      while(true){
    cout << "----------informe a opção:----------" <<endl;
    cout << "1-> ler pessoas"<<endl;
    cout << "2-> imprimir pessoas"<<endl;
    cout << "3-> limpar lista"<< endl;
    cout << "4-> mostrar o valor das parcelas de todos"<<endl;
    cin>>opcao;

    cout<<"----------"<<endl;
    system("clear");
      switch (opcao) {

        case 1:
        tam_vetor=gravar_pessoa();//pede as informações para o usuario
        break;

        case 2:
        ler_pessoa(tam_vetor);//imprimir os dados salvos

        break;

        case 3:
        limpar_txt();//deleta o arquivo
        break;

        case 4:
        calcular_valor_parcelas(tam_vetor);
        break;

    }
  }
}
