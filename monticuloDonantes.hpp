/*! 
  \file monticuloDonantes.hpp
  \brief monticuloDonantes crea un heap de donantes
  \author Miguel Angel Gavilan Merino
  \date 04/05/2016
*/


#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP


// Ficheros de cabecera
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cassert>
#include <fstream>
#include <sstream>
#include "donante.hpp"
#include "donanteInterfaz.hpp"
#include "monticuloDonantesInterfaz.hpp"
#include "macros.hpp"


// Facilita la entrada y salida
using std::ios;
using std::ofstream;
using std::ifstream;
using std::string;
using std::stringstream;
using std::swap;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;



/*!
   \brief Espacio de nombres para la asignatura de Estructura de datos.

*/
namespace ed
{
	/*!
	   \brief Clase MonticuloDonantes

	*/
	class MonticuloDonantes : public ed::MonticuloDonantesInterfaz
	{
		//! \name Atributos privados de la clase MonticuloDonantes
		private:
			vector <Donante> _vecDon;

		//! \name Funciones o métodos públicos de la clase MonticuloDonantes
		public:

			//! \name Constructores de la clase Donantes

			/*! 
				\brief Constructor vacio que inicializa un monticulo
			
			*/
			MonticuloDonantes()
			{

			}


			/*! 
				\brief Funcion que devuelve el tamaño de nuestro monticulo de donantes
			*/
			int tamanio()
			{
				return _vecDon.size();
			}


			/*! 
				\brief Funcion de tipo Donante que devuelve un donante del monticulo
				\param pos de tipo int
				\pre el monticulo deve existir
				\post Ninguna
			*/
			Donante item(int pos)
			{
				return _vecDon[pos];
			}


			/*! 
				\brief Funcion booleana que dice si un monticulo esta vacio
				\pre ninguna
				\post Ninguna
			*/
			bool isEmpty() const
			{
				if(_vecDon.size() == 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}


			/*! 
				\brief Funcion que devuelve el donante que se encuentra en la cima del monticulo
				\pre El monticulo no debe estar vacio
				\post Ninguna
			*/
			Donante cima() const
			{
				assert(not (isEmpty()));

				return _vecDon[0];
			}


			/*! 
				\brief Funcion booleana que dice si existe un donante
				\pre El monticulo no debe estar vacio
				\post Ninguna
			*/
			bool has(Donante it)
			{
			 	assert (not (isEmpty()));

				int i=0;

				while(unsigned(i) < _vecDon.size() and _vecDon[i] != it)
				{
					i++;
				}

				return not (unsigned(i) == _vecDon.size());
			}


			/*! 
				\brief Funcion que inserta un donante en un monticulo
				\param item de tipo Donante
				\sa shiftUp()
			*/
			void insert(Donante item)
			{
				_vecDon.push_back(item);
				shiftUp(_vecDon.size()-1);
			}


			/*! 
				\brief Funcion que elimina un Donante de un monticulo
				\pre El monticulo no debe estar vacio
				\post Ninguna
				\sa shiftDown()
			*/
			void remove()
			{
				assert(not (isEmpty()));

				_vecDon[0]=_vecDon[_vecDon.size()-1];
				_vecDon.pop_back();
				shiftDown(0);
			}


			/*! 
				\brief Funcion que modifica la cima segun el numero de donaciones
				\param m de tipo MonticuloDonantes
				\sa cima(), setDonaciones(), remove(), insert()
			*/
			void modificarCima(MonticuloDonantes &m){
				Donante d;
				d=cima();
				d.setDonaciones(d.getDonaciones()+1);
				m.remove();
				m.insert(d);
			}


			/*! 
				\brief Funcion que devuelve el hijo izquierdo
				\param i de tipo int
			*/
			int leftChild(int i)
			{
				return i*2+1;
			}


			/*! 
				\brief Funcion que devuelve el hijo derecho
				\param i de tipo int
			*/
			int rightChild(int i)
			{
				return i*2+2;
			}


			/*! 
				\brief Funcion que devuelve el padre
				\param i de tipo int
			*/
			int parent(int i)
			{
				return ((i-1)/2);
			}


			/*! 
				\brief Funcion que flota hacia arriba un donante
				\param i de tipo int
				\sa parent(), shiftUp()
			*/
			void shiftUp(int i)
			{
				if ((i > 0) and (_vecDon[i] <= _vecDon[parent(i)]))
				{
					swap(_vecDon[parent(i)], _vecDon[i]);
					shiftUp(parent(i));
				}
			}


			/*! 
				\brief Funcion que flota hacia abajo un donante
				\param i de tipo int
				\sa leftChild(), rightChild(), shiftDown()
			*/
			void shiftDown(int i)
			{
				int n=i;
				int lc=leftChild(i);
				int rc=rightChild(i);

				if((unsigned(lc) < _vecDon.size()) and (_vecDon[lc] <= _vecDon[n]))
				{
					n=lc;
				}

				if((unsigned(rc) < _vecDon.size()) and (_vecDon[rc] <= _vecDon[n]))
				{
					n=rc;
				}

				if(i!=n)
				{
					swap(_vecDon[i], _vecDon[n]);
					shiftDown(n);
				}
			}


			/*! 
				\brief Escribe en un fichero el monticulo
				\sa isEmpty(), cima(), remove()
			*/
			void escribirFichero(string nombreFich)
			{
				const char * nombreF = nombreFich.c_str();

				Donante d;
				ofstream salida;
				salida.open(nombreF);

				while(isEmpty()==false)
				{
					d=cima();
					remove();
					salida<<d;
				}

				salida.close();
			}


			/*! 
				\brief Funcion que lee un monticulo de un fichero
				\sa insert()
			*/
			MonticuloDonantes leerFichero(string nombreFich)
			{
				MonticuloDonantes vec;
				Donante d;
				char nombre[30];
				char apellidos[30];
				char grSang[5];
				char rh[10];
				int donaciones;
				string l;

				ifstream f (nombreFich.c_str());

				while(getline(f, l))
				{
					stringstream linea (l);

					linea.getline(nombre, 30, ',');
					linea.getline(apellidos, 30, ',');
					linea.getline(grSang, 5, ',');
					linea.getline(rh, 10, ',');
					linea >> donaciones;

					d.setNombre(nombre);
					d.setApellidos(apellidos);
					d.setGrSang(grSang);
					d.setRH(rh);
					d.setDonaciones(donaciones);

					vec.insert(d);
				}

				f.close();

				return vec;
			}

			
	}; // Fin de la definicion de la clase MonticuloDonantes

}// \brief Fin de namespace ed


// MONTICULODONANTES_HPP
#endif

















