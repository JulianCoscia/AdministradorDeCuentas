#ifndef SLL_C_INCLUDED
#define SLL_C_INCLUDED
#include "stdlib.h"
#include "stddef.h"
#include "ListaSimplementeEnlazada.h"
#include "string.h"
#include "stdio.h"

Pnodo lista = NULL;


/*
    Inserta un nuevo perfil al principio de la lista.
    Si la funcion retorna:
                          0: Se ingreso un nuevo perfil a la lista correctamente.
                          1: No se pudo ingresar el perfil a la lista correctamente.
*/
int insertar(char nombre[], int contra){
    if (lista == NULL){
        Pperfil nuevo = malloc(sizeof(struct perfil));
        strcpy(nuevo->nombre, nombre);
        nuevo->contra = contra;
        Pnodo nodoNuevo = malloc(sizeof(struct nodo));
        nodoNuevo->actual = nuevo;
        nodoNuevo->sig = NULL;
        lista = nodoNuevo;
        return 0;
    }
    else {
        Pnodo cabeza = lista;

        Pperfil nuevo = malloc(sizeof(struct perfil));
        strcpy(nuevo->nombre, nombre);
        nuevo->contra = contra;
        Pnodo nodoNuevo = malloc(sizeof(struct nodo));
        nodoNuevo->actual = nuevo;
        nodoNuevo->sig = cabeza;
        lista = nodoNuevo;
        return 0;
    }
return 1;
}

/*
    Elimina al primer perfil encontrado con el nombre buscado.
    Si la funcion retorna:
                          0: Se elimino el perfil de la lista correctamente.
                          1: No se encontro el perfil en la lista.
*/
int eliminar(char nombre[]){
    Pnodo navegador = lista;
    Pnodo anterior = lista;

    if (lista != NULL){
        if (!strcmp(navegador->actual->nombre, nombre)){
            if (navegador->sig != NULL){
                lista = navegador->sig;
            }
            else{
                lista = NULL;
            }

            free(navegador->actual);
            free(navegador);
            return 0;
        }
        else{
            while(navegador->sig != NULL){
                navegador = navegador->sig;

                if (!strcmp(navegador->actual->nombre, nombre)){
                    anterior->sig = navegador->sig;
                    free(navegador->actual);
                    free(navegador);
                    return 0;
                }
                else{
                    anterior = anterior->sig;
                }
            }
        }
    }
return 1;
}

/*
    Busca un perfil dentro de la lista.
    Si la funcion retorna:
                          0: No se encontro el perfil buscado dentro de la lista.
                          1: El perfil buscado corresponde a un perfil perteneciente a la lista.
*/
int buscar(char nombre[]){
Pnodo navegador = lista;

    if (lista != NULL){
        if (!strcmp(navegador->actual->nombre, nombre)){
            return 1;
        }

        while (navegador->sig != NULL){
            navegador = navegador->sig;
            if (!strcmp(navegador->actual->nombre, nombre)){//=0 si es verdadero
              return 1;
            }
        }
    }
return 0;
}

/*
    Imprime por consola los datos del perfil indicado.
*/
void imprimirDatos(char nombre[]){
Pperfil aImprimir = NULL;

Pnodo navegador = lista;
int encontre = 0;

    if (lista != NULL){
        if (!strcmp(navegador->actual->nombre, nombre)){
            aImprimir = navegador->actual;
            encontre = 1;
        }

        while (!encontre && navegador->sig != NULL){
            navegador = navegador->sig;

            if (!strcmp(navegador->actual->nombre, nombre)){
                aImprimir = navegador->actual;
                encontre = 1;
            }
        }
    }

    if (aImprimir == NULL){
        printf("\nEL USUARIO BUSCADO NO FUE ENCONTRADO.\n");
    }
    else{
         printf("\nUsuario: %s\nContrasenia: %d\n", aImprimir->nombre, aImprimir->contra);
        }
}

/*
    Imprime en consola todos los perfiles dentro de la lista.
*/
void imprimirLista(){
    Pnodo navegador = lista;

    if (lista != NULL){
        printf("\nImprimiendo datos...\n\n");
        printf("Usuario: %s\nConstrasenia: %d\n\n", navegador->actual->nombre, navegador->actual->contra);

        while (navegador->sig != NULL){
            navegador = navegador->sig;
            printf("Usuario: %s\nConstrasenia: %d\n\n", navegador->actual->nombre, navegador->actual->contra);
        }
    }
    else{
        printf("\nLA LISTA ESTA VACIA.\n");
    }
}
#endif // SLL_C_INCLUDED
