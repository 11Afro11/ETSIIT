#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include "player.h"
#include "environment.h"

using namespace std;

const double masinf=9999999999.0, menosinf=-9999999999.0;
const double perfecto = 100, muybueno = 50, bueno = 25;
const double catastrofe = -perfecto, muymalo = -muybueno, malo = -bueno;


// Constructor
Player::Player(int jug){
    jugador_=jug;
}

// Actualiza el estado del juego para el jugador
void Player::Perceive(const Environment & env){
    actual_=env;
}

double Puntuacion(int jugador, const Environment &estado){
    double suma=0;

    for (int i=0; i<7; i++)
      for (int j=0; j<7; j++){
         if (estado.See_Casilla(i,j)==jugador){
            if (j<3)
               suma += j;
            else
               suma += (6-j);
         }
      }

    return suma;
}


// Funcion de valoracion para testear Poda Alfabeta
double ValoracionTest(const Environment &estado, int jugador){
    int ganador = estado.RevisarTablero();

    if (ganador==jugador)
       return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador!=0)
            return -99999999.0; // Pierde el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
            return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else
          return Puntuacion(jugador,estado);
}

// ------------------- Los tres metodos anteriores no se pueden modificar

double Min(double uno, double dos){
    if(uno <= dos){
        return uno;
    }
    else 
        return dos;
}

void MuestraMatriz(const Environment &env){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            cout << (char)(env.See_Casilla(i,j)+48)<<" ";
        }
        cout << endl;
    }
}

bool Player::MiFilaBomba(const Environment &matriz, int fila){
    for(int i = 0; i < 7; i++){
        if(static_cast <int>(matriz.See_Casilla(fila, i)) -3 == jugador_){
            return true;
        }
    }
    return false;
}

bool Player::SuFilaBomba(const Environment &matriz, int fila){
    for(int i = 0; i < 7; i++){
        if(static_cast<int>(matriz.See_Casilla(fila, i)) -3 == jugadorOpuesto(jugador_)){
            return true;
        }
    }
    return false;
}


double Max(double uno, double dos){
    if(uno >= dos){
        return uno;
    }
    else return dos;
}

int Player::FormaLineaHoriz(const Environment &matriz, int i, int j, char valor){
    int cont = 0; 
    int mueve = j;
    // cout << "Vmos a ver si la forma\n";
    int numerico = static_cast<int>(valor);
    while((static_cast<int>(matriz.See_Casilla(i,j)) == numerico or
     static_cast<int>(matriz.See_Casilla(i,j))-2 == numerico ) and j < 7){
        j++;
        cont++;
    }
    if(numerico == jugador_ or numerico -2 == jugador_){
        cont = -1*cont;
    }
    // cout << "Hay "<< cont << " horizontales\n";
    return cont;
}

int Player::FormaLineaVert(const Environment &matriz, int i, int j, char valor){
    int cont = 0; 
    int mueve= i;
    int numerico = static_cast<int>(valor);
    while((static_cast<int>(matriz.See_Casilla(mueve,j)) == numerico or
     static_cast<int>(matriz.See_Casilla(mueve,j))-2 == numerico ) and mueve < 6 and mueve >= 0){
        mueve++;
        cont++;
    }
    if(numerico == jugador_ or numerico -2 == jugador_){
        cont = -1*cont;
    }
    // cout << "Hay "<< cont << " verticales\n";
    return cont;
}

int Player::FormaLineaDiagIzq(const Environment &matriz, int i, int j, char valor){
    int cont = 0; 
    int mueve= i;
    int muevej = j;
    int numerico = static_cast<int>(valor);
    while((static_cast<int>(matriz.See_Casilla(mueve,muevej)) == numerico or
     static_cast<int>(matriz.See_Casilla(mueve,muevej))-2 == numerico ) and mueve < 6 and muevej < 6 and mueve >= 0 and muevej >= 0){
        mueve++;
        muevej++;
        cont++;
    }
    if(numerico == jugador_ or numerico -2 == jugador_){
        cont = -1*cont;
    }
    // cout << "Hay "<< cont << " diagonales\n";
    return cont;
}

int Player::FormaLineaDiagDer(const Environment &matriz, int i, int j, char valor){
    int cont = 0; 
    int mueve= i;
    int muevej = j;
    int numerico = static_cast<int>(valor);
    while((static_cast<int>(matriz.See_Casilla(mueve,muevej)) == numerico or
     static_cast<int>(matriz.See_Casilla(mueve,muevej))-2 == numerico ) and mueve < 6 and muevej < 6 and mueve >= 0 and muevej >= 0){
        mueve++;
        muevej--;
        cont++;
    }
    if(numerico == jugador_ or numerico -2 == jugador_){
        cont = -1*cont;
    }
    // cout << "Hay "<< cont << " diagonales\n";
    return cont;
}

double Player::BuenoOMalo(int tam, char valor){
    if(static_cast<int>(valor) == jugador_){
        if(tam == 3){
            return -25.0;
        }
        else{
            return -15.0;
        }
    }
    else if(static_cast<int>(valor) == jugadorOpuesto(jugador_)){
        if(tam == 3){
            return 25.0;
        }
        else{
            return 15.0;
        }
    }
}

double Player::MuyBuenoOMalo(const Environment &matriz, int posx, char valor){
    if(static_cast<int>(valor) == jugador_){
        if(SuFilaBomba(matriz,posx)){
            return -100.0;
        }  
        else{
            return -50.0;
        }
    }
    else if(static_cast<int>(valor) == jugadorOpuesto(jugador_)){
        if(MiFilaBomba(matriz, posx)){
            return 100.0;       
        }
        else{
            return 50.0;
        }
    }
}

double Player::ValorPorPunto(const Environment &estado, int posx, int posy, char valor){

    // cout << "he llegado hasta aqui\n";
    double vheuristico=0;
    // int miLinea=0.0;
    // int suLinea=0.0;
    int horiz = FormaLineaHoriz(estado, posx, posy, valor);
    int vert = FormaLineaVert(estado, posx, posy, valor);
    int diagIzq = FormaLineaDiagIzq(estado, posx, posy, valor);
    int diagDer = FormaLineaDiagDer(estado, posx, posy, valor);

    // cout << horiz << " " << vert << " " << diagIzq << " " << diagDer <<endl;

    int cuatro = 0;
    int tres = 0; 
    int dos = 0;
    int menoscuatro = 0;
    int menostres = 0;
    int menosdos = 0;

    // cout << "Hay "<<horiz<<"en horizontal"<<endl;
    // cout << "Hay "<<vert<<"en vertical"<<endl;
    // cout << "Hay "<<diag<<"en diagonal"<<endl;

    //VALOR HORIZONTAL PERJUDICIAL
    if(horiz == -4){
        menoscuatro++;
        // cout << "hay una linea de 4 con valor"<< valor <<endl;
    }
    else if(horiz == -3){
        menostres++;
        // cout << "hay una linea de 3 con valor"<< valor <<endl;
    }
    else if(horiz == -2){
        menosdos++;
        // cout << "Si la forma, de 2 "<<endl;
    }

    //VALOR HORIZONTAL BENEFICIONSO

    if(horiz == 4){
        cuatro++;
        // cout << "hay una linea de 4 con valor"<<valor<<endl;
    }
    else if(horiz == 3){
        tres++;
        // cout << "hay una linea de 3 con valor"<<valor<<endl;
    }
    else if(horiz == 2){
        dos++;
        // cout << "Si la forma, de 2 "<<endl;
    }

    //VALOR VERTICAL BENEFICIONSO

    if(vert == 4){
        cuatro++;
        // cout << "hay una linea de 4 con valor"<<valor<<endl;
    }
    else if(vert == 3){
        tres++;
        // cout << "hay una linea de 3 con valor"<<valor<<endl;
    }
    else if(vert == 2){
        dos++;
        // cout << "Si la forma, de 2 "<<endl;
    }

    //VALOR VERTICAL PERJUDICIAL

    if(vert == -4){
        menoscuatro++;
        // cout << "hay una linea de 4 con valor"<<valor<<endl;
    }
    else if(vert == -3){
        menostres++;
        // cout << "hay una linea de 3 con valor"<<valor<<endl;
    }
    else if(vert == -2){
        menosdos++;
        // cout << "Si la forma, de 2 "<<endl;
    }

    //VALOR DIAGONAL IZQUIERDA BENEFICIOSO

    if(diagIzq == 4){
        cuatro++;
        // cout << "hay una linea de 4 con valor"<<valor<<endl;
    }
    else if(diagIzq == 3){
        tres++;
        // cout << "hay una linea de 3 con valor"<<valor<<endl;
    }
    else if(diagIzq == 2){
        dos++;
        // cout << "Si la forma, de 2 "<<endl;
    }

    //VALRO DIAGONAL IZQUIERDA PERJUDICIAL

    if(diagIzq == -4){
        menoscuatro++;
        // cout << "hay una linea de 4 con valor"<<valor<<endl;
    }
    else if(diagIzq == -3){
        menostres++;
        // cout << "hay una linea de 3 con valor"<<valor<<endl;
    }
    else if(diagIzq == -2){
        menosdos++;
        // cout << "Si la forma, de 2 "<<endl;
    }

    //VALOR DIAGONAL DERECHA BENEFICIOSO

    if(diagDer == 4){
        cuatro++;
        // cout << "hay una linea de 4 con valor"<<valor<<endl;
    }
    else if(diagDer == 3){
        tres++;
        // cout << "hay una linea de 3 con valor"<<valor<<endl;
    }
    else if(diagDer == 2){
        dos++;
        // cout << "Si la forma, de 2 "<<endl;
    }

    //VALOR DIAGONAL DERECHA PERJUDICIAL

    if(diagDer == -4){
        menoscuatro++;
        // cout << "hay una linea de 4 con valor"<<valor<<endl;
    }
    else if(diagDer == -3){
        menostres++;
        // cout << "hay una linea de 3 con valor"<<valor<<endl;
    }
    else if(diagDer == -2){
        menosdos++;
        // cout << "Si la forma, de 2 "<<endl;
    }


    vheuristico =0 + (cuatro*10000+ tres*100+ dos*10)-(menoscuatro*10000+ menostres*100 + menosdos*10);
    // vheuristico += - (menoscuatro+ menostres + menosdos);

    cout << "El valor heuristico de este nodo es: "<<vheuristico<<endl;
    return vheuristico;


    /*int ha_formado_linea = 0;
    if(FormaLineaHoriz(estado, posx, posy, valor) == 3){
        if(estado.See_Casilla(posx+1, posy+3) == valor or estado.See_Casilla(posx+1, posy-1) == valor){
            return MuyBuenoOMalo(estado, posx, valor);    
        }

        else if(estado.See_Casilla(posx-1, posy+3) == valor or estado.See_Casilla(posx-1, posy-1) == valor){
            return MuyBuenoOMalo(estado, posx-1, valor);   
        }
        ha_formado_linea = 3;
        cout << "Ha formado una linea de 3 "<<endl;

    }

    else if(FormaLineaHoriz(estado, posx, posy, valor) == 2){
        if(estado.See_Casilla(posx+1, posy-1) == valor and estado.See_Casilla(posx+1, posy+3) == valor){
            return MuyBuenoOMalo(estado, posx, valor);
        }

        else if(estado.See_Casilla(posx-1, posy-1) == valor and estado.See_Casilla(posx-1, posy+3) == valor){
            return MuyBuenoOMalo(estado, posx-1, valor);
        }

        else if(estado.See_Casilla(posx, posy-2) == valor and estado.See_Casilla(posx-1, posy-1) == valor){
            return MuyBuenoOMalo(estado, posx-1, valor);
        }

        else if(estado.See_Casilla(posx, posy-2) == valor and estado.See_Casilla(posx-1, posy+1) == valor){
            return MuyBuenoOMalo(estado, posx, valor);
        }

        else if(estado.See_Casilla(posx, posy+2) == valor and estado.See_Casilla(posx+1, posy-1) == valor){
            return MuyBuenoOMalo(estado, posx-1, valor);
        }

        else if(estado.See_Casilla(posx, posy+2) == valor and estado.See_Casilla(posx+1, posy+1) == valor){
            return MuyBuenoOMalo(estado, posx, valor);
        }
        ha_formado_linea = 2;
        cout << "ha formado una linea de 2"<<endl;
    }

    else if(FormaLineaVert(estado, posx, posy, valor) == 3){
        if(estado.See_Casilla(posx+3, posy) != valor and estado.See_Casilla(posx+4, posy) == valor){
            return MuyBuenoOMalo(estado, posx+3, valor);         
        }

        else if(estado.See_Casilla(posx+2, posy) != valor and estado.See_Casilla(posx+3, posy) == valor 
                and estado.See_Casilla(posx+4, posy) == valor){
            return MuyBuenoOMalo(estado, posx+2, valor);         
        }

        else if(estado.See_Casilla(posx+1, posy) != valor and estado.See_Casilla(posx+4, posy) == valor
            and estado.See_Casilla(posx+2, posy) == valor
            and estado.See_Casilla(posx+3, posy) == valor
            and estado.See_Casilla(posx+4, posy) == valor){
            return MuyBuenoOMalo(estado, posx+1, valor);         
        }

        ha_formado_linea = 3;
        cout << "Ha formado una linea de 3 en vertical"<<endl;
    }

    else if(ha_formado_linea > 0){
        ha_formado_linea = BuenoOMalo(ha_formado_linea, valor);
    }
    return ha_formado_linea;*/
}


int Player::jugadorOpuesto(int jug){
    if(jug == 1){
        return 2;
    }
    if(jug == 2){
        return 1;
    }
}

bool Vacio(const Environment &tablero){
    for(int i = 0; i < 7; i++){
        if(tablero.See_Casilla(0, i) != 0){
            return false;
        }
    }
    return true;
}

// Funcion heuristica (ESTA ES LA QUE TENEIS QUE MODIFICAR)
//vamos a poder devolver valores según como de buena sea la situación del tablero

double Player::Valoracion(const Environment &estado, int jugador){
    double min = masinf;
    int ganador = estado.RevisarTablero();

    if (ganador==jugador)
       return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador!=0)
            return -99999999.0; // Pierde el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
            return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else
          return Puntuacion(jugador,estado);

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            char a_mirar = estado.See_Casilla(i,j)+48;
            char miramos = estado.See_Casilla(i,j);
            // int numerico = static_cast<int>(a_mirar);
            if(a_mirar != '0'){
                // cout << "He llegado aqui\n";
                // double aux = ValorPorPunto(estado, i, j, a_mirar);
                // cout << "El valor que voy a mirar es "<<aux<<endl;
                min = Min(min, ValorPorPunto(estado, i, j, miramos));
            }
        }
    }
    // MuestraMatriz(estado);
    return -1*min;   
}

double Player::Poda_AlfaBeta(const Environment & matriz, int player, int prof, int lim, 
    Environment::ActionType & acction, double alfa, double bet, bool minmax){

    Environment::ActionType last_action;
    if(prof == 0 or matriz.JuegoTerminado()){
        return Valoracion(matriz, player);
    }
    else if(minmax){
        int ultima_accion = -1;
        Environment hijo = matriz.GenerateNextMove(ultima_accion);
        while(ultima_accion < 8){
            double aux = Poda_AlfaBeta(hijo, player, prof-1, lim, last_action, alfa, bet, false);
            if(aux > alfa){
                alfa = aux;
                acction = static_cast <Environment::ActionType> (ultima_accion);
            }

            if(bet <= alfa){
                return bet;
            }
            hijo = matriz.GenerateNextMove(ultima_accion);
        }
        return alfa;
    }

    else{
        int ultima_accion = -1;
        Environment hijo = matriz.GenerateNextMove(ultima_accion);
        while(ultima_accion < 8){
            double aux = Poda_AlfaBeta(hijo, player, prof-1, lim, last_action, alfa, bet, true);
            if(aux < bet){
                bet = aux;
                acction = static_cast <Environment::ActionType> (ultima_accion);
            }

            if(bet <= alfa){
                return alfa;
            }
            hijo = matriz.GenerateNextMove(ultima_accion);
        }
        return bet;
    }

        
/*    else{
        int ultima_accion = -1;
        Environment hijo = matriz.GenerateNextMove(ultima_accion);
        while(!(hijo == matriz) && alfa < bet){
            double aux = Poda_AlfaBeta(hijo, player, prof+1, lim, last_action, alfa, bet, false);
            if(prof %2 == 0){
                if(aux > alfa){
                    alfa = aux;
                    acction = static_cast <Environment::ActionType> (ultima_accion);
                }
            }
            else{
                if(aux < bet){
                    bet = aux;
                    acction = static_cast <Environment::ActionType> (ultima_accion);
                }
            }
            
            hijo = matriz.GenerateNextMove(ultima_accion);
        }
        if(prof %2 == 0){
            return alfa;
        }
        else{
            return bet;
        }
    }*/
    
}

double Prueba(const Environment &T, int jugador, int prof, int & act){
    double max = -99999999999999.9;
    if(prof == 0){
        return ValoracionTest(T, jugador);
    }
    else{
        int ult_act = -1;
        int kk;
        double valor;
        Environment hijo = T.GenerateNextMove(ult_act);
        while(ult_act < 8){
            valor = Prueba(hijo, jugador, prof-1, kk);
            if(valor > max){
                max = valor;
                act = ult_act;
            }
            
            hijo = T.GenerateNextMove(ult_act);
        }
        return max;
    }
}


// Esta funcion no se puede usar en la version entregable
// Aparece aqui solo para ILUSTRAR el comportamiento del juego
// ESTO NO IMPLEMENTA NI MINIMAX, NI PODA Poda_AlfaBeta
void JuegoAleatorio(bool aplicables[], int opciones[], int &j){
    j=0;
    for (int i=0; i<8; i++){
        if (aplicables[i]){
           opciones[j]=i;
           j++;
        }
    }
}






// Invoca el siguiente movimiento del jugador
Environment::ActionType Player::Think(){
    const int PROFUNDIDAD_MINIMAX = 6;  // Umbral maximo de profundidad para el metodo MiniMax
    const int PROFUNDIDAD_ALFABETA = 8; // Umbral maximo de profundidad para la poda Alfa_Beta

    Environment::ActionType accion; // acción que se va a devolver
    bool aplicables[8]; // Vector bool usado para obtener las acciones que son aplicables en el estado actual. La interpretacion es
                        // aplicables[0]==true si PUT1 es aplicable
                        // aplicables[1]==true si PUT2 es aplicable
                        // aplicables[2]==true si PUT3 es aplicable
                        // aplicables[3]==true si PUT4 es aplicable
                        // aplicables[4]==true si PUT5 es aplicable
                        // aplicables[5]==true si PUT6 es aplicable
                        // aplicables[6]==true si PUT7 es aplicable
                        // aplicables[7]==true si BOOM es aplicable



    double valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
    double alpha, beta; // Cotas de la poda AlfaBeta
    alpha = menosinf;
    beta = masinf;
    int n_act; //Acciones posibles en el estado actual


    n_act = actual_.possible_actions(aplicables); // Obtengo las acciones aplicables al estado actual en "aplicables"
    int opciones[10];

    // Muestra por la consola las acciones aplicable para el jugador activo
    //actual_.PintaTablero();
    cout << " Acciones aplicables ";
    (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
    for (int t=0; t<8; t++)
      if (aplicables[t])
         cout << " " << actual_.ActionStr( static_cast< Environment::ActionType > (t)  );
    cout << endl;


    //--------------------- COMENTAR Desde aqui
/*    cout << "\n\t";
    int n_opciones=0;
    JuegoAleatorio(aplicables, opciones, n_opciones);

    if (n_act==0){
      (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
      cout << " No puede realizar ninguna accion!!!\n";
      //accion = Environment::actIDLE;
    }
    else if (n_act==1){
           (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
            cout << " Solo se puede realizar la accion "
                 << actual_.ActionStr( static_cast< Environment::ActionType > (opciones[0])  ) << endl;
            accion = static_cast< Environment::ActionType > (opciones[0]);

         }
         else { // Hay que elegir entre varias posibles acciones
            int aleatorio = rand()%n_opciones;
            cout << " -> " << actual_.ActionStr( static_cast< Environment::ActionType > (opciones[aleatorio])  ) << endl;
            accion = static_cast< Environment::ActionType > (opciones[aleatorio]);
         }
*/
    //--------------------- COMENTAR Hasta aqui


    //--------------------- AQUI EMPIEZA LA PARTE A REALIZAR POR EL ALUMNO ------------------------------------------------
    
    if(Vacio(actual_))
        return accion = Environment::PUT7;


    // MuestraMatriz(actual_);


    // Opcion: Poda AlfaBeta
    // NOTA: La parametrizacion es solo orientativa
    valor = Poda_AlfaBeta(actual_, jugador_, 8, PROFUNDIDAD_ALFABETA, accion, alpha, beta, true);
    cout << "Valor MiniMax: " << valor << "  Accion: " << actual_.ActionStr(accion) << endl;

    return accion;
}

