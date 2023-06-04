#include <iostream>
#include <math.h>
#include "Quadrilatero.h"

using namespace std;

int main()
{
	cout<<"QUADRILATERO: "<<endl;
	
	//Oggetto quadrilatero 1 con costruttore di default
	Quadrilatero q1;  
	cout<<"\nIl perimetro e': "<<q1.perimetro()<<endl;
	
	//Oggetto quadrilatero 2 con costruttore con numeri
	Quadrilatero q2(10,3,4,5);   
	cout<<"\nIl perimetro e': "<<q2.perimetro()<<endl;
	
	cout<<"\nRETTANGOLO: "<<endl;
	
	//Oggetto rettangolo 1 con costruttore di default
	Rettangolo r1;
	cout<<"\nIl perimetro e': "<<r1.perimetro()<<endl;
	cout<<"La diagonale e': "<<r1.diagonale()<<endl;
	cout<<"L'area e': "<<r1.area()<<endl;
	
	//Oggetto rettangolo 2 con costruttore con numeri
	Rettangolo r2(10,3);
	cout<<"\nIl perimetro e': "<<r2.perimetro()<<endl;
	cout<<"L'area e': "<<r2.area()<<endl;
	cout<<"La diagonale e': "<<r2.diagonale()<<endl;
	
	cout<<"\nQUADRATO: "<<endl;
	
	//Oggetto quadrato 1 con costruttore di default
	Quadrato q3;
	cout<<"\nIl perimetro e': "<<q3.perimetro()<<endl;
	cout<<"L'area e': "<<q3.area()<<endl;
	
	//Oggetto quadrato 2 con costruttore con numeri
	Quadrato q4(10);
	cout<<"\nIl perimetro e': "<<q4.perimetro()<<endl;
	cout<<"L'area e': "<<q4.area()<<endl;
	
	cout<<"\nTRAPEZIO: "<<endl;
	
	//Oggetto trapezio 1 con costruttore di default
	Trapezio t1;
	cout<<"\nL'area e': "<<t1.area()<<endl;
	cout<<"Il perimetro e': "<<t1.perimetro()<<endl;
	
	//Oggetto trapezio 2 con costruttore con numeri
	Trapezio t2(10,12,6,19);
	cout<<"\nL'area e': "<<t2.area()<<endl;
	cout<<"Il perimetro e': "<<t2.perimetro()<<endl;
}
