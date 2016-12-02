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

void db_manager::setPass(char* pPass){
	password = pPass;
}
void db_manager::setSueldo(double pSueldo){
	sueldo = pSueldo;
}

double db_manager::getSueldo(){
	return sueldo;
}

char* db_manager::getPass(){
	return password;
}
