#pragma once
#include "tupla.hpp"
#include "relacion.hpp"

class archivo{
    public:
        archivo();
        void guardar( relacion _relacion );
        vector<relacion> cargar();
};