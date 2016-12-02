#ifndef DB_ADMNIISTRADOR
#define DB_ADMNIISTRADOR
#include "usuario.h"

class db_administrador : public usuario
{
protected:
	string fecha_entrada;
public:
	string getFecha();
	void setFecha(string);
	string getUser();
	void setUser(string);
	void setCorreo(string);
	void setPass(char*);
	char* getPass();

	db_administrador();
	~db_administrador();
	
};


#endif