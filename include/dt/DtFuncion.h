#ifndef DTFUNCION_H
#define DTFUNCION_H
#include "DtFecha.h"
#include "DtHorario.h"

class DtFuncion
{
private:
    int id;
    DtFecha dia;
    DtHorario horario;

public:
    DtFuncion();
    DtFuncion(int, DtFecha, DtHorario);
    ~DtFuncion();

    // Getters
    int getId();
    DtFecha getDia();
    DtHorario getHorario();
};

#endif