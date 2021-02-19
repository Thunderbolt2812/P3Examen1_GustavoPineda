#include "Partido.hpp"
Partido::Partido(){	
}  
Partido::Partido(Equipo* e_equipo_1,Equipo* e_equipo_2,int e_goles_e1,int e_goles_e2,bool e_jugado){
	this->equipo_1 = e_equipo_1;
	this->equipo_2 = e_equipo_2;
	this->goles_e1 = e_goles_e1;
	this->goles_e2 = e_goles_e2;
	this->jugado = e_jugado;
}
Partido::~Partido(){
}
Equipo* Partido::getEquipo_1(){
	return this->equipo_1;
}
Equipo* Partido::getEquipo_2(){
	return this->equipo_2;
}
int Partido::getGoles_1(){
	return this->goles_e1;
}
int Partido::getGoles_2(){
	return this->goles_e2;
}
bool Partido::getJugado(){
	return this->jugado;
}
void Partido::setEquipo_1(Equipo* e_equipo_1){
	this->equipo_1 = e_equipo_1;
}
void Partido::setEquipo_2(Equipo* e_equipo_2){
	this->equipo_2=e_equipo_2;
}
void Partido::setGoles_1(int e_goles_e1){
	this->goles_e1=e_goles_e1;
}
void Partido::setGoles_2(int e_goles_e2){
	this->goles_e2=e_goles_e2;
}
void Partido::setJugado(bool e_jugado){
	this->jugado=e_jugado;
}