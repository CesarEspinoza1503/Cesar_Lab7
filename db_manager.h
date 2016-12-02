#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include "usuario.h"

class db_manager : public usuario
{
private:
	double sueldo;
public:
	double getSueldo();
	void setSueldo();

	string getUser();
	void setUser(string);
	void setCorreo(string);
	void setPass(char*);
	char* getPass();
	db_manager();
	~db_manager();
	
};


#endif