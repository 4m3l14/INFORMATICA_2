#include <iostream>
#include <math.h>
#include "PoligonoRegolare.h"

using namespace std;

int main(){
    cout<<"POLIGONO REGOLARE: "<<endl;
    
    PoligonoRegolare pr1;
    cout<<"\nIl perimetro e': "<<pr1.perimetro()<<endl;
    PoligonoRegolare pr2(3,5);
    cout<<"\nIl perimetro e': "<<pr2.perimetro()<<endl;
    
    cout<<"ROMBO: "<<endl;
    Rombo r1;
    cout<<"\nLa diagonale minore e': "<<r1.DiagonaleMinore()<<endl;
    cout<<"\nL'area e': "<<r1.area()<<endl;
    cout<<"\nIl perimetro e': "<<r1.perimetro()<<endl;
    Rombo r2(4,7);
    cout<<"\nLa diagonale minore e': "<<r2.DiagonaleMinore()<<endl;
    cout<<"\nL'area e': "<<r2.area()<<endl;
    cout<<"\nIl perimetro e': "<<r2.perimetro()<<endl;
    
    cout<<"QUADRATO: "<<endl;
    Quadrato q1;
    cout<<"\nL'area e': "<<q1.area()<<endl;
    cout<<"\nIl perimetro e': "<<q1.perimetro()<<endl;
    Rombo q2(4,6);
    cout<<"\nL'area e': "<<q2.area()<<endl;
    cout<<"\nIl perimetro e': "<<q2.perimetro()<<endl;
    
    TriangoloEquilatero te1;
    cout<<"\nL'area e': "<<te1.area()<<endl;
    cout<<"\nIl perimetro e': "<<te1.perimetro()<<endl;
    Rombo te2(4,7);
    cout<<"\nL'area e': "<<te2.area()<<endl;
    cout<<"\nIl perimetro e': "<<te2.perimetro()<<endl;
}
