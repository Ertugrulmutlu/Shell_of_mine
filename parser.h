#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arg_buffer_size 4

char **parser(char *command, int *argc);

char free_args(char **args, int argc);

#endif