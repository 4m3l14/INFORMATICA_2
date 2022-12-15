/******************************************************************************************
* \mainpage esercizio d file
*
* @brief il file numeri.txt composto da una sequenza di numeri e successivamente scrive 2 file, pari.txt e dispari.txt, 
*		nei quali dovrai inserire i numeri che hai letto a seconda del loro valore pari o dispari
* 
* @author 		Wannaku Amelia
* @date 		21/11/2022
* @version 1.0 	21/11/2022	Versione iniziale
*/

#include <stdio.h>


int main ()
{
	char nomeFileIN[]="numumeri.txt";
	char nomeFileOUT[]="pari.txt";
	char nomeFileD[]="dispari.txt";

	char c;
	int err;
	FILE *fileIN, *fileOUT, *fileD;
	
	fileIN = fopen(nomeFileIN,"r");
	if(fileIN==NULL) {
		printf("\nErrore nell'apertura del fileIN"); 
	} else {
		printf("File aperto correttamente\n");
	}

	fileOUT = fopen(nomeFileOUT,"w");
	if(fileOUT==NULL) {
		printf("\nErrore nell'apertura del fileOUT");
	} 
	fileD = fopen(nomeFileD,"w");
	if(fileD==NULL) {
		printf("\nErrore nell'apertura del fileT");
	} 
	
	while ((c=getc(fileIN))!=EOF)
	{
		if (c>=48 && c<=57){
			if (c%2==0){
				fputc (c, fileOUT);
			}
			else {
				fputc (c, fileD);
			}
		}
	}
	
	err=fclose(fileIN);
	if(err!=NULL) {
		printf("\nErrore nella chiusura del fileIN");
	} 
	err=fclose(fileOUT);
	if(err!=NULL) {
		printf("\nErrore nella chiusura del fileOUT");
	} 
	err=fclose(fileD);
	if(err!=NULL) {
		printf("\nErrore nella chiusura del fileT");
	} 
	
	return 0;
}
