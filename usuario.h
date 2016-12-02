#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
using namespace std;

class usuario
{
protected:
	string user_name;
    string correo;
    string password;

public:
	virtual string getUser();
	virtual void setUser(string);
	virtual string getCorreo();
	
	virtual void setCorreo(string);
	virtual void setPass(string);
	virtual string getPass();
	usuario();
	~usuario();
	
};


#endif