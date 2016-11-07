#include "belkan.h"
#include "conexion.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;



// -----------------------------------------------------------
void PasarVectoraMapaCaracteres(int fila, int columna, char m[200][200], char *v, int brujula){
  m[fila][columna]=v[0];

    switch(brujula){
        case 0: // Orientacion Norte

		m[fila-1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila-2][columna+i-1]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila-3][columna+j-2]=v[5+j];
		}
	        break;
	case 1: // Orientacion Este
		m[fila][columna+1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+i-1][columna+2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+j-2][columna+3]=v[5+j];
		}
	        break;
        case 2: // Orientacion Sur
		m[fila+1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+2][columna+1-i]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+3][columna+2-j]=v[5+j];
		}
		                break;
        case 3: // Orientacion Oeste
		m[fila][columna-1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+1-i][columna-2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+2-j][columna-3]=v[5+j];
		}

                break;
    }

}

void PasarVectoraMapaCaracteres100(int fila, int columna, char m[100][100], char *v, int brujula){
  m[fila][columna]=v[0];

    switch(brujula){
        case 0: // Orientacion Norte

		m[fila-1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila-2][columna+i-1]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila-3][columna+j-2]=v[5+j];
		}
	        break;
	case 1: // Orientacion Este
		m[fila][columna+1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+i-1][columna+2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+j-2][columna+3]=v[5+j];
		}
	        break;
        case 2: // Orientacion Sur
		m[fila+1][columna]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+2][columna+1-i]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+3][columna+2-j]=v[5+j];
		}
		                break;
        case 3: // Orientacion Oeste
		m[fila][columna-1]=v[1];
		for (int i=0; i<3; i++){
		  m[fila+1-i][columna-2]=v[2+i];
		}
		for (int j=0; j<5; j++){
		  m[fila+2-j][columna-3]=v[5+j];
		}

                break;
    }

}


// -----------------------------------------------------------
void Agent::Perceive(Environment &env)
{
	env.SenSorStatus(VISTA_, SURFACE_, MENSAJE_, REINICIADO_, EN_USO_, MOCHILLA_, PUNTUACION_, FIN_JUEGO_, SALUD_, false);

}


bool Agent::Perceive_Remote(conexion_client &Cliente, Environment &env)
{
	bool actualizado=false;


	actualizado = env.Perceive_Remote(Cliente);
	if (actualizado)
		env.SenSorStatus(VISTA_, SURFACE_, MENSAJE_, REINICIADO_, EN_USO_, MOCHILLA_, PUNTUACION_, FIN_JUEGO_, SALUD_, true);

    return actualizado;
}


// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actIDLE: return "IDLE";
	case Agent::actPICKUP: return "PICK UP";
	case Agent::actPUTDOWN: return "PUT DOWN";
	case Agent::actPUSH: return "PUSH";
	case Agent::actPOP: return "POP";
	case Agent::actGIVE: return "GIVE";
	case Agent::actTHROW: return "THROW";
	default: return "????";
	}
}

void Agent::Rellena(int i, int j)
{
	cout << "ESTAMOS RELLENANDO"<<endl;
	if(mapa_entorno_[i][j] == '?'){
		char arriba, abajo, izq, der;
		arriba = mapa_entorno_[i-1][j];
		abajo = mapa_entorno_[i+1][j];
		izq = mapa_entorno_[i][j-1];
		der = mapa_entorno_[i][j+1];
		if((arriba == 'M' or arriba == '?') 
			&& (abajo == 'M' or abajo == '?') 
			&& (izq == 'M' or izq == '?')
			&& (der == 'M' or der == '?')){
			mapa_entorno_[i][j] = 'S';
			mapa_solucion_[i][j] = 'S';
		}
		if(arriba == 'M' and izq == 'P'){
			mapa_entorno_[i][j] = 'M';
			mapa_solucion_[i][j] = 'M';
		}
		Rellena(i-1, j);
		Rellena(i+1,j); 
		Rellena(i,j-1);
		Rellena(i, j+1);
	}
}


bool Agent::Suposicion(int i, int j){
	cout << "ESTAMOS SUPONIENDO"<<endl;
	if(mapa_entorno_[i][j] == '?'){
		char arriba, abajo, izq, der;
		arriba = mapa_entorno_[i-1][j];
		abajo = mapa_entorno_[i+1][j];
		izq = mapa_entorno_[i][j-1];
		der = mapa_entorno_[i][j+1];
		if((arriba == 'M' or arriba == '?' or arriba == 'P' or arriba == 'D') 
			&& (abajo == 'M' or abajo == '?' or abajo == 'P' or abajo == 'D') 
			&& (izq == 'M' or izq == '?' or izq == 'P' or izq == 'D')
			&& (der == 'M' or der == '?' or der == 'P' or der == 'D') 
			&& Suposicion(i-1, j) && Suposicion(i+1,j) 
			&& Suposicion(i,j-1) && Suposicion(i, j+1)){
			return true;
		}
		else{
			return false;
		}
	}
	else if(mapa_entorno_[i][j] == 'M'){
		return true;
	}
	else{
		return false;
	}
}

// -----------------------------------------------------------
void Agent::ActualizarInformacion(Environment *env){
	// Actualizar mi informacion interna
	if (REINICIADO_){ 
		// Lo que tengas que hacer si eres reposicionado en el juego
		x_= 99;
		y_= 99;
		bit_de_giro = 0;
		giro_inicial=false;
		giro_final=false;
		giro_derecha=false;
		orientacion_=3;
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
		      migas_de_pan_[i][j] = 0;
		    }
		

		pk1f = 0;
		pk1c = 0;
		pk2f = 0;
		pk2c = 0;
		mypk1f = 0;
		mypk1c = 0;
		mypk2f = 0;
		mypk2c = 0;

		primera_vez = true;
		coordenadas_correctas = false;
		respawn = true;
	}



	switch(last_accion_){
	  case 0: //avanzar
	  if(MENSAJE_ != "Has chocado con un obstaculo movil. " and MENSAJE_!= "Menudo golpe contra el arbol. "){
		  switch(orientacion_){
		    case 0: // norte
			    y_--;
			    break;
		    case 1: // este
			    x_++;
			    break;
		    case 2: // sur
			    y_++;
			    break;
		    case 3: // oeste
			    x_--;
			    break;
		  }
		}
	  break;
	  case 1: // girar izq
		  orientacion_=(orientacion_+3)%4;
		  break;
	  case 2: // girar dch
		  orientacion_=(orientacion_+1)%4;
		  break;
	}

	if(MENSAJE_.substr(0,8) == "PK fila:"  && !coordenadas_correctas){
		cout << "HE VISTO EL MENSAJE Y ES: " << MENSAJE_ <<endl;
		if(primera_vez){
			CapturaFilaColumnaPK(MENSAJE_, pk1f, pk1c);
			mypk1f = y_;
			mypk1c = x_;
			primera_vez = false;
			cout << "La fila de la matriz solucion es: "<< pk1f << endl;
			cout << "La columna de la matriz solucion es : "<< pk1c << endl;
			cout << "Mi matriz esta en la fila : " << mypk1f << "Columna: " << mypk1c <<endl;
		}
		else{
			CapturaFilaColumnaPK(MENSAJE_, pk2f, pk2c);
			if(pk2c != pk1c && pk2f != pk1f){
				coordenadas_correctas = true;
				mypk2f = y_;
				mypk2c = x_;
				cout << "La SEGUNDA fila de la matriz solucion es: "<< pk2f << endl;
				cout << "La SEGUNDAcolumna de la matriz solucion es : "<< pk2c << endl;
				cout << "Mi matriz (SEGUNDA) esta en la fila : " << mypk2f << "Columna: " << mypk2c <<endl;
				Orientarse();
			}
		}
	}

	//suelto miguita de pan
	tiempo ++;
	if(tiempo == 19999){
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				if(mapa_entorno_[i][j] == 'M'){
					bool cerrado = true;
					bool es_cerrado = false;
					int primerx = i;
					int primery = j+1;
					int segundox = i+1;
					int segundoy = j;
					int cuenta_fil = 0;
					int cuenta_col = 0;
					while(cerrado and !es_cerrado){

						if(primerx == segundox and primery == segundoy){
							es_cerrado = true;
						}

						if(mapa_entorno_[primerx][primery+1] == 'M' || mapa_entorno_[primerx][primery+1] == 'D'){
							primery += 1;
							cuenta_col++;
						}
						else if(mapa_entorno_[primerx][primery +1] == '?' and mapa_entorno_[primerx -1][primery+1] == 'P'){
							mapa_entorno_[primerx][primery+1] = 'M';
							mapa_solucion_[primerx][primery+1] = 'M';
							primery +=1;
							cuenta_col++;
						}
						else if(mapa_entorno_[primerx+1][primery] == 'M' || mapa_entorno_[primerx+1][primery] == 'D'){
							primerx += 1;
						}
						else if(mapa_entorno_[primerx+1][primery] == '?' and mapa_entorno_[primerx+1][primery+1] == 'P'){
							mapa_entorno_[primerx+1][primery] = 'M';
							mapa_solucion_[primerx+1][primery] = 'M';
							primerx +=1;
						}
						else 
							cerrado = false;

						if(mapa_entorno_[segundox+1][segundoy] == 'M' || mapa_entorno_[segundox+1][segundoy] == 'D'){
							segundox +=1;
							cuenta_fil++;
						}
						else if(mapa_entorno_[segundox+1][segundoy] == '?' and mapa_entorno_[segundox+1][segundoy-1] == 'P'){
							mapa_entorno_[segundox+1][segundoy] = 'M';
							mapa_solucion_[segundox+1][segundoy] = 'M';
							segundox +=1;
							cuenta_fil++;
						}

						else if(mapa_entorno_[segundox][segundoy+1] == 'M' || mapa_entorno_[segundox][segundoy+1] == 'D'){
							segundoy+=1;
						}

						else if(mapa_entorno_[segundox][segundoy+1] == '?' and mapa_entorno_[segundox+1][segundoy+1] == 'P'){
							mapa_entorno_[segundox][segundoy+1] = 'M';
							mapa_solucion_[segundox][segundoy+1] = 'M';
							segundoy +=1;
						}
						else 
							cerrado = false;
					}

					if(es_cerrado){
						for(int z = 0; z < cuenta_fil; z++){
							for(int k = 0; k < cuenta_col; k++){
								mapa_entorno_[i+1+z][j+1+k] = 'S';
								mapa_solucion_[i+1+z][j+1+k] = 'S';
							}
						}
					}
				}
			}
		}
	}

	migas_de_pan_[y_][x_] = tiempo;
	/*int x_9, x_8, x_6, x_5, x_4, x_2, y_9, y_8, y_6, y_5, y_4, y_2;
	if(orientacion_ == 0){
		migas_de_pan_[y_-3][x_-2] = tiempo;
		migas_de_pan_[y_-3][x_-1] = tiempo;
		migas_de_pan_[y_-2][x_-1] = tiempo;
		migas_de_pan_[y_-3][x_+1] = tiempo;
		migas_de_pan_[y_-2][x_+1] = tiempo;
		migas_de_pan_[y_-3][x_+2] = tiempo;
	}
	else if(orientacion_ == 1){
		migas_de_pan_[y_-1][x_+2] = tiempo;
		migas_de_pan_[y_-1][x_+2] = tiempo;
		migas_de_pan_[y_-2][x_+3] = tiempo;
		migas_de_pan_[y_+1][x_+2] = tiempo;
		migas_de_pan_[y_+1][x_+2] = tiempo;
		migas_de_pan_[y_+2][x_+3] = tiempo;
	}

	else if(orientacion_ == 2){
		migas_de_pan_[y_+2][x_+1] = tiempo;
		migas_de_pan_[y_+3][x_+1] = tiempo;
		migas_de_pan_[y_+3][x_+2] = tiempo;
		migas_de_pan_[y_+2][x_-1] = tiempo;
		migas_de_pan_[y_+3][x_-1] = tiempo;
		migas_de_pan_[y_+3][x_-2] = tiempo;
	}
	else if(orientacion_ == 3){
		migas_de_pan_[y_+1][x_-3] = tiempo;
		migas_de_pan_[y_+1][x_-2] = tiempo;
		migas_de_pan_[y_+2][x_-3] = tiempo;
		migas_de_pan_[y_-1][x_-2] = tiempo;
		migas_de_pan_[y_-1][x_-3] = tiempo;
		migas_de_pan_[y_-2][x_-3] = tiempo;
	}*/
	
	// Comprobacion para no salirme del rango del mapa
	bool algo_va_mal=false;
	if (y_<0){
		y_=0;
		algo_va_mal=true;
	} 
	else if (y_>199){
		y_=199;
		algo_va_mal=true;
	}
	if (x_<0){
		x_=0;
		algo_va_mal=true;
	} 
	else if (x_>199){
		x_=199;
		algo_va_mal=true;
	}

	if (algo_va_mal){
		cout << "CUIDADO: NO ESTAS CONTROLANDO BIEN LA UBICACION DE TU AGENTE\n";
	}


	PasarVectoraMapaCaracteres(y_,x_,mapa_entorno_,VISTA_,orientacion_);
	PasarVectoraMapaCaracteres(y_,x_,mapa_objetos_,SURFACE_,orientacion_);
	if(coordenadas_correctas)
		PasarVectoraMapaCaracteres100(y_,x_,mapa_solucion_,VISTA_,orientacion_);

	env->ActualizarMatrizUsuario(mapa_entorno_);


}

bool Agent::sePuedeIr(int X, int Y){

	char vision = mapa_entorno_[Y][X];
	char personaje = mapa_objetos_[Y][X];

	if(vision =='M' or vision == 'P' or vision =='D')
		return false;
	else if(personaje >= 'a' && personaje <= 'z'){
		return false;
	}
	else if(vision =='A' and EN_USO_ == '0' or find('0')){
		return true;
	}
	else if(vision =='A' and !find('0')){
		return false;
	}
	else if(vision =='B' and EN_USO_ == '6' or find('6')){
		return true;
	}
	else if(vision =='B' and !find('6')){
		return false;
	}

	return true;
}



void CapturaFilaColumnaPK (string mensaje, int &fila, int &columna){
	if (mensaje.substr(0,8)=="PK fila:"){
		int pos = mensaje.find('c');
		string valor = mensaje.substr(9,pos-8);
		fila = atoi(valor.c_str());
		
		int pos2 = mensaje.find('.');
		pos = pos+8;
		valor = mensaje.substr(pos,pos2-1);
		columna = atoi(valor.c_str());
	}
}

bool Agent::find(char objeto){
	for(int i = 0; i < 5; i++){
		if(MOCHILLA_[i] == objeto){
			return true;
		}
	}
	return false;
}

void swap(int &x, int &y){
	int tmp = x;
	x = y;
	y = tmp;
}

int Agent::Orientarse(){

	cout << "Vamos a orientarnos"<<endl;

	int f1, f2, c1, c2;
	f1 = pk1f - pk2f;
	f2 = mypk1f - mypk2f;
	c1 = pk1c - pk2c;
	c2 = mypk1c - mypk2c;

	cout << "el valor de F1 es: "<< f1<<endl;
	cout << "el valor de F2 es: "<< f2<<endl;
	cout << "el valor de C1 es: "<< c1<<endl;
	cout << "el valor de C2 es: "<< c2<<endl;
	char aux[200][200];
	int aux_migas[200][200];
	for(int i = 0; i < 200; i++){
		for(int j = 0; j < 200; j++){
			aux[i][j] = '?';
			aux_migas[i][j] = 0;
		}
	}

	if(f1 == f2){
		cout << "Estoy bien orientado"<<endl;
		for(int fila = 0; fila < 200; fila++){
			for(int col = 0; col < 200;col++){
				aux[fila][col] = mapa_entorno_[fila][col];
				aux_migas[fila][col] = migas_de_pan_[col][fila];
			}
		}
	}

	else if(f1 == -f2){
		cout << "Estoy boca abajo" << endl;
		/*for(int fila = mypk1f - pk1f+ 99, i = 0; i < 100; i++, fila--){
			for(int col = mypk1c - pk1c + 99, j = 0; j < 100; j++, col--){
				aux[i][j] = mapa_entorno_[col][fila];
				aux_migas[i][j] = migas_de_pan_[col][fila];
			}
		}*/

		mypk1f = 199 -mypk1f;
		mypk1c = 199 -mypk1c;
		mypk2f = 199 -mypk2f;
		mypk2c = 199 -mypk2c;

		for(int fila = 0; fila < 200; fila++){
			for(int col = 0; col < 200;col++){
				aux[fila][col] = mapa_entorno_[199-fila][199-col];
				aux_migas[fila][col] = migas_de_pan_[199- fila][199-col];
			}
		}


		orientacion_=(orientacion_+2)%4;
	}


	else if(f1 == c2){
		cout << "Estoy girado a la izquierda"<<endl;
		// swap(pk2f, pk2c);
		swap(mypk2f, mypk2c);
		
		// mypk1c = 199 -mypk1c;
		mypk2c = 199 -mypk2c;
		// pk2f = 99 - pk2f;
		// mypk2f = 199 - mypk2f;


		/*for(int fila = mypk1f - pk1f, i = 0; i < 100; i++, fila++){
			for(int col = mypk1c - pk1c + 99, j = 0; j < 100; j++, col--){
				aux[i][j] = mapa_entorno_[col][fila];
				aux_migas[i][j] = migas_de_pan_[col][fila];
			}
		}*/

		for(int fila = 0; fila < 200; fila++){
			for(int col = 0; col < 200;col++){
				aux[fila][col] = mapa_entorno_[199-col][fila];
				aux_migas[fila][col] = migas_de_pan_[199-col][fila];
			}
		}

		orientacion_=(orientacion_+1)%4;
	}
	else if(f1 == -c2){
		cout << "Estoy girado a la derecha" << endl;
		// swap(pk2f, pk2c);
		swap(mypk2c, mypk2f);
		// mypk1f = 199 -mypk1f;
		mypk2f = 199 -mypk2f;
		// pk2c = 99 - pk2c;
		/*for(int fila = mypk1f - pk1f+ 99, i = 0; i < 100; i++, fila--){
			for(int col = mypk1c - pk1c, j = 0; j < 100; j++, col++){
				aux[i][j] = mapa_entorno_[fila][col];
				aux_migas[i][j] = migas_de_pan_[fila][col];
			}
		}*/

		for(int fila = 0; fila < 200; fila++){
			for(int col = 0; col < 200;col++){
				aux[fila][col] = mapa_entorno_[col][199-fila];
				aux_migas[fila][col] = migas_de_pan_[col][199-fila];
			}
		}

		orientacion_=(orientacion_+3)%4;
	}

	for(int i = 0; i < 200; i++){
		for(int j = 0; j < 200; j++){
			mapa_entorno_[i][j] = '?';
			migas_de_pan_[i][j] = 0;
		}
	}

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			// mapa_entorno_[i][j] = aux[mypk2f -pk2f + i][mypk2c - pk2c + j];
			if(respawn){
				if(mapa_solucion_[i][j] == '?'){
					mapa_solucion_[i][j] = aux[mypk2f -pk2f + i][mypk2c - pk2c + j];
					migas_de_pan_[i][j] = aux_migas[mypk2f -pk2f + i][mypk2c - pk2c + j];
				}
				else{
					migas_de_pan_[i][j] = 3 + aux_migas[mypk2f -pk2f + i][mypk2c - pk2c + j];
				}
			}
			else{
				// if(mapa_solucion_[i][j] != '?' and aux[mypk2f -pk2f + i][mypk2c - pk2c + j] == '?')
				mapa_solucion_[i][j] = aux[mypk2f -pk2f + i][mypk2c - pk2c + j];
				migas_de_pan_[i][j] = aux_migas[mypk2f -pk2f + i][mypk2c - pk2c + j];
			}
			
		}
	}

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			mapa_entorno_[i][j] = mapa_solucion_[i][j];
			mapa_solucion_[i][j] = mapa_entorno_[i][j];
		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 100; j++){
			mapa_entorno_[i][j] = 'P';
			mapa_solucion_[i][j] = 'P';
		}
	}

	for(int i = 97; i < 100; i++){
		for(int j = 0; j < 100; j++){
			mapa_entorno_[i][j] = 'P';
			mapa_solucion_[i][j] = 'P';
		}
	}
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 3; j++){
			mapa_entorno_[i][j] = 'P';
			mapa_solucion_[i][j] = 'P';
		}
	}

	for(int i = 97; i < 100; i++){
		for(int j = 97; j < 100; j++){
			mapa_entorno_[i][j] = 'P';
			mapa_solucion_[i][j] = 'P';
		}
	}




	x_ = pk2c;
	y_ = pk2f;


}

bool Agent::cabe(){
	int cont = 0;
	for(int i = 0; i < 4; i++){
		if(MOCHILLA_[i] == '-'){
			cont ++;
		}
	}

	cout << "En la mochila tengo "<< cont << " huecos";


	if(cont == 2 and find('0') and find('6') || (cont == 2 and EN_USO_ == '0' and find('6') || (cont == 2 and EN_USO_ == '6' and find('0')))){
		cout << "Puedo cogerlo\n";
		return true;
	}

	else if(cont <= 2){
		cout << "NO PUEDO COGERLO\n";
		return false;
	}

	else if(cont == 3 and EN_USO_ == '-'){
		cout << "Puedo cogerlo\n";
		return true;
	}

	else if(cont > 3){
		cout << "Puedo cogerlo\n";
		return true;
	}	

	else {
		cout << "NO Puedo cogerlo\n";
		return false;
	}
}



int Agent::a_donde_voy(int izquierda_x, int izquierda_y, int derecha_x, int derecha_y, int alante_x, int alante_y){

	int izquierda = migas_de_pan_[izquierda_y][izquierda_x];
	int derecha = migas_de_pan_[derecha_y][derecha_x];
	int alante = migas_de_pan_[alante_y][alante_x];

	if(!sePuedeIr(izquierda_x, izquierda_y)){
		izquierda = 1000000;
	}

	if(!sePuedeIr(derecha_x, derecha_y)){
		derecha = 1000000;
	}

	if(!sePuedeIr(alante_x, alante_y)){
		alante = 1000000;
	}
	cout << "El valor de mi casilla es: " << migas_de_pan_[y_][x_]<<endl;
	cout << "El valor de izquierda es: " << izquierda<<endl;
	cout << "El valor de derecha es: " << derecha << endl;
	cout << "El valor de alante es: " << alante << endl;

	if(alante <= izquierda && alante <= derecha){
		if(alante == 1000000){
			return 1;
		}
		else 
			return 0;
	}
	else if(izquierda <= derecha){
		return 1;
	}

	else 
		return 2;


	/*if(izquierda == derecha && derecha == alante){
		if(sePuedeIr(alante_x, alante_y)){
			return 0;
		}
		else if(sePuedeIr(derecha_x, derecha_y)){
			return 2;
		}
		else{
			return 1;
		}
	}

	else if(alante == derecha && alante < izquierda){
		if(sePuedeIr(alante_x, alante_y)){
			return 0;
		}
		else if(sePuedeIr(derecha_x, derecha_y)){
			return 2;
		}
		else{
			return 1;
		}
	}


	else if(alante == izquierda && alante < derecha){
		if(sePuedeIr(alante_x, alante_y)){
			return 0;
		}
		else if(sePuedeIr(izquierda_x, izquierda_y)){
			return 2;
		}
		else{
			return 1;
		}
	}

	else if(izquierda == derecha && izquierda < alante){
		if(sePuedeIr(izquierda_x, izquierda_y)){
			return 1;
		}
		else if(sePuedeIr(derecha_x, derecha_y)){
			return 2;
		}
		else{
			return 0;
		}
	}

	else if(alante < izquierda && alante < derecha){
		if(sePuedeIr(alante_x, alante_y))
			return 0;
		else if(izquierda < derecha)
			if(sePuedeIr(izquierda_x, izquierda_y)){
				return 1;
			}
		else
			return 2;
	}

	else if(izquierda < alante && izquierda < derecha){
		if(sePuedeIr(izquierda_x, izquierda_y))
			return 1;
		else if(sePuedeIr(alante_x, alante_y))
			return 0;
		else
			return 2;
	}

	else if(derecha < alante && derecha < izquierda){
		if(sePuedeIr(derecha_x, derecha_y))
			return 1;
		else if(sePuedeIr(alante_x, alante_y))
			return 0;
		else
			return 2;
	}*/
}

// void agregar_aux()

// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
	Agent::ActionType accion = actFORWARD; // Por defecto avanza


	// tomar accion
	/*if(giro_final){
		cout << "Regla 3: ultima parte del movimiento\n";
		if(giro_derecha)
			accion = actTURN_L;
		else
			accion = actTURN_R;
		giro_final=false;
		giro_derecha = false;
	}

	if(VISTA_[1] =='B' or VISTA_[1] =='M' or VISTA_[1] == 'P' or VISTA_[1] =='A' or VISTA_[1] =='D'){
		
		accion = actTURN_L;
		giro_derecha = false;
		
		giro_inicial=true;
		giro_final=false;
		cout << "Regla 1: evita obstaculo del terreno\n";
		// avances=0;
	}*/

	//aciones al ver un personaje
/*
	else if(VISTA_[1] >='e' and VISTA_[1] <='z'){
		if(rand()%2==0){
			accion = actTURN_L;
			giro_derecha = false;
		}
		else{
			accion = actTURN_R;
			giro_derecha = true;
		}
		giro_inicial=true;
		giro_final=false;
		cout << "HE VISTO A UN PERSONAJE; QUE HORROR...\n";
	}*/
/*
	else if(giro_inicial){
		cout << "Regla 2: primera parte del movimiento\n";
		accion = actFORWARD;
		giro_inicial=false;
		giro_final=true;
	}*/	

	/*else if(avances<20){
		cout << "Regla 4: Sigo palante\n";
		accion = actFORWARD;
		avances++;
	}

	else if(rand()%2==0){
		if(VISTA_[4] =='B' or VISTA_[4] =='M' or VISTA_[4] == 'P' or VISTA_[4] =='A' or VISTA_[4] =='D')
			accion = actFORWARD;
		else{
			cout << "Regla 5a: giro a la derecha\n";
			accion = actTURN_R;
			avances=0;
		}
	}
	else{
		if(VISTA_[2] =='B' or VISTA_[2] =='M' or VISTA_[2] == 'P' or VISTA_[2] =='A' or VISTA_[2] =='D')
			accion = actFORWARD;
		else{
			cout << "Regla 5a: giro a la izquierda\n";
			accion = actTURN_L;
			avances=0;
		}
	}*/

	if(he_guardado){
		accion = actPICKUP;
		he_guardado = false;
	}	

	//coger bañador

	else if(SURFACE_[0] == '0' and EN_USO_ == '-'){
		cout << "He recogido el bañador\n";
		accion = actPICKUP;
	}
	else if(SURFACE_[0] == '0' and EN_USO_ != '-'){
		cout << "He visto el bañador pero tengo algo en la mano"<<endl;
		accion = actPUSH;
		he_guardado = true;
	}

	//coger botas

	else if(SURFACE_[0] == '6' and EN_USO_ == '-'){
		cout << "He recogido el zapatillas\n";
		accion = actPICKUP;
	}
	else if(SURFACE_[0] == '6' and EN_USO_ != '-'){
		cout << "He visto las zapatillas pero tengo algo en la mano"<<endl;
		accion = actPUSH;
		he_guardado = true;
	}
	//coger algoritmo

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '9' and EN_USO_ == '-' and cabe()){
		cout << "He recogido el alg\n";
		accion = actPICKUP;
	}

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '9' and EN_USO_ != '-' and cabe()){
		cout << "He visto un algoritmo pero tengo algo en la mano"<<endl;
		accion = actPUSH;
		he_guardado = true;
	}

	//coger oscar

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '5' and EN_USO_ == '-' and cabe()){
		cout << "He recogido el alg\n";
		accion = actPICKUP;
	}

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '5' and EN_USO_ != '-' and cabe()){
		cout << "He visto un oscar pero tengo algo en la mano"<<endl;
		accion = actPUSH;
		he_guardado = true;
	}

	//coger manzana

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '8' and EN_USO_ == '-' and cabe()){
		cout << "He recogido una manzana\n";
		accion = actPICKUP;
	}

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '8' and EN_USO_ != '-' and cabe()){
		cout << "He visto una manzana pero tengo algo en la mano"<<endl;
		accion = actPUSH;
		he_guardado = true;
	}

	//coger oro

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '4' and EN_USO_ == '-' and cabe()){
		cout << "He recogido una oro\n";
		accion = actPICKUP;
	}

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '4' and EN_USO_ != '-' and cabe()){
		cout << "He visto oro pero tengo algo en la mano"<<endl;
		accion = actPUSH;
		he_guardado = true;
	}

	//coger oscar

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '2' and EN_USO_ == '-' and cabe()){
		cout << "He recogido la espada\n";
		accion = actPICKUP;
	}

	else if(VISTA_[0] != 'B' and VISTA_[0] != 'A' and SURFACE_[0] == '2' and EN_USO_ != '-' and cabe()){
		cout << "He visto una espada pero tengo algo en la mano"<<endl;
		accion = actPUSH;
		he_guardado = true;
	}

	//entrar al agua

	else if(VISTA_[1] == 'A' and EN_USO_ == '0' && (buscando1 or buscando2)){	
		buscando1 = false;
		buscando2 = false;
		accion = actFORWARD;
	}

	//entrar al bosque

	else if(VISTA_[1] == 'B' and EN_USO_ == '6' && (buscando1 or buscando2)){

		cout << "voy a entrar en el bosque"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actFORWARD;
	}

	//dar el alg al profe

	else if(SURFACE_[1] == 'o' and EN_USO_ == '9'){
		cout << "Le dou el algoritmo al profesor"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] == 'p' and EN_USO_ == '9'){
		cout << "Le dou el algoritmo al profesor"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] == 'o' and EN_USO_ == '9' && (buscando1 or buscando2)){
		cout << "le dou el algoritmo al profesor"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	else if(SURFACE_[1] == 'p' and EN_USO_ == '9' && (buscando1 or buscando2)){
		cout << "Le dou el algoritmo al profesor"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	//dar el oscar a dicaprio

	else if(SURFACE_[1] == 'i' and EN_USO_ == '5' and VISTA_[0] != 'B' and VISTA_[0] != 'A'){
		cout << "Le dou el oscar a dicaprio"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] == 'j' and EN_USO_ == '5' and VISTA_[0] != 'B' and VISTA_[0] != 'A'){
		cout << "Le dou el oscar a dicaprio"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] == 'i' and EN_USO_ == '5' && (buscando1 or buscando2) and VISTA_[0] != 'B' and VISTA_[0] != 'A'){
		cout << "le doy el oscar a dicaprio"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	else if(SURFACE_[1] == 'j' and EN_USO_ == '5' && (buscando1 or buscando2) and VISTA_[0] != 'B' and VISTA_[0] != 'A'){
		cout << "Le dou el oscar a dicaprio"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	//dar la manzana a la bruja

	else if(SURFACE_[1] == 'm' and EN_USO_ == '8'){
		cout << "Le doy la manzana a la bruja"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] == 'n' and EN_USO_ == '8'){
		cout << "Le doy la manzana a la bruja"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] == 'm' and EN_USO_ == '8' && (buscando1 or buscando2)){
		cout << "le doy la manzana a la bruja"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	else if(SURFACE_[1] == 'n' and EN_USO_ == '8' && (buscando1 or buscando2)){
		cout << "Le doy la manzana a la bruja"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	//dar oro a cualquiera


	else if(SURFACE_[1] >= 'g' and SURFACE_[1] <= 'p' and EN_USO_ == '4'){
		cout << "le doy el oro a alguien"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] >= 'g' and SURFACE_[1] <= 'p' and EN_USO_ == '4' && (buscando1 or buscando2)){
		cout << "le doy el oro a alguien"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	else if(SURFACE_[1] >= 'g' and SURFACE_[1] <= 'p' and EN_USO_ == '4' && (buscando1 or buscando2)){
		cout << "le doy el oro a alguien"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	//dar la espada al princeso

	else if(SURFACE_[1] == 'k' and EN_USO_ == '2'){
		cout << "Le doy la espada al princeso"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] == 'l' and EN_USO_ == '2'){
		cout << "Le doy la espada al princeso"<<endl;
		accion = actGIVE;
		buscando1 = false;
		buscando2 = false;
	}

	else if(SURFACE_[1] == 'k' and EN_USO_ == '2' && (buscando1 or buscando2)){
		cout << "Le doy la espada al princeso"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	else if(SURFACE_[1] == 'l' and EN_USO_ == '2' && (buscando1 or buscando2)){
		cout << "Le doy la espada al princeso"<<endl;
		buscando1 = false;
		buscando2 = false;
		accion = actGIVE;
	}

	//busqueda

	else if(buscando2){
		accion = actPUSH;
		cout << "En uso tengo: " << EN_USO_ << endl;
		buscando2 = false;
		buscando1 = true;
	}

	else if(buscando1){
		// cout << "saco de la mochila" << MOCHILLA_[0]<<endl;
		accion = actPOP;
		cout << "En uso tengo: " << EN_USO_ << endl;
		buscando1 = false;
		buscando2 = true;
	}

	//ver algo pero no poder usarlo

	else if(VISTA_[1] == 'A' and EN_USO_ != '0' and find('0')){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;	
	}

	else if(VISTA_[1] == 'B' and EN_USO_ != '6' and find('6')){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] == 'o' and EN_USO_ != '9' and find('9') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] == 'p' and EN_USO_ != '9' and find('9') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] == 'i' and EN_USO_ != '5' and find('5') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] == 'j' and EN_USO_ != '5' and find('5') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] == 'm' and EN_USO_ != '8' and find('8') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] == 'n' and EN_USO_ != '8' and find('8') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] >= 'g' and SURFACE_[1] <= 'p' and EN_USO_ != '4' and find('4') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] == 'k' and EN_USO_ != '2' and find('2') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else if(SURFACE_[1] == 'l' and EN_USO_ != '2' and find('2') and VISTA_[0] != 'B' and VISTA_[0] != 'A'){	
		buscando1 = true;
		cout << "guardo en la mochila"<< EN_USO_ <<endl;
		accion = actPUSH;

	}

	else{
/*
		if(MENSAJE_ == "Has chocado con un obstaculo movil. "){
			switch(orientacion_){
		    case 0: // norte
			    y_++;
			    break;
		    case 1: // este
			    x_--;
			    break;
		    case 2: // sur
			    y_--;
			    break;
		    case 3: // oeste
			    x_++;
			    break;
		  }
		}*/


	// else{

	
		cout << "Sigo el algoritmo de Hansel y Gretel\n";
		int decision;

		if(orientacion_ == 0){
			cout << "miro al norte\n";
			decision = a_donde_voy(x_-1, y_, x_+1, y_, x_, y_-1);
		}
		else if(orientacion_ == 1){
			cout << "miro al este\n";
			decision = a_donde_voy(x_, y_-1, x_, y_+1, x_+1, y_);
		}
		else if(orientacion_ == 2){
			cout << "miro al sur\n";
			decision = a_donde_voy(x_+1, y_, x_-1, y_, x_, y_+1);
		}
		else if(orientacion_ == 3){
			cout << "miro al oeste\n";
			decision = a_donde_voy(x_, y_+1, x_, y_-1, x_-1, y_);
		}

		if(decision == 0){
			cout << "Vamos Palante\n";
			accion = actFORWARD;
			// bit_de_giro = 0;

		}
		else if(decision == 1){
			cout << "Giramos pa la izquierda\n";
			accion = actTURN_L;
			// bit_de_giro = 1;
		}
		else if(decision == 2){
			cout << "Giramos pa la derecha\n";
			accion = actTURN_R;
			// bit_de_giro = 2;
		}

		cout << "En uso tengo: "<< EN_USO_ << endl;
	}

	


	// recuerdo la ultima accion realizada
	last_accion_ = accion;

	return accion;

}
