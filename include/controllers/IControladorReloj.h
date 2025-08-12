#ifndef ICONTROLADORRELOJ_H
#define ICONTROLADORRELOJ_H

#include <string>
#include "DtFecha.h" 

using namespace std;

class IControladorReloj
{
public:
    virtual ~IControladorReloj() {};
    virtual void modificarFechaSistema(string) = 0;
    virtual void consultarFechaSiestema() = 0;
    virtual DtFecha getDtFecha() = 0;
};
#endif