#include "tupla.hpp"

tupla::tupla(){}

void tupla::setAtributo( string atributo ){
    atributos.push_back( atributo );
}

void tupla::setAtributos( vector<string> atributos ){
    this->atributos = atributos;
}

void tupla::setID( int ID ){
    this->ID = ID;
}

int tupla::getID(){
    return ID;
}

vector<string> tupla::getAtributos(){
    return atributos;
}