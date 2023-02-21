#include <iostream>
#include <math.h>
#include "PoligonoRegolare.h"

using namespace.h

//PoligonoRegolare
PoligonoRegolare::PoligonoRegolare(){
    numeroLati=4;
    MisuraLato=1;
}

PoligonoRegolare::PoligonoRegolare(int n, double m){
    numeroLati=n;
    MisuraLato=m;
}
int PoligonoRegolare::getnumeroLati(){
    return numeroLati;
}
void PoligonoRegolare::setnumeroLati(int n){
    numeroLati=n;
}
double PoligonoRegolare::getMisuraLato(){
    return MisuraLato;
}
void PoligonoRegolare::setMisuraLato(int m){
    MisuraLato=m;
}
double PoligonoRegolare::perimetro(){
    return MisuraLato*numeroLati;
}

//Rombo
Rombo::Rombo():PoligonoRegolare(){
    numeroLati=4;
    MisuraLato=5;
    DiagonaleMaggiore=8;
}
Rombo::Rombo(int n,double m, double d):PoligonoRegolare(n,m,d){
   numeroLati=n;
   MisuraLato=m;
   DiagonaleMaggiore=d;
}
double Rombo::DiagonaleMinore(){
    return 2*area/DiagonaleMaggiore;
}
double Rombo::area(){
    return 2*sqrt(pow(getMisuraLato(),2)-pow(DiagonaleMaggiore/2,2));
}
double Rombo::perimetro(){
    return MisuraLato*numeroLati;
}

//Quadrato
Quadrato::Quadrato():PoligonoRegolare(){
    numeroLati=4;
    MisuraLato=6;
}
Quadrato::Quadrato(int n,double m):PoligonoRegolare(n,m){
   numeroLati=n;
    MisuraLato=m;
}
double Quadrato::area(){
    return MisuraLato*MisuraLato;
}
double Quadrato::perimetro(){
    return MisuraLato*numeroLati;
}

//Triangolo Equilatero
TriangoloEquilatero::TriangoloEquilatero():PoligonoRegolare(){
    numeroLati=3;
    MisuraLato=7;

}
TriangoloEquilatero::TriangoloEquilatero(int n, double m, double h):PoligonoRegolare(n,m,h){
    numeroLati=n;
    MisuraLato=m;
    altezza=h;
}
double TriangoloEquilatero::area(){
    return (MisuraLato*altezza)/2;
}
double TriangoloEquilatero::perimetro(){
    return MisuraLato*numeroLati;
}
