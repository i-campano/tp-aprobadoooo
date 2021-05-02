#ifndef MY_LIBRARY_
#define MY_LIBRARY_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LENGTH_HEAD 30
#define CANT_OPERATION 7
#define MSG_INIT_PLANIF "INICIAR_PLANIFICACION"
#define MSG_PAUSE_PLANIF "PAUSAR_PLANIFICACION"
#define MSG_RESUME_PLANIF "REANUDAR_PLANIFICACION"
#define MSG_NEW_PATOTA "INICIAR_PATOTA"
#define MSG_LIST_CREW "LISTAR_TRIPULANTES"
#define MSG_EXP_CREW "EXPULSAR_TRIPULANTE"
#define MSG_BITACORA "OBTENER_BITACORA"


typedef enum
{
	INICIAR_PLANIFICACION = 0,
	PAUSAR_PLANIFICACION = 1,
	REANUDAR_PLANIFICACION = 2,
	NEW_TRIPULANTE = 3,
	LISTAR_TRIPULANTES = 4,
	EXPULSAR_TRIPULANTE = 5,
	BITACORA_TRIPULANTE = 6,
	MENSAJE,
	PAQUETE
}op_code;


char* obtener_primera_palabra(char* mensaje);
int reconocer_op_code(char* mensaje);

#endif
