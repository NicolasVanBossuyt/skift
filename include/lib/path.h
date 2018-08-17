#pragma once
#include "types.h"

#define PATH_MAX_SIZE 1024
#define PATH_MAX_FILE_NAME_SIZE 128

int path_len(const char * path);
int path_read(const char * path, int index, char * buffer);
char * path_cat(const char *  pathA, const char *  pathB, char * dest);
int path_split(const char * path, char * dir, char * file);