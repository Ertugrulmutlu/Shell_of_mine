#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
typedef struct Command
{
    char *name;
    void (*action)(char **args, int argc);
} Command;

void execute_command(char **args, int argc, Command *command, int command_count);

void help_action(char **args, int argc);
void clear_action(char **args, int argc);
void say_action(char **args, int argc);
void exit_action(char **args, int argc);
void cwp_command(char **args, int argc);
void date_command(char **args, int argc);
void clone_file_command(char **args, int argc);
void read_file_command(char **args, int argc);
void delete_file_command(char **args, int argc);
void cut_file_command(char **args, int argc);
void open_program_command(char **args, int argc);
void list_of_directory(char **args, int argc);
void sub_class_of_list_of_directory(const char *dir_path, int depth);

#endif