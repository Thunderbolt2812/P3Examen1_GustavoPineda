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
	for(int i = 0; i<equipos.size();i++){
		delete equipos.at(i);
	}
	for(int i = 0; i<jornada.size();i++){
		delete jornada.at(i);
	}
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
void Liga::agregarEquipo(Equipo* _equipo){
	equipos.push_back(_equipo);
}
void Liga::agregarJornada(Partido* _partido){
	jornada.push_back(_partido);
}
void Liga::eliminarEquipo(int pos){
	for(int i = 0;i<equipos.size();i++){
		if(i==pos){
			equipos.erase(equipos.begin()+pos);
			delete equipos.at(i);
		}
	}
}