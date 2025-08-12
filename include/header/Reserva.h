#ifndef RESERVA_H
#define RESERVA_H

using namespace std;

#include <memory>
#include <Usuario.h>
#include <Funcion.h>
#include "Utils.h"

class Funcion;
class Reserva
{
private:
    float costo;
    int cantEntradas;
    Usuario *usuario;
    Funcion *funcion;

public:
    Reserva();
    Reserva(float, int, Usuario*, Funcion*);
    virtual ~Reserva();

    // Getters
    float getCosto();
    int getCantEntradas();
    Usuario* getUsuario();
    Funcion* getFuncion();

    // Setters
    void setCosto(float);
    void setCantEntradas(int);
    void setUsuario(Usuario*);
    void setFuncion(Funcion*);

    // Others
    virtual string getNombre() = 0;
    virtual TipoReserva getTipoReserva() = 0;
};

#endif /* RESERVA_H */