#include "ControladorReloj.h"

ControladorReloj *ControladorReloj::instancia = nullptr;

ControladorReloj *ControladorReloj::getInstancia()
{
    if (!instancia)
    {
        instancia = new ControladorReloj();
    }
    return instancia;
}

ControladorReloj::ControladorReloj() {
    this->dtFecha = DtFecha();
    this->hora = this->dtFecha.getHora();
}

ControladorReloj::~ControladorReloj() {}

// Getters
DtFecha ControladorReloj::getDtFecha()
{
    return this->dtFecha;
}
string ControladorReloj::getHora()
{
    return this->hora;
}

// Setter
void ControladorReloj::setDtFecha(DtFecha dtFecha)
{
    this->dtFecha = dtFecha;
}
void ControladorReloj::setHora(string hora)
{
    this->hora = hora;
}

// Others
void ControladorReloj::modificarFechaSistema(string nuevaFecha)
{

    bool len = nuevaFecha.length() == 16;
    bool slash = nuevaFecha[2] == '/' && nuevaFecha[5] == '/';
    bool spaceAndPeriod = nuevaFecha[10] == ' ' && nuevaFecha[13] == ':';

    if (!len && !slash && !spaceAndPeriod)
    {
        throw invalid_argument("\n#### [ERROR] - Formato inválido. Use dd/mm/aaaa hh:mm ####\n");
    }

    int dia = stoi(nuevaFecha.substr(0, 2));
    int mes = stoi(nuevaFecha.substr(3, 2));
    int anio = stoi(nuevaFecha.substr(6, 4));

    this->dtFecha = DtFecha(dia, mes, anio);
    this->hora = nuevaFecha.substr(11, 5);
}

void ControladorReloj::consultarFechaSiestema()
{
    cout << "\n#### [INFO] - Fecha del sistema: " << "[" << this->dtFecha.toString() << " " << this->hora << "] ####" << endl;
}