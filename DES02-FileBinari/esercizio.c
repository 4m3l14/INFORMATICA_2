/******************************************************************************************
* \mainpage record dei file
*
* @brief inserisce record carica e stampa dati dello studente, ricerca tramite cognome, correggi				
* @author 		Wannaku Amelia
* @date 		29/11/2022
* @version 1.0 	29/11/2022 Versione iniziale
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C 20
#define V 8
#define N 2

struct data
{
	int giorno;
	char mese[C];
	int anno;
}typedef data;

struct studente
{
	char cognome[C];
	data nascita;
	int voti[V];
}typedef studente;

int menu(void); //menu 

void InserisciRecord(char[], int );    /*inserisce in coda n record con i dati richiesti all’utente. 
Se il file non esiste va creato e quindi effettuare l’inserimento. */

void stampaFile(char[]); /*stampa su monitor (una riga per record) tutte le informazioni contenute nel file*/

int ricercaRecord (char[], char[]);  /*per ogni record che ha il contenuto del campo cognome uguale al parametro, 
stampa cognome, eta' e media dei voti. La funzione restituisce la posizione del primo record trovato.*/

int stampaRecord(char [], int ); /*stampa le informazioni presenti nel record specificato 
dal parametro posizione. Restituisce 0 se il record è presente -1 altrimenti.*/

int correggiRecord(char [], int ); /*visualizza le informazioni del record richiamando la funzione stampaRecord e
 corregge l’intero record, con i nuovi dati richiesti all’utente.*/
 
int numeroRecord(char []); //restituisce il numero di record presenti nel file.


int main()
{
	char nomeFile[]={"test.dat"};
	int r, s, a, dim=2;
	char st[C];
	do{
		s=menu();	
		switch(s){
			case 1: 
				printf("\nInserire quanti record vuoi. Inserisci un intero\n");
				scanf("%d", &r);
				InserisciRecord(nomeFile, r);	
				break;
			case 2: 
				stampaFile(nomeFile);	
				break;
			case 3:	
				printf("\nInserisci il cognome da cercare\n");
				scanf("%s", st);
				r=ricercaRecord(nomeFile, st);		
				if(r!=1){	
					printf("\nErrore, record non trovato");
				}
				break;
			case 4:	
				printf("\nInserisci la posizione \n");
				scanf("%d", &a);
				r=stampaRecord(nomeFile, a);	
				if(r==-1){
					printf("\nErrore, record non trovato");
				}
				break;
			case 5:	
				printf("\nInserire la posizione del record da correggere\n");
				scanf("%d", &a);
				r=correggiRecord(nomeFile, a);
				if(r==-1){
					printf("\nErrore, record non trovato");
				}
				break;
			case 6:	
				r=numeroRecord(nomeFile);	
				printf("\nSono presenti %d record nel file", r);
				break;
			case 0:	
				printf("\nCiao!");				
				break;
			default:	
				printf("Errore!");	
				break;			
		}	
	}while(s!=0);
	return 0;
}



/** ****************************************************************************************
* @brief inserisce in coda n record con i dati richiesti all’utente. 
*Se il file non esiste va creato e quindi effettuare l’inserimento.
*
*
* @author Wannaku Amelia
* @version 1.0 29/11/2022
*/

void InserisciRecord(char fileName[], int numRecord)
{
	FILE *pFile;
	studente buffer;
	int i, j, r;
	
	pFile=fopen(fileName,"ab");
	
	srand(time(NULL));
	if(pFile!=NULL){
		for(i=0;i<numRecord;i++){
			printf("Inserisci il cognome dello studente:\n");
			scanf("%s",buffer.cognome);
			printf("Inserisci il giorno di nascita dello studente:\n");
			scanf("%d",&buffer.nascita.giorno);
			printf("Inserisci in caratteri il mese di nascita dello studente in caratteri:\n");
			scanf("%s",buffer.nascita.mese);
			printf("Inserisci l'anno di nascita dello studente:\n");
			scanf("%d",&buffer.nascita.anno);
		}
		for(j=0;j<V;j++){
			buffer.voti[j]=1+rand()%10;
		}
		fwrite(&buffer,sizeof(studente), 1, pFile);
	fclose(pFile);
}


/******************************************************************************************
* @brief stampa su monitor (una riga per record) tutte le informazioni contenute nel file
*
* @author Wannaku Amelia
* @version 1.0 29/11/2022
*/

void stampaFile(char fileName[])
{
	FILE *pFile;
	studente buffer;
	int n, j;
	
	pFile=fopen(fileName,"rb");
	
	if(pFile!=NULL){
		while(!feof(pFile)){
			n=fread(&buffer, sizeof(studente), 1, pFile);
		
			if(n>0){
				printf("Cognome dello studente: %s\t",buffer.cognome);
				printf("E' nato il %d/%s/%d\t",buffer.nascita.giorno,buffer.nascita.mese,buffer.nascita.anno);
				printf("I voti sono:\t");
				for(j=0;j<V;j++){	
					printf("%d\t",buffer.voti[j]);            
				}
			}
		printf("\n");
		}	
	fclose(pFile);	
	}	
	else
		printf("Errore nell'apertura del file");
}

/** ****************************************************************************************
* @brief per ogni record che ha il contenuto del campo cognome uguale al parametro, 
*stampa cognome, eta' e media dei voti. La funzione restituisce la posizione del primo record trovato.
*
*
* @author Wannaku Amelia
* @version 1.0 19/12/2022
*/

int ricercaRecord (char fileName[], char cognome[])
{
	FILE *pFile;
	studente buffer;
	int i, n=0, media=0, eta=0, anno=2022;
	
	pFile=fopen(fileName,"rb");
	
	if(pFile!=NULL){
		while(!feof(pFile)){
			n=fread(&buffer, sizeof(studente), 1, pFile);
			if(strcmp(buffer.cognome,cognome)==0){
				printf("Cognome dello studente: %s\n",buffer.cognome);
				printf("e' nato il %d/%d/%d\n",buffer.nascita.giorno,buffer.nascita.mese,buffer.nascita.anno);
				eta=anno-buffer.nascita.anno;
				printf("eta':%d\n",eta);
			}	
			for(i=0; i<V; i++){
				media=media+buffer.voti[i];
			}
			media=media/V;
			printf("la media e' %.2f\n",media);
		}
		fclose(pFile);
		return 1;
	}	
	else{
		printf("Errore nell'apertura del file");
		return -1;
	}		
}


/** ****************************************************************************************
* @brief stampa le informazioni presenti nel record specificato 
*dal parametro posizione. Restituisce 0 se il record è presente -1 altrimenti.
*
*
* @author Wannaku Amelia
* @version 1.0 19/12/2022
*/


int stampaRecord(char fileName[], int posizione)
{
	FILE *pFile;
	studente buffer;
	int n;
	
	pFile=fopen(fileName,"rb");
	//apertura del file senza problemi
	if(pFile!=NULL){
		//funzione fseek posizionare il puntatore del File nella posizione desiderata 
		fseek(pFile, posizione*sizeof(buffer), SEEK_SET); 
		//lettura dei dati dello struct scelto dall'utente 
		n=fread(&buffer, sizeof(studente), 1, pFile);
		if(n>0){
			printf("Cognome dello studente: %s\t",buffer.cognome);
			printf("E' nato il %d/%s/%d\t",buffer.nascita.giorno,buffer.nascita.mese,buffer.nascita.anno);
			printf("I voti sono:\t");
			for(j=0;j<V;j++){	
				printf("%d\t",buffer.voti[j]); 
			}
			printf("\n");   
			fclose(pFile);  
			return 0;     
		}
		else{
		//se il record non viene letto
		return -1;
		}
	}
	else{
		printf("Errore in apertura file");
		return -1;
	}
}



/** ****************************************************************************************
* @brief visualizza le informazioni del record richiamando la funzione stampaRecord e
*corregge l’intero record, con i nuovi dati richiesti all’utente
*
*
* @author Wannaku Amelia
* @version 1.0 20/12/2022
*/

int correggiRecord(char fileName[], int posizione)
{
	FILE *pFile;
	studente buffer;
	pFile=fopen("file.dat","rb+");
	int r, n;
	
	if(pFile!=NULL){
		fseek(pFile, posizione*sizeof(buffer), SEEK_SET);
		n=fread(&buffer,sizeof(studente),1,pFile);
		r=stampaRecord(fileName, posizione);
		if(n>0){
			printf("Inserisci il cognome dello studente:\n");
			scanf("%s",buffer.cognome);
			printf("Inserisci il giorno di nascita dello studente:\n");
			scanf("%d",&buffer.nascita.giorno);
			printf("Inserisci in caratteri il mese di nascita dello studente in caratteri:\n");
			scanf("%s",buffer.nascita.mese);
			printf("Inserisci l'anno di nascita dello studente:\n");
			scanf("%d",&buffer.nascita.anno);
			fseek(pFile, posizione*sizeof(buffer), SEEK_SET);
			fwrite(&buffer,sizeof(studente),1,pFile);
			fclose(pFile);
			return 0;
		}
		else
		return -1;			
	}
	else
	{
		printf("Errore in apertura file");
		return -1;
	}	
}
	



/** ****************************************************************************************
* @brief restituisce il numero di record presenti nel file.
*
*
* @author Wannaku Amelia
* @version 1.0 20/12/2022
*/


int numeroRecord(char fileName[])
{
	FILE *pFile;		
	int n, cont=0;		
	studente buffer;	
	//apertura del file in reading binary mode
	pFile=fopen(fileName,"rb");	
	//Controllo che il file si apra senza problemi
	if(pFile!=NULL)	{
		while(!feof(pFile))	{
			n=fread(&buffer, sizeof(buffer),1,pFile);	
			if(n>0){
				cont++;	
			}			
		}
		fclose(pFile);	
		return cont;	
	}
	else{
		printf("Errore in apertura file");
		return -1;
	}
}

int menu(void)
{
	int x;
	printf("Inserisci il numero della funzione che desideri: \n");
	printf("1:InserisciRecord\n");
	printf("2:stampaFile\n");
	printf("3:ricercaRecord\n");
	printf("4:stampaRecord\n");
	printf("5:correggiRecord\n");
	printf("6:numeroRecord\n");
	printf("0:Esci");
	scanf("%d",&x);
	return x;
}
