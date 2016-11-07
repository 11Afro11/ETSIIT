#ifndef PLAYER_H
#define PLAYER_H

#include "environment.h"

class Player{
    public:
      Player(int jug);
      Environment::ActionType Think();
      void Perceive(const Environment &env);
      bool MiFilaBomba(const Environment &matriz, int fila);
      bool SuFilaBomba(const Environment &matriz, int fila);
      int jugadorOpuesto(int jug);
      double BuenoOMalo(int tam, char valor);
      double MuyBuenoOMalo(const Environment & estdo, int posx, char valor);
      double ValorPorPunto(const Environment &estado, int posx, int posy, char valor);
      double Valoracion(const Environment &estado, int jugador);
      double Poda_AlfaBeta(const Environment & matriz, int player, int prof, int lim, 
    Environment::ActionType & acction, double alfa, double bet, bool minmax);
      int FormaLineaHoriz(const Environment &matriz, int i, int j, char valor);
      int FormaLineaVert(const Environment &matriz, int i, int j, char valor);
      int FormaLineaDiagIzq(const Environment &matriz, int i, int j, char valor);
      int FormaLineaDiagDer(const Environment &matriz, int i, int j, char valor);
    private:
      int jugador_;
      Environment actual_;
};
#endif
