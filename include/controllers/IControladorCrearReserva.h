#ifndef ICONTROLADORCREARRESERVA_H
#define ICONTROLADORCREARRESERVA_H

#include <map>
#include <string>
#include "DtCine.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "Banco.h"
#include "Financiera.h"

using namespace std;

class IControladorCrearReserva
{
public:
    virtual ~IControladorCrearReserva() {}
    virtual void seleccionarPelicula(string titulo) = 0;
    virtual map<int, DtCine> listarCines() = 0;
    virtual map<int, DtFuncion> listarFunciones(int idCine, DtFecha fechaActual) = 0;
    virtual void seleccionarFuncion(int idFuncion, int cantidadAsientos) = 0;
    virtual float ingresarBanco(const string nombreBanco) = 0;
    virtual float ingresarFinanciera(const string nombreFinanciera) = 0;
    virtual void confirmarReserva() = 0;
    virtual void cancelarReserva() = 0;
    virtual set<string> listarBancos() = 0;
    virtual Banco *obtenerBanco(string nombre) = 0;
    virtual set<string> listarFinancieras() = 0;
    virtual Financiera *obtenerFinanciera(string) = 0;
};

#endif
