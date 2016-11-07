
#ifndef AGENT__
#define AGENT__

#include <string>
#include <iostream>
#include <cstdlib>
#include "conexion.h"
using namespace std;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------
class Environment;
class Agent
{
public:
	Agent(){
		x_= 99;
		y_= 99;
		tiempo =1;
		bit_de_giro = 0;
		giro_inicial=false;
		giro_final=false;
		giro_derecha=false;
		orientacion_=3;
		EN_USO_ = '-';
		avances=0;
		role_="PlYR";
		last_accion_=3;
		REINICIADO_=false;
		size_=200;
		ir_a_1 = ir_a_2 = ir_a_3 = ir_a_4 = ir_a_5 = ir_a_6 = ir_a_7 = ir_a_8 = ir_a_9 = 0;
		for (int i=0;i<200;i++)
		    for(int j=0;j<200;j++){
		      // mapa_[i][j]=0;
		      mapa_entorno_[i][j]='?';
		      mapa_objetos_[i][j]='?';
		      migas_de_pan_[i][j]=0;
		    }

		for (int i=0;i<100;i++){
		    for(int j=0;j<100;j++){
		      mapa_solucion_[i][j]='?';
		    }
		}

		pk1f = 0;
		pk1c = 0;
		pk2f = 0;
		pk2c = 0;
		mypk1f = 0;
		mypk1c = 0;
		mypk2f = 0;
		mypk2c = 0;
		he_guardado = true;
		buscando1 = false;
		buscando2 = false;

		primera_vez = true;
		coordenadas_correctas = false;
		respawn = false;

	}

	enum ActionType
	{
	    actFORWARD, // avanzar
	    actTURN_L,  // Girar Izquierda
	    actTURN_R,  // Girar Derecha
	    actIDLE,    // No hacer nada
	    actPICKUP,  // Recoger un objeto
	    actPUTDOWN, // Soltar un objeto
	    actPUSH,    // Meter en la mochila
	    actPOP,     // Sacar de la mochila
	    actGIVE,	// Dar un objeto a un personaje
	    actTHROW	// Lanzar un objeto

	};

	void Perceive(Environment &env);
	bool Perceive_Remote(conexion_client &Cliente, Environment &env);
	void ActualizarInformacion(Environment *env);
	ActionType Think();
	void FixLastAction(Agent::ActionType x){last_accion_=x;};

	char mapa_entorno_[200][200]; // mapa que muestra el tipo de terreno
	char mapa_objetos_[200][200]; // mapa que muestra los objetos que estan encima del terreno
	char mapa_solucion_[100][100]; // Mapa que almacena la solucion que el alumno propone
	int migas_de_pan_[200][200];	//Mapa que almacena por donde he pasado
	// Funciones de acceso a los datos
	void GetCoord(int &fila, int &columna, int &brujula){fila=y_;columna=x_;brujula=orientacion_;};
	bool sePuedeIr(int X, int Y);
	bool find(char objeto);
	bool cabe();
	void Rellena(int i, int j);
	bool Suposicion(int i, int j);
	int a_donde_voy(int izquierda_x, int izquierda_y, int derecha_x, int derecha_y, int alante_x, int alante_y);
	//funciones para orientarse
	int Orientarse();
	// void HanselYGretel();


private:
	//Variables de interaccion con el entorno grafico
	int size_;	

	//SENSORES
	char VISTA_[10];
	char SURFACE_[10];
	bool REINICIADO_;
	string MENSAJE_;
	bool giro_inicial;
	bool giro_derecha;
	
	bool giro_final;
	char EN_USO_;
	char MOCHILLA_[5];
	char PUNTUACION_[9];
	bool FIN_JUEGO_;
	char SALUD_;


	//Variables de estado
	// double mapa_[200][200];
	int x_,y_, orientacion_;
	int last_accion_;
	string role_;
	int ir_a_1, ir_a_2, ir_a_3, ir_a_4, ir_a_5, ir_a_6, ir_a_7, ir_a_8, ir_a_9;
	int bit_de_giro;
	int avances;
	int tiempo;
	int cero_x;
	int cero_y;
	bool he_guardado;
	bool buscando1;
	bool buscando2;

	//Para orientarme

	int pk1f;
	int pk1c;
	int pk2f;
	int pk2c;
	int mypk1f;
	int mypk1c;
	int mypk2f;
	int mypk2c;

	bool primera_vez;
	bool coordenadas_correctas;
	bool respawn;


};

string ActionStr(Agent::ActionType);

void CapturaFilaColumnaPK (string mensaje, int &fila, int &columna);

#endif
