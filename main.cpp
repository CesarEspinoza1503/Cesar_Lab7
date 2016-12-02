#include "db_supervisor.h"
#include "db_intern.h"
#include "db_manager.h"
#include "db_administrador.h"
#include "usuario.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void leerTxt(char*, vector<usuario*>*);

int main(int argc, char const *argv[])
{
	ofstream archivo;
	
	vector<usuario*> admin;
	vector<usuario*> interns;
	vector<usuario*> supervisors;
	vector<usuario*> managers;

	int opt=1;
	string user;
	char* password;
	do
	{
		cout<<"		LOG IN"<<endl<<"		---------------------"<<endl;
		cout<<"		Username: ";
		cin>> user;
		cout<<"		Password: "
		cin >> password;
		if(admin.at(0)->getUser() == user && admin.at(0)->getPass() == password)
		{

		}
		//db_administrador* adm = dynamic_cast<db_administrador*>()
		leerTxt("Administrador.txt", &admin);

		cout<<admin.at(0)->getCorreo()<<endl;

		opt=0;
	} while (opt != 0);
	return 0;
}



void leerTxt(char* txt_name, vector<usuario*>* vec){
	string a1 = " ";
	string user, pass, correo, fecha;
	string line;
	ifstream archivo (txt_name);
	if (archivo.is_open())
	{
		if (txt_name == "Administrador.txt")
		{
			db_administrador* admin = new db_administrador();
			while( archivo >> user >> pass >> correo >>fecha)
			{
				admin->setUser(user);
				admin->setPass(pass);
				admin->setCorreo(correo);
				admin->setFecha(fecha);
				vec->push_back(admin);
			}
		}
		
		archivo.close();
	}else{
		cout<< "El archivo no se pudo abrir.";
	}
}