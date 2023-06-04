class ADT{
	protected:
		int *p;
    	int size;
		int end; 
	public:
    	ADT(int);
		bool isFull();
		bool isEmpty();
		int GetFine();
		int GetInizio();
		int SommaElementi();
		int Trova(int);
		bool InserisciInPosizione(int, int);
		bool CancellaInPosizione(int);
};

class Coda:public ADT{
	public:
		Coda(int);
		bool InserisciCoda(int);
		bool CancellaCoda(void);
};

class Pila:public ADT{
	private:
		int numIns;
		int numCanc;
	public:
		Pila(int);
		bool InserisciPila(int);
		bool CancellaPila(void);
};
