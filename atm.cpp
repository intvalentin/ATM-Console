#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "atm.h"
using namespace std;


void atm::make(){
	pointer c=new Nod;
	
	temp->next=c;
	temp=c;
	temp->next=NULL;
}
void atm::Cont(){
	pointer aux=new Nod; int i=0;
	primul=aux,temp=primul;
	ifstream conturi;
	conturi.open("conturi.txt");
	
		if(!conturi.is_open()){
			exit(EXIT_FAILURE);
		}
	
	
		while(conturi.good()){
			
			atm::make();
			
			conturi >>aux->nume>>aux->pin>>aux->credit>>aux->ID;
			aux=temp;
			
		}
		
		
	
}

void atm::Afisare(string nume){
	pointer aux=primul; 
	int gasit=0;
	while(aux!=NULL && gasit==0){
		if(nume==aux->nume){
		
		cout<<"ID: "<<aux->ID<<endl;
		cout<<"Nume: "<<aux->nume<<endl;
		cout<<"Pin: "<<aux->pin<<endl;
		cout<<"Credit= "<<aux->credit<<" LEI"<<endl;
		gasit=1;
		}
		
		aux=aux->next;
	}
}

int atm::Logarea(){
	string name;
	pointer aux=primul;
	int gasit=0,i=0,pass;
	cout<<"------------[LogIN]------------"<<endl;
	cout<<"///////////////////////////////"<<endl;
	cout<<"-----------[Nume Cont]---------"<<endl;
	
	 log=NULL;
	
	for(i=0;gasit!=1 && i<3;i++){
		cin>>name;
	    while(aux!=NULL && gasit==0){
		    if(name==aux->nume){
			gasit=1;
			acc=aux->nume;
			log=aux;
			}
			
			aux=aux->next;
		}
		
	}
	gasit=0;
	if(!log){
	    		cout<<"Contul nu exista!"<<endl;
	    		Logarea();
	    		
			}
	cout<<"------------[Parola]-----------"<<endl;
	for(i=0;gasit!=1 && i<3;i++){
		
	    	
			cin>>pass;
		    
			if(pass==log->pin){
			gasit=1;
			return 1;
			}
			else{
				cout<<"Parola gresita!"<<endl;
			}
	}
	
	return 2;
}

void atm::Logareb(){
	int i=1,a;
	
	
	while(i=1){
	cout<<"------------[Meniu Cont]------------"<<endl;
	cout<<"[ 1 <> Vizualizarea date cont]"<<endl;
	cout<<"[ 2 <> Retragere numerar]"<<endl;
	cout<<"[ 3 <> Depunere de numerar]"<<endl;
	cout<<"[ 0 <> EXIT]"<<endl;
		cin>>a;
			if(a==1){
				Afisare(acc);
			}
			if(a==2){
				Retrager();
			}
			if(a==3){
				Depunere();
			}
			if(a==0){
				i=0;
				Logarea();
			}
			
	}
	
	
}
void atm::Retrager(){
	float suma;
	cout<<"-----------[Suma]---------"<<endl;
	cin>>suma;
	
	if(suma>log->credit){
		cout<<"Eroare[Suma dorita este prea mare]";
	}
	else{
		log->credit=log->credit-suma;
	}
}

void atm::Depunere(){
	float suma;
	cout<<"-----------[Suma]---------"<<endl;
	cin>>suma;
	log->credit=log->credit+suma;
}
