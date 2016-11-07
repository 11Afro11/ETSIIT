


#ifndef LISTA
#define LISTA

struct TipoLista{
	double info;
	TipoLista * sig;
};


TipoLista * CreaEstructuraLineal (void);

void MuestraEstructuraLineal (TipoLista * p);

int NumCeldas(TipoLista *p);

int Media(TipoLista *p);

int Varianza(TipoLista *p);

bool EstaOrdenada(TipoLista *p);

void Ordena_por_Seleccion(TipoLista *&primero);

void InsertarElemento(TipoLista *&lista, double valor);

void EliminarElemento(TipoLista *&lista, int valor);

TipoLista * Enlaza(TipoLista *&lista1, TipoLista *&lista2);

void pinta();



#endif