#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
/*#include <fstream>
#include <iostream>
#include <string>*/
//#include "sesion.h"
//#include "gestor.h"
#include "usuario.h"

using namespace std;

//const int MAX_ELEMS = 100;

typedef tUsuario tUsuarios[MAX_ELEMS];

typedef struct{
	tUsuarios datos;
	int contador;
}tListaUsuarios;

inline void iniciar(tListaUsuarios & usuarios){
	usuarios.contador = 0;
}

inline bool llena(const tListaUsuarios & usuarios){
	return usuarios.contador == MAX_ELEMS; 
}

inline int longitud(const tListaUsuarios & usuarios){
	return usuarios.contador; 
}
bool cargar(tListaUsuarios & usuarios, const string & nombre);
//Carga la lista de usuarios desde el fichero de usuarios nombre (ver ejemplo de
// secci�n 1.3).

void guardar(const tListaUsuarios & usuarios, const string & nombre);
//Guarda de la lista de usuarios en el fichero de usuarios nombre.

bool insertar(tListaUsuarios & usuarios, const tUsuario & usuario);
/*A�ade un usuario en la posici�n de la lista que le corresponde, si
hay sitio para ello. Adem�s devuelve un booleano indicando si la operaci�n
tuvo �xito o no.*/

bool buscar(const tListaUsuarios & usuarios, const string & idUser, int & posicion);
/*Dado un identificador de usuario y la lista,
devuelve, si dicho identificador existe en la lista, su posici�n y el valor true, y
si no existe en la lista, la posici�n que le corresponder�a y el valor false.*/
#endif