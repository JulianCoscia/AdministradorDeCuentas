#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"


int main()
{
int op = 0;
char nombre[20];
int resultado;
do{
    printf("\nBienvenido al administrador de cuentas.\n\nOperaciones:\n(1) Crear cuenta.\n(2) Eliminar cuenta.\n(3) Buscar una cuenta.\n(4) Imprimir datos de una cuenta.\n(5) Imprimir todas las cuentas.\n(0) Salir.\n\nOperacion: ");
    scanf("%i", &op);

    switch(op){
        case 0: {return 0;}
        case 1: {
                int contra;
                printf("\nIngrese nombre de usuario: ");
                scanf("%s", &nombre);
                printf("\nIngrese una contrasenia numerica: ");
                scanf("%d", &contra);
                resultado = insertar(nombre, contra);

                if (resultado == 0){
                    printf("\nSE INSERTO UN NUEVO PERFIL CORRECTAMENTE.\n");
                }
                else {
                    printf("\nLA OPERACION NO SE PUDO REALIZAR CORRECTAMENTE.\n");
                }

                break;}
        case 2: {
                printf("\nIngrese el nombre de la cuenta a eliminar: ");
                scanf("%s", &nombre);
                resultado = eliminar(nombre);

                if (resultado == 0){
                    printf("\nSE ELIMINO LA CUENTA CORRECTAMENTE.\n");
                }
                else {
                    printf("\nLA CUENTA NO FUE ENCONTRADA.\n\n");
                }

                break;}
        case 3: {
                printf("\nNombre de la cuenta a buscar: ");
                scanf(" %s", &nombre);

                if (buscar(nombre) == 1){
                    printf("\nEL NOMBRE CORRESPONDE A UNA CUENTA EXISTENTE.\n\n");
                }
                else{
                    printf("\nEL NOMBRE NO CORRESPONDE A UNA CUENTA EXISTENTE.\n\n");
                }

                fflush(stdin);
                break;}
        case 4: {
                printf("\nCuenta a buscar: ");
                scanf("%s", &nombre);
                imprimirDatos(nombre);
                break;}
        case 5: {
                imprimirLista();
                break;
                }
        default:{
                printf("\nERROR! CODIGO DE OPERACION INVALIDO.\n\n");
                break;}
    }
}while (op != 0);
return 0;
}
