#ifndef TABLAPOSICIONES_H
#define TABLAPOSICIONES_H
#include<string>
#include <vector>
#include<iostream>
#include "PuntosPorEquipo.hpp"
using namespace std;
class TablaPosiciones {
  private:
	  vector<PuntosPorEquipo*> puntos;
  public:
	  TablaPosiciones();  
	  TablaPosiciones(vector<PuntosPorEquipo*>);
	  ~TablaPosiciones();
	  vector<PuntosPorEquipo*> getPuntos();
	  void agregarPuntosPorEquipo (PuntosPorEquipo* ppe);
	  void mostrarTablaPosiciones ();
};
#endif