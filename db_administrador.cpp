#include "db_administrador.h"

db_administrador::db_administrador(){

}

db_administrador::~db_administrador(){
	
}

void db_administrador::setUser(string pUser){
	user_name = pUser;
}

string db_administrador::getUser(){
	return user_name;
}

void db_administrador::setCorreo(string pCorreo){
	correo = pCorreo;
}

void db_administrador::setPass(char* pPass){
	password = pPass;
}

string db_administrador::getFecha(){
	return fecha_entrada;
}

void db_administrador::setFecha(string pFecha){
	fecha_entrada = pFecha;
}

char* db_administrador::getPass(){
	return password;
}