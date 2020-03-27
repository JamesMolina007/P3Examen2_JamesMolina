#include "relacion.hpp"

relacion::relacion(){}

relacion::relacion( string nombre ){
    this->nombre = nombre;
}

void relacion::setEncabezado( string encabezado ){
    encabezados.push_back( encabezado );
}

void relacion::setEncabezados( vector<string> encabezados ){
    this->encabezados = encabezados;
}

void relacion::setTupla( tupla _tupla ){
    tuplas.push_back( _tupla );
}

void relacion::setTuplas( vector<tupla> tuplas ){
    this->tuplas = tuplas;
}

void relacion::setNombre( string nombre ){
    this->nombre = nombre;
}

string relacion::getNombre(){
    return nombre;
}

vector<string> relacion::getEncabezados(){
    return encabezados;
}

vector<tupla> relacion::getTuplas(){
    return tuplas;
}