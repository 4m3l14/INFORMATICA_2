#include <iostream>
#include <math.h>
#include "Quadrilatero.h"

using namespace std;

//Quadrilatero
Quadrilatero::Quadrilatero()
{
	lato1=0;
	lato2=1;
	lato3=2;
	lato4=3;
}

Quadrilatero::Quadrilatero(double l1,double l2,double l3,double l4)
{
	lato1=l1;
	lato2=l2;
	lato3=l3;
	lato4=l4;
}

double Quadrilatero::getLati()
{
	return lato1,lato2,lato3,lato4;
}

void Quadrilatero::setLati(double l1,double l2,double l3,double l4)
{
	lato1=l1;
	lato2=l2;
	lato3=l3;
	lato4=l4;
}

double Quadrilatero::perimetro()
{
	return lato1+lato2+lato3+lato4;
}

//Rettangolo
Rettangolo::Rettangolo():Quadrilatero()
{
	base=1;
	altezza=2;
}

Rettangolo::Rettangolo(double b,double h):Quadrilatero(b,h,b,h)
{
	base=b;
	altezza=h;
}

double Rettangolo::perimetro()
{
	return (base*2)+(altezza*2);
}

double Rettangolo::diagonale()
{
	return sqrt(base*base+(altezza*altezza));
}

double Rettangolo::area()
{
	return (base*altezza);
}

Quadrato::Quadrato():Rettangolo()
{
	lato=1;
}

Quadrato::Quadrato(double l):Rettangolo(l,l)
{
	lato=l;
}

double Quadrato::area()
{
	return lato*lato;
}

double Quadrato::perimetro()
{
	return lato*4;
}

//Trapezio
Trapezio::Trapezio():Quadrilatero()
{
	base1=0;
	base2=2;
	altezza=6;
	obliquo=0;
}

Trapezio::Trapezio(double b1,double b2, double h, double o):Quadrilatero(b1,b2,h,o)
{
	base1=b1;
	base2=b2;
	altezza=h;
	obliquo=o;
}

double Trapezio::area()
{
	return ((base1+base2)*altezza)/2;
}

double Trapezio::perimetro()
{
	return base1+base2+(obliquo*2);
}
