#ifndef CONTROLADORRELOJ_H
#define CONTROLADORRELOJ_H

#include <string>
#include <iostream>
#include "IControladorReloj.h"
#include "DtFecha.h"

using namespace std;

class ControladorReloj : public IControladorReloj
{
private:
    static ControladorReloj *instancia;
    ControladorReloj();

    DtFecha dtFecha;
    string hora;

public:
    static ControladorReloj *getInstancia();
    ~ControladorReloj();

    // Getters
    DtFecha getDtFecha();
    string getHora();

    // Setter
    void setDtFecha(DtFecha);
    void setHora(string);

    // Others
    void modificarFechaSistema(string);
    void consultarFechaSiestema();
};

#endif