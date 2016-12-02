#include "usuario.h"

usuario::usuario(){
}

usuario::~usuario(){
}

void usuario::setUser(string pUser){
	user_name = pUser;
}

string usuario::getUser(){
	return user_name;
}

void usuario::setCorreo(string pCorreo){
	correo = pCorreo;
}

void usuario::setPass(string pPass){
	password = pPass;
}

string usuario::getPass(){
	return password;
}

string usuario::getCorreo(){
	return correo;
}