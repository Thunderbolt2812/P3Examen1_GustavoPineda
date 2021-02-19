#include "Liga.hpp"

Liga::Liga(){
}

Liga::Liga(string l_nombre,vector<Equipo*> l_equipos,vector<Partido*> l_jornada,TablaPosiciones* l_tabla_p){
  this->nombre = l_nombre;
  this->equipos = l_equipos;
  this->jornada = l_jornada;
  this->tabla_p = l_tabla_p;
}

Liga::~Liga(){
}

string Liga::getNombre(){
  return this->nombre;
}

void Liga::setNombre(string l_nombre){
  this->nombre = l_nombre;
}

vector<Equipo*> Liga::getEquipos(){
  return this->equipos;
}

vector<Partido*> Liga::getJornada(){
  return this->jornada;
}

TablaPosiciones* Liga::getTabla_P(){
  return this->tabla_p;
}

void Liga::setTabla_P(TablaPosiciones* l_tabla_p){
  this->tabla_p = l_tabla_p;
}