#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdio>
#include <map>
#include <fstream>
#include "pessoa.h"

using namespace std;


void inserirpessoa(){

    int idade;
    string nome,cidade;
    map<string,pessoa> map1;
    map<string,pessoa> ::iterator it;

        cout << "Nome: ";
        cin >> nome;
        cout << "idade: ";
        cin >> idade;
        cout<<"cidade:";
        cin>>cidade;
        
        map1.insert(make_pair(nome,pessoa(idade, cidade)));

}

void imprimir(){
	map<string,pessoa>::iterator it;
	map<string,pessoa> map1;
	
	for (it=map1.begin();it!=map1.end();it++){
      cout << "nome: " << it->first<< endl;
      cout<<"idade: "<<it->second.getidade();
	  cout<<"cidade: "<<it->second.getcidade();		
	}
	
}

void gravar_lista(){
	
	 map<string,pessoa> map1;
	fstream arq;

    arq.open("dados_pessoa.txt",ios::trunc );
    map<string,pessoa>::iterator it;
	
	for (it=map1.begin();it!=map1.end();it++){
	arq<<it->first<<"/t"<<it->second.getidade()<<it->second.getcidade();
	}
    arq.close();
}


void apagar_pessoa(){
	string nome;
	 map<string,pessoa> map1;
	cout <<"informe o nome a ser apagado da lista:"<<endl;
	cin>>nome;
	
	map1.erase(nome);
	
}

int main(){
      int opcao;
      while(true){
			
    cout << "1-> inserir pessoas"<<endl;
    cout << "2-> Mostrar dados da lista"<<endl;
    cout << "3-> apagar pessoa"<< endl;
    cout << "4-> Salvar a lista em arquivo"<<endl;
    cin>>opcao;

    
      switch (opcao) {

        case 1:
			
        inserirpessoa();

        case 2:
        imprimir();
        break;

        case 3:
        apagar_pessoa();
        break;
        
        case 4 :
		gravar_lista();
		break;

    }
  }
}
