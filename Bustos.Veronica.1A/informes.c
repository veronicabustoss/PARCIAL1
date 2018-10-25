#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "utn.h"
#include "clientes.h"
#include "juegos.h"
#include <limits.h>



///Promedio y total de los Importes de los juegos alquilados
int promedioYTotalImporteJuegos(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos)
{
    float suma=0;
    float promedio;
    int i, j;
    int retorno=-1;
    int contadorAlquileres=0;
    //  int contadorSuperanElpromedio=0;

    if(listaAlquileres!=NULL &&listaJuegos!=NULL)
    {
        for( i=0 ; i<lenAlquileres ; i++)
        {
            for(j=0; j<lenJuegos ; j++)
            {
                if(listaAlquileres[i].codigoJuego == listaJuegos[j].codigoJuego && listaAlquileres[i].isEmpty == 0 && listaJuegos[j].isEmpty == 0)
                {
                    suma = suma + listaJuegos[i].importe;
                    contadorAlquileres ++;
                    promedio= suma / contadorAlquileres;
                }
            }

        }
        /*      for( i=0; i<len ; i++)
        {
          if(lista[i].isEmpty == 0)
          {
              if(lista[i].salary> promedio)
              {
                  contadorSuperanElpromedio ++;
              }
          }

        }*/


        printf("La suma es %.3f --- El promedio es %f \n", suma, promedio);
        retorno=0;
    }

    return retorno;
}

///La cantidad de juegos cuyo Importe NO superan el promedio anterior
int juegosQueNosSuperanPromedio(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos)
{
    float suma=0;
    float promedio;
    int i, j;
    int retorno=-1;
    int contadorAlquileres=0;
    int contadorSuperanElpromedio=0;

    if(listaAlquileres!=NULL &&listaJuegos!=NULL)
    {
        for( i=0 ; i<lenAlquileres ; i++)
        {
            for(j=0; j<lenJuegos ; j++)
            {
                if(listaAlquileres[i].codigoJuego == listaJuegos[j].codigoJuego && listaAlquileres[i].isEmpty == 0 && listaJuegos[j].isEmpty == 0)
                {
                    suma = suma + listaJuegos[i].importe;
                    contadorAlquileres ++;
                    promedio= suma / contadorAlquileres;
                }
            }

        }
        for( i=0 ; i<lenAlquileres ; i++)
        {
            for(j=0; j<lenJuegos ; j++)
            {
                if(listaAlquileres[i].codigoJuego == listaJuegos[j].codigoJuego && listaAlquileres[i].isEmpty == 0 && listaJuegos[j].isEmpty == 0)
                {
                    if(listaJuegos[j].importe< promedio)
                    {
                        contadorSuperanElpromedio ++;
                    }
                }
            }


        }

        printf("La cantidad de juegos cuyo Importe NO superan el promedio anterior es %d \n", contadorSuperanElpromedio);
        retorno=0;
    }

    return retorno;
}


///El juego con menos alquileres
int juegosMenosAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos)
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
            if(flagPrimeraPasada || (acumuladorCliente < cantidadClientesMin && acumuladorCliente!=0 )) //Preguntar
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

///Listar todos los clientes que alquilaron un juego determinado. REVISAR
int clientesQueAlquilaronJuegoDeterminado(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    int retorno=-1;
    int i, j, codigoJuego;
    int indiceJuego;
    if(listaAlquileres!=NULL && listaCliente!=NULL && listaJuegos!=NULL)
    {
        mostrarTodosLosJuegos(listaJuegos, lenJuegos);
        printf("\nIngrese el codigo: ");
        scanf("%d",&codigoJuego);
        indiceJuego = buscarJuegoPorId(listaJuegos, lenJuegos, codigoJuego);
        if (indiceJuego == -1)
        {
            printf("\nNo existe el codigo.\n\n");
        }
        else
        {
            for (i=0; i<lenAlquileres; i++)
            {
                if (listaAlquileres[i].isEmpty == 0)
                {
                    if (codigoJuego == listaAlquileres[i].codigoJuego)
                    {
                        for (j=0; j<lenCliente; j++)
                        {
                            if (listaAlquileres[i].codigoCliente == listaCliente[j].codigoCliente)
                            {
                                mostrarUnCliente(listaCliente, listaCliente[j-1].codigoCliente);
                                retorno=0;
                            }

                        }
                    }
                }
            }
        }
    }


    return retorno;
}

///Listar todos los juegos que fueron alquilados por un cliente determinado.

int juegosQueFueronAlquiladosPorClienteDeterminado(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    int retorno=-1;
    int i, j, codigoCliente;
    int indiceCliente;
    if(listaAlquileres!=NULL && listaCliente!=NULL && listaJuegos!=NULL)
    {
        mostrarTodosLosClientes(listaCliente, lenCliente);
        printf("\nIngrese el codigo: ");
        scanf("%d",&codigoCliente);
        indiceCliente = buscarClientePorId(listaCliente, lenCliente, codigoCliente);
        if (indiceCliente == -1)
        {
            printf("\nNo existe el codigo.\n\n");
        }
        else
        {
            for (i=0; i<lenAlquileres; i++)
            {
                if (listaAlquileres[i].isEmpty == 0)
                {
                    if (codigoCliente == listaAlquileres[i].codigoCliente)
                    {
                        for (j=0; j<lenJuegos; j++)
                        {
                            if (listaAlquileres[i].codigoJuego == listaJuegos[j].codigoJuego)
                            {
                                mostrarUnJuego(listaJuegos, listaJuegos[j-1].codigoJuego);
                                retorno=0;
                            }

                        }
                    }
                }
            }
        }
    }

    return retorno;
}
///Listar todos los juegos alquilados en una fecha determinada REVISAR
int juegoAlquiladosEnFechaDeterminada(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    int retorno=-1;
    int dia, mes, anio;
    int i,j;

    if(listaAlquileres!=NULL  && listaCliente!=NULL &&  listaJuegos!=NULL)
    {
        printf("Ingrese eldia en que fue alquilado el juego: ");
        scanf("%d",&dia);
        printf("ingrese mes ");
        scanf("%d",&mes);
        printf("ingrese anio");
        scanf("%d",&anio);

        for(i=0; i<lenAlquileres ; i++)
        {
            if(listaAlquileres[i].fechaIngreso.dia == dia && listaAlquileres[i].fechaIngreso.mes == mes && listaAlquileres[i].fechaIngreso.anio == anio && listaAlquileres[i].isEmpty == 0)
            {
                for(j=0; j<lenJuegos; j++)
                {
                    if(listaJuegos[j].codigoJuego == listaAlquileres[i].codigoJuego && listaJuegos[j].isEmpty == 0)
                    {
                        mostrarUnJuego(listaJuegos, listaJuegos[j-1].codigoJuego);
                        retorno=0;
                    }
                }

            }
        }

    }
    return retorno;
}


///Listar todos los juegos ordenados por Importe(descendente), utilizando METODO DE BURBUJEO MAS EFICIENTE

void listarJuegoPorBurbujeoDescendente(eJuegos *listaJuegos, int lenJuegos)
{
    eJuegos auxiliarJuegos;
    int j, banderaOrdenado = 1;
    while(banderaOrdenado ==1)
    {
        banderaOrdenado = 0;
        for (j=1; j<lenJuegos; j++)
        {
            if (listaJuegos[j].importe > listaJuegos[j-1].importe)
            {
                auxiliarJuegos = listaJuegos[j]; //Estoy cambiando la poscicion de cada uno
                listaJuegos[j] = listaJuegos[j-1];
                listaJuegos[j-1] = auxiliarJuegos;
                banderaOrdenado = 1;
            }
        }
    }
    mostrarTodosLosJuegos(listaJuegos, lenJuegos);
    system("pause");
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


///ERRORES ENCONTRADOS: FALTA VALIDAR LOS PUNTEROS, CUANDO SE ELIMNA UN JUEGO, ALQUILER O CLIENTE, EL ID CAMBIA POR COMPLETO
