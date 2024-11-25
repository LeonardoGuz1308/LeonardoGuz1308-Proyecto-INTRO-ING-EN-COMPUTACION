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
void Leerarchivo(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{
	FILE* archivo;
	fopen_s(&archivo, szNombre, "r");
	if (!archivo)
	{
		printf("Archivo no se pudo abrir");
		return;
	}
	char palabra[TAMTOKEN];
	while (fscanf_s(archivo, "%s", palabra, TAMTOKEN) != EOF)
	{
		Limpiarpalabra(palabra);
		if (strlen(palabra) > 0)
		{
			int existe = 0;
			for (int i = 0; i < iNumElementos; i++)
			{
				if (strcmp(szPalabras[i], palabra) == 0)
				{
					iEstadisticas[i]++;
					existe = 1;
					i = iNumElementos;
				}

			}
			if (!existe && iNumElementos < NUMPALABRAS)
			{
				strcpy_s(szPalabras[iNumElementos], TAMTOKEN, palabra);
				iEstadisticas[iNumElementos] = 1;
				iNumElementos++;
			}
		}
	}
	fclose(archivo);

}
void Limpiarpalabra(char* palabra)
{
	int j = 0;
	for (int i = 0; palabra[i]; i++)
	{
		if (isalpha(palabra[i]) || strchr("áéíóú", palabra[i]))
		{
			palabra[j++] = tolower(palabra[i]);
		}
	}
	palabra[j] = '\0';

}
void limpiarYNormalizar(char* palabra, const char* simbolos)
{
	int indiceValido = 0; // Índice para sobrescribir caracteres válidos

	// Recorrer la cadena y procesar cada carácter
	for (int i = 0; palabra[i] != '\0'; i++)
	{
		int esValido = 1;

		// Comprobar si el carácter está en la lista de símbolos
		for (int j = 0; simbolos[j] != '\0'; j++)
		{
			if (palabra[i] == simbolos[j])
			{
				esValido = 0;
				break;
			}
		}

		// Si el carácter es válido, conservarlo y convertirlo a minúscula
		if (esValido)
		{
			palabra[indiceValido++] = tolower(palabra[i]);
		}
	}

	// Terminar la cadena con un carácter nulo
	palabra[indiceValido] = '\0';
}

