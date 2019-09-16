
/** @file Treecode.cc
    @brief Implementación de la clase treecode 
*/

#include "Treecode.hh"

Treecode::Treecode(){

}

void Treecode::crear_codigos(const BinTree < pair<string,int> >& arbol, string code) {
    if (not arbol.left().empty()) {
        crear_codigos(arbol.left(), code+ "0");
    }
    if (not arbol.right().empty()) {
        crear_codigos(arbol.right(), code+ "1");
    } else if (arbol.left().empty()) { //if both are empty
        string c = (arbol.value().first);
        codigos[c] = code;
    }
}


void Treecode::imprimir_treecode2() const{
    cout << "recorrido en preorden:" << endl;
    imprimir_treecode_rec(treecode);
    cout << "recorrido en inorden:" << endl; 
    imprimir_treecode_rec2(treecode);
    cout << endl;
}

void Treecode::imprimir_treecode_rec(const BinTree < pair<string,int> > arbol)  {                                                             //en preorden
    
    cout << arbol.value().first  << " "  << arbol.value().second << endl;
    if (not arbol.left().empty()) imprimir_treecode_rec(arbol.left());
    if (not arbol.right().empty()) imprimir_treecode_rec(arbol.right());
    
}

void Treecode::imprimir_treecode_rec2(const BinTree < pair<string,int> > arbol)  {                                                             //en inorden
    
    if (not arbol.left().empty()) imprimir_treecode_rec2(arbol.left());
    cout << arbol.value().first << " " << arbol.value().second << endl;
    if (not arbol.right().empty()) imprimir_treecode_rec2(arbol.right());
}

void Treecode::imprimir_codigo2(string c) const{
   map<string, string>::const_iterator it = codigos.find(c);
     
    if (it != codigos.end()){
        
        cout << codigos.find(c)->first << " " <<  codigos.find(c)->second << endl; 
    } else {
        cout << "El idioma no existe o el caracter no esta en el idioma" << endl; 
    }
    
    cout << endl;
}

void Treecode::imprimir_codigos2() const{
    for (map<string,string>::const_iterator it = codigos.begin(); it!=codigos.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
}

void Treecode::codifica_treecode(const string& palabra) {

    string palabra_codificada;
    string ultima;
    bool codificable = true;
    int i=0; 
    
    while (codificable and i<palabra.size()) {
        
        string letra;
        
        if (palabra[i] >= 0){
        letra.push_back(palabra[i]); 
        //cout << "letra normal: " << letra; 
        i++;
        
        } else {
            letra = string(palabra, i, 2); 
            //cout << "letra especial: " << letra; 
            i+=2;
        }
        
        if (codigos.find(letra)!=codigos.end()) {
            //cout << " found" << endl; 
            palabra_codificada += codigos[letra];
            
        } else {
            codificable = false;
            ultima = letra; 
        }
    }
    
    
    if (codificable) {
        cout << palabra_codificada << endl; 
    } else {
        cout << "El texto no pertenece al idioma; primer caracter que falla: " << ultima << endl; 
    }
    cout << endl;
}



void Treecode::pre_dec(string paraula){
    
    
        BinTree< pair<string,int> > arbol = treecode;
        bool decodificable = true;
        int i = 0; 
        int pos = 0; 
        string palabra_decodificada; 
        
        while(i < paraula.size()){
         
        decodifica(paraula,i,arbol,palabra_decodificada,decodificable,pos);        
        
//          cout << " he volvido" << endl; 
//          cout << i << " " << paraula.size() << " " << decodificable << endl;
//          cout << palabra_decodificada << endl; 
        }
        
        if(decodificable or pos == paraula.size()){
            cout << palabra_decodificada << endl; 
        
        } else {
            cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: "<< pos << endl;
    }
        
    cout << endl; 
}


void Treecode::decodifica(string& palabra, int& i, const BinTree< pair<string,int> >& arbol , string& palabra_decodificada,bool& decodificable,int& pos){
     
//        cout << i << " " << decodificable << endl << "palabra[i] == " << palabra[i] << endl;  
    
//          cout << "padentro" << endl; 
        
        if (arbol.left().empty()) {
//             cout << "hoja" << endl;  
            palabra_decodificada += arbol.value().first;
            pos = i;
            
            
        } else if (i == palabra.size()){
//             cout << "final" << endl; 
            decodificable = false; 
            
        } else if (palabra[i] == '0') {
//             cout << "izq" << endl;
            ++i;
            decodifica(palabra,i,arbol.left(),palabra_decodificada,decodificable,pos);
            
        } else if (palabra[i] == '1') {
//             cout << "der" << endl;
            ++i;
            decodifica(palabra,i,arbol.right(),palabra_decodificada,decodificable,pos);
            
        }  else {
//             cout << "ninguna" << endl;
            decodificable = false; 
          
        }
    } 


void Treecode::crear_treecode(map<string,int> tabla){
    
    struct ordenar_por_frecuencia {
        bool operator() (const BinTree<pair<string,int> >& pair1, const BinTree<pair<string,int> >& pair2) const {
            if (pair1.value().second == pair2.value().second) return pair1.value().first < pair2.value().first;
            else return pair1.value().second < pair2.value().second;
        }
    };
    
    set< BinTree <pair<string,int> >, ordenar_por_frecuencia > tree_table;
    for (map<string,int>::const_iterator it=tabla.begin(); it!=tabla.end(); ++it) tree_table.insert(BinTree<pair<string,int>>(*it));
    // set "tree_table" está formado por bintrees sin hijos de la tabla de frecuencias, ordenado por frecuencia en lugar de alfabéticamente.
    
    
    while (tree_table.size() > 1) {
        BinTree< pair<string,int> > izq (*tree_table.begin());
        tree_table.erase(tree_table.begin());
        
        BinTree< pair<string,int> > der (*tree_table.begin());
        tree_table.erase(tree_table.begin());
        
        string izqder_name;
        if (izq.value().first < der.value().first) izqder_name = izq.value().first + der.value().first;
        else izqder_name = der.value().first + izq.value().first;
        BinTree< pair<string,int> > izqder ({izqder_name, izq.value().second + der.value().second},izq,der);
            
        tree_table.insert(izqder);
        
        //debug:
        //cout << "(" << izqder.value().first << " " << izqder.value().second << ")" << endl;
    }
    
    treecode = *tree_table.begin();
    
    string t;
    crear_codigos(treecode, t);
    
}

