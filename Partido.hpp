#ifndef PARTIDO_H
#define PARTIDO_H
#include<string>
#include<iostream>
#include "Equipo.hpp"
using namespace std;
class Partido {
  private:
	  Equipo* equipo_1;
	  Equipo* equipo_2;
	  int goles_e1;
	  int goles_e2;
	  bool jugado;
  public:
	  Partido();  
	  Partido(Equipo*,Equipo*,int,int,bool);
	  ~Partido();
	  Equipo* getEquipo_1();
	  Equipo* getEquipo_2();
	  int getGoles_1();
	  int getGoles_2();
	  bool getJugado();
	  void setEquipo_1(Equipo*);
	  void setEquipo_2(Equipo*);
	  void setGoles_1(int);
	  void setGoles_2(int);
	  void setJugado(bool);
};
#endif