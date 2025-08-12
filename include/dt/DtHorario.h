#ifndef DTHORARIO_H
#define DTHORARIO_H
#include <string>

using namespace std;

class DtHorario
{
private:
    string horaComienzo;
    string horaFin;

public:
    DtHorario();
    DtHorario(string, string);
    ~DtHorario();

    //Getters
    string getHoraComienzo();
    string getHoraFin();
    
    string toString();
};

#endif