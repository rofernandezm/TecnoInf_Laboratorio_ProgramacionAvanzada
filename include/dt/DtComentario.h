#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <string>

using namespace std;

class DtComentario
{
private:
    int id;
    string comentario;

public:
    DtComentario();
    DtComentario(int, string);
    ~DtComentario();

    //Getters
    int getId();
    string getComentario();
};

#endif


