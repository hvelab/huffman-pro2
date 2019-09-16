/** @file Treecode.hh
    @brief Especificación de la clase Idioma
*/
//poner const!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef TREECODE_HH
#define TREECODE_HH

#ifndef NO_DIAGRAM 
#include "BinTree.hh"
#include <iostream> //includes que no quiero que salgan en el doxygen
#include <string>
#include <map>
#include <set>
#include <iterator>
#endif

class Treecode {
    
/*
 * Clase Treecode
 */

/** @class Treecode
 *  @brief Representa el treecode y los códigos que salen de él 
 */

private:
    
    /** @brief treecode del idioma */
    BinTree< pair<string,int> > treecode; 
    
    /** @brief códigos del idioma */
    map<string,string> codigos;
    

    void crear_codigos(const BinTree <pair<string,int>>& arbol, string code);
    
    static void imprimir_treecode_rec(const BinTree <pair<string,int>> arbol) ;
    
    static void imprimir_treecode_rec2(const BinTree <pair<string,int>> arbol) ;
    
    void decodifica(string& palabra, int& i, const BinTree< pair<string,int> >& arbol , string& palabra_decodificada,bool& decodificable,int& pos);
    

public: 

    Treecode(); 
    
    void crear_treecode(map<string,int> tabla);
    
    void imprimir_treecode2() const;
    
    void imprimir_codigo2(string c)const;
    
    void imprimir_codigos2() const;
    
    void codifica_treecode(const string& palabra);
    
    void pre_dec(string paraula);



    

   
};

#endif
