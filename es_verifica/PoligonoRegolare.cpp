#include <iostream>
#include <math.h>
#include "PoligonoRegolare.h"

using namespace std;

//PoligonoRegolare
PoligonoRegolare::PoligonoRegolare(){
    numeroLati=4;
    MisuraLato=1;
}

PoligonoRegolare::PoligonoRegolare(double m){
    numeroLati=4;
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
void PoligonoRegolare::setMisuraLato(double m){
    MisuraLato=m;
}
double PoligonoRegolare::perimetro(){
    return MisuraLato*numeroLati;
}

//Rombo
Rombo::Rombo(){
    setnumeroLati(4);
    setMisuraLato(5);
    DiagonaleMaggiore=8;
}
Rombo::Rombo(double d){
   setnumeroLati(4);
   setMisuraLato(5);
   DiagonaleMaggiore=d;
}

double Rombo::area(){
    return (DiagonaleMinore()*DiagonaleMaggiore)/2;
}
double Rombo::DiagonaleMinore(){
    return 2*sqrt(pow(getMisuraLato(),2)-pow(DiagonaleMaggiore/2,2));
}
double Rombo::perimetro(){
    return getMisuraLato()*getnumeroLati();
}

//Quadrato
Quadrato::Quadrato(){
    setnumeroLati(4);
    setMisuraLato(6);
}
Quadrato::Quadrato(double m){
	setnumeroLati(4);
    setMisuraLato(m);
}
double Quadrato::area(){
    return getMisuraLato()*getMisuraLato();
}
double Quadrato::perimetro(){
    return getMisuraLato()*getnumeroLati();
}

//Triangolo Equilatero
TriangoloEquilatero::TriangoloEquilatero(){
    setnumeroLati(3);
    setMisuraLato(7);
    altezza=5;
}
double TriangoloEquilatero::getaltezza(){
    return altezza;
}
void TriangoloEquilatero::setaltezza(double h){
    altezza=h;
}
TriangoloEquilatero::TriangoloEquilatero(double h){
    setnumeroLati(3);
    setMisuraLato(7);
    setaltezza(h);
}
double TriangoloEquilatero::area(){
    return (getMisuraLato()*getaltezza())/2;
}
