#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
/*
    Lista Simplemente enlazada de perfiles
*/

struct perfil{
char nombre[20];
int contra;
};

struct nodo{
    struct perfil* actual;
    struct nodo* sig;
};

typedef struct perfil* Pperfil;
typedef struct nodo* Pnodo;

int insertar(char nombre[], int contra);
int eliminar(char nombre[]);
int buscar(char nombre[]);
void imprimirDatos(char nombre[]);
void imprimirLista();

#endif // SLL_H_INCLUDED
