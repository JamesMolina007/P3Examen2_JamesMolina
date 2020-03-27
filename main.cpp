#include <iostream>
#include <string>
#include <vector>
#include "relacion.hpp"
#include "tupla.hpp"
#include "archivo.hpp"

using namespace std;
archivo _archivo;
vector<relacion> _relaciones;

void opciones();
void opcion1();
void opcion2();
void opcion3();

int main(){
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
    relacion _relacion;
    string nombre, encabezado;
    int respuesta;
    cout << endl << endl;
    cout << "******************Crear Relacion*****************";
    cout << "Ingrese el nombre de la relacion: ";
    cin >> nombre;
    _relacion.setNombre( nombre );
    do{
        cout << "Ingrese encabezado: ";
        cin >> encabezado;
        _relacion.setEncabezado( encabezado );
        cout << "Desea continuar[ No = 0 ]: ";
        cin >> respuesta;
    }while( respuesta );
    cout << "*************************************************";
    _relaciones.push_back( _relacion );
    _archivo.guardar( _relacion );
}