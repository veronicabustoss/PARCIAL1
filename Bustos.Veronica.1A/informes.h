#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


void informes(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int mostrarAlquileresConImporteYApellido(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int juegosMenosAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);

int juegoMasImporte(eJuegos* lista, int len);

void ordenarClientesPorInsercion(eCliente *pClientes, int largoClientes);

int clienteMasAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eCliente* listaClientes,int lenClientes);

int promedioYTotalImporteJuegos(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);

int juegosQueNosSuperanPromedio(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);

void listarJuegoPorBurbujeoDescendente(eJuegos *listaJuegos, int lenJuegos);

int clientesQueAlquilaronJuegoDeterminado(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int juegosQueFueronAlquiladosPorClienteDeterminado(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int juegoAlquiladosEnFechaDeterminada(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );


#endif
