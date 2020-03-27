#include "archivo.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

archivo::archivo(){}

void archivo::guardar( relacion _relacion ){
    string nombre_txt = _relacion.getNombre() + ".txt";
    ofstream nombres( "Archivos.txt", ios::app);
    nombres << nombre_txt << endl;
    string path =  _relacion.getNombre() + ".txt";
    ofstream archivoTXT( path.c_str() );
    if( !archivoTXT ){
        cerr << "No se ṕuedo abrir el archivo" << endl;
        exit( EXIT_FAILURE );
    }
    for (size_t i = 0; i < _relacion.getEncabezados().size(); i++){
        archivoTXT << _relacion.getEncabezados()[i] << ";";
    }
    archivoTXT << endl;
    vector< tupla > _tuplas = _relacion.getTuplas();
    vector< string > encabezados = _relacion.getEncabezados();
    for (size_t i = 0; i < _tuplas.size(); i++){
        tupla _tupla = _tuplas[i];
        archivoTXT << _tupla.getID() << ";";
        for (size_t j = 0; j < encabezados.size(); j++){
            archivoTXT << _tupla.getAtributos()[j] << ";";   
        }
        archivoTXT << endl;
    }
}

vector<relacion> archivo::cargar(){
    vector<relacion> relaciones;
    vector< string > direcciones;
    ifstream archivoTXT( "Archivos.txt", ios::in );
    string linea;
    while( archivoTXT >> linea ){
        direcciones.push_back( linea );
    }
    for (size_t i = 0; i < direcciones.size(); i++){
        ifstream RELACIONES_TXT( direcciones[i].c_str() , ios::in );
        string nombre = "";
        for (size_t k = 0; k < direcciones[i].size() - 4; k++){
            nombre += direcciones[i][k];
        }
        int cont = 0;
        relacion _relacion;
        _relacion.setNombre( nombre );
        while( RELACIONES_TXT >> linea ){
            tupla _tupla;
            string token = "";
            for (size_t j = 0; j < linea.size(); j++){
                if( linea[j] != ';' ) token += linea[j];
                else{
                    if( !cont ) _relacion.setEncabezado( token );
                    else{
                        if( j == 4 ){
                            _tupla.setID( stoi(token));
                        }else{
                            _tupla.setAtributo( token );
                        }
                    }
                    token = "";
                } 
            }
            if( cont ){ 
                _relacion.setTupla( _tupla );
            }
            cont++;
        }
        relaciones.push_back( _relacion );
    }
    return relaciones;
}
