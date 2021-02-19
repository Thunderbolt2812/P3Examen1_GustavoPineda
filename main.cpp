#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Equipo.hpp"
#include "Liga.hpp"
#include "Partido.hpp"
#include "PuntosPorEquipo.hpp"
#include "TablaPosiciones.hpp"
int main(int argc, char** argv) {
	srand (time(NULL));
	Liga* L = new Liga();
	TablaPosiciones* TP = new TablaPosiciones();
	L->setNombre("Liga Borrachos");
	int opcion1 = 0;
	while(opcion1!=5){
		cout << "Bem Vindo" << endl;
		cout<< "Ingrese una opcion"<<endl;
		cout<<"1) Mantenimiento"<<endl;
		cout<<"2) Generar Jornada"<<endl;
		cout<<"3) Simular Partidos"<<endl;
		cout<<"4) Imprimir Tabla de Posiciones por Jornada"<<endl;
		cout<<"5) Salir Corriendo"<<endl;
		cout << "Opcion: ";
    	cin >> opcion1;
    	switch(opcion1){
    		case 1:{
    			int opcion2 = 0;
    			while(opcion2!=5){
    				cout<< "Ingrese una opcion"<<endl;
					cout<<"1) Agregar Equipo"<<endl;
					cout<<"2) Modificar un Equipo"<<endl;
					cout<<"3) Eliminar un Equipo"<<endl;
					cout<<"4) Listar Equipos"<<endl;
					cout<<"5) Regresar al Menu anterior"<<endl;
					cout<<"Opcion: ";
					cin>>opcion2;
					cout<<endl;
					switch(opcion2){
						case 1:{
							int skill = 0+(rand()%101);
							string nombre;
							cout<<"Ingrese el nombre del equipo: "<<endl;
							cin>>nombre;
							if(!L->getEquipos().empty()){
								for(int i = 0;i<L->getEquipos().size();i++){
									
								}
							}
							L->agregarEquipo(new Equipo(nombre,skill));
							TP->agregarPuntosPorEquipo(new PuntosPorEquipo(new Equipo(nombre,skill),0,0,0,0,0));
							cout<<"Equipo agreado exitosamente";
							cout<<endl;
							cout<<endl;
							break;
						}
						case 2:{
							int pos;
							for(int i = 0;i<L->getEquipos().size();i++){
								Equipo* temp = L->getEquipos().at(i);
								cout<<(i+1)<<" "<<temp->getNombre()<<" "<<temp->getSkill();
								cout<<endl;
							}
							cout<<"Ingrese la posicion del equipo que desea modificar: ";
							cin>>pos;
							Equipo* mod = L->getEquipos().at(pos-1);
							int opcion3=0;
							while(opcion3!=3){
								cout<<"Ingrese una opcion"<<endl;
								cout<<"1) Modificar Nombre"<<endl;
								cout<<"2) Modificar Skill"<<endl;
								cout<<"3) Volver al Menu anterior"<<endl;
								cout<<"Opcion: ";
								cin>>opcion3;
								switch(opcion3){
									case 1:{
										string nuevo_nombre;
										cout<<"Ingrese el nuevo nombre del equipo: ";
										cin>>nuevo_nombre;
										mod->setNombre(nuevo_nombre);
										cout<<"Nombre modificado exitosamente";
										cout<<endl;
										cout<<endl;
										break;
									}
									case 2:{
										int nuevo_skill = 0+(rand()%101);
										mod->setSkill(nuevo_skill);
										cout<<"Skill modificado exitosamente";
										cout<<endl;
										cout<<endl;
										break;
									}
								}
							}
							break;
						}
						case 3:{
							int pos;
							for(int i = 0;i<L->getEquipos().size();i++){
								Equipo* temp = L->getEquipos().at(i);
								cout<<(i+1)<<" "<<temp->getNombre()<<" "<<temp->getSkill();
								cout<<endl;
							}
							cout<<"Ingrese la posicion del equipo que desea eliminar: ";
							cin>>pos;
							L->eliminarEquipo(pos-1);
							break;
						}
						case 4:{
							for(int i = 0;i<L->getEquipos().size();i++){
								Equipo* temp = L->getEquipos().at(i);
								cout<<(i+1)<<" "<<"Equipo: "<<temp->getNombre()<<endl<<"  Skill: "<<temp->getSkill();
								cout<<endl;
								cout<<endl;
							}
							cout<<endl;
							break;
						}
					}
				}
				break;
			}
			case 2:{
				bool eliminar = false;
				vector<Equipo*>temporal;
				for(int i =0;i<L->getEquipos().size();i++){
					temporal.push_back(L->getEquipos().at(i));
				}
				if(temporal.size()%2==0){
					while(!temporal.empty()){
						int pos1=0+(rand()%temporal.size()),pos2=0+(rand()%temporal.size());
						while(pos1==pos2){
							pos1=0+(rand()%temporal.size());
							pos2=0+(rand()%temporal.size());
						}
						bool yaJugaron = false;
						if(!L->getJornada().empty()){
							for(int i =0;i<L->getJornada().size();i++){
									Partido* p = L->getJornada().at(i);
									Equipo* e1=p->getEquipo_1();
									string nombre1 = e1->getNombre();
									Equipo* e2=p->getEquipo_2();
									string nombre2 = e2->getNombre();
									Equipo* e3=temporal.at(pos1);
									string nombre3 = e3->getNombre();
									Equipo* e4=temporal.at(pos2);
									string nombre4 = e4->getNombre();
									if(nombre1==nombre3&&nombre2==nombre4||nombre1==nombre4&&nombre2==nombre3){
										cout<<nombre1<<" y "<<nombre2<<" ya jugaron un partido";
										bool yaJugaron= true;
										cout<<endl;
									}
							}
						}
						if(!yaJugaron){
							L->agregarJornada(new Partido(temporal[pos1],temporal[pos2],0,0,false));
							if(pos1<pos2){
								temporal.erase(temporal.begin()+pos2);
								temporal.erase(temporal.begin()+pos1);
							}else if(pos1>pos2){
								temporal.erase(temporal.begin()+pos1);
								temporal.erase(temporal.begin()+pos2);
							}
						}
					}
					for(int i=0;i<L->getJornada().size();i++){
							Partido* p = L->getJornada().at(i);
							Equipo* e1v = p->getEquipo_1();
							Equipo* e2v = p->getEquipo_2();
							cout<<e1v->getNombre()<<" vs "<<e2v->getNombre();
							cout<<endl;
					}
					cout<<endl;
					eliminar = true;
				}else{
					cout<<"Jornada no creada. El numero de equipos es Impar, Agregue almenos un equipo mas.";
					cout<<endl;
				}
				if(eliminar){
					for(int i = 0;i<temporal.size();i++){
					delete temporal.at(i);
					}
				}
				break;
			}
			case 3:{
				PuntosPorEquipo* aux;
				PuntosPorEquipo* aux2;
				for(int i = 0;i<L->getJornada().size();i++){
					Partido* P = L->getJornada().at(i);
					Equipo* e1 = P->getEquipo_1();
					string nombre1 = e1->getNombre();
					Equipo* e2 = P->getEquipo_2();
					string nombre2 = e2->getNombre();
					int skillTotale1 = e1->getSkill()+(-15+(rand()%16));
					int skillTotale2 = e2->getSkill()+(-15+(rand()%16));
					int golese1;
					int golese2;
					if(skillTotale1<=0){
						golese1 = 0;
					}else{
						golese1 = skillTotale1/10;
					}
					if(skillTotale2<=0){
						golese2 = 0;
					}else{
						golese2 = skillTotale2/10;
					}
					for(int i = 0;i<TP->getPuntos().size();i++){
						PuntosPorEquipo* equipo1 = TP->getPuntos().at(i);
						Equipo* etemp = equipo1->getEquipo();
						string nombreetemp = etemp->getNombre();
						if(nombreetemp==nombre1){
							aux = equipo1;
						}
					}
					for(int i = 0;i<TP->getPuntos().size();i++){
						PuntosPorEquipo* equipo2 = TP->getPuntos().at(i);
						Equipo* etemp2 = equipo2->getEquipo();
						string nombreetemp2 = etemp2->getNombre();
						if(nombreetemp2==nombre2){
							aux2 = equipo2;
						}
					}
					if(skillTotale1>skillTotale2){
						int partg = aux->getPartidos_Ganados();
						aux->setPartidos_Ganados(partg+1);
						int partp = aux2->getPartidos_Perdidos();
						aux2->setPartidos_Perdidos(partp+1);
						cout<<nombre1<<" vs "<<nombre2<<endl;
						cout<<"Ganador: "<<nombre1<<endl;
						cout<<"Goles a Favor: "<<golese1<<endl;
						cout<<"Goles en Contra: "<<golese2<<endl;
						cout<<endl;
						cout<<"Perdedor: "<<nombre2<<endl;
						cout<<"Goles a Favor: "<<golese2<<endl;
						cout<<"Goles en Contra: "<<golese1<<endl;
						cout<<endl;
					}
					if(skillTotale1<skillTotale2){
						int partg = aux2->getPartidos_Ganados();
						aux2->setPartidos_Ganados(partg+1);
						int partp = aux->getPartidos_Perdidos();
						aux->setPartidos_Perdidos(partp+1);
						cout<<nombre1<<" vs "<<nombre2<<endl;
						cout<<"Ganador: "<<nombre1<<endl;
						cout<<"Goles a Favor: "<<golese1<<endl;
						cout<<"Goles en Contra: "<<golese2<<endl;
						cout<<endl;
						cout<<"Perdedor: "<<nombre2<<endl;
						cout<<"Goles a Favor: "<<golese2<<endl;
						cout<<"Goles en Contra: "<<golese1<<endl;
						cout<<endl;
					}
					if(skillTotale1==skillTotale2){
						int parte1 = aux->getPartidos_Empatados();
						aux->setPartidos_Ganados(parte1+1);
						int parte2 = aux2->getPartidos_Empatados();
						aux2->setPartidos_Empatados(parte2+1);
						cout<<nombre1<<" vs "<<nombre2<<endl;
						cout<<"Empate"<<endl;
						cout<<nombre1<<endl;
						cout<<"Goles a Favor: "<<golese1<<endl;
						cout<<"Goles en Contra: "<<golese2<<endl;
						cout<<endl;
						cout<<nombre2<<endl;
						cout<<"Goles a Favor: "<<golese2<<endl;
						cout<<"Goles en Contra: "<<golese1<<endl;
						cout<<endl;
					}	
				}
				break;
			}
			case 4:{
				TP->mostrarTablaPosiciones();
				break;
			}
		}
	}
	L->~Liga();
	TP->~TablaPosiciones();	
	return 0;
}