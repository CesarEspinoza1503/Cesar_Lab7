#include "db_supervisor.h"


db_supervisor::db_supervisor(){
	cont = 0;
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

void db_supervisor::setPass(string pPass){
	password = pPass;
}


string db_supervisor::getSCont(){
	s_cont = cont + "";
	return s_cont;
}

void db_supervisor::setCont(){
	cont ++;
}

string db_supervisor::getPass(){
	return password;
}
string db_supervisor::getCorreo(){
	return correo;
}