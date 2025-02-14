#include "read_command.h"

char *read_command()
{
    char *command = malloc(INT_BUFFER_SIZE * sizeof(char));
    if (!command)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    int size = INT_BUFFER_SIZE;
    int lenght = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (lenght >= (size - 1))
        {
            size *= 2;

            char *new_command = realloc(command, (size + 1));
            if (!new_command)
            {
                free(command);
                perror("Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
            command = new_command;
        }
        command[lenght++] = c;
    }

    command[lenght] = '\0'; // String sonlandırıcı karakter ekle
    return command;
}