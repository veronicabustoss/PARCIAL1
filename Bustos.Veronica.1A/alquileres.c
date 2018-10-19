#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "utn.h"
#include "clientes.h"
#include "juegos.h"
#include <limits.h>


static int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int inicializarAlquiler(eAlquileres* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL )
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;
        }
        retorno = 0;
    }

    return retorno;

}


int espacioLibreAlquiler(eAlquileres* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }

    }
    return retorno;
}

int buscarAlquilerPorId(eAlquileres* lista,int len, int id)
{
    int i;
    int retorno=-1;
    if( lista!= NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].codigoAlquiler == id && lista[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int mostrarUnAlquiler(eAlquileres* lista, int indice)
{
    int retorno=-1;
    if( lista!= NULL)
    {
        if(lista[indice].isEmpty==0)
        {
            printf("%d\t    %d\t    %d\t    %d/%d/%d \n\n", lista[indice].codigoAlquiler, lista[indice].codigoCliente, lista[indice].codigoAlquiler, lista[indice].fechaIngreso.dia, lista[indice].fechaIngreso.mes, lista[indice].fechaIngreso.anio );
            retorno=0;
        }
    }
    return retorno;

}

int mostrarTodosLosAlquileres(eAlquileres* lista, int len)
{
    int retorno=-1;
    int i;
    if(lista!= NULL)
    {
        printf("ID ALQUILER\t    ID JUEGO\t    ID CLIENTE\t    FECHA DE INGRESO\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnAlquiler(lista, i);
                retorno=0;
            }
        }
    }
    return retorno;
}



int altaAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    eAlquileres auxiliarAlquiler;
    int retorno=-1;
    int indiceAuxiliar=0;
    int indiceAuxiliar2=0;
    int estaLibre=espacioLibreAlquiler(listaAlquileres, lenAlquileres);
    if(estaLibre==-1)
    {
        printf("No hay espacio libre");
    }
    if(estaLibre!=-1)
    {
        auxiliarAlquiler.codigoJuego = elegirJuego(listaJuegos, lenJuegos);

        if(auxiliarAlquiler.codigoJuego==-1)
        {
            printf("No existe ese Id.\n");
        }
        else
        {
            auxiliarAlquiler.codigoCliente=elegirCliente(listaCliente, lenCliente);
            if(auxiliarAlquiler.codigoCliente==-1)
            {
                printf("No existe ese Id.\n");
                system("pause");
            }
            else
            {
                auxiliarAlquiler.fechaIngreso.dia= getValidInt("Ingrese dia: ","Error, dia no valido.", 1, 31);
                auxiliarAlquiler.fechaIngreso.mes = getValidInt("Ingrese mes: ","Error, mes no valido.", 1, 12);
                auxiliarAlquiler.fechaIngreso.anio = getValidInt("Ingrese anio: ","Error, anio no valido.", 1000, 2018);
                auxiliarAlquiler.codigoAlquiler=generarNextId();

                auxiliarAlquiler.isEmpty=0;

                listaAlquileres[estaLibre] = auxiliarAlquiler;

                printf("Se alquilo el juego:  ");

                indiceAuxiliar = buscarJuegoPorId(listaJuegos, lenJuegos, auxiliarAlquiler.codigoJuego);
                mostrarUnJuego(listaJuegos, indiceAuxiliar);

                printf("Y el cliente que lo alquilo fue: ");

                indiceAuxiliar2 = buscarClientePorId(listaCliente, lenCliente, auxiliarAlquiler.codigoCliente);
                mostrarUnCliente(listaCliente, indiceAuxiliar2);

                printf("En el dia de la fecha : %d/%d/%d", auxiliarAlquiler.fechaIngreso.dia,auxiliarAlquiler.fechaIngreso.mes, auxiliarAlquiler.fechaIngreso.anio);


                printf("Alquiler logrado con exito!\n");
                retorno=0;
            }
        }
    }
    return retorno;
}

int elegirJuego(eJuegos* listaJuegos, int len)
{
    int retorno=-1;
    int i;
    int idJuegos;
    printf("\nJuegos\n\n");
    mostrarTodosLosJuegos(listaJuegos, len);
    printf("\nSeleccione Juego: ");
    scanf("%d", &idJuegos);
    for( i=0; i<len ; i++)
    {
        if(listaJuegos[i].codigoJuego==idJuegos && listaJuegos[i].isEmpty==0)
        {
            retorno=idJuegos;
            break;
        }

    }
    return retorno;
}

int elegirCliente(eCliente* listaCliente, int len)
{
    int retorno=-1;
    int idClientes;
    int i;
    printf("\nClientes\n\n");
    mostrarTodosLosClientes(listaCliente, len);
    printf("\nSeleccione cliente :  ");
    scanf("%d",&idClientes);
    for(i=0; i < len; i++)
    {
        if(listaCliente[i].codigoCliente == idClientes && listaCliente[i].isEmpty==0)
        {
            retorno=idClientes;
            break;
        }

    }

    return retorno;
}

///Hardcodeo alquileres
void hardcodearAlquileres(eAlquileres alquileres[])
{
    int i;
    eAlquileres vecHard[] =
    {
        {1, 1, 2, {30, 4, 2018}, 0},
        {2, 3, 3, {30, 4, 2018}, 0},
        {3, 3, 3, {20, 4, 2018}, 0},
        {4, 2, 2, {30, 4, 2018}, 0},
        {5, 2, 5, {30, 4, 2018}, 0}
    };
    for(i=0; i<5; i++)
    {
        alquileres[i]=vecHard[i];
        generarNextId();
    }
}

///El juego con menos alquileres
int juegosMenosAlquileros(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos)
{
    int retorno=-1;
    int i, j; //uno nunca sabe
    int flagPrimeraPasada = 1;
    int cantidadClientesMin;
    //int juegoMaximo=0;
    int acumuladorCliente;
    if(listaAlquileres!=NULL && listaJuegos!=NULL)
    {
        for(i=0; i<lenJuegos; i++)
        {
            acumuladorCliente=0; //Va contando la cantidad de clientes que tiene cada juego
            for(j=0; j<lenAlquileres; j++)
            {
                if(listaJuegos[i].codigoJuego == listaAlquileres[j].codigoJuego && listaAlquileres[j].isEmpty==0 && listaJuegos[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            if(flagPrimeraPasada || (acumuladorCliente < cantidadClientesMin && acumuladorCliente!=0 ))
            {
                flagPrimeraPasada = 0;
                cantidadClientesMin=acumuladorCliente;
            }
        }
        // Para aca ya tengo la cantidad maxima que se puede repetir un juego!!!!!1
        for(i=0; i<lenJuegos; i++)
        {
            acumuladorCliente=0; //Va contando la cantidad de clientes que tiene cada juego
            for(j=0; j<lenAlquileres; j++)
            {
                if(listaJuegos[i].codigoJuego == listaAlquileres[j].codigoJuego && listaAlquileres[j].isEmpty==0 && listaJuegos[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            // Sabiendo que ya tengo el maximo, ver si un juego llega a ese maximo
            if(acumuladorCliente == cantidadClientesMin)
            {
                mostrarUnJuego(listaJuegos, i);
            }
        }
        //mostrarUnJuego(listaJuegos, juegoMaximo-1);
        retorno=0;
    }
    return retorno;
}

///El o los clientes con mas alquileres
int clienteMasAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eCliente* listaClientes,int lenClientes)
{
    int retorno=-1;
    int i, j; //uno nunca sabe
    int cantidadClientesMax=0;
    int acumuladorCliente;
    if(listaAlquileres!=NULL && listaClientes!=NULL)
    {
        for(i=0; i<lenClientes; i++)
        {
            acumuladorCliente=0; //Va contando la cantidad de clientes que tiene cada juego
            for(j=0; j<lenAlquileres; j++)
            {
                if(listaClientes[i].codigoCliente == listaAlquileres[j].codigoCliente && listaAlquileres[j].isEmpty==0 && listaClientes[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            if(acumuladorCliente>cantidadClientesMax)
            {
                cantidadClientesMax=acumuladorCliente; //Como utilizaba en javascript
                //juegoMaximo=listaJuegos[i].codigoJuego;
            }
        }
        // Para aca ya tengo la cantidad maxima que se puede repetir un juego!!!!!1
        for(i=0; i<lenClientes; i++)
        {
            acumuladorCliente=0; //Va contando la cantidad de clientes que tiene cada juego
            for(j=0; j<lenAlquileres; j++)
            {
                if(listaClientes[i].codigoCliente == listaAlquileres[j].codigoCliente && listaAlquileres[j].isEmpty==0 && listaClientes[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            // Sabiendo que ya tengo el maximo, ver si un juego llega a ese maximo
            if(acumuladorCliente == cantidadClientesMax)
            {
                mostrarUnCliente(listaClientes, i);
            }
        }
        //mostrarUnJuego(listaJuegos, juegoMaximo-1);
        retorno=0;
    }
    return retorno;
}

///Mostrar alquileres por importe y apellido
int mostrarAlquileresConImporteYApellido(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    int retorno=-1;
    int i; //por las moscas

    if(listaAlquileres!=NULL && listaCliente!=NULL && listaJuegos!=NULL)
    {
        printf("importe juego || apellido persona");
        for( i=0 ; i<lenAlquileres ; i++)
        {
            if(listaAlquileres[i].isEmpty==0)
            {
                printf("%f\t   %s\t\n", listaJuegos[buscarJuegoPorId(listaJuegos, lenJuegos, listaAlquileres[i].codigoJuego)].importe, listaCliente[buscarClientePorId(listaCliente, lenCliente, listaAlquileres[i].codigoCliente)].apellido);
            }
        }
        retorno=0;
    }

    return retorno;
}


///El juego con mas importes
int juegoMasImporte(eJuegos* lista, int len)
{
    int retorno=-1;
    int i;
    float maxImporte;

    if(lista!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(lista[i].importe > maxImporte && lista[i].isEmpty==0)
            {
                maxImporte=lista[i].importe;
            }
        }
        printf("%f\n\n", maxImporte);
        retorno=0;
    }
    return retorno;
}

///Metodo de insercion en clientes por apellido ascendente
void ordenarClientesPorInsercion(eCliente *pClientes, int largoClientes)
{
    eCliente miAuxiliar;
    int i, j;
    for (i=1; i < largoClientes; i++)
    {
        miAuxiliar = pClientes[i];
        j = i-1;
        while (strcmp(pClientes[j].apellido, miAuxiliar.apellido) > 0 && j>=0)
        {
            pClientes[j+1] = pClientes[j];
            j--;
        }
        pClientes[j+1] = miAuxiliar;
    }
    mostrarCliente(pClientes, largoClientes);
    system("pause");
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
        printf("\n\nElija una opcion");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:


            break;
        case 2:


            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
           juegosMenosAlquileros(listaAlquileres, lenAlquileres, listaJuegos, lenJuegos);
           system("pause");
           system("cls");
            break;
        case 6:
            clienteMasAlquileres(listaAlquileres, lenAlquileres, listaCliente, lenCliente);
            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

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

