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

	vector<usuario*> admins;
	vector<usuario*> interns;
	vector<usuario*> supervisors;
	vector<usuario*> managers;
	string user_n, pass, correo;
	int opt=1;
	string use;
	char* password;

	leerTxt("Administrador.txt", &admins);
	cout<<admins.at(0)->getUser()<<endl<< admins.at(0)->getPass()<< endl;
	do
	{
		cout<<"		LOG IN"<<endl<<"		---------------------"<<endl;
		cout<<"		Username: "<<endl;
		cin >> use;
		cout<<"		Password: "<<endl;
		cin >> password;

		if((admins.at(0)->getUser() == use) && (admins.at(0)->getPass() == password))
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
					managers.push_back(manager);
				}
				if (admin_opt == 2)
				{
					db_intern* interno = new db_intern();
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
					interno->setUser(user_n);
					interno->setCorreo(correo);
					interno->setPass(pass);
					interno->setDias(dias);

					interns.push_back(interno);
				}
				if (admin_opt == 3)
				{
					db_supervisor* supervi = new db_supervisor();
					string sueldo;
					cout<<"		SUPERVISOR"<<endl;
					cout<<"Ingrese Nombre de usuario: "<<endl;
					cin>>user_n;
					cout<<"Ingrese contraseña: "<<endl;
					cin>>pass;
					cout<<"Ingrese correo: "<<endl;
					cin>>correo;
					supervi->setUser(user_n);
					supervi->setPass(pass);
					supervi->setCorreo(correo);
				}
				if (admin_opt == 4)
				{
					for (int i = 0; i < managers.size(); ++i)
					{
						cout<<managers.at(i)->getUser()<<endl<<managers.at(i)->getCorreo()<<endl;
					}
					cout<<"Eliminar: "<<endl;
					int borrar;
					cin>>borrar;
					managers.erase(managers.begin() + borrar);
				}
				if (admin_opt == 5)
				{
					for (int i = 0; i < interns.size(); ++i)
					{
						cout<<interns.at(i)->getUser()<<endl<<interns.at(i)->getCorreo()<<endl;
					}
					cout<<"Eliminar: "<<endl;
					int borrar;
					cin>>borrar;
					interns.erase(interns.begin() + borrar);
				}
				if (admin_opt == 6)
				{
					for (int i = 0; i < supervisors.size(); ++i)
					{
						cout<<supervisors.at(i)->getUser()<<endl<<supervisors.at(i)->getCorreo()<<endl;
					}
					cout<<"Eliminar: "<<endl;
					int borrar;
					cin>>borrar;
					supervisors.erase(supervisors.begin() + borrar);
				}
			} while (admin_opt!=7);

		
		}
		if (interns.size() != 0)
		{
			for (int i = 0; i < interns.size(); ++i)
			{
				if (interns.at(i)->getUser() == use && interns.at(i)->getPass() == password)
				{
					int opcion;
					do
					{
						cout<<"1)Ver Internos\n2)Eliminar Internos\n3)Volver"<<endl;
						cin>>opcion;
						if (opcion==1)
						{
							for (int i = 0; i < interns.size(); ++i)
							{
								cout<<interns.at(i)->getUser()<<endl<<interns.at(i)->getCorreo()<<endl;
								//cout<<interns.at(i)->getDias()<<endl;
							}
						}
						if (opcion==2)
						{
							for (int i = 0; i < interns.size(); ++i)
							{
								cout<<i<<"). "<<interns.at(i)->getUser()<<endl;
							}
							int borrar;
							cout<<"Borrar interno en: "<<endl;
							cin>>borrar;
							interns.erase(interns.begin() + borrar);
							cout<<"Interno borrado"<<endl;
						}
					} while (opcion != 3);
				}
			}
		}
		if (supervisors.size() != 0)
		{
			for (int i = 0; i < supervisors.size(); ++i)
			{
				if (supervisors.at(i)->getUser() == use && supervisors.at(i)->getPass() == password)
				{
					db_supervisor* super = dynamic_cast<db_supervisor*>(supervisors.at(i));
					super->setCont();
					cout<<"Admin"<<endl;
					for (int i = 0; i < admins.size(); ++i)
					{
						cout<<admins.at(i)->getUser()<<endl<<admins.at(i)->getCorreo()<<endl;
					}
					cout<<"Supervisores"<<endl;
					for (int i = 0; i < supervisors.size(); ++i)
					{
						db_supervisor* sp = dynamic_cast<db_supervisor*>(supervisors.at(i));
						cout<<supervisors.at(i)->getUser()<<endl<<supervisors.at(i)->getCorreo()<<endl;
						cout<<sp->getSCont()<<endl;
					}
					cout<<"Internos"<<endl;
					for (int i = 0; i < interns.size(); ++i)
					{
						db_intern* inter = dynamic_cast<db_intern*>(interns.at(i));
						cout<<interns.at(i)->getUser()<<endl<<interns.at(i)->getCorreo()<<endl;
						cout<<inter->getDias()<<endl;
					}
				}
			}
		}
		if (managers.size() != 0)
		{
			for (int i = 0; i < managers.size(); ++i)
			{
				if (managers.at(i)->getUser() == use && managers.at(i)->getPass() == password)
				{
					int opc;
					cout<<"1)Agregar un Manager \n2)Agregar un Interno"
					<<"\n3)Agregar un Supervisor\n4)Eliminar un Manager"
					<<"\n5)Eliminar un Interno\n6)Eliminar un Supervisor"
					<<"\n7)Volver"<<endl;
					cin>> opc;
					if (opc == 1)
					{
						db_intern* interno = new db_intern();
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
						interno->setUser(user_n);
						interno->setCorreo(correo);
						interno->setPass(pass);
						interno->setDias(dias);

						interns.push_back(interno);
					}
					if (opc == 2)
					{
						db_supervisor* supervi = new db_supervisor();
						string sueldo;
						cout<<"		SUPERVISOR"<<endl;
						cout<<"Ingrese Nombre de usuario: "<<endl;
						cin>>user_n;
						cout<<"Ingrese contraseña: "<<endl;
						cin>>pass;
						cout<<"Ingrese correo: "<<endl;
						cin>>correo;
						supervi->setUser(user_n);
						supervi->setPass(pass);
						supervi->setCorreo(correo);
					}
					if (opc == 3)
					{
						for (int i = 0; i < interns.size(); ++i)
						{
							cout<<interns.at(i)->getUser()<<endl<<interns.at(i)->getCorreo()<<endl;
						}
						cout<<"Eliminar: "<<endl;
						int borrar;
						cin>>borrar;
						interns.erase(interns.begin() + borrar);
					}
					if (opc == 4)
					{
						for (int i = 0; i < supervisors.size(); ++i)
						{
							cout<<supervisors.at(i)->getUser()<<endl<<supervisors.at(i)->getCorreo()<<endl;
						}
						cout<<"Eliminar: "<<endl;
						int borrar;
						cin>>borrar;
						supervisors.erase(supervisors.begin() + borrar);
					}
				}
			}
		}
		//db_administrador* adm = dynamic_cast<db_administrador*>()
		
		//cout<<admins.at(0)->getCorreo()<<endl;

	} while (opt != 0);
	ofstream archive_exp;
	archive_exp.open("Manager.txt");

	if (managers.size() != 0)
	{
		for (int i = 0; i < managers.size(); ++i)
		{
			db_manager* mana = dynamic_cast<db_manager*>(managers.at(i));
			archive_exp << managers.at(i)->getUser() <<endl;
			archive_exp << managers.at(i)->getCorreo() <<endl;
			archive_exp << managers.at(i)->getPass() <<endl;
			archive_exp << mana->getSueldo() <<endl;
		}
	}
	archive_exp.close();

	archive_exp.open("Supervisor.txt");
	if (supervisors.size() != 0)
	{
		for (int i = 0; i < supervisors.size(); ++i)
		{
			db_supervisor* super = dynamic_cast<db_supervisor*>(supervisors.at(i));
			archive_exp << supervisors.at(i)->getUser()<<endl;
			archive_exp << supervisors.at(i)->getCorreo()<<endl;
			archive_exp << supervisors.at(i)->getPass()<<endl;
			archive_exp << super->getSCont() <<endl;
		}
	}
	archive_exp.close();


	archive_exp.open("Internos.txt");
	if (interns.size() != 0)
	{
		for (int i = 0; i < interns.size(); ++i)
		{
			db_intern* interno = dynamic_cast<db_intern*>(interns.at(i));
			archive_exp << interns.at(i)->getUser()<<endl;
			archive_exp << interns.at(i)->getCorreo()<<endl;
			archive_exp << interns.at(i)->getPass()<<endl;
			archive_exp << interno->getDias() <<endl;
		}
	}
	archive_exp.close();

	return 0;
}

void leerTxt(char* txt_name, vector<usuario*>* vec){
	string user, pass, correo, fecha;
	string line;
	ifstream archivo;
	archivo.open(txt_name);
	if (archivo.is_open())
	{
		if (txt_name == "Administrador.txt")
		{
			db_administrador* admin = new db_administrador();
			for (int i = 0; i < 1; ++i)
			{
				
			
				getline(archivo,user);
				getline(archivo,pass);
				getline(archivo,correo);
				getline(archivo,fecha);
				//cout<<"Imprimir en metodo"<<endl<<user<<endl<<pass<<endl<<correo<<endl<<fecha<<endl<<"YA";
				admin->setUser(user);
				admin->setPass(pass);
				admin->setCorreo(correo);
				admin->setFecha(fecha);
				vec->push_back(admin);
				//cout<<vec->at(0)->getUser();
			}
		}
		
		archivo.close();

	}else{
		cout<< "El archivo no se pudo abrir.";
	}
}
