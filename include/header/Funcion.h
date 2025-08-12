
#ifndef FUNCION_H
#define FUNCION_H

#include <memory>
#include "DtSala.h"
#include "DtFecha.h"
#include "Reserva.h"
#include "DtFuncion.h"
#include "DtHorario.h"

using namespace std;
class Sala;
class Reserva;
class Funcion
{
private:
    int id;
    DtFecha dia;
    DtHorario horario;
    Sala *sala;
    set<Reserva*> reservas;

public:
    Funcion();
    Funcion(DtFecha, DtHorario, Sala *);
    ~Funcion();

    // Getters
    int getId();
    DtFecha getDia();
    DtHorario getHorario();
    Sala *getSala();

    // Setters
    void setDia(DtFecha);
    void setHorario(DtHorario);
    void setSala(Sala *);

    // Others
    DtSala obtenerSala();
    DtFuncion obtenerFuncion();
    void eliminarReservas();
    set<Reserva*> obtenerReservas(); //FALTA IMPLEMENTAR

    void agregarReserva(Reserva* reserva);
    bool tieneReservas();
};

#endif
