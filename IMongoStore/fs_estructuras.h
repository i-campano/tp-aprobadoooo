/*
 * fs_estructuras.h
 *
 *  Created on: 3 jul. 2021
 *      Author: utnso
 */

#ifndef FS_ESTRUCTURAS_H_
#define FS_ESTRUCTURAS_H_

typedef t_config str_metadata;

typedef struct {
	uint32_t tamanio;
	uint32_t cantidadBloques;
	char* bloques;
	char caracterLlenado;
	char* md5;
} str_metadata2;

typedef struct _archivo{
	char* clave;
	t_list * blocks;
	FILE * file;
	char * contenido;
	t_config * metadata;
	pthread_mutex_t mutex_file;
} _archivo;

_archivo archivo_oxigeno;
_archivo archivo_comida;
_archivo archivo_basura;


typedef struct blocks{
	FILE * file_blocks;
	char * fs_bloques;
	pthread_mutex_t mutex_blocks;
} blocks;

blocks _blocks;

typedef struct  {
	uint32_t tamanio_bloque;
	uint32_t cantidad_bloques;
	t_bitarray	* bitmap;
	char * bitmapstr;
} str_superblock;

str_superblock superblock;

typedef struct {
	char data[4];
} __attribute__((packed)) t_bloque;

typedef struct {
	char campo[100];
} __attribute__((packed)) t_registros_metadata;


int fs_server;


#endif /* FS_ESTRUCTURAS_H_ */
