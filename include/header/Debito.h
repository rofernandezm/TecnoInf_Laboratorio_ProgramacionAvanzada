#ifndef DEBITO_H
#define DEBITO_H

#include <memory>
#include <string>
#include "Banco.h"
#include "Reserva.h"

using namespace std;

class Debito : public Reserva
{
private:
    Banco *banco;

public:
    Debito();
    Debito(float costo, int cantEntradas, Usuario *usuario, Funcion *funcion, Banco *banco);
    ~Debito();

    // Getters
    Banco *getBanco();

    // Setters
    void setBanco(Banco *banco);

    // Others
    string getNombre();
    TipoReserva getTipoReserva();
};

#endif
