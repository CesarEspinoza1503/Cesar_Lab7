#include "db_supervisor.h"


db_supervisor::db_supervisor(){

}

db_supervisor::~db_supervisor(){

}


void db_supervisor::setUser(string pUser){
	user_name = pUser;
}

string db_supervisor::getUser(){
	return user_name;
}

void db_supervisor::setCorreo(string pCorreo){
	correo = pCorreo;
}

void db_supervisor::setPass(char* pPass){
	password = pPass;
}
void db_supervisor::setSueldo(double pSueldo){
	sueldo = pSueldo;
}

double db_supervisor::getSueldo(){
	return sueldo;
}

int db_supervisor::getCont(){
	return cont;
}

void db_supervisor::setCont(){
	cont ++;
}