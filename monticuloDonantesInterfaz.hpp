/*! 
  \file monticuloDonantesInterfaz.hpp
  \brief monticuloDonantesInterfaz declara de manera publica las funciones virtuales de la clase monticuloDonantes
  \author Miguel Angel Gavilan Merino
  \date 
*/


#ifndef MONTICULO_DONANTES_INTERFAZ_HPP
#define MONTICULO_DONANTES_INTERFAZ_HPP


// Ficheros de cabecera
#include <iostream>
#include "donante.hpp"



namespace ed
{
	/*!
	   \brief Clase MonticuloDonantesInterfaz

	*/
	class MonticuloDonantesInterfaz
	{
		//! \name Funciones publicas virtuales de la clase MonticuloDonantesInterfaz
		public:
			/*! 
				\brief Funcion virtual que devuelve true si un monticulo esta vacio
			*/
			virtual bool isEmpty() const = 0;

			/*! 
				\brief Funcion virtual que devuelve la cima del monticulo
			*/
			virtual ed::Donante cima() const = 0;

			/*! 
				\brief Funcion virtual que inserta un donante en un monticulo
			*/
			virtual void insert(Donante item) = 0;

			/*! 
				\brief Funcion virtual que borra la cima del monticulo
			*/
			virtual void remove() = 0;
			
	}; // Fin de la definicion de la clase MonticuloDonantesInterfaz
} // \brief Fin de namespace ed


// MONTICULO_DONANTES_INTERFAZ_HPP
#endif