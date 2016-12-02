#ifndef DB_SUPERVISOR_H
#define DB_SUPERVISOR_H

#include "usuario.h"

class db_supervisor : public usuario
{
private:
	int cont;
	string s_cont;
public:
	db_supervisor();
	~db_supervisor();
	string getSCont();

	void setCont();

	string getUser();
	void setUser(string);
	void setCorreo(string);
	string getCorreo();
	void setPass(string);
	string getPass();

};


#endif