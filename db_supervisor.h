#ifndef DB_SUPERVISOR_H
#define DB_SUPERVISOR_H

#include "usuario.h"

class db_supervisor : public usuario
{
private:
	int cont;
public:
	db_supervisor();
	~db_supervisor();
	int getCont();
	void setCont();

	string getUser();
	void setUser(string);
	void setCorreo(string);
	void setPass(char*);
	char* getPass();

};


#endif