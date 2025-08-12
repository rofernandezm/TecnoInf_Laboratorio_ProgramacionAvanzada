#ifndef DTDIRECCION_H
#define DTDIRECCION_H
#include <string>
#include <sstream>

using namespace std;

class DtDireccion
{
private:
    int numero;
    string calle;

public:
    DtDireccion();
    DtDireccion(int, string);
    ~DtDireccion();

    //Getters
    int getNumero();
    string getCalle();
    string toString();
};

#endif
