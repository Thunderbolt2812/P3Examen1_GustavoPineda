#ifndef TABLAPOSICIONES_H
#define TABLAPOSICIONES_H
#include<string>
#include<iostream>
#include "PuntosPorEquipo.hpp"
using namespace std;
class TablaPosiciones {
  private:
	  vector<PuntosPorEquipo*> tabla;
  public:
	  TablaPosiciones();  
	  TablaPosiciones(PuntosPorEquipo*);
	  ~TablaPosiciones();
	  PuntosPorEquipo getTabla();
};
#endif