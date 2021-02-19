#include "Equipo.hpp"

Equipo::Equipo(){
}

Equipo::Equipo(string e_nombre,int e_skill){
  this->nombre = e_nombre;
  this->skill = e_skill;
}

Equipo::~Equipo(){
}

string Equipo::getNombre(){
  return this->nombre;
}

void Equipo::setNombre(string e_nombre){
  this->nombre = e_nombre;
}

int Equipo::getSkill(){
  return this->skill;
}

void Equipo::setSkill(int e_skill){
  this->skill = e_skill;
}

