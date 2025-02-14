#include "parser.h"

char **parser(char *command, int *argc)
{
    int size = arg_buffer_size;
    int lenght = 0;
    char **args = malloc(size * sizeof(char *));

    *argc = 0;
    char *token = strtok(command, " ");
    while (token)
    {
        if (*argc >= size)
        {
            size *= 2;
            args = realloc(args, size * sizeof(char *));
        }
        args[*argc] = strdup(token);
        (*argc)++;
        token = strtok(NULL, " ");
    }
    args[*argc] = NULL;
    return args;
}

char free_args(char **args, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        free(args[i]);
    }
    free(args);
}
