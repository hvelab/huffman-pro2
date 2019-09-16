
/** @file Idioma.hh
    @brief Especificación de la clase Idioma
*/

#ifndef IDIOMA_HH
#define IDIOMA_HH


#include "Treecode.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <iostream> 
#include <map> 
#include <set>
#include <iterator>
#endif
using namespace std;

/*
 * Clase idioma 
 */

/** @class idioma
 *  @brief Representa un idioma y los datos que lo forman  
 */


class idioma {
    
    /* Contiene un idioma y las operaciones que se pueden hacer con él */
    
private:
    
    /*un idioma se compone por su tabla de frecuencias, su treecode y sus códigos  */
    
    /** @brief treecode del idioma */
    Treecode treecode;
    
    /** @brief tabla de frecuencias del idioma */
    map<string,int> tabla;
    
    /** @brief nombre del idioma */
    string nombre;
    
   
    
public:
    //Constructora 
    /** @brief Creadora por defecto
        \pre  cierto
        \post El resultado es un idioma, sin nombre ni tabla de frecuencias
        \coste 
    */
    idioma();
    
    //Entrada
    
    /** @brief operación de lectura
        \pre   cierto
        \post  se ha leído la tabla de frecuencias del idioma, se generan el treecode y los códigos a partir de ahí 
        \coste 
    */
    void leer();
    
     /** @brief operación de lectura
        \pre    el idioma no existía en el conjunto
        \post   una vez introducido por el canal de lectura estándar,se ha añadido al conjunto de idiomas con el nombre del parámetro implícito
        \coste 
    */
    
    void nuevo_idioma(string nom);
    
    /** @brief operación de modificación de la tabla 
        \pre   el idioma existe 
        \post  se ha modificado la tabla de frecuencias del idioma, sumando las que no existían y modificando las que deben cambiarse 
        \coste 
    */
    
    //Modificadora 
    
    void modificar_tabla(); 

    //Salida
    
    /** @brief  operación para imprimir la tabla de frecuencias
        \pre    el idioma existe
        \post   escribe por el canal estándar la tabla de frecuencias  
        \coste 
    */
    
    void imprimir_tabla() const;
    
    /** @brief  operación para imprimir el treecode del idioma, llama a la clase treecode para hacerlo
        \pre    el idioma existe
        \post   escribe por el canal estándar la tabla de frecuencias  
        \coste 
    */
    
    void imprimir_treecode() const;
     
     /** @brief  operación para imprimir todos los códigos del idioma
        \pre     el idioma existe
        \post    escribe por el canal estándar todos los códigos de un idioma
        \coste 
    */
     
     void imprimir_codigos() const;
    
     /** @brief  operación para imprimir un código en concreto del idioma, el parámetro implícito es el carácter en concreto que se busca
        \pre     el idioma existe
        \post    escribe por el canal estándar el carácter elegido y su codificación en el idioma
    */
    
     void imprimir_codigo(string c) const;
    
    
    //Operadora 
    
    /** @brief  operación para codificar una palabra dada por el usuario (la del parámetro implícito)
        \pre    cierto
        \post   usando la tabla de códigos del idioma devuelve la palabra codificada, en caso de fallo imprime el error
        \coste 
    */
    void codifica(const string& palabra);
   
     /** @brief  operación para decodificar un código dado por el usuario (el del parámetro implícito)
        \pre    cierto
        \post   recorre el treecode hasta lograr decodificar la palabra, en caso contrario imprime el error
        \coste 
    */
    void decodifica(string& palabra);
    
    //Consultora
    
      /** @brief Consultar nombre
        \pre  cierto
        \post retorna el nombre del idioma para poder utilizarlo en otras clases
        \coste 
    */
    string consultar_nombre();
    
};

#endif
