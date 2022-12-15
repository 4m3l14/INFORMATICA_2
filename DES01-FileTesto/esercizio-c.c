/******************************************************************************************
* \mainpage esercizio c file
*
* @brief conta i caratteri, le parole e le righe presenti in un file di testo 
* 
* @author 		Wannaku Amelia
* @date 		21/11/2022
* @version 1.0 	14/11/2022	Versione iniziale
* @version 2.0 	21/11/2022	Versione finale
*/


#include <stdio.h>

int main ()
{
	char nomeFileIN[]="conta.txt";
	char c;
	int err, cchar=0, cparole=0, crighe=1; 			//cchar= conta caratteri, cstring= conta parole, crighe= conta righe
	FILE *fileIN;
	
	fileIN = fopen(nomeFileIN,"r");
	if(fileIN==NULL) {
		printf("\nErrore nell'apertura del fileIN"); 
	} else {
		printf("File aperto correttamente\n");
	}
	
	while ((c=fgetc(fileIN))!=EOF)   					//lettura tutti caratteri fino alla fine del file
	{
		if((c>='A' && c<='Z') || (c>='a' && c<='z')){						
			cchar++;
		}
		if ((c>=' ' && c<='/')|| (c>=':' && c<='?')){ 
			cparole++;
		}
		if (c=='\n'){
			crighe++;
		}
	}
	
	err=fclose(fileIN);
	if(err!=0) {
		printf("Errore nella chiusura del file");
	} else {
		printf("\nFile chiuso correttamente");
	}
	
	printf ("\nI caratteri sono: %d", cchar);
	printf ("\nLe parole sono: %d", cparole);
	printf ("\nLe righe sono: %d", crighe);
	
	return 0;
	
}


