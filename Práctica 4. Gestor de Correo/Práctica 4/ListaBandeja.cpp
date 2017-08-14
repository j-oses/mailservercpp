#include "ListaBandeja.h"

void guardar(const tListaBandeja & listElems, ofstream & archivo){
//Dado un flujo de archivo de salida (ya abierto), guarda los datos de
//los elementos de la lista(ver ejemplo de la secci�n 1.3)

	int i;

	archivo << listElems.contador << endl;

	for(i = 0; i < listElems.contador; i++){
		archivo << listElems.lista[i].id << " ";
		if(listElems.lista[i].leido == true){
			archivo << 1 << endl;
		}
		else{
			archivo << 0 << endl;
		}
	}

}

void cargar(tListaBandeja & listElems, ifstream & archivo){//This one is oki doki
//Dado un flujo de archivo de entrada (ya abierto), lee los datos que corresponden a 
//una lista y la devuelve.
//Recibe el archivo del que tiene que cargar y desde donde tiene que empezar y lo asigna a la bandeja correspondiente

	int cont, i, leido;
	string correo;

	archivo >>  cont;

	listElems.contador = cont;

	for(i = 0; i < cont; i++){
		archivo >> correo >> leido;
		listElems.lista[i].id = correo;
		if(leido == 1){
			listElems.lista[i].leido = true;
		}
		else{
			listElems.lista[i].leido = false;
		}
	}

}

bool insertar(tListaBandeja & listElems, const tElemBandeja & elem){

	bool insertado = false;

	if(!llena(listElems)){
	
		listElems.contador++;
		listElems.lista[listElems.contador-1].id = elem.id;
		listElems.lista[listElems.contador-1].leido = false;	
		insertado = true;
	}

return insertado;
} 
 // Pero aqu� s�lo paso una por referencia.
//^ Es hacer lo mismo pero siendo listElems listaRecibidos o listaEnviados, es decir, se hace en main o donde sea.
//CREO que lo que pasa es que cuando se manda un correo se a�ade a la lista de correos y luego FUERA de esta funci�n
//se introduce ese correo en las listas de correos de entrada y salida.

int buscar(const tListaBandeja & listElems, const string & idMail){
//Dado un identificador de correo y la lista, devuelve, si dicho
//identificador existe en la lista, su posici�n, y si no existe devuelve -1.

	int pos, i = 0;
	bool encontrado = false;

	while(i < listElems.contador && encontrado == false){

		if(listElems.lista[i].id == idMail){
			pos = i;
			encontrado = true;
		}

		i++;

	}

	if (encontrado == false){
		pos = -1;
	}

return pos;
}

bool eliminar(tListaBandeja & listElems, const string & idMail){
/*Dado un identificador de correo, lo busca en la lista y si lo encuentra lo elimina
de la lista (�sin dejar huecos!). Si no lo encuentra, devuelve false, en otro caso
devuelve true. Este subprograma representa la acci�n de borrar un correo de
una de sus bandejas del usuario. OJO: esta operaci�n s�lo supone que el
elemento se elimina de la bandeja, pero el correo puede seguir existiendo en la
lista de correos del gestor.*/

	bool eliminado = false;
	int pos, j;

	pos = buscar(listElems, idMail);

	if(pos != -1){

		eliminado = true;

		for(j = pos; j < listElems.contador; j++){
			listElems.lista[j] = listElems.lista[j+1];
		}
		listElems.contador--;
	}

return eliminado;
}

bool correoLeido(tListaBandeja & listElems, const string & idMail){
/*Dado un identificador de correo, lo busca en la lista y pone el
indicador de le�do a true. La operaci�n devuelve un booleano indicando si se
encontr� o no el identificador.*/

	bool encontrado = false;
	int pos;

	pos = buscar(listElems, idMail);

	if(pos != -1){
		listElems.lista[pos].leido = true;
		encontrado = true;
	}

return encontrado;
}

/*Es importante tener en cuenta que EL GESTOR S�LO ALMACENA UNA
COPIA DE CADA CORREO, m�s concretamente, la almacena en la lista de
correos. Por su parte, un usuario no almacena sus correos recibidos y enviados,
sino que tanto su bandeja de entrada como su bandeja de salida ser�n una lista de
registros que contendr�n, entre otras cosas, un identificador que permitir�
localizar el correo en la lista de correos.*/