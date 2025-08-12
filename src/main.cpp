/*
    GRUPO 3
    Laboratorio de PAv 2025
    UTU - LATU - Turno Nocturno
    Profesor Carlos Fidalgo
 */

// #include "ManejadorBanco.h"
#include <termios.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <locale>
#include <vector>
#include <thread>
#include <chrono>
#include "Fabrica.h"
#include "UiMessages.h"
// #include "ControladorReloj.h"

using namespace std;

Fabrica *f;
IControladorSesion *iConSesion;
IControladorAltaUsuario *iConAltaUsuario;
IControladorAltaPelicula *iConAltaPelicula;
IControladorAltaCine *iConAltaCine;
IControladorAltaFuncion *iConAltaFuncion;
IControladorPuntuarPelicula *iConPuntuarPelicula;
IControladorComentarioPelicula *iConComentarioPelicula;
IControladorVerReservaPelicula *iConVerReservaPelicula;
IControladorVerInformacionPelicula *iConVerInformacionPelicula;
IControladorCrearReserva *iConCrearReserva;
IControladorReloj *iControladorReloj;
IControladorEliminarPelicula *iConEliminarPelicula;
IControladorVerComentariosPuntajes *iConVerComentariosPuntajes;

int soloUnaVez = 0;
void menu();
void limpiarPantalla();
void exitMessage();
string obtenerTextoConEspacios();
void cargaDeDatos();
void barraDeCarga(int seg);
void imprimirPeliculasSinopsisPoster(map<std::string, DtPelicula> peliculas);
void imprimirCines(map<int, DtCine> cines);

// 1 - INICIAR SESION
void iniciarSesion();
void menuCancelar_CU1();
bool ingresarContra_CU1();

// 2 - CERRAR SESION
void cerrarSesion();

// 3 - ALTA USUARIO (SOLO ADMIN)
void altaUsuario();
bool obtenerNombreUsuario_CU3();
void obtenerPass_CU3();
void menuFotoPerfil_CU3();
void obtenerUrlFotoPerfil_CU3();
void menuCancelar_CU3();

// 4 - ALTA PELICULA
void altaPelicula();
bool ingresoTitulo_CU4();
void ingresoSinopsis_CU4();
void ingresoPoster_CU4();
void cancelarCU_CU4();

// 5 - ALTA CINE
void menuContinuarIngresandoCines();
void menuContinuarIngresandoSalas();
void menuConfirmaAlta();
void ingresoDeSalas();
void ingresarDirCine();
void altaDeCine();

// 6 - ALTA FUNCION
void altaFuncion();
void listarPeliculas_CU6();
void elegirPelicula_CU6();
void elegirCine_CU5();
void elegirSala_CU5();
void confirmarAlta_CU5();

// 8 - VER RESERVAS DE PELICULA
void verReservasDePelicula();
void listarPeliculas_CU8();
void seleccionaPelicula_CU8();
void listarFuncionesConReserva_CU8();

// 7 - CREAR RESERVA
void crearReserva();
bool listarPeliculas_CU7();
void seleccionarPelicula_CU7();
void listarCines_CU7();
// void seleccionarCine_CU7();
void listarFunciones_CU7();
void seleccionarFuncion_CU7();
void menuSeleccionarMetodoPago_CU7();
void seleccionarModoPago_CU7();
void confirmarReserva_CU7();

// 9 - ELIMINAR PELICULA
void eliminarPelicula();

// 10 - PUNTUAR PELICULA
void puntuarPelicula();
// void listarPeliculas_CU10();
// void seleccionarPelicula_CU10();
// void ingresarPuntaje_CU10();

// 11 - COMENTAR PELICULA
void menuComentarPelicula();
void comentarPelicula();
void listarPeliculas_CU11();
void seleccionaPelicula_CU11();
void seleccionarComentario_CU11();
void ingresarComentario_CU11();

// 12 - VER INFORMACION DE PELICULA
void verInformacionPelicula();
// void listarFunciones_CU12();

// 13 - VER COMENTARIOS Y PUNTAJES DE PELICULA
void verComentariosYPuntajes();

// CONFIGURAR RELOJ
void configurarReloj();
void modificarFecha();
void consultarFecha();
void menuReloj();

int main()
{
    setlocale(LC_ALL, ""); // Configuracion linux UTF-8

    f = Fabrica::getInstancia();
    iConSesion = f->getIControladorSesion();
    iConAltaUsuario = f->getIControladorAltaUsuario();
    iConAltaPelicula = f->getIControladorAltaPelicula();
    iConAltaCine = f->getIControladorAltaCine();
    iConAltaFuncion = f->getIControladorAltaFuncion();
    iConPuntuarPelicula = f->getIControladorPuntuarPelicula();
    iConComentarioPelicula = f->getIControladorComentarioPelicula();
    iConVerReservaPelicula = f->getIControladorVerReservaPelicula();
    iConVerInformacionPelicula = f->getIControladorVerInformacionPelicula();
    iConCrearReserva = f->getIControladorCrearReserva();
    iControladorReloj = f->getIControladorReloj();
    iConEliminarPelicula = f->getIControladorEliminarPelicula();
    iConVerComentariosPuntajes = f->getIControladorVerComentariosPuntajes();

    bool salir = false;

    while (!salir)
    {
        int opcion;
        system("clear");
        menu();
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ;
        cout << endl;

        switch (opcion)
        {
        case 1:
            limpiarPantalla();
            iniciarSesion();
            limpiarPantalla();
            break;

        case 2:
            limpiarPantalla();
            cerrarSesion();
            limpiarPantalla();
            break;

        case 3:
            limpiarPantalla();
            altaUsuario();
            limpiarPantalla();
            break;

        case 4:
            limpiarPantalla();
            altaPelicula();
            limpiarPantalla();
            break;

        case 5: // ALTA DE CINE
            limpiarPantalla();
            altaDeCine();
            limpiarPantalla();
            break;

        case 6:
            limpiarPantalla();
            altaFuncion();
            limpiarPantalla();
            break;

        case 7:
            limpiarPantalla();
            crearReserva();
            limpiarPantalla();
            break;

        case 8:
            limpiarPantalla();
            verReservasDePelicula();
            limpiarPantalla();
            break;

        case 9: // ELIMINAR PELICULA
            limpiarPantalla();
            eliminarPelicula();
            limpiarPantalla();
            break;

        case 10: // PUNTUAR PELICULA
            limpiarPantalla();
            puntuarPelicula();
            limpiarPantalla();
            break;

        case 11: // COMENTAR
            limpiarPantalla();
            comentarPelicula();
            limpiarPantalla();
            break;

        case 12: // VER INFORMACION DE PELICULA
            limpiarPantalla();
            verInformacionPelicula();
            limpiarPantalla();
            break;

        case 13: // VER COMENTARIOS Y PUNTAJES DE PELICULA
            limpiarPantalla();
            verComentariosYPuntajes();
            break;

        case 14:
            limpiarPantalla();
            configurarReloj();
            limpiarPantalla();
            break;

        case 15:
            if (soloUnaVez == 0)
            {
                cargaDeDatos();
                limpiarPantalla();
                // iniciarSesion();
                limpiarPantalla();
                soloUnaVez = 1;
            }
            else
            {
                limpiarPantalla();
                cout << "\n#### [ERROR] - Los datos ya fueron cargados. No es posible cargar datos mas de una vez. ####\n"
                     << endl;
                sleep(2);
            }
            break;
        case 0:
            limpiarPantalla();
            cout << "#### Saliendo del sistema ####" << endl;
            barraDeCarga(2);
            salir = true;
            limpiarPantalla();
            cout << "#### ¡Vuelva prontos! ####\n"
                 << endl;
            exitMessage();
            break;

        default:
            limpiarPantalla();
            cout << INVALID_OPTION << endl;
            break;
        }
    }
    limpiarPantalla();
    return 0;
}

void menu()
{
    cout << "\n#### Bienvenido - TecninfCinemas ####\n"
         << endl;
    cout << "Elija una opcion:" << endl;
    cout << "1. Iniciar sesion" << endl;
    cout << "2. Cerrar sesion" << endl;
    cout << "3. Alta de usuario" << endl;
    cout << "4. Alta de pelicula" << endl;
    cout << "5. Alta de cine" << endl;
    cout << "6. Alta de funcion" << endl;
    cout << "7. Crear reserva" << endl;
    cout << "8. Ver reservas de pelicula" << endl;
    cout << "9. Eliminar pelicula" << endl;
    cout << "10. Puntuar pelicula" << endl;
    cout << "11. Comentar pelicula" << endl;
    cout << "12. Ver informacion de pelicula" << endl;
    cout << "13. Ver comentarios y puntajes de pelicula" << endl;
    cout << "14. Fecha del sistema" << endl;
    cout << "15. Carga de datos" << endl;
    cout << "-------------------" << endl;
    cout << "0. Salir" << endl;
    cout << endl;
    cout << "Ingrese el numero de la opcion: ";
}

// Method from lab_1
string obtenerTextoConEspacios()
{
    string rtn;
    getline(cin, rtn);
    return rtn;
}
string leerPasswords()
{
    string pass;
    cout << "Contraseña: ";
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);

    // Crear copia y desactivar echo
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;

    // Aplicar nueva configuración (sin echo)
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    pass = obtenerTextoConEspacios();

    // Restaurar configuración original
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return pass;
}
DtFecha obtenerFecha(string fecha)
{
    bool len = fecha.length() == 16;
    bool slash = fecha[2] == '/' && fecha[5] == '/';
    bool spaceAndPeriod = fecha[10] == ' ' && fecha[13] == ':';

    if (!len && !slash && !spaceAndPeriod)
    {
        throw invalid_argument("\n#### [ERROR] - Formato inválido. Use dd/mm/aaaa ####\n");
    }

    // hh:mm
    int dia = stoi(fecha.substr(0, 2));
    int mes = stoi(fecha.substr(3, 2));
    int anio = stoi(fecha.substr(6, 4));

    return DtFecha(dia, mes, anio);
}
void limpiarPantalla()
{
    sleep(1);
    system("clear");
    fflush(stdout);
}

void imprimirPeliculasSinopsisPoster(map<string, DtPelicula> peliculas)
{
    if (!peliculas.empty())
    {
        cout << TITLE_MOVIE_CATALOG << endl;
    }
    for (auto &p : peliculas)
    {
        cout << "Titulo: " << p.second.getTitulo() << endl;
        cout << "├── Sinopsis: \"" << p.second.getSinopsis() << "\"" << endl;
        cout << "└── Poster: " << p.second.getPoster() << endl;
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}
void imprimirCines(map<int, DtCine> cines)
{
    if (!cines.empty())
    {
        cout << TITLE_CINEMAS_LIST << endl;
    }
    for (auto &c : cines)
    {
        cout << "ID Cine: " << c.first << endl;
        cout << "└── Dirección: " << c.second.getDireccion().toString() << endl;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
    cout << endl;
}
void imprimirSalas(map<int, DtSala> salas)
{
    for (auto &sp : salas)
    {
        cout << "Nro de sala: " << sp.second.getId() << endl;
        cout << "└── Capacidad de sala: " << sp.second.getCapacidad() << endl;
    }
    cout << endl;
}

// RELOJ
void modificarFecha()
{
    limpiarPantalla();
    cout << "\n##### MODIFICAR FECHA DEL SISTEMA #####\n"
         << endl;
    cout << "Ingrese la fecha utilizando el siguiente formato: 'dd/mm/aaaa hh:mm'" << endl;
    string fecha = obtenerTextoConEspacios();
    iControladorReloj->modificarFechaSistema(fecha);
    consultarFecha();
}
void consultarFecha()
{
    limpiarPantalla();
    iControladorReloj->consultarFechaSiestema();
    sleep(2);
}
void menuReloj()
{
    limpiarPantalla();
    cout << "\n##### FECHA DEL SISTEMA #####\n"
         << endl;
    cout << "¿Que operacion desea realizar?:" << endl;
    cout << "1. Modificar" << endl;
    cout << "2. Consultar" << endl;
    cout << "\nIngrese el numero de la opcion: ";
}
void configurarReloj()
{

    int opt;
    do
    {
        menuReloj();
        cin >> opt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ;

        switch (opt)
        {
        case 1:
            try
            {
                modificarFecha();
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
                sleep(1);
                limpiarPantalla();
            }

            break;
        case 2:
            consultarFecha();
            break;
        default:
            cout << INVALID_OPTION << endl;
            break;
        }
    } while (opt != 1 && opt != 2);
}

// 1 - INICIAR SESION
void menuCancelar_CU1()
{
    limpiarPantalla();
    cout << "Desea cancelar ingreso de sesion:" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese el numero de la opcion: ";
}
bool ingresarContra_CU1()
{
    string pass = leerPasswords();
    return iConSesion->ingresoContrasenia(pass);
}
void iniciarSesion()
{
    // Control sesion iniciada
    if (!iConSesion->existeSesionIniciada())
    {
        try
        {
            string user;
            bool cancelaCu = false;
            int opt;
            cout << TITLE_SIGN_IN << endl;
            cout << "Nombre de usuario: ";
            user = obtenerTextoConEspacios();
            iConSesion->ingresoUsuario(user);
            bool passValida = ingresarContra_CU1();

            do
            {

                if (!passValida)
                {
                    cout << "\n#### [ERROR] - Contraseña invalida. ####\n"
                         << endl;
                    menuCancelar_CU1();
                    cin >> opt;
                    switch (opt)
                    {
                    case 1: // CancelaCU
                        iConSesion->cancelarCU();
                        cancelaCu = true;
                        break;

                    case 2: // Reingresa pass
                        limpiarPantalla();
                        cout << TITLE_SIGN_IN << endl;
                        passValida = ingresarContra_CU1();
                        break;

                    default:
                        cout << INVALID_OPTION << endl;
                        menuCancelar_CU1();
                        break;
                    }
                }

            } while (!passValida && !cancelaCu);

            if (passValida)
            {
                limpiarPantalla();
                iConSesion->iniciaSesion();
                limpiarPantalla();
            }
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
        }
    }
    else
    {
        cerr << "\n#### [ERROR] - Ya hay una sesión activa. Cerrala antes de iniciar sesión con otro usuario. ####\n"
             << endl;
        sleep(2);
    }
}

// 2 - CERRAR SESION
void cerrarSesion()
{
    try
    {
        iConSesion->cerrarSesion();
        cout << "\n#### [INFO] - Sesion cerrada correctamente. ####\n"
             << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

// 3 - ALTA USUARIO (SOLO ADMIN)
void altaUsuario()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (iConSesion->esUsuarioAdmin())
        {
            int opt;
            bool cancelaCu = false;
            bool usuarioDisponible = obtenerNombreUsuario_CU3();
            obtenerPass_CU3();
            obtenerUrlFotoPerfil_CU3();
            do
            {

                if (!usuarioDisponible)
                {
                    cout << "\n#### [ERROR] - Nombre de usuario no disponible. ####\n"
                         << endl;
                    menuCancelar_CU3();
                    cin >> opt;
                    switch (opt)
                    {
                    case 1: // CancelaCU
                        iConAltaUsuario->cancelarCU();
                        cancelaCu = true;
                        break;

                    case 2: // Reingresa usuario
                        limpiarPantalla();
                        usuarioDisponible = obtenerNombreUsuario_CU3();
                        break;

                    default:
                        cout << INVALID_OPTION << endl;
                        menuCancelar_CU3();
                        break;
                    }
                }

            } while (!usuarioDisponible && !cancelaCu);

            if (usuarioDisponible)
            {
                iConAltaUsuario->confirmarAlta();
                limpiarPantalla();
                cout << "\n#### [INFO] - Se ha creado el nuevo usuaro correctamente. ####\n"
                     << endl;
            }
        }
        else
        {
            cerr << ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED << endl;
            sleep(2);
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
    }
}
bool obtenerNombreUsuario_CU3()
{
    string user;
    cout << "Nombre de usuario: ";
    user = obtenerTextoConEspacios();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return iConAltaUsuario->ingresoUsuario(user);
}
void obtenerPass_CU3()
{
    string pass = leerPasswords();
    if (pass.empty())
    {
        do
        {
            cerr << "\n#### [ERROR] - La contraseña no puede estar vacia. ####\n"
                 << endl;
            sleep(2);
            limpiarPantalla();
            pass = leerPasswords();
        } while (pass.empty());
    }

    return iConAltaUsuario->ingresoContrasenia(pass);
}
void menuFotoPerfil_CU3()
{
    limpiarPantalla();
    cout << "¿Desea ingresar la URL de su foto de perfil?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese el numero de la opcion: ";
}
void obtenerUrlFotoPerfil_CU3()
{
    int opt;
    string msg = "Por favor, ingrese una URL válida de su foto de perfil: ";
    string url;
    do
    {
        limpiarPantalla();
        menuFotoPerfil_CU3();
        cin >> opt;

        // Si no desea ingresar, no entra a switch (Evita Case 2: vacio)
        if (opt != 2)
        {
            switch (opt)
            {
            case 1: // Ingresa foto

                cout << msg;
                cin >> url;

                if (url.empty())
                {
                    do
                    {
                        cerr << "\n#### [ERROR] - La url no puede estar vacia. ####\n"
                             << endl;
                        limpiarPantalla();
                        cout << msg;
                        cin >> url;
                    } while (url.empty());
                }

                iConAltaUsuario->ingresoFotoPerfil(url);
                break;

            default:
                cout << INVALID_OPTION << endl;
                menuFotoPerfil_CU3();
                break;
            }
        }

    } while (opt != 1 && opt != 2);
}
void menuCancelar_CU3()
{
    limpiarPantalla();
    cout << "Desea cancelar el alta de usuario:" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese el numero de la opcion: ";
}

// 4 - ALTA PELICULA
void altaPelicula()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (iConSesion->esUsuarioAdmin())
        {
            bool tituloExiste = true;
            char cont = 'y';

            while (tituloExiste && (cont == 'y' || cont == 'Y'))
            {
                tituloExiste = ingresoTitulo_CU4();
                if (tituloExiste)
                {
                    cout << "Error: Titulo ya existe. ¿Desea ingresar otro? (y/n).\n";
                    cin >> cont;
                }
                else
                {
                    ingresoSinopsis_CU4();
                    ingresoPoster_CU4();
                    iConAltaPelicula->altaPelicula();
                }
                if (cont != 'y' && cont != 'Y')
                {
                    cancelarCU_CU4();
                }
            }
        }
        else
        {
            cerr << ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED << endl;
            sleep(2);
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
    }
}
bool ingresoTitulo_CU4()
{
    bool existeTitulo = true;
    string nuevoTitulo;
    cout << "\nIngrese el nuevo titulo: ";
    nuevoTitulo = obtenerTextoConEspacios();
    existeTitulo = iConAltaPelicula->ingresoTitulo(nuevoTitulo);
    return existeTitulo;
}
void ingresoSinopsis_CU4()
{
    string sinopsis;
    cout << "\nIngrese una breve sinopsis: ";
    sinopsis = obtenerTextoConEspacios();
    iConAltaPelicula->ingresoSinopsis(sinopsis);
}
void ingresoPoster_CU4()
{
    string posterURL;
    cout << "\nIngrese el URL del poster: ";
    posterURL = obtenerTextoConEspacios();
    iConAltaPelicula->ingresoPoster(posterURL);
}
void cancelarCU_CU4()
{
    iConAltaPelicula->cancelarCU();
}

// 5 - ALTA CINE
void menuContinuarIngresandoCines()
{
    limpiarPantalla();
    cout << "¿Desea ingresar un nuevo cine?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese el numero de la opcion: ";
}
void ingresarDirCine()
{

    string dir;
    do
    {
        limpiarPantalla();
        cout << "Ingrese la dirección del nuevo cine: [Ejemplo: Av. Italia 6201]" << endl;
        dir = obtenerTextoConEspacios();
    } while (dir.empty());

    istringstream iss(dir);
    string palabra;
    string calle;
    int numero = -1;

    // Leer palabra por palabra
    while (iss >> palabra)
    {
        istringstream testInt(palabra);
        if (!(testInt >> numero && testInt.eof()))
        {
            if (!calle.empty())
                calle += " ";
            calle += palabra;
        }
    }

    if (numero <= 0)
    {
        numero = 0;
        calle += " s/n.";
    }

    iConAltaCine->ingresoDirCine(DtDireccion(numero, calle));
    limpiarPantalla();
}
void altaDeCine()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (iConSesion->esUsuarioAdmin())
        {

            int opt;
            bool cancelaCu = false, cancelaAlta = false;
            do
            {
                ingresarDirCine();
                ingresoDeSalas();
                do
                {
                    menuConfirmaAlta();
                    cin >> opt;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    switch (opt)
                    {
                    case 1:
                        iConAltaCine->crearCine();
                        limpiarPantalla();
                        cout << "\n#### [INFO] - El alta del cine ha sido realizada correctamente. ####\n"
                             << endl;
                        limpiarPantalla();
                        break;
                    case 2:
                        limpiarPantalla();
                        iConAltaCine->cancelarAlta();
                        cout << "\n#### [INFO] - El alta del cine ha sido cancelada correctamente. ####\n"
                             << endl;
                        cancelaAlta = true;
                        limpiarPantalla();
                        break;
                    default:
                        cout << INVALID_OPTION << endl;
                        break;
                    }
                } while (!cancelaAlta && opt != 1);

                if (!cancelaCu)
                {
                    do
                    {
                        menuContinuarIngresandoCines();
                        cin >> opt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if (opt != 1)
                        {
                            switch (opt)
                            {
                            case 2:
                                limpiarPantalla();
                                iConAltaCine->cancelarCU();
                                cancelaCu = true;
                                break;

                            default:
                                cout << INVALID_OPTION << endl;
                                break;
                            }
                        }

                    } while (!cancelaCu && opt != 1);
                }

            } while (!cancelaCu);
        }
        else
        {
            cerr << ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED << endl;
            sleep(2);
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
    }
}
void menuContinuarIngresandoSalas()
{
    limpiarPantalla();
    cout << "¿Desea ingresar mas salas?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese el numero de la opcion: ";
}
void menuConfirmaAlta()
{
    limpiarPantalla();
    cout << "¿Confirma el alta de cine?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Ingrese el numero de la opcion: ";
}
void ingresoDeSalas()
{
    bool ingresaSalas = true;
    do
    {
        int opt;
        limpiarPantalla();
        cout << "Ingrese la capacidad de la sala:" << endl;
        cin >> opt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        iConAltaCine->ingresarSala(opt);
        do
        {
            limpiarPantalla();
            menuContinuarIngresandoSalas();
            cin >> opt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (opt != 1)
            {
                switch (opt)
                {
                case 2:
                    ingresaSalas = false;
                    break;

                default:
                    cout << INVALID_OPTION << endl;
                    break;
                }
            }

        } while (opt != 1 && opt != 2);

    } while (ingresaSalas);
}

// 6 - ALTA FUNCION
void altaFuncion()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (iConSesion->esUsuarioAdmin())
        {
            char cont = 'y';
            try
            {
                listarPeliculas_CU6();
                elegirPelicula_CU6();
                while (cont == 'y' || cont == 'Y')
                {
                    elegirCine_CU5();
                    elegirSala_CU5();
                    confirmarAlta_CU5();
                    cout << "¿Desea seguir agregando funciones de esta pelicula? (y/n)";
                    cin >> cont;
                }
            }
            catch (const exception &e)
            {
                limpiarPantalla();
                cerr << e.what() << '\n';
                sleep(2);
                limpiarPantalla();
            }
        }
        else
        {
            cerr << ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED << endl;
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
    }
}
void listarPeliculas_CU6()
{
    auto peliculas = iConAltaFuncion->listarPeliculas();
    if (peliculas.empty())
    {
        throw invalid_argument("No hay peliculas registradas");
    }
    imprimirPeliculasSinopsisPoster(peliculas);
}
void elegirPelicula_CU6()
{
    string tituloElegido;
    cout << "\nElija el titulo que desea ver: \n";
    tituloElegido = obtenerTextoConEspacios();
    auto listadoCines = iConAltaFuncion->elegirPelicula(tituloElegido);
    if (listadoCines.empty())
    {
        throw invalid_argument("No se dispone de cines registrados");
    }
    limpiarPantalla();
    imprimirCines(listadoCines);
}
void elegirCine_CU5()
{
    int nroCine;
    cout << "Ingrese el numero del cine del que quiere dar un alta: ";
    cin >> nroCine;
    auto salasPelicula = iConAltaFuncion->elegirCine(nroCine); /// ERROR
    if (salasPelicula.empty())
    {

        throw invalid_argument("No hay salas registradas para esta pelicula");
    }
    limpiarPantalla();
    cout << "Salas en las que pasan la pelicula: " << endl;
    cout << endl;
    imprimirSalas(salasPelicula);
}
void elegirSala_CU5()
{
    int nroSala;
    string fecha, horaComienzo, horaFin;

    cout << "Ingrese la sala en la que quiere dar un alta: ";
    cin >> nroSala;
    limpiarPantalla();

    cout << "Ingrese la fecha para la funcion [dd/mm/aaaa]: ";
    cin.ignore();
    fecha = obtenerTextoConEspacios();
    cout << "Ingrese la hora que comienza [hh:mm]: ";
    cin >> horaComienzo;
    cout << "Ingrese la hora que termina [hh:mm]: ";
    cin >> horaFin;

    auto fechaPelicula = obtenerFecha(fecha);
    auto horarioPelicula = DtHorario(horaComienzo, horaFin);
    iConAltaFuncion->elegirSala(nroSala, fechaPelicula, horarioPelicula);
}
void confirmarAlta_CU5()
{
    iConAltaFuncion->confirmarAlta();
    cout << "Funcion agregada exitosamente\n";
}

// 8 - VER RESERVAS DE PELICULA
void verReservasDePelicula()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (iConSesion->esUsuarioAdmin())
        {
            try
            {
                listarPeliculas_CU8();
                seleccionaPelicula_CU8();
                listarFuncionesConReserva_CU8();
            }
            catch (const exception &e)
            {
                limpiarPantalla();
                cerr << e.what() << '\n';
                sleep(2);
                limpiarPantalla();
            }
        }
        else
        {
            cerr << ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED << endl;
            sleep(2);
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
    }
}
void listarPeliculas_CU8()
{
    auto peliculas = iConVerReservaPelicula->listarPeliculas();
    if (peliculas.empty())
    {
        throw invalid_argument("No hay peliculas registradas");
    }
    imprimirPeliculasSinopsisPoster(peliculas);
}
void seleccionaPelicula_CU8()
{
    string tituloElegido;
    cout << "Elija el titulo que desea ver\n";
    tituloElegido = obtenerTextoConEspacios();
    iConVerReservaPelicula->seleccionarPelicula(tituloElegido);
}
void listarFuncionesConReserva_CU8()
{
    auto reservas = iConVerReservaPelicula->listarFuncionesConReserva();
    for (const auto &r : reservas)
    {
        auto toPrint = r;
        cout << "Costo: " << toPrint.second->getCosto() << "\nEntradas vendidas: " << toPrint.second->getCantEntradas() << "\nTipo de reserva: " << toPrint.second->getTipoReserva();
    }
}

// 7 - CREAR RESERVA
void crearReserva()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (!iConSesion->esUsuarioAdmin())
        {
            try
            {
                listarPeliculas_CU7();
                seleccionarPelicula_CU7();
                listarCines_CU7();
                listarFunciones_CU7();
                seleccionarFuncion_CU7();
                seleccionarModoPago_CU7();
                confirmarReserva_CU7();
            }
            catch (const exception &e)
            {
                limpiarPantalla();
                cerr << e.what() << '\n';
                sleep(2);
                limpiarPantalla();
                iConCrearReserva->cancelarReserva();
            }
        }
        else
        {
            cerr << "\n#### [ERROR] - No permitido para usuario administrador. ####\n"
                 << endl;
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
    }
}

// Lista todas las películas disponibles
bool listarPeliculas_CU7()
{

    auto peliculas = iConVerReservaPelicula->listarPeliculas();
    imprimirPeliculasSinopsisPoster(peliculas);
    return peliculas.empty();
}

// Elige la película por ID
void seleccionarPelicula_CU7()
{
    string tituloElegido;
    cout << "Ingrese el titulo que desea ver: " << endl;
    tituloElegido = obtenerTextoConEspacios();

    iConCrearReserva->seleccionarPelicula(tituloElegido);
}

// Lista los cines que proyectan la película seleccionada
void listarCines_CU7()
{
    auto cines = iConCrearReserva->listarCines();
    imprimirCines(cines);
}

// Elije cine y Lista las funciones disponibles (fecha >= hoy)
void listarFunciones_CU7()
{

    int idCine;
    cout << "Ingrese ID del cine: ";
    cin >> idCine;

    DtFecha hoy = iControladorReloj->getDtFecha();

    auto funciones = iConCrearReserva->listarFunciones(idCine, hoy);

    if (!funciones.empty())
    {

        for (const auto &f : funciones)
        {
            auto toPrint = f;
            cout << "ID Función: " << toPrint.first
                 << "  Fecha: " << toPrint.second.getDia().toString()
                 << " Hora: " << toPrint.second.getHorario().toString()
                 << "\n";
        }
    }
}

// Selecciona la función y cantidad de asientos
void seleccionarFuncion_CU7()
{

    int idF, cant;
    cout << "Ingrese ID de la función: ";
    cin >> idF;
    cout << "Ingrese cantidad de asientos: ";
    cin >> cant;
    iConCrearReserva->seleccionarFuncion(idF, cant);
}

void menuSeleccionarMetodoPago_CU7()
{
    cout << "Seleccione modo de pago:" << endl;
    cout << "1) Débito\n2) Crédito\nOpción: ";
}

// Elige medio de pago y pide datos correspondientes
void seleccionarModoPago_CU7()
{
    cout << "Seleccione modo de pago:\n1) Débito\n2) Crédito\nOpción: ";
    int opc;

    auto bancos = iConCrearReserva->listarBancos();

    cin >> opc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ;

    if (opc == 1)
    {
        cout << "\n=== Bancos disponibles ===\n";
        for (auto nombre : iConCrearReserva->listarBancos())
        {
            cout << "- " << nombre << "\n";
        }

        string banco;
        cout << "Ingrese nombre del banco: ";
        banco = obtenerTextoConEspacios();

        float total = iConCrearReserva->ingresarBanco(banco);
        cout << "Precio total (débito): $" << total << "\n";
    }
    else if (opc == 2)
    {
        cout << "\n=== Financieras disponibles ===\n";
        for (auto nombre : iConCrearReserva->listarFinancieras())
        {
            cout << "- " << nombre << "\n";
        }

        string financiera;
        cout << "Ingrese nombre de la financiera: ";
        financiera = obtenerTextoConEspacios();

        float total = iConCrearReserva->ingresarFinanciera(financiera);
        cout << "Precio total (crédito): $" << total << "\n";
    }
    else
    {
        cout << "Opción inválida. Cancelando reserva.\n";
        iConCrearReserva->cancelarReserva();
    }
}

// Confirma y crea la reserva
void confirmarReserva_CU7()
{
    cout << "¿Confirmar reserva? (s/n): ";
    char resp;
    cin >> resp;
    if (resp == 's' || resp == 'S')
    {
        iConCrearReserva->confirmarReserva();
        cout << "Reserva confirmada exitosamente.\n";
    }
    else
    {
        iConCrearReserva->cancelarReserva();
        cout << "Reserva cancelada.\n";
    }
}

// 9 - ELIMINAR PELICULA
void eliminarPelicula()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (iConSesion->esUsuarioAdmin())
        {
            string titulo;
            listarPeliculas_CU7();
            if (listarPeliculas_CU7())
            {
                cout << "Desea eliminar la pelicula '" << titulo << "'? (s/n): ";
                char resp;
                cin >> resp;
                if (resp != 's' && resp != 'S')
                {
                    cout << "\n#### [INFO] - Eliminacion de pelicula cancelada. ####\n"
                         << endl;
                    return;
                }
                else
                {
                    iConEliminarPelicula->seleccionarPelicula(titulo);
                    iConEliminarPelicula->confirmarEliminacion();
                    cout << "\n#### [INFO] - Pelicula eliminada correctamente. ####\n"
                         << endl;
                }
            }
            else
            {
                cout << "Ingrese el titulo de la pelicula a eliminar: ";
                titulo = obtenerTextoConEspacios();
                try
                {
                    cout << "Desea eliminar la pelicula '" << titulo << "'? (s/n): ";
                    char resp;
                    cin >> resp;
                    if (resp != 's' && resp != 'S')
                    {
                        cout << "\n#### [INFO] - Eliminacion de pelicula cancelada. ####\n"
                             << endl;
                    }
                    else
                    {
                        iConEliminarPelicula->seleccionarPelicula(titulo);
                        iConEliminarPelicula->confirmarEliminacion();
                        limpiarPantalla();
                        cout << "\n#### [INFO] - Pelicula eliminada correctamente. ####\n"

                             << endl;
                        sleep(2);
                        limpiarPantalla();
                    }
                }
                catch (const exception &e)
                {
                    cerr << e.what() << '\n';
                }
            }
        }
        else
        {
            cerr << ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED << endl;
            sleep(2);
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
    }
}

// 10 - PUNTUAR PELICULA
void puntuarPelicula()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        if (iConSesion->esUsuarioAdmin())
        {
            cerr << "\n#### [ERROR] - Acceso denegado: solo los usuarios pueden puntuar. ####\n"
                 << endl;
            sleep(1);
        }
        else
        {

            listarPeliculas_CU7();
            cout << "\n"
                 << endl;
            cout << "Ingrese el titulo de la pelicula a puntuar: ";
            string titulo = obtenerTextoConEspacios();
            try
            {
                DtPuntaje puntaje = iConPuntuarPelicula->seleccionarPelicula(titulo);

                bool ingresarPuntaje = true;
                if (puntaje.yaPuntuo())
                {
                    cout << "El puntaje actual de la pelicula '" << titulo << "' es: " << puntaje.getPuntaje() << "\n";
                    cout << "¿Desea modificar su puntaje? (s/n): ";
                    char resp;
                    cin >> resp;
                    if (resp == 'n' || resp == 'N')
                    {
                        ingresarPuntaje = false;
                        limpiarPantalla();
                        cout << "\n#### [INFO] - No se modificara el puntaje. ####\n"
                             << endl;
                        sleep(2);
                        iConPuntuarPelicula->cancelarCU();
                    }
                }

                if (ingresarPuntaje)
                {
                    int nuevoPuntaje;
                    cout << "Ingrese el puntaje (1-5): ";
                    cin >> nuevoPuntaje;
                    iConPuntuarPelicula->ingresarPuntaje(nuevoPuntaje);
                    limpiarPantalla();
                    cout << "\n#### [INFO] - Puntuacion registrada correctamente. ####\n"
                         << endl;
                    sleep(2);
                }
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
            }
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
    }
}

// 11 - COMENTAR PELICULA
void menuComentarPelicula()
{
    cout << "\n¿Desea comentar la pelicula o responder a un comentario?";
    cout << "\n1. Comentar\n2. Responder\n0. Salir";
    cout << "\nOpcion: ";
}
void comentarPelicula()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (iConSesion->esUsuarioAdmin())
        {
            try
            {
                bool cancelarCu = false;
                int comPeliculaOpt;

                do
                {
                    listarPeliculas_CU11();
                    seleccionaPelicula_CU11();
                    menuComentarPelicula();
                    cin >> comPeliculaOpt;
                    switch (comPeliculaOpt)
                    {
                    case 1:
                        ingresarComentario_CU11();
                        break;

                    case 2:
                        seleccionarComentario_CU11();
                        break;
                    case 0:
                        cancelarCu = true;
                        break;
                    default:
                        limpiarPantalla();
                        cout << INVALID_OPTION << endl;
                        break;
                    }
                } while (!cancelarCu && (comPeliculaOpt == 1 || comPeliculaOpt == 2));
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
            }
        }
        else
        {
            cerr << ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED << endl;
            sleep(2);
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
    }
}
void listarPeliculas_CU11()
{
    cout << "Lista de peliculas\n";
    auto peliculas = iConComentarioPelicula->listarPeliculas();
    if (!peliculas.empty())
    {
        for (const auto &p : peliculas)
        {
            auto toPr = p.second;
            cout << "Titulo: " << toPr.getTitulo() << "\n";
        }
        cout << "\n";
    }
    else
    {
        limpiarPantalla();
        throw invalid_argument("No hay peliculas disponibles\n");
        sleep(2);
    }
}
void seleccionaPelicula_CU11()
{
    string tituloElegido;
    cout << "¿Que titulo desea comentar?\n";
    tituloElegido = obtenerTextoConEspacios();
    auto peliculaSeleccionada = iConComentarioPelicula->seleccionarPelicula(tituloElegido);
    limpiarPantalla();
    cout << "Comentarios de este titulo:\n";
    for (const auto &ps : peliculaSeleccionada)
    {
        auto toPrnt = ps.second;
        cout << "ID: " << toPrnt.getId() << "\nComentario: " << toPrnt.getComentario() << "\n";
    }
}
void seleccionarComentario_CU11()
{
    int com;
    cout << "\n¿Que comentario desea responder?\n";
    cin >> com;
    iConComentarioPelicula->seleccionarComentario(com);
    string respuesta;
    cout << "Escriba su respuesta:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ; // Si no esta este ignore, se rompe todo
    respuesta = obtenerTextoConEspacios();
    iConComentarioPelicula->responderComentario(respuesta);
    // iConComentarioPelicula->ingresarComentario(respuesta);
}
void ingresarComentario_CU11()
{
    string comentario;
    cout << "Escriba su comentario: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ; // Si no esta este ignore tambien se rompe todo
    comentario = obtenerTextoConEspacios();
    iConComentarioPelicula->ingresarComentario(comentario);
}

// 12 - VER INFORMACION DE PELICULA
void verInformacionPelicula()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        // Control usuario admin
        if (iConSesion->esUsuarioAdmin())
        {
            char repetir = 'y';
            while (repetir == 'y' || repetir == 'Y')
            {

                cout << "Desea ver la informacion de una pelicula? (y/n): ";
                char opt;
                cin >> opt;
                if (opt != 'y' && opt != 'Y')
                {
                    cout << "No se mostrara informacion de peliculas.\n";
                    iConVerInformacionPelicula->cancelarCU();
                    return; // Sale de la función como en eliminarPelicula()
                }

                // seleccionarPelicula_CU7();
                string tituloElegido;
                cout << "Elija el titulo que desea ver: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ;
                tituloElegido = obtenerTextoConEspacios();
                iConVerInformacionPelicula->seleccionarPelicula(tituloElegido);
                DtPelicula peliculaSeleccionada = iConVerInformacionPelicula->seleccionarPelicula(tituloElegido);
                cout << "Titulo: " << peliculaSeleccionada.getTitulo() << endl;
                cout << "Sinopsis: " << peliculaSeleccionada.getSinopsis() << endl;
                cout << "Poster: " << peliculaSeleccionada.getPoster() << endl;

                cout << "Desea ver los cines donde se emite la pelicula? (y/n): ";
                cin >> opt;
                if (opt == 'n' || opt == 'N')
                {
                    limpiarPantalla();
                    iConVerInformacionPelicula->cancelarCU();
                    continue; // Vuelve a preguntar si quiere consultar otra película
                }

                listarCines_CU7();
                auto cines = iConVerInformacionPelicula->listarCines();
                imprimirCines(cines);
                cout << endl;
                cout << "Desea ver las funciones de los cines? (y/n): ";
                cin >> opt;
                if (opt == 'n' || opt == 'N')
                {
                    limpiarPantalla();
                    cout << "No se mostraran las funciones de los cines.\n";
                    iConVerInformacionPelicula->cancelarCU();
                    continue;
                }

                limpiarPantalla();
                cout << "Seleccione un cine para ver sus funciones:\n";
                int idCine;
                cout << "Ingrese el ID del cine que desea ver: ";
                cin >> idCine;
                iConVerInformacionPelicula->seleccionarCine(idCine);
                cout << "Cine seleccionado con ID: " << idCine << "\n";

                listarFunciones_CU7();

                cout << "¿Desea consultar otra película? (y/n): ";
                cin >> repetir;
            }
        }
        else
        {
            cerr << ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED << endl;
            sleep(2);
        }
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
    }
}

// 13 - VER COMENTARIOS Y PUNTAJE DE PELICULAS
void verComentariosYPuntajes()
{
    // Control sesion iniciada
    if (iConSesion->existeSesionIniciada())
    {
        string tituloImprimir;
        auto peliculas = iConVerComentariosPuntajes->listarPeliculas();
        if (peliculas.size() > 0)
        {
            cout << TITLE_MOVIE_CATALOG << endl;

            for (const auto &p : peliculas)
            {
                auto toPrnt = p.second;
                cout << "Titulo: " << toPrnt.getTitulo() << endl;
                cout << "└── Poster: [" << toPrnt.getPoster() << "]" << endl;
                cout << endl;
                this_thread::sleep_for(chrono::milliseconds(30));
            }
            cout << "Ingrese titulo: ";
            tituloImprimir = obtenerTextoConEspacios();
            limpiarPantalla();
            iConVerComentariosPuntajes->seleccionaPelicula(tituloImprimir);
        }
        else
        {
            cerr << "\n#### [ERROR] - No hay peliculas registradas en el catalogo. ####\n"
                 << endl;
            sleep(2);
            limpiarPantalla();
        }
        cout << "\nPresione Enter para continuar... \n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        cerr << ERR_NO_ACTIVE_SESSION << endl;
        sleep(1);
        limpiarPantalla();
    }
}

// EXTRAS

void exitMessage()
{
    vector<string> arte = {
        "                                                                                         ",
        "                                         -+##%@@@@@@@@@@@%#*=.                          ",
        "                                    -*%@@@@@@@@@@@@@@@@@@@@@@@@%=                       ",
        "                                 +%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*                     ",
        "                              -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=                   ",
        "                            +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+                  ",
        "                          =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=                 ",
        "                        .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                ",
        "                       %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
        "                      -@@@@@@@@@@@@@@@@@@@@@%%%%%%%%@@@@@@@@@@@@@@@@@@@@.               ",
        "                      *@@@@@@@@@@@@@@@@#*--------------=#%@@@@@@@@@@@@.-:               ",
        "             .+@@@@@@%%@@@@@@@@@@@@@#=---------------------+@@@@@@@@@@                  ",
        "            +@@@@@@@@@@@@@@@@@@@@@+--------------------------#@@@@@@@%                  ",
        "           =@@@@@@@@@@@@@@@@@@@@+-----------------------------%@@@@@@:                  ",
        "           #@@@@@@@@@@@@@@@@@@#--------------------------------@@@@%:                   ",
        "          .@@@@@@@@@@@@@@@@@@@---------------------------------@@*.                     ",
        "          .@@@@@@@@@@@@@@@@@@@@=--------------------------------                        ",
        "           %@@@@@@@@@@@@@@@@@@@@=-------------------------------                        ",
        "           *@@@@@@@@@@@@@@@@@@@@@-------------------------------=.                      ",
        "           -@@@@@@@@@@@@@@@@@@@@@*-------------------------------*                      ",
        "            +@@@@@@@@@@@@@@@@@@@@@-------+:.:==---------+:   .-=+                       ",
        "             =@@@@@@@@@@@@@@@@@@@%----+         =-----#                                 ",
        "               #@@@@%*++#@@@@@@@@%=--=   +@=     #-----+   .@@   =                      ",
        "                .#@#-----=@@@@@@@@+---:   :      *------*       :                       ",
        "                  :+--=*+=@@@@@@@@+---=-.      -=--------+----==-                       ",
        "                  .=--==-+@@@@@@@@+------=---==----------*------*                       ",
        "                  .+--=*-=@@@@@@@@+------------+*=---------=+=-+                        ",
        "                   :=----=@@@@@@@@+-----------+--------------+--.                       ",
        "                     :+=-=@@@@@@@%=-----------#=-----------=*=--=:                      ",
        "                          :@@@@@@@-----------------=+++=-----------=*=                  ",
        "                            :----------------------===-----=**+=------=.                ",
        "                             -------=*#-----=+------------------------+                 ",
        "                             :----+=--====--------------------==--==                    ",
        "                             ----==-== -    :--==+==#+-::.                              ",
        "                             ----==-+. -            -:                                  ",
        "                             ==---+--=:%            =+=+                                ",
        "                             ==----------=+==::::--==---.                               ",
        "                             ==----------------------+=.                                ",
        "                             ==--------------------=:                                   ",
        "                           -@*---------------------*@:                                  ",
        "                          @@@*---------------------*@@@.                                ",
        "                         @@@@%---------------------*@@@@@                               ",
        "                         @@@@@=--------------------+@@@@@@*                             ",
        "                        =@@@@@@=-------------------++#@@@@@#                            ",
        "                      +*#@@@@@@@=------------------==-@@@@@@#:                          ",
        "                    .**+*@@@@@@@@%--------------------@@@@@@@#**#-                      ",
        "                   .*+++*@@@@@@@@@@*------------------@@@@@@@###++*:                    "};

    for (const auto &linea : arte)
    {
        cout << linea << endl;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}
void barraDeCarga(int seg)
{
    const int total_barras = 20;
    const int duracion_ms = seg * 1000;
    const int delay_ms = duracion_ms / total_barras;

    cout << "Cargando: ";

    for (int i = 0; i <= total_barras; ++i)
    {
        cout << "\r["; // retorno al principio de línea
        for (int j = 0; j < i; ++j)
            cout << "#";
        for (int j = i; j < total_barras; ++j)
            cout << " ";
        cout << "] " << (i * 100) / total_barras << "%" << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
}
void cargaDeDatos()
{
    iConSesion->cargarDatos();
    iConAltaPelicula->cargarDatos();
    iConAltaCine->cargarDatos();
    iConAltaFuncion->cargarDatos();
    iConPuntuarPelicula->cargarDatos();
    iConComentarioPelicula->cargarDatos();
    limpiarPantalla();
    cout << TITLE_LOADING_DATA << endl;
    barraDeCarga(3);
}
