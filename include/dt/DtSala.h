#ifndef DTSALA_H
#define DTSALA_H

#include <string>

using namespace std;

class DtSala
{
private:
    int id;
    int capacidad;

public:
    DtSala();
    DtSala(int id, int capacidad);
    ~DtSala();

    // Getters
    int getId();
    int getCapacidad();
    
    string toString();
};

#endif