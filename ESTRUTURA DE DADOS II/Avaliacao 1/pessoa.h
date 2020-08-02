#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class pessoa{
	private:
		int idade;
		string cidade;
	
	
	public:
		pessoa();
		~pessoa();
		pessoa (int idade, string cidade);
		void setidade(int idade);
		int getidade();
		void setcidade(string cidade);
		string getcidade();
		void imprimir();
		
};

	pessoa::pessoa(){}
	
	pessoa::~pessoa(){}
	
	pessoa::pessoa(int idade, string cidade){
		this->idade=idade;
		this->cidade=cidade;
	}
	
	void pessoa::imprimir(){
		cout<<"cidade:"<<cidade<<"/t"<<"idade"<<idade;
	}
	
	void pessoa::setidade(int idade){
		this->idade=idade;
	}
	
	int pessoa::getidade(){
		return idade;
	}
	void pessoa::setcidade(string cidade){
		this->cidade=cidade;
	}
	string pessoa::getcidade(){
		return cidade;
	} 
