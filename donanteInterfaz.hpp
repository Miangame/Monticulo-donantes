/*! 
  \file donanteInterfaz.hpp
  \brief DonanteInterfaz declara de manera publica las funciones virtuales de la clase Donante
  \author Miguel Angel Gavilan Merino
  \date 13/04/2016
*/


#ifndef DONANTEINTERFAZ_HPP
#define DONANTEINTERFAZ_HPP


// Ficheros de cabecera
#include <iostream>



namespace ed
{
	/*!
	   \brief Clase DonanteInterfaz

	*/
	class DonanteInterfaz
	{
		//! \name Funciones publicas virtuales de la clase DonanteInterfaz
		public:
			/*! 
				\brief Funcion virtual que devuelve el nombre de un donante
			*/
			virtual char * getNombre() const = 0;

			/*! 
				\brief Funcion virtual que devuelve los apellidos de un donante
			*/
			virtual char * getApellidos() const = 0;

			/*! 
				\brief Funcion virtual que devuelve el grupo sanguineo de un donante
			*/
			virtual char * getGrSang() const = 0;

			/*! 
				\brief Funcion virtual que devuelve el factor RH de un donante
			*/
			virtual char * getRH() const = 0;

			/*! 
				\brief Funcion virtual que asigna un nombre pasado por parametro
			*/
			virtual void setNombre(const char * nombre) = 0;

			/*! 
				\brief Funcion virtual que asigna los apellidos pasados por parametro
			*/
			virtual void setApellidos(const char * apellidos) = 0;

			/*! 
				\brief Funcion virtual que asigna el grupo sanguineo pasado por parametro
			*/
			virtual void setGrSang(const char * grSang) = 0;

			/*! 
				\brief Funcion virtual que asigna el RH pasado por parametro
			*/
			virtual void setRH(const char * rh) = 0;
			
	}; // Fin de la definicion de la clase DonanteInterfaz
} // \brief Fin de namespace ed


// DONANTEINTERFAZ_HPP
#endif