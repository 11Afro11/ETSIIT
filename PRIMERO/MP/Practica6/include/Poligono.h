


#ifndef POLIGONO
#define POLIGONO

struct Punto2D{
	double x;
	double y;
};

struct Nodo{
	Punto2D punto;
	Nodo * sigpunto;
};

typedef Nodo * Poligono;

Poligono  CreaEstructuraGeometrica (Punto2D *vector, int total_utilizados);

void MuestraEstructuraGeometrica (Poligono p);

Punto2D *  Redimensiona (Punto2D * p,  int &capacidad);

void LiberaEspacio(Poligono &poligono);

int CuentaCaras(const Poligono &poligono);

//void PintaRecta(Poligono poligono);

Poligono TrianguloCuadrado(Poligono cuadrado);

Poligono TrianguloCentral (Poligono triangulo);

Poligono Circunferencia(Punto2D centro, double radio, double a);

void pinta();



#endif