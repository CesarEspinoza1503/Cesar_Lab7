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

	vector<usuario*> admins;
	vector<usuario*> interns;
	vector<usuario*> supervisors;
	vector<usuario*> managers;
	string user_n, pass, correo;
	int opt=1;
	string use;
	char* password;

	leerTxt("Administrador.txt", &admins);
	cout<<"TAMAÑO: "<<admins.size();
	admins.at(0)->getCorreo();
	do
	{
		cout<<"		LOG IN"<<endl<<"		---------------------"<<endl;
		cout<<"		Username: "<<endl;
		cin>> use;
		cout<<"		Password: "<<endl;
		cin >> password;
		if(admins.at(0)->getUser() == use && admins.at(0)->getPass() == password)
		{
			int admin_opt;

			do
			{
				cout<<"1)Agregar un Manager \n2)Agregar un Interno"
				<<"\n3)Agregar un Supervisor\n4)Eliminar un Manager"
				<<"\n5)Eliminar un Interno\n6)Eliminar un Supervisor"
				<<"\n7)Volver"<<endl;
				cin>> admin_opt;
				if (admin_opt == 1)
				{
					db_manager* manager = new db_manager();
					string sueldo;
					cout<<"		MANAGER"<<endl;
					cout<<"Ingrese Nombre de usuario: "<<endl;
					cin>>user_n;
					cout<<"Ingrese contraseña: "<<endl;
					cin>>pass;
					cout<<"Ingrese correo: "<<endl;
					cin>>correo;
					cout<<"Ingrese Sueldo del Manager: "<<endl;
					cin>>sueldo;
					manager->setUser(user_n);
					manager->setPass(pass);
					manager->setCorreo(correo);
					manager->setSueldo(sueldo);
				}
				if (admin_opt == 2)
				{

					string dias;
					cout<<"		INTERNO"<<endl;
					cout<<"Ingrese Nombre de usuario: "<<endl;
					cin>>user_n;
					cout<<"Ingrese contraseña: "<<endl;
					cin>>pass;
					cout<<"Ingrese correo: "<<endl;
					cin>>correo;
					cout<<"Ingrese Numero de dias que trabajara: "<<endl;
					cin>>dias;
				}
				if (admin_opt == 3)
				{

					string sueldo;
					cout<<"		SUPERVISOR"<<endl;
					cout<<"Ingrese Nombre de usuario: "<<endl;
					cin>>user_n;
					cout<<"Ingrese contraseña: "<<endl;
					cin>>pass;
					cout<<"Ingrese correo: "<<endl;
					cin>>correo;
				}
			} while (admin_opt!=7);
		}
		//db_administrador* adm = dynamic_cast<db_administrador*>()
		
		cout<<admins.at(0)->getCorreo()<<endl;

	} while (opt != 0);
	return 0;
}



void leerTxt(char* txt_name, vector<usuario*>* vec){
	string user, pass, correo, fecha;
	string line;
	ifstream archivo (txt_name);
	if (archivo.is_open())
	{
		if (txt_name == "Administrador.txt")
		{
			db_administrador* admin = new db_administrador();
			while( archivo >> user >> pass >> correo >> fecha)
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