/** @mainpage

    Pŕactica resuelta. 

    El programa principal se encuentra en el módulo program.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
    módulo para representar el Conjunto de Idiomas, incluye a su vez éstos mismos 
    y otra clase para representar específicamente el Treecode y los códigos que lo forman. 
*/

/** @file program.cc

    @brief Programa principal
    Tal y como se afirma en el enunciado de la práctica, todos los datos introducidos son correctos, por tanto 
    no se realizarán comprobaciones adicionales sobre los susodichos
*/


#include "Cjt_Idiomes.hh"
#include "idioma.hh"


#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

int main (){
    
    int num; 
    cin >> num;                                     //número de idiomas a leer 
    
    Cjt_Idiomes a; 
    
    for (int k = 0; k < num ; k++ ){                //se leen uno a uno 
        idioma aux; 
        aux.leer(); 
        a.anadir_idioma(aux); 
        
    }
    
    string codigo;
    
    while (cin >> codigo && codigo != "fin" ){
        
        if (codigo == "tabla_frec"){                //función imprimir tabla 
            string nom; 
            cin >> nom; 
             
            cout << "Tabla de frecuencias de " << nom << ":" << endl;
            
            if (a.existe_idioma(nom)) {
                map<string,idioma>::iterator it = a.consultar_idioma(nom); 
                (it->second).imprimir_tabla();
                
                } else {
                    cout << "El idioma no existe" << endl << endl;    
                }
            }                    
            
        if (codigo == "treecode"  ){                //función imprimir treecode
            string nom; 
            cin >> nom; 
            
            cout << "Treecode de " << nom << ":" << endl;
            
            if (a.existe_idioma(nom)) {
                map<string,idioma>::iterator it = a.consultar_idioma(nom); 
                (it->second).imprimir_treecode();
                } else {
                    cout << "El idioma no existe" << endl << endl;    
                }
            }
            
        if (codigo == "codigos"   ){                //función imprimir codigos
            
            string nom,codi; 
            cin >> nom >> codi;
            
            
            
            if (codi == "todos"){
                
                cout << "Codigos de " << nom << ":" << endl;
                
                if(a.existe_idioma(nom)){
                    
                    map<string,idioma>::iterator it = a.consultar_idioma(nom); 
                    (it->second).imprimir_codigos();
                    
                    } else {
                        cout << "El idioma no existe" << endl << endl;  
                }
                
            } else {
                        cout << "Codigo de " << codi << " en " << nom << ":" <<endl;
                        
                        if (a.existe_idioma(nom)){
    
                            map<string,idioma>::iterator it = a.consultar_idioma(nom); 
                            (it->second).imprimir_codigo(codi);
                            } else {
                                cout << "El idioma no existe o el caracter no esta en el idioma" << endl << endl;    
                    }
                }
        }
        
        if (codigo == "codifica"){      //función codificar
            
            string nom, paraula; 
            cin >> nom >> paraula; 
            
            cout << "Codifica en " << nom << " el texto:" << endl; 
            cout << paraula << endl;
            
            if (a.existe_idioma(nom)){
    
                map<string,idioma>::iterator it = a.consultar_idioma(nom); 
                (it->second).codifica(paraula);
                
                } else {
                    cout << "El idioma no existe" << endl << endl; 
                }
            
        }
        
        if (codigo == "decodifica"){            //función decodificar 
            
            string nom, paraula; 
            cin >> nom >> paraula; 
            
            cout << "Decodifica en " << nom << " el texto:" << endl; 
            cout << paraula << endl;
            
            if (a.existe_idioma(nom)){
    
                map<string,idioma>::iterator it = a.consultar_idioma(nom); 
                (it->second).decodifica(paraula);
                
                } else {
                    cout << "El idioma no existe" << endl << endl; 
                }
            
        }
        
        if (codigo == "anadir/modificar"){      //función para añadir o modificar un nuevo idioma
            
            string nom; 
            cin >> nom; 
            if (a.existe_idioma(nom)){
                map<string,idioma>::iterator it = a.consultar_idioma(nom); 
                (it->second).modificar_tabla(); 
                
            } else {
                idioma x; 
                x.nuevo_idioma(nom);
                a.anadir_idioma(x); 
                
                }
            }
            
        }
    }

            
    

