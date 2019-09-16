/** @file Idioma.cc
    @brief Implementación de la clase Idioma
*/
#include "idioma.hh"

idioma::idioma() {
    
}

void idioma::leer() {
    
    string name,caracter;
    int num,frecuencia; 
    
    cin >> name >> num;
    nombre = name; 
    for (int i = 0; i < num; i++) {
        cin >> caracter >> frecuencia;
        tabla[caracter] = frecuencia;
        }
    
    treecode.crear_treecode(tabla);
    
}

void idioma::nuevo_idioma(string nom){
    
    string caracter; 
    int num,frecuencia;
    nombre = nom; 
    cin >> num; 
    for (int i = 0; i < num; i++) {
        cin >> caracter >> frecuencia;
        tabla[caracter] = frecuencia;
        }
        
        
    cout << "Anadido " << nombre << endl << endl; 
        
    treecode.crear_treecode(tabla);
    
}


void idioma::modificar_tabla(){
    
    string caracter; 
    int num, frecuencia;
    
    cin >> num; 
    
    for (int i = 0; i < num; i++) {
        cin >> caracter >> frecuencia;
        map<string,int>::iterator it  = tabla.find(caracter);
        
        if (it == tabla.end()){
            tabla[caracter] = frecuencia;
            } else {
                int aux = (*it).second; 
                aux += frecuencia; 
                tabla[caracter] = aux; 
            }
        }
    
     cout << "Modificado " << nombre << endl << endl;
     
    treecode.crear_treecode(tabla);
}


 void idioma::imprimir_tabla() const{
    
    for (map<string,int>::const_iterator it = tabla.begin(); it != tabla.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
}



 void idioma::imprimir_treecode() const{
    
    treecode.imprimir_treecode2(); 
}

 void idioma::imprimir_codigos() const {
    
    treecode.imprimir_codigos2(); 
    

}

 void idioma::imprimir_codigo(string c) const{
    
    treecode.imprimir_codigo2(c); 
}

void idioma::codifica(const string& palabra){
    
    treecode.codifica_treecode(palabra); 
    
}

void idioma::decodifica(string& palabra){
    
    treecode.pre_dec(palabra); 

}

string idioma::consultar_nombre(){
    return nombre; 
}
