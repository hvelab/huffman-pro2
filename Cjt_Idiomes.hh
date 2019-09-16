
/** @file Cjt_Idiomes.hh
    @brief Especificación de la clase Conjunt d'Idiomes
*/





#ifndef CONJ_ID_HH
#define CONJ_ID_HH

#include "idioma.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iterator>
#endif

class Cjt_Idiomes {
    
/*
 * Clase Conjunt d'Idiomes 
 */

/** @class Cjt_Idiomes
 *  @brief Representa un conjunto de idiomas 
 *  Las operaciones se limitan a la creadora, añadir un idioma al conjunto y comprobar si existe (en caso afirmativo se puede consultar)
 */

    
private:
    /** @brief conjunto como tal */
map<string,idioma> conjunt;


public: 

    //Constructora 
    /** @brief Creadora por defecto
        \pre  cierto
        \post El resultado es un conjunto de idiomas vacío 
        \coste 
    */
    Cjt_Idiomes();
    
    /** @brief operación que añade un idioma al conjunto 
        \pre   se ha leído un idioma por el canal estándar
        \post  el conjunto de idiomas se ha modificado y se ha añadido éste
        \coste 
    */
    void anadir_idioma(idioma aux); 
    
     //Consultoras
    
    /** @brief operación que consulta si existe un idioma
        \pre   se ha leído un nombre para poder buscar el idioma 
        \post  devuelve cierto si existe dentro del conjunto 
        \coste 
    */
    bool existe_idioma(string nombre) const;  
    
    /** @brief operación que consulta un idioma del conjunto 
        \pre   el idioma existe
        \post  retorna un iterador que apunta al idioma que se busca
        \coste 
    */
    map<string,idioma>::iterator consultar_idioma(string nombre);
    
    
};

#endif
