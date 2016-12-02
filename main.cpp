#include "db_supervisor.h"
#include "db_intern.h"
#include "db_manager.h"
#include "db_administrador.h"
#include "usuario.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	usuario* USER = new usuario();
	int opt;
	string user;
	char* password;
	do
	{
		cout<<"		LOG IN"<<endl<<"		---------------------";
		cout<<"	Username: ";
		cin>> user;
		cin >> password;

	} while (opt != 9);
	return 0;
}

