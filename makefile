main: main.o db_administrador.o db_supervisor.o db_intern.o db_manager.o usuario.o
	g++ main.o db_administrador.o db_supervisor.o db_intern.o db_manager.o usuario.o -o main


main.o: main.cpp db_administrador.h db_supervisor.h db_intern.h db_manager.h usuario.h
	g++ -c main.cpp

usuario.o: usuario.h usuario.cpp
	g++ -c usuario.cpp

db_administrador.o: usuario.h db_administrador.cpp db_administrador.h
	g++ -c db_administrador.cpp

db_supervisor.o: db_supervisor.h db_supervisor.cpp usuario.h
	g++ -c db_supervisor.cpp

db_intern.o: db_intern.h db_intern.cpp usuario.h
	g++ -c db_intern.cpp

db_manager.o: db_manager.h db_manager.cpp usuario.h
	g++ -c db_manager.cpp

clean:
	rm -f *.o main
