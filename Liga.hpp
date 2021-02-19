#ifndef LIGA_H
#define LIGA_H
#include<vector>
#include<string>
#include<iostream>
#include "Equipo.hpp"
#include "Partido.hpp"
#include "TablaPosiciones.hpp"
using namespace std;
class Liga {
  private:
	  string nombre;
	  vector<Equipo*> equipos;
	  vector<Partido*> jornada;
	  TablaPosiciones* tabla_p;
  public:
	  Liga();  
	  Liga(string,vector<Equipo*>,vector<Partido*>,TablaPosiciones*);
	  ~Liga();
	  string getNombre();
	  vector<Equipo*> getEquipos();
	  vector<Partido*> getJornada();
	  TablaPosiciones* getTabla_P();
	  void setNombre(string);
	  void setTabla_P(TablaPosiciones*);
	  void agregarEquipo(Equipo*);
	  void agregarJornada(Partido*);
	  void eliminarEquipo(int);
};
#endif