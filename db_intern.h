#ifndef DB_INTERN_H
#define DB_INTERN_H
#include "usuario.h"


class db_intern : public usuario
{
private:
	string dias;

public:
	string getDias();
	void setDias(string);

	string getUser();
	void setUser(string);
	void setCorreo(string);
	string getCorreo();
	void setPass(string);
	string getPass();

	db_intern();
	~db_intern();
	
};

#endif