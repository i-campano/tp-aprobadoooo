/*
 * conexiones.h
 *
 *  Created on: 3 mar. 2019
 *      Author: utnso
 */

#ifndef CONEXIONES_H_
#define CONEXIONES_H_

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<commons/log.h>
#include<commons/config.h>
#include<commons/collections/list.h>
#include<commons/txt.h>
#include<commons/string.h>
#include<commons/bitarray.h>
#include<string.h>
#include "socket.h"
#include<time.h>

#include"utils.h"

struct {
	uint32_t tamanio_bloque;
	uint32_t cantidad_bloques;
	t_bitarray bitmap;
} superblock;



struct {
	uint32_t tamanio;
	uint32_t cantidadBloques;
	char* bloques;
	char caracterLlenado;
	char* md5;

} metadata;




//VARIABLES DEL ARCHIVO DE CONFIGURACION
char* conf_PUNTO_MONTAJE;
uint32_t conf_PUERTO_IMONGO;
uint32_t conf_TIEMPO_SICRONIZACION;
char* conf_POSICIONES_SABOTAJE;
uint32_t conf_PUERTO_DISCORDIADOR;
char* conf_IP_DISCORDIADOR;
char* conf_ARCHIVO_OXIGENO_NOMBRE;
char* conf_ARCHIVO_COMIDA_NOMBRE;
char* conf_ARCHIVO_BASURA_NOMBRE;
char* conf_PATH_BITACORA;

//MUTEX PARA ARCHIVOS
pthread_mutex_t mut_ARCHIVO_OXIGENO;
pthread_mutex_t mut_ARCHIVO_COMIDA;
pthread_mutex_t mut_ARCHIVO_BASURA;
pthread_mutex_t mut_ARCHIVO_OXIGENO_METADATA;
pthread_mutex_t mut_ARCHIVO_COMIDA_METADATA;
pthread_mutex_t mut_ARCHIVO_BASURA_METADATA;
pthread_mutex_t mut_ARCHIVO_BLOCKS;
pthread_mutex_t mut_ARCHIVO_SUPERBLOQUE;

int server_fd;

typedef enum
{
	MENSAJE = 7,
	PAQUETE = 8
}op_code;

t_log* logger;

void *atenderNotificacion(void * paqueteSocket);

void iniciar_configuracion();

void iniciar_logger();

t_config* leer_config();

////////FUNCIONES DE TAREAS/////////
void generarOxigeno(uint32_t cantidad);
void generarComida(uint32_t cantidad);
void generarBasura(uint32_t cantidad);
void consumirOxigeno(uint32_t cantidad);
void consumirComida(uint32_t cantidad);
void descartarBasura();
char *devolverTarea(char* tarea);
////////FUNCIONES DE TAREAS/////////
void ejecutarTarea(char* tarea, uint32_t cantidad);

/* Bitacora */
void escribirBitacora(char* tarea, uint32_t idTripulante);

char* generarIdArchivo(uint32_t idTripulante);
char* generarPath(char* archivoTripulante);



#endif /* CONEXIONES_H_ */
