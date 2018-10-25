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

    if(listaAlquileres!=NULL && listaCliente!=NULL && listaJuegos!=NULL)
    {
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
    }

    return retorno;
}

int elegirJuego(eJuegos* listaJuegos, int len)
{
    int retorno=-1;
    int i;
    int idJuegos;

    if (listaJuegos!=NULL)
    {
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
    }

    return retorno;
}

int elegirCliente(eCliente* listaCliente, int len)
{
    int retorno=-1;
    int idClientes;
    int i;

    if(listaCliente!=NULL)
    {
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

    }

    return retorno;
}

///Hardcodeo alquileres
void hardcodearAlquileres(eAlquileres alquileres[])
{
    int i;
    eAlquileres vecHard[] =
    {
        {1, 1, 2, {30, 5, 2010}, 0},
        {2, 3, 3, {30, 10, 2018}, 0},
        {3, 3, 3, {20, 6, 2018}, 0},
        {4, 2, 2, {30, 4, 2018}, 0},
        {5, 2, 5, {30, 4, 2018}, 0}
    };
    for(i=0; i<5; i++)
    {
        alquileres[i]=vecHard[i];
        generarNextId();
    }
}

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

///ERRORES ENCONTRADOS: FALTA VALIDAR LOS PUNTEROS, CUANDO SE ELIMNA UN JUEGO, ALQUILER O CLIENTE, EL ID CAMBIA POR COMPLETO
