class PoligonoRegolare
{
	private:
		int numeroLati;
		double MisuraLato;
		
	public:
		PoligonoRegolare();
		PoligonoRegolare(double);
		int getnumeroLati();
		void setnumeroLati(int);
		double getMisuraLato();
		void setMisuraLato(double);
		double perimetro();
	
};

class Rombo:public PoligonoRegolare
{
	private:
		double DiagonaleMaggiore;
	public:
		Rombo();
		Rombo(double);
		double getDiagonaleMaggiore();
		void setDiagonaleMaggiore(double);
	    double DiagonaleMinore();
	    double perimetro();
	    double area();
};

class Quadrato:public Rombo
{

	public:
	
		Quadrato();
		Quadrato(double);
		
		double area();
		double perimetro();
};

class TriangoloEquilatero:public PoligonoRegolare
{
	private:
		double altezza;
	public:
		TriangoloEquilatero();
		TriangoloEquilatero(double);
		double getaltezza();
		void setaltezza(double);
		
		double area();
};
