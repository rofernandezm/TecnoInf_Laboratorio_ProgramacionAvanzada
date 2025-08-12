#ifndef DTFECHA_H
#define DTFECHA_H
#include <ctime>
#include <string>

using namespace std;

class DtFecha
{
private:
    int dia;
    int mes;
    int anio;
    string hora;

public:
    DtFecha();
    DtFecha(int, int, int);
    ~DtFecha();

    // Getters
    int getDia();
    int getMes();
    int getAnio();
    string getHora();

    string toString();
    string toStringWithHour();
    bool menorIgualQueFecha(DtFecha);
    bool mayorIgualQueFecha(DtFecha); // Util para comparacion ejemplo, reservas >= a la fecha actual (Caso de uso)
    bool esIgual(DtFecha fecha);
};

#endif