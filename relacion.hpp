#pragma once

#include <vector>
#include <string>
#include "tupla.hpp"

using namespace std;

class relacion{
    private:
        vector<string> encabezados;
        vector<tupla> tuplas;
        string nombre;
    public:
        relacion();
        relacion( string );
        void setEncabezado( string );
        void setEncabezados( vector<string> );
        void setTupla( tupla );
        void setTuplas( vector<tupla> );
        void setNombre( string );
        string getNombre();
        vector<string> getEncabezados();
        vector<tupla> getTuplas();
};