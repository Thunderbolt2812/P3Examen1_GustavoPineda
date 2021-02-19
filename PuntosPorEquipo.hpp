#ifndef PUNTOSPOREQUIPO_H
#define PUNTOSPOREQUIPO_H
#include<string>
#include<iostream>
#include "Equipo.hpp"
using namespace std;
class PuntosPorEquipo {
  private:
	  Equipo* equipo;
	  int goles_favor;
	  int goles_contra;
	  int partidos_ganados;
	  int partidos_perdidos;
	  int partidos_empatados;
  public:
	  PuntosPorEquipo();  
	  PuntosPorEquipo(Equipo*,int,int,int,int,int);
	  ~PuntosPorEquipo();
	  Equipo* getEquipo();
	  int getGoles_Favor();
	  int getGoles_Contra();
	  int getPartidos_Ganados();
	  int getPartidos_Perdidos();
	  int getPartidos_Empatados();
	  void setEquipo(Equipo*);
	  void setGoles_Favor(int);
	  void setGoles_Contra(int);
	  void setPartidos_Ganados(int);
	  void setPartidos_Perdidos(int);
	  void setPartidos_Empatados(int);
};
#endif