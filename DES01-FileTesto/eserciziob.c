/******************************************************************************************
* \mainpage esercizio b file
*
* @brief legge carattere per carattere il contenuto del file in.txt e lo ricopia nel file out.txt. 
* 
* @author Wannaku Amelia
* @date 14/11/2022 
* @version 1.0 <14/11/2022> Versione iniziale
*/


#include <stdio.h>
#include <stdlib.h> 


int main()
{
	char nomeFileIN[]="in.txt";
	char nomeFileOUT[]="out.txt";
	char c;
	int err;
	FILE *fileIN, *fileOUT;    				 			//apertura del file 
	
	fileOUT = fopen(nomeFileOUT,"w");
	if(fileOUT==NULL) {
		printf("Errore nella apertura del FileOUT");
		return 1;
	}
	fileIN = fopen(nomeFileIN,"r");
	if(fileIN==NULL) {
		printf("Errore nella apertura del FileIN");
		return 1;
	}
	
	while (!feof(fileIN)) 							//finchè il file non finisce
	{
		c=fgetc(fileIN);
		if(c!=EOF){
			fputc(c, fileOUT);
		}   				
	}
	
	err=fclose(fileOUT);							//chiusura del file
	if(err!=0) {
		printf("Errore nella chiusura del file");
	} else {
		printf("File chiuso correttamente");
	}

	return 0;
}
	
