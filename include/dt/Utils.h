#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <random>
#include "Banco.h"

using namespace std;

enum TipoUsuario
{
    ADMIN,
    BASICO
};

// enum Financiera {
//     CREDITEL,
//     PRONTO,
//     OCA
// };

// enum Banco {
//     SANTANDER,
//     ITAU,
//     BROU,
//     BBVA
// };

const int precioEntrada = 300;

enum TipoReserva
{
    CREDITO,
    DEBITO
};

int getRandomInRange(int min, int max);

#endif