
#include "ControladorCrearReserva.h"
#include "../dt/Utils.h"

ControladorCrearReserva *ControladorCrearReserva::instancia = nullptr;

ControladorCrearReserva *ControladorCrearReserva::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorCrearReserva();
    }
    return instancia;
}

ControladorCrearReserva::ControladorCrearReserva()
{
}

ControladorCrearReserva::~ControladorCrearReserva()
{
}

void ControladorCrearReserva::seleccionarPelicula(string titulo)
{
    pelicula = ManejadorPelicula::getInstancia()->buscarPelicula(titulo);
}

map<int, DtCine> ControladorCrearReserva::listarCines()
{
    if (!pelicula)
    {
        cancelarReserva();
        throw runtime_error("No se seleccionó ninguna película valida.");
    }
    return pelicula->listarCines();
}

map<int, DtFuncion> ControladorCrearReserva::listarFunciones(int idCine, DtFecha fechaActual)
{

    map<int, DtFuncion> resultado;

    // Obtiene todas las funciones para el cine dado
    auto funcionesAll = pelicula->listarFunciones(idCine);
    // Filtra por fecha >= fechaActual
    for (auto &pr : funcionesAll)
    {
        DtFuncion &dtF = pr.second;
        if (dtF.getDia().mayorIgualQueFecha(fechaActual))
        {
            resultado.insert(pr);
        }
    }
    if (resultado.empty())
    {
        throw runtime_error("No hay funciones disponibles para ese cine en fechas futuras.");
    }
    return resultado;
}

void ControladorCrearReserva::seleccionarFuncion(int idFuncion, int cantidadAsientos)
{
    Funcion *f = pelicula->obtenerFuncion(idFuncion);
    if (!f)
    {
        cancelarReserva();
        throw runtime_error("La función seleccionada no existe.");
    }
    this->funcion = pelicula->obtenerFuncion(idFuncion);
    this->cantAsientos = cantidadAsientos;
}

float ControladorCrearReserva::ingresarBanco(string nombreBanco)
{

    if (!funcion || cantAsientos <= 0)
    {
        cancelarReserva();
        throw runtime_error("Faltan datos para confirmar la reserva.");
    }

    Banco *b = ManejadorBanco::getInstancia()->obtenerBanco(nombreBanco);
    if (!b)
    {
        cancelarReserva();
        throw runtime_error("El banco no existe.");
    }

    this->pagoDebito = true;
    this->nombreBanco = nombreBanco;
    this->costoTotal = precioEntrada * cantAsientos;
    return costoTotal;
}

float ControladorCrearReserva::ingresarFinanciera(string nombreFinanciera)
{

    if (!funcion || cantAsientos <= 0)
    {
        cancelarReserva();
        throw runtime_error("Faltan datos para confirmar la reserva.");
    }

    Financiera *f = obtenerFinanciera(nombreFinanciera);
    if (!f)
    {
        cancelarReserva();
        throw runtime_error("La financiera no existe.");
    }

    this->pagoDebito = false;
    this->nombreFinanciera = nombreFinanciera;
    float precioBase = precioEntrada * cantAsientos;
    this->costoTotal = precioBase * (1 - f->getporcentajeDescuento());
    return this->costoTotal;
}

void ControladorCrearReserva::confirmarReserva()
{
    if (!funcion || !Sesion::getInstanciaSesion()->getUsuario())
    {
        cancelarReserva();
        throw runtime_error("Faltan datos para confirmar la reserva.");
    }

    Usuario *usrActivo = Sesion::getInstanciaSesion()->getUsuario();

    if (!usrActivo)
    {
        cancelarReserva();
        throw runtime_error("No hay un usuario activo.");
    }

    if (pagoDebito)
    {
        Banco *ban = ManejadorBanco::getInstancia()->obtenerBanco(nombreBanco);
        Debito *res = new Debito(this->costoTotal, cantAsientos, usrActivo, funcion, ban);
        funcion->agregarReserva(res);
    }
    else
    {
        Financiera *financiera = obtenerFinanciera(nombreFinanciera);
        Credito *res = new Credito(this->costoTotal, cantAsientos, usrActivo, funcion, financiera);
        funcion->agregarReserva(res);
    }
    // Limpia estado temporal
    cancelarReserva();
}

void ControladorCrearReserva::cancelarReserva()
{
    pelicula = nullptr;
    funcion = nullptr;
    cantAsientos = 0;
    pagoDebito = false;
    nombreBanco = "";
    nombreFinanciera = "";
}

// Getters

Pelicula *ControladorCrearReserva::getPelicula()
{
    return pelicula;
}

Funcion *ControladorCrearReserva::getFuncion()
{
    return funcion;
}

int ControladorCrearReserva::getCantAsientos()
{
    return cantAsientos;
}

string ControladorCrearReserva::getNombreBanco()
{
    return nombreBanco;
}

string ControladorCrearReserva::getNombreFinanciera()
{
    return nombreFinanciera;
}

bool ControladorCrearReserva::getPagoDebito()
{
    return pagoDebito;
}

// Setters

void ControladorCrearReserva::setPelicula(Pelicula *p)
{
    this->pelicula = p;
}

void ControladorCrearReserva::setFuncion(Funcion *f)
{
    this->funcion = f;
}

void ControladorCrearReserva::setCantAsientos(int cant)
{
    this->cantAsientos = cant;
}

void ControladorCrearReserva::setNombreBanco(string nombreB)
{
    this->nombreBanco = nombreB;
}

void ControladorCrearReserva::setNombreFinanciera(string nombreF)
{
    this->nombreFinanciera = nombreF;
}

void ControladorCrearReserva::setPagoDebito(bool valor)
{
    this->pagoDebito = valor;
}

set<string> ControladorCrearReserva::listarBancos()
{
    set<string> rtn;
    for (auto banco : ManejadorBanco::getInstancia()->obtenerBancos())
    {
        if (dynamic_cast<Banco *>(banco))
        {
            rtn.insert(banco->getNombre());
        }
    }
    return rtn;
}

set<string> ControladorCrearReserva::listarFinancieras()
{
    set<string> rtn;
    for (auto financiera : ManejadorBanco::getInstancia()->obtenerBancos())
    {
        if (dynamic_cast<Financiera *>(financiera))
        {
            rtn.insert(financiera->getNombre());
        }
    }
    return rtn;
}

Banco *ControladorCrearReserva::obtenerBanco(string nombre)
{
    return ManejadorBanco::getInstancia()->obtenerBanco(nombre);
}

Financiera *ControladorCrearReserva::obtenerFinanciera(string nombre)
{
    return dynamic_cast<Financiera *>(ManejadorBanco::getInstancia()->obtenerBanco(nombre));
}