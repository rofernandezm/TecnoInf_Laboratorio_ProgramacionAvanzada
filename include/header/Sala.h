#ifndef SALA_H
#define SALA_H
#include <memory>
#include <set>
#include "DtSala.h"
#include "Funcion.h"

class Cine;

class Sala
{
private:
    int id;
    int capacidad;
    Cine* cine; // Se agrega bidireccional con cine por colaboracion CrearReserva
    // set<unique_ptr<Funcion>> funciones;
public:
    Sala(int, int);
    Sala(DtSala);
    ~Sala();

    // Getters
    int getId();
    int getCapacidad();
    Cine *getCine();

    // Setters
    void setId(int);
    void setCapacidad(int);
    void setCine(Cine *);

    // Other methods
    DtSala obtenerDtSala();
    bool proyectaEnCine(int idCine);
    void agregarFuncion(unique_ptr<Funcion>);
};

#endif /* SALA_H */