/*******************************************************************************************
* \mainpage record dei file
*
* @brief inserisce record carica dati degli studenti e stampa dati dello studente, ricerca tramite cognome,
*        stampa informazioni nel record passato come parametro, correggi, numero record presenti nel file				
* @author 		Wannaku Amelia
* @date 		22/12/2022
* @version 1.0 	29/11/2022 Versione iniziale
* @version 2.0 	22/12/2022 Versione finale
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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

int correggiRecord (char[], int ); /*visualizza le informazioni del record richiamando la funzione stampaRecord e
e corregge l’intero record, con i nuovi dati richiesti all’utente.*/
 
int numeroRecord(char []); //restituisce il numero di record presenti nel file.

	char nomeFile[]={"file.dat"};
	int r, s, a; 

int main()
{
	char st[C];
	do{
		s=menu();	
		switch(s){
			case 1: 
				printf("\nInserire quanti record vuoi\n");
				scanf("%d", &r);
				InserisciRecord(nomeFile, r);	
			case 2: 
				stampaFile(nomeFile);	
				break;
				break;
			case 3:	
				printf("\nInserisci il cognome da cercare\n");
				scanf("%s", st);
				r=ricercaRecord(nomeFile, st);	
				//se la funzione non restituisce 1, visualizza errore	
				if(r!=1){            	
					printf("\nErrore, record non trovato\n");
				}
				break;
			case 4:	
				printf("\nInserisci la posizione \n");
				scanf("%d", &a);
				r=stampaRecord(nomeFile, a);
				//la funzione restituisce -1 se il record non e' presente	
				if(r==-1){
					printf("\nErrore, record non trovato\n");
				}
				break;
			case 5:	
				printf("\nInserire la posizione del record");
				r=correggiRecord(nomeFile, a);
				//la funzione restituisce -1 se il record non e' presenteecord da correggere\n");
				scanf("%d", &a);	
				if(r==-1){
					printf("\nErrore, record non trovato\n");
				}
				break;
			case 6:	
				r=numeroRecord(nomeFile);	
				printf("\nSono presenti %d record nel file\n", r);
				break;
			case 0:	
				printf("\nArrivederci!");				
				break;
			default:	
				printf("Errore\n!");	
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
	
	//Apertura del file binario in modalita' append
	pFile=fopen(fileName,"ab"); 
	
	srand(time(NULL));
	//controllo del file, che sia aperto senza errori
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
			for(j=0;j<V;j++){
				buffer.voti[j]=1+rand()%10;
			}
		//fwrite funzione che ci permette di scrivere sul file binario
		fwrite(&buffer,sizeof(studente), 1, pFile);
		}
		fclose(pFile);
	}
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
	
	//apertura del file binario in lettura
	pFile=fopen(fileName,"rb");
	
	//controllo del file, che sia aperto senza errori
	if(pFile!=NULL){
		//finche' il file non finisce
		while(!feof(pFile)){
			n=fread(&buffer, sizeof(studente), 1, pFile);
		
			if(n>0){
				printf("Cognome dello studente: %s\t",buffer.cognome);
				printf("E' nato il %d/%s/%d\t",buffer.nascita.giorno,buffer.nascita.mese,buffer.nascita.anno);
				printf("\nI voti sono:\t");
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
	int i, n, media, eta, anno=2022;
	
	//apertura del file binario in lettura
	pFile=fopen(fileName,"rb");
	
	//controllo del file, che sia aperto senza errori
	if(pFile!=NULL){
		//finche' il file non finisce
		while(!feof(pFile)){
			//funzione fread permette di leggere i dati che l'utente ha passato come parametro
			n=fread(&buffer, sizeof(studente), 1, pFile);
			if(strcmp(buffer.cognome,cognome)==0){
				printf("Cognome dello studente: %s\n",buffer.cognome);
				printf("e' nato il %d/%s/%d\n",buffer.nascita.giorno,buffer.nascita.mese,buffer.nascita.anno);
				eta=anno-buffer.nascita.anno;
				printf("eta': %d\n", eta);
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
	//restituisce -1 se c'e' un errore nell' apertura del file
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
	int n,j;
	
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
		//se il record non viene letto restituisce -1
		else{
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
	//apertura file binario in lettura/scrittura
	pFile=fopen(fileName,"rb+");
	int r, n;
	
	//controllo del file, che sia aperto senza errori
	if(pFile!=NULL){
		//funzione fseek posizionare il puntatore del File nella posizione desiderata 
		fseek(pFile, posizione*sizeof(buffer), SEEK_SET); 
		n=fread(&buffer,sizeof(studente),1,pFile);
		//chiamata della funzione stampaRecord
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
			//funzione fseek posizionare il puntatore del File nella posizione desiderata 
			fseek(pFile, posizione*sizeof(buffer), SEEK_SET);
			//fwrite funzione che ci permette di scrivere sul file binario
			fwrite(&buffer,sizeof(studente),1,pFile);
			fclose(pFile);
			return 0;
		}
		else
		return -1;			
	}
	else{
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
	//controllo che il file senza errori
	if(pFile!=NULL)	{
		//finche' il file non finisce
		while(!feof(pFile))	{
			//lettura del file binario
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

//menu
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
	printf("0:Esci\n");
	scanf("%d",&x);
	return x;
}

