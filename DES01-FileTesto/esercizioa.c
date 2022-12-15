/** ****************************************************************************************
* \mainpage esercizio a file
*
* @brief leggere il file  nomi.txt e scrivere un file NOMI2.TXT, dove tutti i nomi sono stati trasformati in caratteri maiuscoli.
* 
* @author Wannaku Amelia
* @date 14/11/2022
* @version 1.0 14/11/2022 Versione iniziale
*/


#include <stdio.h>
#include <stdlib.h> 


int main()
{
	char nomeFileIN[]="nomi.txt";
	char nomeFileOUT[]="NOMI2.txt";
	char c;
	int err;
	FILE *fileIN, *fileOUT;    				
	
	fileOUT = fopen(nomeFileOUT,"w");				 	//apertura dei file 
	if(fileOUT==NULL) {
		printf("Errore nella apertura del FileOUT");
		return 1;
	}
	fileIN = fopen(nomeFileIN,"r");
	if(fileIN==NULL) {
		printf("Errore nella apertura del FileIN");
		return 1;
	}

	while (!feof(fileIN))
	{
		c= fgetc(fileIN);
		if(c!=EOF)
		{
			if(c>='a' && c<='z'){ 				//controllo se sono in minuscolo 
				c-=32;         					//trasformo in maiuscolo
			}
			fputc(c, fileOUT);
		}
	}
	
	err=fclose(fileOUT);						//chiusura file
	if(err!=0) {
		printf("Errore nella chiusura del file");
	} else {
		printf("File chiuso correttamente");
	}

	return 0;
}
	
