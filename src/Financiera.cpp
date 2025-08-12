#include "Financiera.h"

Financiera::Financiera() : Banco(), porcentajeDescuento(0.0f) {}

Financiera::Financiera(string nombre, float porcentajeDescuento) : Banco(nombre), porcentajeDescuento(porcentajeDescuento) {}

Financiera::~Financiera() {}

float Financiera::getporcentajeDescuento()
{
    return this->porcentajeDescuento;
}

void Financiera::setPorcentajeDescuento(float porcentaje)
{
    this->porcentajeDescuento = porcentaje;
}
