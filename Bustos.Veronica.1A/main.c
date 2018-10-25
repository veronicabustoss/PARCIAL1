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

void informes(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

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

void informes(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    char continuar= 's';
    int opcion;

    do
    {
        printf("--------------------INFORMES--------------------\n\n");
        printf("1)Promedio y total de los Importes de los juegos alquilados.\n");
        printf("2)La cantidad de juegos cuyo Importe NO superan el promedio anterior.\n");
        printf("3)Listar todos los clientes que alquilaron un juego determinado.\n");
        printf("4)Listar todos los juegos que fueron alquilados por un cliente determinado.\n");
        printf("5)Listar el/los juego/s menos alquilado/s.\n");
        printf("6)Listar el/los clientes que realizo mas alquileres.\n");
        printf("7)Listar todos los juegos alquilados en una fecha determinada.\n");
        printf("8)Listar todos los clientes que realizaron al menos un alquiler en una fecha determinada.\n");
        printf("9)Listar todos los juegos ordenados por Importe(descendente), utilizando METODO DE BURBUJEO MAS EFICIENTE.\n");
        printf("10)Listar todos los clientees ordenados por Apellido(ascendente) , utilizando el metodo de insercion.\n");
        printf("11. Salir");
        printf("\n\nElija una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            promedioYTotalImporteJuegos(listaAlquileres, lenAlquileres, listaJuegos,lenJuegos);
            system("pause");
            system("cls");
            break;
        case 2:
            juegosQueNosSuperanPromedio(listaAlquileres, lenAlquileres,listaJuegos,lenJuegos);
            system("pause");
            system("cls");
            break;
        case 3:
            clientesQueAlquilaronJuegoDeterminado(listaAlquileres, lenAlquileres,listaJuegos,lenJuegos,listaCliente,lenCliente );
            system("pause");
            system("cls");
            break;
        case 4:
            juegosQueFueronAlquiladosPorClienteDeterminado(listaAlquileres, lenAlquileres, listaJuegos, lenJuegos, listaCliente, lenCliente );
            system("pause");
            system("cls");
            break;
        case 5:
            juegosMenosAlquileres(listaAlquileres, lenAlquileres, listaJuegos, lenJuegos);
            system("pause");
            system("cls");
            break;
        case 6:
            clienteMasAlquileres(listaAlquileres, lenAlquileres, listaCliente, lenCliente);
            system("pause");
            system("cls");
            break;
        case 7:
            juegoAlquiladosEnFechaDeterminada(listaAlquileres,  lenAlquileres, listaJuegos, lenJuegos, listaCliente, lenCliente );
            break;
        case 8:

            break;
        case 9:
            listarJuegoPorBurbujeoDescendente(listaJuegos, lenJuegos);
            system("pause");
            system("cls");
            break;
        case 10:
            ordenarClientesPorInsercion(listaCliente, lenCliente);
            system("pause");
            system("cls");
            break;
        case 11:
            system("cls");
            continuar='n';
            break;
        default:
            printf("Opcion no valida");
        }

    }
    while(continuar == 's' || continuar == 'S');

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

