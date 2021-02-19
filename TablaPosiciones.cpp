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
	int tamano=puntos.size();
	int orden [tamano] ;
	vector<PuntosPorEquipo*> orden2;
	for(int i = 0;i<puntos.size();i++){
		orden2.push_back(puntos.at(i));
	}
	cout<<endl;
	for(int i = 0;i<orden2.size();i++){
		for(int j = 0;j<orden2.size();j++){
			PuntosPorEquipo* ppe = orden2.at(i);
			int parg = ppe->getPartidos_Ganados();
			int pare = ppe->getPartidos_Empatados();
			int totali= (parg*3)+pare;
			PuntosPorEquipo* ppe2 = orden2.at(j);
			int parg2 = ppe2->getPartidos_Ganados();
			int pare2 = ppe2->getPartidos_Empatados();
			int totalj= (parg2*3)+pare2;
			if(totali>totalj){
				PuntosPorEquipo* temp = ppe;
				ppe = ppe2;
				ppe = temp;
			}
		}
	}
	for(int i =0;i<orden2.size();i++){
		PuntosPorEquipo* aux = orden2.at(i);
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