/** ****************************************************************************************
* \mainpage record dei file
*
* @brief carica, stampa dati dello studente, ricerca tramite cognome
* 				e correggi
*
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
	int mese;
	int anno;
}typedef data;

struct studente
{
	char cognome[C];
	data nascita;
	int voti[V];
}typedef studente;

void InserisciRecord(char[], int);    /*inserisce in coda n record con i dati richiesti all’utente. 
Se il file non esiste va creato e quindi effettuare l’inserimento. */

void stampaFile(char[]); /*Stampa su monitor (una riga per record) tutte le informazioni contenute nel file*/

/*void ricercaRecord (char[], char[]);  per ogni record che ha il contenuto del campo cognome uguale al parametro, 
stampa cognome, età e media dei voti. La funzione restituisce la posizione del primo record trovato.*/

/*void stampaRecord(char[], int); stampa le informazioni presenti nel record specificato dal parametro posizione. 
Restituisce 0 se il record è presente -1 altrimenti.*/

int main()
{
	int r, dim;
	char st[C];
	char cognome[C];
	char c;
	
	carica(st, dim);
	stampa(st, dim);
	
	/*printf("Inserisci il cognome\n");
	scanf("%s",c);
	cognome(st, dimen, cognome);
	printf("I dati dello studente sono: %d\n",r); */
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
	if(r==0){
		pFile=fopen("file.dat","wb");
	}
	
	for(i=0;i<numRecord;i++){
		srand(time(NULL));
		printf("Inserisci il cognome dello studente:\n");
		scanf("%s",buffer.cognome);
		printf("Inserisci il giorno di nascita dello studente:\n");
		scanf("%d",&buffer.nascita.giorno);
		printf("Inserisci in caratteri il mese di nascita dello studente:\n");
		scanf("%s",buffer.nascita.mese);
		printf("Inserisci l'anno di nascita dello studente:\n");
		scanf("%d",&buffer.nascita.anno);
		for(j=0;j<V;j++){
			buffer.voti[j]=1+rand()%10;
		}
		fwrite(&buffer,sizeof(studente), 1, pFile);
	}
	fclose(pFile);
}


/** ****************************************************************************************
* @brief Stampa su monitor (una riga per record) tutte le informazioni contenute nel file
*
* @author Wannaku Amelia
* @version 1.0 29/11/2022
*/

void stampaFile(char fileName[])
{
	FILE *pFile;
	studente buffer;
	int n, j, media=0;
	pFile =fopen("file.dat","rb");
	while(!feof(pFile)){
		n=fread(&buffer, sizeof(studente), 1, pFile);
		if(n>0){
			printf("Cognome dello studente: %s\n",buffer.cognome);
			printf("E' nato il %d/%s/%d\n",buffer.nascita.giorno,buffer.nascita.mese,buffer.nascita.anno);
			for(j=0;j<V;j++){
				printf("I voti sono: %d\n",buffer.voti[j]);
				media+=buffer.voti[j];              
			}
		media=media/V;                                //media dei voti di ogni singolo studente
		printf("La media e': %.2f\n",media);
		printf("\n");
		}
	}
	fclose(pFile);
}

/*void ricercaRecord (char fileName[], char cognome[])
{
	FILE *pFile;
	studente buffer;
	int i,n;
	char c;
	c= fopen(st[],"r");
	for(i=0; i<dim; i++){
		n=fread(&buffer, sizeof(studente), 1, pFile);
		if(buffer[i].cognome==cog){
			printf("Cognome dello studente: %s\n",buffer.cognome);
			printf("e' nato il %d/%d/%d\n",buffer.nascita.giorno,buffer.nascita.mese,buffer.nascita.anno);
		}	
	}
	fclose(pFile);
}

int correggi()
{
	FILE *pFile;
	stud buffer;
	int n, i, j=0;
	pFile=fopen("file.dat","rb");
	while(!feof(pFile))
	{
		n=fread(&buffer, sizeof(studente), 1, pFile);
		for(i=0;i<N;i++){
			if(buffer.cognome[i]==){
				fseek(pFile, -1*sizeof(studente),SEEK_CUR);
				buffer.cognome[i]=4;
				fwrite(&buffer,sizeof(studente), 1, pFile);
				fseek(pFile,0,SEEK_CUR);
			}
	    }
	}
	fclose(pFile);
}

void stampaRecord(char fileName, int posizione)
{
	
}*/



