#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int codigoJuego; //autoincremental
    char descripcion[51];
    float importe; //mayor a cero
    int isEmpty;
}eJuegos;

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en 1 en todas las posiciones del array.
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */
int inicializarJuegos(eJuegos* lista, int len);

/** \brief Muestra el menu de opciones
 * \return int Return, retorna la opcion que se elige
 */
int menuDeOpciones();

/** \brief Indica que posicion del array esta vacia
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna el lugar que se encuentra libre
 */
int espacioLibreJuegos(eJuegos* lista, int len);

/** \brief Muestra un unico juego
 * \param lista* eJuegos Puntero del array de juegos
 * \param indice int posicion del array a ser mostrada
* \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */
int mostrarUnJuego(eJuegos* lista, int indice);

/** \brief Muestra una lista de juegos
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */
int mostrarTodosLosJuegos(eJuegos* lista, int len);

/** \brief Busca un juego recibiendo como parámetro de búsqueda su Id
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \param id int Id a ser registrado
 * \return Return Devuelve la posicion que coincide con el Id ingresado, de lo contrario, devuelve -1 como error
 *
 */
int buscarJuegoPorId(eJuegos* lista, int len, int id);

/** \brief Agrega  un array de juegos
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 **/
int agregarJuego(eJuegos* lista, int len);

/** \brief Da de baja al juego que se encuentra por Id
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int largo del array
 * \param id int Id a ser registrado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */
int removerJuego(eJuegos* lista, int len, int id);

/** \brief Modifica el juego que se encuentra por Id
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int Largo del array
 * \param id int Id a ser modificado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */
int modificarJuegos(eJuegos* lista,int len,  int id);

/** \brief Ordena el array de juegos por Importe y Descripcion de manera ascendente y descendente ,
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int Largo del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */
int mostrarJuegos(eJuegos* lista, int len);

/** \brief Carga descripcion e importe de juegos ,
 * \param eJuegos juegos[] cadena de juegos a ser utilizada
 */
void hardcodearJuegos(eJuegos juegos[]);


#endif
