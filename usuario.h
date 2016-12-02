#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class usuario
{
protected:
	string user_name;
    string correo;
    char* password;

public:
	virtual string getUser();
	virtual void setUser(string);
	virtual void setCorreo(string);
	virtual void setPass(char*);
	virtual char* getPass();
	usuario();
	~usuario();
	
};


#endif