#include <iostream>
#include <math.h>
#include "PoligonoRegolare.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"POLIGONO REGOLARE: "<<endl;
    
    PoligonoRegolare pr1;
    PoligonoRegolare pr2(3,5);
    cout<<"\nIl perimetro e': "<<pr2.perimetro()<<endl;
    
    cout<<"ROMBO: "<<endl;
    Rombo r1;
    Rombo r2(4,7);
    cout<<"\nLa diagonale minore e': "<<r2.DiagonaleMinore()<<endl;
    cout<<"\nL'area e': "<<r2.area()<<endl;
    cout<<"\nIl perimetro e': "<<r2.perimetro()<<endl;
    
    cout<<"QUADRATO: "<<endl;
    Quadrato q1;
    Quadrato q2(4,6);
    cout<<"\nL'area e': "<<q2.area()<<endl;
    cout<<"\nIl perimetro e': "<<q2.perimetro()<<endl;
    
    TriangoloEquilatero te1;
    Rombo te2(4,7);
    cout<<"\nL'area e': "<<te2.area()<<endl;
    cout<<"\nIl perimetro e': "<<te2.perimetro()<<endl;
}
