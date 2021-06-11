#ifndef DISCORDIADOR_H_
#define DISCORDIADOR_H_

#include "utils.h"
#include "socket.h"
#include "hilosDiscordiador.h"
#include "tripulante.h"






typedef struct patota{
	uint32_t patota_id;
    uint32_t cantidad_tripulantes;
    char * tareas;
    int longitud_tareas;
    int longitud_posiciones;
    char * posiciones;
    int socketMIRAM;

} patota;



void iniciarEstructurasAdministrativasPlanificador();

//Funciones para los hilos
void leer_consola();
void atender_ram();
void atender_imongo_store();

//Funciones que crean hilos

//Funciones administrativas - loggeo - configuracion
void iniciarEstructurasAdministrativasPlanificador();

void iniciar_logger(void);
t_config* leer_config(void);
void leer_consola2(t_log* logger,int conexion_ram,int conexion_fs,int conexion_trip);
t_paquete* armar_paquete();
int terminar_programa(t_log* logger,t_config* config,int conexion[2]);


void crear_patota();

void* crear_buffer_patota(int longitud_tareas, int longitud_posiciones, uint32_t patotaId, uint32_t cantidad_tripulantes, int* tamanioGet, char* tareas, char* posiciones);

void * crear_buffer_with_struct(patota patota,int * tamanio);

void *labor_tripulante_new(void * id_tripulante);

//Funciones PARA REVISAR o PARA IMPLEMENTAR (NO SE USAN)
int realizar_operacion(char* mensaje,int conexion_mi_ram,int conexion_file_system,int conexion_tripulante);
void iniciar_patota(char* mensaje);
void *labor_tripulante (void* tripulante);
#endif /* DISCORDIADOR_H_ */
