#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include "usuario.h"

class db_manager : public usuario
{
private:
	string sueldo;
public:
	string getSueldo();
	void setSueldo(string);

	string getUser();
	void setUser(string);
	void setCorreo(string);
	string getCorreo();
	void setPass(string);
	string getPass();
	db_manager();
	~db_manager();
	
};


#endif