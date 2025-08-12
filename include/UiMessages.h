#include <string>

using namespace std;

static const string INVALID_OPTION = "#### Opcion no valida ####";
static const string ERR_NO_ACTIVE_SESSION = "\n#### [ERROR] - No hay una sesión activa. ####\n";
static const string ERR_ACCESS_DENIED_ONLY_ADMIN_ALLOWED = "\n#### [ERROR] - Acceso denegado: Se requieren permisos de administrador. ####\n";
static const string ERR_ACCESS_DENIED_ONLY_BASIC_ALLOWED = "\n#### [ERROR] - Acceso denegado: No permitido para usuario administrador. ####\n";

// CU TITLES
static const string TITLE_SIGN_IN = "##### INICIO DE SESION #####\n";
static const string TITLE_SIGN_OUT = "##### CIERRE DE SESION #####\n";
static const string TITLE_MOVIE_CATALOG = "\n#### Catalogo de peliculas ####\n";
static const string TITLE_CINEMAS_LIST = "\n#### Listado de cines ####\n";
static const string TITLE_LOADING_DATA = "\n##### CARGA DE DATOS #####\n";