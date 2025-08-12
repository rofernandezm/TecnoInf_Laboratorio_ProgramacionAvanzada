
#ifndef CONTROLADORCREARRESERVA_H
#define CONTROLADORCREARRESERVA_H

#include <string>
#include <map>
#include <memory>
#include "../dt/DtCine.h"
#include "../dt/DtPelicula.h"
#include "../dt/DtFuncion.h"
#include "../dt/DtFecha.h"
#include "../header/Pelicula.h"
#include "../header/Funcion.h"
#include "../header/Sesion.h"
#include "../header/Usuario.h"
#include "../header/ManejadorPelicula.h"
#include "../header/ManejadorCine.h"
#include "../header/ManejadorBanco.h"
#include "../header/Debito.h"
#include "../header/Credito.h"
#include "IControladorCrearReserva.h"
#include "ManejadorBanco.h"

using namespace std;

class ControladorCrearReserva : public IControladorCrearReserva
{
private:
    static ControladorCrearReserva *instancia;
    ControladorCrearReserva();
    ~ControladorCrearReserva();

    Pelicula *pelicula;
    Funcion *funcion;
    int cantAsientos;
    float costoTotal;
    string nombreBanco;
    string nombreFinanciera;
    bool pagoDebito;

public:
    static ControladorCrearReserva *getInstancia();

    // Getters
    Pelicula *getPelicula();
    Funcion *getFuncion();
    int getCantAsientos();
    string getNombreBanco();
    string getNombreFinanciera();
    bool getPagoDebito();

    // Setters
    void setPelicula(Pelicula *);
    void setFuncion(Funcion *);
    void setCantAsientos(int);
    void setNombreBanco(string);
    void setNombreFinanciera(string);
    void setPagoDebito(bool);

    // Operaciones del caso de uso
    void seleccionarPelicula(string titulo);
    map<int, DtCine> listarCines();
    map<int, DtFuncion> listarFunciones(int idCine, DtFecha fechaActual);
    void seleccionarFuncion(int idFuncion, int cantidadAsientos);
    float ingresarBanco(const string nombreBanco);
    float ingresarFinanciera(const string nombreFinanciera);
    void confirmarReserva();
    void cancelarReserva();
    set<string> listarBancos();
    set<string> listarFinancieras();
    Banco *obtenerBanco(string);
    Financiera *obtenerFinanciera(string);
};

#endif /* CONTROLADORCREARRESERVA_H */
