#include<iostream>
#include "ADT2.h"
#include<stdlib.h>

using namespace std;

ADT::ADT(int dim){ 
	size=dim;     
	p=new int [size];
	end=-1;}

bool ADT::isFull(){
		return (end==size-1);}

bool ADT::isEmpty(){
		return (end==-1);}
	
int ADT::GetFine(){
	if(isEmpty()){
		return -1;}
		else{
		return p[end];}
	}	

int ADT::GetInizio(){
		if(isEmpty()){
		return -1;}
		else{
		return p[0];}}


int ADT::Trova(int x){
if(!isEmpty()){
	int cont=0;
	int *v;
	for(v=p;v-p<end;v++){
		if(p[*v]==x)
			cont++;}
		return cont;			
			}
	else{
	return -1;}
}

int ADT::SommaElementi(){
	int somma=0;
	int *v;
	for(v=p;v-p<end;v++){
		somma+=p[*v];}
	return somma;
}

bool ADT::InserisciInPosizione(int elem, int indice){
	if(!isFull()){
		if(isEmpty()){
		end=0;
		p[end]==elem;
		return true;}
	for(int i=end; i>indice;i--){
		p[i+1]=p[i];}
		p[indice]=elem;
	return true;}
	else{
		return -1; //array pieno
	}
}		

bool ADT::CancellaInPosizione(int indice){
	if(!isEmpty()){
	for(int i=indice; i>end; i++){
		p[i]=p[i+1];}
	end--;	
	return true;
	}
	else{
		return false;
	}
}

Coda::Coda(int x):ADT(x){}

bool Coda::InserisciCoda(int elem){
	return ADT::InserisciInPosizione(elem,end+1);
}

bool Coda::CancellaCoda(void){
	return ADT::CancellaInPosizione(0);
}

Pila::Pila(int x):ADT (x){ 
	numIns=0;
	numCanc=0;
}

bool Pila::InserisciPila(int elem){
	return ADT::InserisciInPosizione(elem,end+1);
	numIns++;
}

bool Pila::CancellaPila(void){
	return ADT::CancellaInPosizione(0);
	numCanc++;
}


