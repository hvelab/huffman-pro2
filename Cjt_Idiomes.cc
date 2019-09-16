/** @file Cjt_Idiomes.cc
    @brief Implementación de la clase conjunt d'idiomes
*/

#include "Cjt_Idiomes.hh"

Cjt_Idiomes::Cjt_Idiomes(){

}


void Cjt_Idiomes::anadir_idioma(idioma aux){
    conjunt.insert(make_pair(aux.consultar_nombre(),aux));
}

bool Cjt_Idiomes::existe_idioma(string nombre) const {
    map<string, idioma>::const_iterator it;   
    it = conjunt.find(nombre);         
    
    if(it == conjunt.end()){              
           return false;
    } else {
           return true;
    
    }
    
}


map<string,idioma>::iterator Cjt_Idiomes::consultar_idioma(string nombre) {
            map<string, idioma>::iterator it = conjunt.find(nombre);
            return it; 
}
    



