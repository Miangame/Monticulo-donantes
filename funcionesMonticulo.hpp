/*! 
  \file funcionesMonticulo.hpp
  \brief Funcion para mostrar un menu del programa en el main()
  \author Miguel Angel Gavilan Merino
  \date 04/05/2016
*/


#ifndef FUNCIONESMONTICULO_HPP
#define FUNCIONESMONTICULO_HPP


// Funciones de cabecera
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include "monticuloDonantes.hpp"
#include "donante.hpp"
#include "macros.hpp"



// Facilita la entrada y salida
using namespace ed;
using std::stringstream;
using std::string;
using std::ios;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;


void mostrarMonticulo(MonticuloDonantes monticulo);


//! \name Funcion menu para el programa

/*! 
	\brief Muestra un menu en el main para hacer funcionar el programa
*/
void menu()
{	
	MonticuloDonantes monticulo;
	Donante d;
	string nombreFich;
	int i, opc, num;
	
	do
	{
		BORRAR;
		LUGAR(5, 10);
		cout << "\e[34;1m-----Escoja alguna de las siguientes opciones-----\e[0m";
		LUGAR(7,10);
		cout << "\e[31m0. Salir del programa\e[0m" << endl;
		LUGAR(8,10);
		cout << "\e[31m1. Comprobar si el monticulo esta vacio\e[0m" << endl;
		LUGAR(9,10);
		cout << "\e[31m2. Crear un montículo de donantes de sangre a partir de un fichero\e[0m" << endl;
		LUGAR(10,10);
		cout << "\e[31m3. Grabar un montículo de donantes de sangre en un fichero\e[0m" << endl;
		LUGAR(11,10);
		cout << "\e[31m4. Mostrar el donante que se encuentra en la cima del montículo\e[0m" << endl;
		LUGAR(12,10);
		cout << "\e[31m5. Simular la realizacion de donaciones\e[0m" << endl;
		LUGAR(13,10);
		cout << "\e[31m6. Mostrar el monticulo de donantes\e[0m" << endl;
		LUGAR(15,10);
		cout << "\e[33mOpcion --> \e[0m";
		cin >> opc;	


		switch(opc)
		{
			case 0:
				BORRAR;
				LUGAR(10,50);
				INVERSO;
				cout << "\n>>>Saliendo del programa...\n" << endl;
				APAGA;

				LUGAR(23,25);
				printf("pulse ");
				SUBRAYADO;
				printf("ENTER");
				APAGA;
				printf(" para ");
				INVERSO;
				printf("continuar"); 
				APAGA;
				getchar();
				getchar();
				BORRAR;
			break;
			
			case 1:
				if(monticulo.isEmpty()==true)
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>El monticulo de donantes está vacio";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
					BORRAR;
				}
				else
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>El monticulo de donantes no está vacio";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
					BORRAR;
				}
			break;

			case 2:
				BORRAR;
				LUGAR(10, 5);
				cout << "Introduzca el nombre del fichero: ";
				cin >> nombreFich;
				monticulo=monticulo.leerFichero(nombreFich);

				if (monticulo.isEmpty()==false)
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>Fichero cargado correctamente...!!";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}
				else
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << "Error al cargar el fichero...!!";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}
			break;

			case 3:
				BORRAR;
				LUGAR(10, 5);
				cout <<"Introduzca el nombre del fichero: ";
				cin >> nombreFich;
				monticulo.escribirFichero(nombreFich);

				getchar();
				BORRAR;
				LUGAR(10, 5);
				cout << ">>>Fichero volcado correctamente...!!";

				LUGAR(23,25);
				printf("pulse ");
				SUBRAYADO;
				printf("ENTER");
				APAGA;
				printf(" para ");
				INVERSO;
				printf("continuar"); 
				APAGA;
				getchar();
			break;

			case 4:
				if (monticulo.isEmpty() == false)
				{
					d=monticulo.cima();
					BORRAR;
					LUGAR(10, 5);
					cout << "El donante que va en la cima del monticulo es: \n" <<endl;
					cout << "\tNombre: " << d.getNombre()<< endl;
					cout << "\tApellidos: " << d.getApellidos() << endl;
					cout << "\tGrupo sanguineo: " << d.getGrSang() << endl;
					cout << "\tRH: " << d.getRH() << endl;
					cout << "\tNumero de donaciones: " << d.getDonaciones() << endl;

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
					getchar();
				}
				else
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>El monticulo esta vacio, por favor use la opcion 2";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}

			break;

			case 5: 
					if (monticulo.isEmpty()==true)
					{
						getchar();
						BORRAR;
						LUGAR(10, 5);
						cout << ">>>El monticulo esta vacio, por favor use la opcion 2";

						LUGAR(23,25);
						printf("pulse ");
						SUBRAYADO;
						printf("ENTER");
						APAGA;
						printf(" para ");
						INVERSO;
						printf("continuar"); 
						APAGA;
						getchar();
					}
					else
					{
						BORRAR;
						LUGAR(10, 5);
						cout << "Ingrese el numero de donaciones que quiere simular: ";
						cin >> num;

						for (i=0; i<num; i++)
						{
							monticulo.modificarCima(monticulo);
						}

						getchar();
						BORRAR;
						LUGAR(10, 5);
						cout << "Se han simulado " << num << " donaciones";

						LUGAR(23,25);
						printf("pulse ");
						SUBRAYADO;
						printf("ENTER");
						APAGA;
						printf(" para ");
						INVERSO;
						printf("continuar"); 
						APAGA;
						getchar();
					}
			break;

			case 6:
				if(monticulo.isEmpty()==false)
				{
					BORRAR;
					LUGAR(10, 5);

					mostrarMonticulo(monticulo);

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
					getchar();
				}
				else
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << ">>>El monticulo esta vacio, por favor use la opcion 2";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}
			break;

			default: 
				BORRAR;
				PARPADEO;
				LUGAR(10,25);
				cout << "\n>>>Opcion incorrecta, vuelva a introducir una opcion valida..\n" << endl;
				APAGA;

				LUGAR(23,25);
				printf("pulse ");
				SUBRAYADO;
				printf("ENTER");
				APAGA;
				printf(" para ");
				INVERSO;
				printf("continuar"); 
				APAGA;
				getchar();
				getchar();
		}
	}while(opc!=0);

	//Fin de la funcion
}



/*! 
	\brief Imprime los donantes de un monticulo por pantalla
	\param monticulo de tipo MonticuloDonantes
	\pre El monticulo debe existir
	\post Ninguna
*/
void mostrarMonticulo(MonticuloDonantes monticulo)
{
	Donante d;
	int i;

	for (i=0; i<monticulo.tamanio(); i++)
	{
		d = monticulo.item(i);
		
		cout << "\tNombre: " << d.getNombre()<< endl;
		cout << "\tApellidos: " << d.getApellidos() << endl;
		cout << "\tGrupo sanguineo: " << d.getGrSang() << endl;
		cout << "\tRH: " << d.getRH() << endl;
		cout << "\tNumero de donaciones: " << d.getDonaciones() << endl;
		cout << endl << endl;
	} 
}



// FUNCIONESMONTICULO_HPP
#endif