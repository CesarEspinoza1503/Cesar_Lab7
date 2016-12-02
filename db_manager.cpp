#include "db_manager.h"

db_manager::db_manager(){

}

db_manager::~db_manager(){

}

void db_manager::setUser(string pUser){
	user_name = pUser;
}

string db_manager::getUser(){
	return user_name;
}

void db_manager::setCorreo(string pCorreo){
	correo = pCorreo;
}

void db_manager::setPass(string pPass){
	password = pPass;
}
void db_manager::setSueldo(string pSueldo){
	sueldo = pSueldo;
}

string db_manager::getSueldo(){
	return sueldo;
}

string db_manager::getPass(){
	return password;
}

string db_manager::getCorreo(){
	return correo;
}