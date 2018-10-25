#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juegos.h"
#define JUE 1000
#include "clientes.h"
#define CLI 1000
#include "alquileres.h"
#define ALQ 1000 //Se cambio
#include "informes.h"

int main()
{
    char seguir  = 's';

    eJuegos juegosInfantiles[JUE];
    eCliente clientes[CLI];
    eAlquileres alquileres[ALQ];
    int lugarLibreJuegos;
    int lugarLibreCliente;
    int flagJuegos=0;
    int flagClientes=0;
    int flagHardcodeo=0;
    inicializarJuegos(juegosInfantiles, JUE);
    incializarClientes(clientes, CLI);
    inicializarAlquiler(alquileres, ALQ);

    do
    {
        switch(menuDeOpciones())
        {
        case 1:
            flagJuegos=1;
            lugarLibreJuegos=espacioLibreJuegos(juegosInfantiles, JUE );
            if(lugarLibreJuegos!=-1)
            {
                agregarJuego(juegosInfantiles, JUE);
            }
            else
            {
                printf("No hay espacio libre!!\n");
            }

            system("pause");
            system("cls");
            break;
        case 2:
            if(flagJuegos==1)
            {
                modificarJuegos(juegosInfantiles, JUE, lugarLibreJuegos);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(flagJuegos==1)
            {
                removerJuego(juegosInfantiles, JUE, lugarLibreJuegos);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(flagJuegos==1)
            {
                mostrarJuegos(juegosInfantiles, JUE);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            flagClientes=1;
            lugarLibreCliente=espacioLibreCliente(clientes, CLI );
            if(lugarLibreCliente!=-1)
            {
                agregarCliente(clientes, CLI);
            }
            else
            {
                printf("No hay espacio libre!!\n");
            }

            system("pause");
            system("cls");
            break;
        case 6:
            if(flagClientes==1)
            {
                modificarCliente(clientes, CLI, lugarLibreCliente);

            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 7:
            if(flagClientes==1)
            {
                removerCliente(clientes, CLI, lugarLibreCliente);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 8:
            if(flagClientes==1)
            {
                mostrarCliente(clientes, CLI);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 9:
            if(flagClientes==1 && flagJuegos==1)
            {
                altaAlquileres(alquileres, ALQ, juegosInfantiles, JUE, clientes, CLI);
            }
            else
            {
                printf("No hay datos que mostrar!\n");
            }
            system("pause");
            system("cls");
            break;
        case 10:
            seguir  = 'n';
            break;
        case 11:
            if(flagHardcodeo==0)
            {
                hardcodearClientes(clientes);
                hardcodearJuegos(juegosInfantiles);
                hardcodearAlquileres(alquileres);
                flagClientes = 1;
                flagJuegos = 1;
                flagHardcodeo=1;
                printf("Hardcodeo con exito!!\n");
            }
            else
            {
                printf("Ya se ha realizado el hardcodeo antes\n");
            }

            system("pause");
            system("cls");
            break;
        case 12:
            ///Hacer informes, mostradolos a todos
            system("cls");
            informes(alquileres, ALQ, juegosInfantiles, JUE, clientes, CLI);
           /* printf("El importe de juego mas alto es :");
           juegoMasImporte(juegosInfantiles, JUE);
           printf("El juego con mas alquileres es : ");
           juegosMasAlquileres(alquileres, ALQ, juegosInfantiles, JUE);*/
           //ordenarClientesPorInsercion(clientes, CLI);
            system("pause");

            break;
        default:
            printf("Se ingresaron mal los datos\n");
            system("pause");
            system("cls");
        }

    }
    while(seguir == 's');

    return 0;
}

/*---------------INFORMES--------------------
 *
 *A) Promedio y total de los Importes de los juegos alquilados. ECHO
 *B) La cantidad de juegos cuyo Importe NO superan el promedio anterior. ECHO
 *C) Listar todos los clientes que alquilaron un juego determinado.
 *D) Listar todos los juegos que fueron alquilados por un cliente determinado.
 *E) Listar el/los juego/s menos alquilado/s. ECHO
 *F) Listar el/los clientes que realizo mas alquileres ECHO
 *G) Listar todos los juegos alquilados en una fecha determinada.
 *H) Listar todos los clientes que realizaron al menos un alquiler en una fecha determinada.
 *I) Listar todos los juegos ordenados por Importe(descendente), utilizando METODO DE BURBUJEO MAS EFICIENTE.
 *J) Listar todos los clientees ordenados por Apellido(ascendente) , utilizando el metodo de insercion.
 */

