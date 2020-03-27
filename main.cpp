#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include "relacion.hpp"
#include "tupla.hpp"
#include "archivo.hpp"

using namespace std;

void opciones();
void opcion1();
void opcion2();
void opcion3();

archivo _archivo;
vector<relacion> _relaciones;

int main(){
    _relaciones = _archivo.cargar();
    opciones();
    return 0;
}

void opciones(){
    int opcion;
    do{
        cout << endl << endl;
        cout << "*********Menu*********" << endl;
        cout << "0- Salir" << endl;
        cout << "1- Crear Relacion" << endl;
        cout << "2- Ver Relaciones" << endl;
        cout << "3- Insertar Tupla" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;
        cout << "**********************" << endl;
        if( opcion == 1 )opcion1();
        if( opcion == 2 )opcion2();
        if( opcion == 3 )opcion3();
    }while( opcion );
}


void opcion1(){
    string nombre, encabezado;
    relacion _relacion;
    int respuesta;
    cout << endl << endl;
    cout << "******************Crear Relacion*****************" << endl;
    cout << "Ingrese el nombre de la relacion: ";
    cin >> nombre;
    _relacion.setNombre( nombre );
    do{
        cout << "Ingrese encabezado: ";
        cin >> encabezado;
        _relacion.setEncabezado( encabezado );
        cout << "Desea continuar[ Si = 1 / No = 0 ]: ";
        cin >> respuesta;
    }while( respuesta );
    cout << "*************************************************" << endl;
    _relaciones.push_back( _relacion );
    _archivo.guardar( _relacion );
}

void listar( relacion _relacion ){
    vector< string > encabezados = _relacion.getEncabezados();
    vector< tupla > tuplas = _relacion.getTuplas();
    printf( "%-12s", "ID" );
    for (size_t i = 0; i < encabezados.size(); i++){
        printf( "%-12s", encabezados[i].c_str() );
    }
    for (size_t i = 0; i < tuplas.size(); i++){
        cout  << endl;
        printf( "%-12s", to_string(tuplas[i].getID()).c_str() );
        vector< string > atributos = tuplas[i].getAtributos();
        for (size_t j = 0; j < encabezados.size(); j++){
            printf( "%-12s", atributos[j].c_str() );
        }
    }
    cout << endl;
}

void opcion2(){
    int numero_relacion;
    cout << endl << endl;
    cout << "******************Ver Relaciones****************" << endl;
    for (size_t i = 0; i < _relaciones.size(); i++){
        cout << i << "- " << _relaciones[i].getNombre() << endl;
    }
    cout << "Ingrese el numero de relacion que desea ver: ";
    cin >> numero_relacion;
    if( numero_relacion < _relaciones.size() && numero_relacion >= 0 )
        listar( _relaciones[numero_relacion] );
    else cout << "No existe ese numero de relacion!" << endl;
    cout << "************************************************" << endl;
}

void agregarTupla( relacion _relacion, int posicion ){
    string atributo;
    tupla _tupla;
    _tupla.setID();
    for (size_t i = 0; i < _relacion.getEncabezados().size(); i++){
        cout << "Ingrese -> " << _relacion.getEncabezados()[i]<< ": ";
        cin >> atributo;
        _tupla.setAtributo( atributo );
    }
    _relaciones[ posicion ].setTupla( _tupla );
    cout << endl;
    _archivo.guardar( _relaciones[ posicion ] );
}

void opcion3(){
    int numero_relacion;
    cout << endl << endl;
    cout << "******************Insertar Tupla****************" << endl;
    for (size_t i = 0; i < _relaciones.size(); i++){
        cout << i << "- " << _relaciones[i].getNombre() << endl;
    }
    cout << "Ingrese el numero de relacion al que desea agregar una tupla: ";
    cin >> numero_relacion;
    if( numero_relacion < _relaciones.size() && numero_relacion >= 0 )
        agregarTupla( _relaciones[numero_relacion], numero_relacion );
    else cout << "No existe ese numero de relacion!" << endl;
    cout << "************************************************" << endl;
}