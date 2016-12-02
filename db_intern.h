#ifndef DB_INTERN_H
#define DB_INTERN_H
#include "usuario.h"


class db_intern : public usuario
{
private:
	int dias;

public:
	int getDias();
	void setDias();

	string getUser();
	void setUser(string);
	void setCorreo(string);
	void setPass(char*);
	char* getPass();

	db_intern();
	~db_intern();
	
};

#endif