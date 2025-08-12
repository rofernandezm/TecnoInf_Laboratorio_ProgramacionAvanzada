#ifndef DTPUNTAJE_H
#define DTPUNTAJE_H

class DtPuntaje
{
private:
    int puntaje;
    bool usuarioPuntuo;

public:
    DtPuntaje(int, bool);
    ~DtPuntaje();

    // Getters
    int getPuntaje();
    bool yaPuntuo();
};

#endif