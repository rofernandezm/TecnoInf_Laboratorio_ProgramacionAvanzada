#include "DtFecha.h"
#include <sstream>
#include <iomanip>

string getHoraActual(tm *localTime)
{
    if (!localTime)
    {
        time_t t = time(NULL);
        localTime = localtime(&t);
    }
    int hora = localTime->tm_hour;
    int minuto = localTime->tm_min;
    return (hora < 10 ? "0" : "") + to_string(hora) + ":" + (minuto < 10 ? "0" : "") + to_string(minuto);
}
DtFecha::DtFecha()
{
    time_t t = time(NULL);
    tm *now = localtime(&t);
    this->dia = now->tm_mday;
    this->mes = now->tm_mon + 1;
    this->anio = now->tm_year + 1900;
    this->hora = getHoraActual(now);
}
DtFecha::DtFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio)
{
    this->hora = getHoraActual(nullptr);
}
DtFecha::~DtFecha() {}

// Getters
int DtFecha::getDia()
{
    return this->dia;
}
int DtFecha::getMes()
{
    return this->mes;
}
int DtFecha::getAnio()
{
    return this->anio;
}

string DtFecha::getHora()
{
    return (this->hora.empty()) ? getHoraActual(nullptr) : this->hora;
}

string DtFecha::toStringWithHour()
{
    return this->toString() + " " + this->getHora();
}

bool DtFecha::menorIgualQueFecha(DtFecha fecha)
{
    if (this->anio < fecha.getAnio())
        return true;
    if (this->anio > fecha.getAnio())
        return false;

    if (this->mes < fecha.getMes())
        return true;
    if (this->mes > fecha.getMes())
        return false;

    return this->dia <= fecha.getDia();
}

// Util para comparacion ejemplo, reservas >= a la fecha actual (Caso de uso)
bool DtFecha::mayorIgualQueFecha(DtFecha fecha)
{

    if (this->anio > fecha.getAnio())
        return true;
    if (this->anio < fecha.getAnio())
        return false;

    if (this->mes > fecha.getMes())
        return true;
    if (this->mes < fecha.getMes())
        return false;

    return this->dia >= fecha.getDia();
}

string DtFecha::toString()
{
    ostringstream oss;
    oss << (dia < 10 ? "0" : "") << dia << "/"
        << (mes < 10 ? "0" : "") << mes << "/"
        << anio;
    return oss.str();
}

bool DtFecha::esIgual(DtFecha fecha)
{
    return this->dia == fecha.getDia() && this->mes == fecha.getMes() && this->anio == fecha.getAnio();
}