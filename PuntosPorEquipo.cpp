#include "PuntosPorEquipo.hpp"

PuntosPorEquipo::PuntosPorEquipo(){
}  
PuntosPorEquipo::PuntosPorEquipo(Equipo* ppe_equipo,int ppe_goles_favor,int ppe_goles_contra,int ppe_partidos_ganados,int ppe_partidos_perdidos,int ppe_partidos_empatados){
	this->equipo=ppe_equipo;
	this->goles_favor = ppe_goles_favor;
	this->goles_contra = ppe_goles_contra;
	this->partidos_ganados = ppe_partidos_ganados;
	this->partidos_perdidos = ppe_partidos_perdidos;
	this->partidos_empatados = ppe_partidos_empatados;
}
PuntosPorEquipo::~PuntosPorEquipo(){
}
Equipo* PuntosPorEquipo::getEquipo(){
	return this->equipo;
}
int PuntosPorEquipo::getGoles_Favor(){
	return this->goles_favor;
}
int PuntosPorEquipo::getGoles_Contra(){
	return this->goles_contra;
}
int PuntosPorEquipo::getPartidos_Ganados(){
	return this->partidos_ganados;
}
int PuntosPorEquipo::getPartidos_Perdidos(){
	return this->partidos_perdidos;
}
int PuntosPorEquipo::getPartidos_Empatados(){
	return this->partidos_empatados;
}
void PuntosPorEquipo::setEquipo(Equipo* ppe_equipo){
	this->equipo=ppe_equipo;
}
void PuntosPorEquipo::setGoles_Favor(int ppe_goles_favor){
	this->goles_favor=ppe_goles_favor;
}
void PuntosPorEquipo::setGoles_Contra(int ppe_goles_contra){
	this->goles_contra=ppe_goles_contra;
}
void PuntosPorEquipo::setPartidos_Ganados(int ppe_partidos_ganados){
	this->partidos_ganados=ppe_partidos_ganados;
}
void PuntosPorEquipo::setPartidos_Perdidos(int ppe_partidos_perdidos){
	this->partidos_perdidos=ppe_partidos_perdidos;
}
void PuntosPorEquipo::setPartidos_Empatados(int ppe_partidos_empatados){
	this->partidos_empatados=ppe_partidos_empatados;
}