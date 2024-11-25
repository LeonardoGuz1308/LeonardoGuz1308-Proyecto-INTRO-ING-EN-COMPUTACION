	/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Ponga su nombre y numero de cuenta aqui.
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/


#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#include <ctype.h>	
//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario	
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
//DECLARAR E INICIAR LAS FUNCIONES
int revertir(int posicion, char szPalabraLeidaCopia2[TAMTOKEN], char szPalabrasSugeridas[][TAMTOKEN], int jPalabra, int longitud);
void Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos);
void Leerarchivo(char* sznombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos);
void Limpiarpalabra(char* palabra);
void OrdenarDiccionario(char szPalabras[][TAMTOKEN], int iEstadisticas[], int iNumElementos);
void limpiaryNormalizar(char* palabra, const char* simbolos);
void Eliminar(char szPalabras[][TAMTOKEN], int& elementos, int iEstadisticas[]);
void Ordenar(char szPalabras[][TAMTOKEN], int elementos, int iEstadisticas[], int opcion);
	
void Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{

	iNumElementos = 0;	
	Leerarchivo		     (szNombre, szPalabras, iEstadisticas, iNumElementos);
	OrdenarDiccionario   (szPalabras,iEstadisticas,iNumElementos);

}

