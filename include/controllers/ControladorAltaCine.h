
#ifndef CONTROLADORALTACINE_H
#define CONTROLADORALTACINE_H

#include <map>
#include <string>
#include <memory>
#include "DtDireccion.h"
#include "DtSala.h"
#include "IControladorAltaCine.h"

using namespace std;

class ControladorAltaCine : public IControladorAltaCine
{
private:
    static ControladorAltaCine* instancia;
    ControladorAltaCine();
    ~ControladorAltaCine();

    DtDireccion direccion;
    map<int, DtSala> salas; // Arreglo temporal ya que el usuario puede confirmar o no el alta de cine. En el lugar de crear la clase, se crea Dt's
    int idDtSala = -1;

public:
    static ControladorAltaCine *getInstancia();

    // Controller
    void ingresoDirCine(DtDireccion);
    void ingresarSala(int);
    void crearCine();
    void cancelarAlta();
    void cancelarCU();
    void cargarDatos();
};

#endif /* CONTROLADORALTACINE_H */
