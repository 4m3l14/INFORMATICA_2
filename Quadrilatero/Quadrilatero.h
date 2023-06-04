class Quadrilatero
{
	private:
		double lato1;
		double lato2;
		double lato3;
		double lato4;
	public:
		Quadrilatero();
		Quadrilatero(double,double,double,double);
		double getLati();
		void setLati(double,double,double,double);
		double perimetro();
};

class Rettangolo:public Quadrilatero
{
	private:
		double base;
		double altezza;
	public:
		Rettangolo();
		Rettangolo(double,double);
	    double perimetro();
	    double diagonale();
	    double area();
};

class Quadrato:public Rettangolo
{
	private:
		double lato;
	public:
		Quadrato();
		Quadrato(double);
		double area();
		double perimetro();
};

class Trapezio:public Quadrilatero
{
	private:
		double base1;
		double base2;
		double altezza;
		double obliquo;
	public:
		Trapezio();
		Trapezio(double b1, double b2, double h, double o);
		double area();
		double perimetro();
};
