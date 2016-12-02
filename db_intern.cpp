#include "db_intern.h"
db_intern::db_intern(){
}

db_intern::~db_intern(){
}


void db_intern::setUser(string pUser){
	user_name = pUser;
}

string db_intern::getUser(){
	return user_name;
}

void db_intern::setCorreo(string pCorreo){
	correo = pCorreo;
}

void db_intern::setPass(string pPass){
	password = pPass;
}

string db_intern::getDias(){
	return dias;
}

void db_intern::setDias(string pDias){
	dias = pDias;
}


string db_intern::getPass(){
	return password;
}

string db_intern::getCorreo(){
	return correo;
}