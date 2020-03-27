#pragma once
#include <vector>
#include <string>

using namespace std;

class tupla{
    private:
        int ID;
        vector<string> atributos;
    public:
        tupla();
        int getID();
        void setID(  );
        void setID( int );
        void setAtributo( string );
        void setAtributos( vector<string> );
        vector<string> getAtributos();
};