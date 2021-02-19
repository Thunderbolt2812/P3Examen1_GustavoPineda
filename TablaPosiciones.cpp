#include "TablaPosiciones.hpp"
#include "PuntosPorEquipo.hpp"
TablaPosiciones::TablaPosiciones(){
}  
TablaPosiciones::TablaPosiciones(vector<PuntosPorEquipo*> tp_puntos){
	this->puntos = tp_puntos;
}
TablaPosiciones::~TablaPosiciones(){
	for(int i = 0; i<puntos.size();i++){
		delete puntos.at(i);
	}
}
vector<PuntosPorEquipo*> TablaPosiciones::getPuntos(){
	return this->puntos;
}
void TablaPosiciones::agregarPuntosPorEquipo(PuntosPorEquipo* ppe){
	puntos.push_back(ppe);
}

void TablaPosiciones::mostrarTablaPosiciones(){
	vector<PuntosPorEquipo*> ayudante;
	for(int i =0;i<puntos.size();i++){
			PuntosPorEquipo* aux = puntos.at(i);
			Equipo* aux2 = aux->getEquipo();
			cout<<"Equipo: "<<aux2->getNombre()<<endl;
			cout<<"Partidos Ganados: "<<aux->getPartidos_Ganados()<<endl;
			cout<<"Partidos Perdidos: "<<aux->getPartidos_Perdidos()<<endl;
			cout<<"Partidos Empatados: "<<aux->getPartidos_Empatados()<<endl;
			cout<<"Goles a Favor: "<<aux->getGoles_Favor()<<endl;
			cout<<"Goles en Contra: "<<aux->getGoles_Contra()<<endl;
			cout<<"Total de Puntos: "<<(aux->getPartidos_Ganados()*3)+aux->getPartidos_Empatados()<<endl;
			cout<<endl;
		}
	}
}