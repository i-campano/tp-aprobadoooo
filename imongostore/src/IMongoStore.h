/*
 */

#ifndef IMONGOSTORE_H_
#define IMONGOSTORE_H_

#include "core.h"



void informarSabotaje(int signal);
void _informar_sabotaje_a_discordiador();
void manejadorDeHilos();
void prueba_func_core_ejecucion();


void check_directory(char *basedir, char *ask);
void check_directories_permissions(char *mount_point);
void check_directorios();
void create_metadata_resource_files();

#endif /* IMONGOSTORE_H_ */
