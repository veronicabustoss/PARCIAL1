#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "alquileres.h"
#include "utn.h"
#include "clientes.h"
#include "juegos.h"
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fechaIngreso;
    int isEmpty;

}eAlquileres;

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en 1 en todas las posiciones del array.
 * \param lista* eAlquileres Puntero del array de alquileres
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */
int inicializarAlquiler(eAlquileres* lista, int len);

/** \brief Indica que posicion del array esta vacia
 * \param lista* eAlquileres Puntero del array de alquileres
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna el lugar que se encuentra libre
 */
int espacioLibreAlquiler(eAlquileres* lista, int len);

/** \brief Agrega un array de clientes
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenCliente tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */
int altaAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

/** \brief elige un juego existente por id
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int len tamaño del array de juegos
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */
int elegirJuego(eJuegos* listaJuegos, int len);

/** \brief elige un cliente existente por id
 * \param eCliente* listaCliente Puntero del array de cliente
 * \param int len tamaño del array de cliente
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */
int elegirCliente(eCliente* listaCliente, int len);

/** \brief Muestra un alquiler
 * \param eCliente* listaCliente Puntero del array de cliente
 * \param int indice indice del cliente a ser mostrado
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */
int mostrarUnAlquiler(eAlquileres* lista, int indice);

/** \brief Muestra una lista de alquileres
 * \param eCliente* listaCliente Puntero del array de cliente
 * \param int indice indice del cliente a ser mostrado
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */
int mostrarTodosLosAlquileres(eAlquileres* lista, int len);

//void informes(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int mostrarAlquileresConImporteYApellido(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int juegosMenosAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);

int juegoMasImporte(eJuegos* lista, int len);

void hardcodearAlquileres(eAlquileres alquileres[]);

void ordenarClientesPorInsercion(eCliente *pClientes, int largoClientes);

int clienteMasAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eCliente* listaClientes,int lenClientes);

int promedioYTotalImporteJuegos(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);

int juegosQueNosSuperanPromedio(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);

void listarJuegoPorBurbujeoDescendente(eJuegos *listaJuegos, int lenJuegos);

int clientesQueAlquilaronJuegoDeterminado(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int juegosQueFueronAlquiladosPorClienteDeterminado(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int juegoAlquiladosEnFechaDeterminada(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );



#endif
