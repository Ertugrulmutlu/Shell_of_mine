#include "execute.h"
void execute_command(char **args, int argc, Command *command, int command_count)
{
    for (int i = 0; i < command_count; i++)
    {
        if (strcmp(args[0], command[i].name) == 0)
        {
            command[i].action(args, argc);
            return;
        }
    }
    printf("Unknown commnad: %s\n", args[0]);
}

void help_action(char **args, int argc)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(args[i], "-help") == 0)
            {
                printf(" Displays this help message\n");
                printf("USAGE----------------------------------------------------------------------\n");
                printf("    help -date\n");
                printf("    help -help\n");
            }
            else if (strcmp(args[i], "-date") == 0)
            {
                printf("Give you a date and time.\n");
                printf("Args can you give-> \n");
                printf("-d  -> just Date \n");
                printf("-dy -> just year \n");
                printf("-dm -> just Month \n");
                printf("-dd -> just Day \n");
                printf("-t  -> just Time \n");
                printf("-th -> just Hour \n");
                printf("-tm -> just Minute \n");
                printf("-ts -> just Second \n");
            }
            else if (strcmp(args[i], "-clone") == 0)
            {
                printf("Copy any file in a path.\n");
                printf("Args 1-> Should be a full name of file\n");
                printf("Args 2-> Should be a path to copy\n");
                printf("Args 2-> Should be a copy name\n");
            }
            else if (strcmp(args[i], "-read") == 0)
            {
                printf("Copy any file in a path.\n");
                printf("Args 1-> Should be a full name | path of file\n");
            }
            else if (strcmp(args[i], "-cut") == 0)
            {
                printf("Cut any file in a path.\n");
                printf("Args 1-> Should be a full name | path of file\n");
                printf("Args 2-> Should be a full path of folder to cut\n");
            }
            else if (strcmp(args[i], "-del") == 0)
            {
                printf("Cut any file in a path.\n");
                printf("Args 1-> Should be a full name | path of file\n");
            }
            else if (strcmp(args[i], "-list") == 0)
            {
                printf("give a directory.\n");
                printf("Args 1-> Should be path \n");
            }
        }
    }
    else
    {
        printf("Available commands:\n");
        printf("  clean                 - Performs cleaning operation\n");
        printf("  help [-command_name]  - Displays this help message\n");
        printf("  say  [-Text]          - Say what you say \n");
        printf("  cwp                   - Give you a current dir \n");
        printf("  date [-Args]          - Give you a date and time\n");
        printf("  clone [-Args1] [-Args2] [-Args3] - Copy any file in a path\n");
        printf("  cut   [-Args1] [-Args2] - Read any file in a path | name\n");
        printf("  read [-Args1]          - Read any file in a path | name\n");
        printf("  del [-Args1]          - delete any file in a  name\n");
        printf("  list [-Args1]          - give a directory\n");
    }
}
void clear_action(char **args, int argc)
{
    system("cls");
}

void say_action(char **args, int argc)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            printf("%s ", args[i]);
        }
    }
    printf("\n");
}
void exit_action(char **args, int argc)
{
    exit(0);
}
void cwp_command(char **args, int argc)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
}
void date_command(char **args, int argc)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(args[i], "-d") == 0)
            {
                printf("%d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
            }
            else if (strcmp(args[i], "-dy") == 0)
            {
                printf("%d\n", tm.tm_year + 1900);
            }
            else if (strcmp(args[i], "-dm") == 0)
            {
                printf("%02d\n", tm.tm_mon + 1);
            }
            else if (strcmp(args[i], "-dd") == 0)
            {
                printf("%02d\n", tm.tm_mday);
            }
            else if (strcmp(args[i], "-t") == 0)
            {
                printf("%02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
            }
            else if (strcmp(args[i], "-th") == 0)
            {
                printf("%02d\n", tm.tm_hour);
            }
            else if (strcmp(args[i], "-tm") == 0)
            {
                printf("%02d\n", tm.tm_min);
            }
            else if (strcmp(args[i], "-ts") == 0)
            {
                printf("%02d\n", tm.tm_sec);
            }
        }
    }
    else
    {
        printf("%d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
}

void clone_file_command(char **args, int argc)
{
    if (argc > 1)
    {
        if (access(args[1], F_OK) == 0)
        {
            if (access(args[2], F_OK) == 0)
            {
                FILE *target_file = fopen(args[1], "rb");
                fseek(target_file, 0, SEEK_END);
                long target_file_size = ftell(target_file);
                fseek(target_file, 0, SEEK_SET);
                char *target_file_buffer = (char *)malloc(target_file_size);
                size_t target_file_bytes_read = fread(target_file_buffer, 1, target_file_size, target_file);
                fclose(target_file);
                FILE *clone_file = fopen(args[3], "wb");
                fwrite(target_file_buffer, 1, target_file_size, clone_file);
                fclose(clone_file);
                free(target_file_buffer);
                printf("Clonening procces done!\n");
            }
            else
            {
                printf("Error: please check yor PATH to clone in \n");
            }
        }
        else
        {
            printf("Error: please check yor file name \n");
        }
    }
    else
    {
        printf("Error: you should give a file name and path\n");
    }
}
void read_file_command(char **args, int argc)
{
    {
        if (argc > 1)
        {
            if (access(args[1], F_OK) == 0)
            {

                FILE *target_file = fopen(args[1], "r");
                fseek(target_file, 0, SEEK_END);
                long target_file_size = ftell(target_file);
                fseek(target_file, 0, SEEK_SET);
                char *target_file_buffer = (char *)malloc(target_file_size);
                if (target_file_buffer == NULL)
                {
                    printf("Error: please check yor file name | path \n");
                    return;
                }
                size_t target_file_bytes_read = fread(target_file_buffer, 1, target_file_size, target_file);
                fclose(target_file);
                printf("%s\n", target_file_buffer);
                free(target_file_buffer);
            }
            else
            {
                printf("Error: please check yor file name | path \n");
            }
        }
    }
}
void delete_file_command(char **args, int argc)
{
    if (argc > 1)
    {
        if (access(args[1], F_OK) == 0)
        {
            if (remove(args[1]) == 0)
            {
                printf("File deleted successfully.\n");
            }
            else
            {
                printf("Error: Unable to delete the file.\n");
            }
        }
        else
        {
            printf("Error: please check yor file name | path \n");
        }
    }
}
void cut_file_command(char **args, int argc)
{
    if (argc > 1)
    {
        if (access(args[1], F_OK) == 0)
        {
            if (access(args[2], F_OK) == 0)
            {
                FILE *target_file = fopen(args[1], "rb");
                fseek(target_file, 0, SEEK_END);
                long target_file_size = ftell(target_file);
                fseek(target_file, 0, SEEK_SET);
                char *target_file_buffer = (char *)malloc(target_file_size);
                size_t target_file_bytes_read = fread(target_file_buffer, 1, target_file_size, target_file);
                fclose(target_file);
                remove(args[1]);
                char *root_tokens = strtok(args[1], "\\");
                char *valued_token = NULL;
                while (root_tokens != NULL)
                {
                    valued_token = root_tokens;
                    root_tokens = strtok(NULL, " \\ ");
                }
                size_t new_root_len = strlen(args[2]) + strlen(valued_token) + 2;
                char *new_root = (char *)malloc(new_root_len);
                sprintf(new_root, "%s\\%s", args[2], valued_token);
                FILE *clone_file = fopen(new_root, "wb");
                fwrite(target_file_buffer, 1, target_file_size, clone_file);
                fclose(clone_file);
                free(target_file_buffer);
                printf("Cut proccses OK \n");
            }
            else
            {
                printf("Error: please check yor PATH to cut \n");
            }
        }
        else
        {
            printf("Error: please check yor file name \n");
        }
    }
    else
    {
        printf("Error: you should give a file name and path\n");
    }
}

void open_program_command(char **args, int argc)
{
    if (argc > 1)
    {
        STARTUPINFO si = {sizeof(si)};
        PROCESS_INFORMATION pi;
        if (CreateProcess(NULL, args[1], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
        {
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
        else
        {
            printf("Error: please check yor file name \n");
        }
    }
    else
    {
        printf("Error: you should give a file name and path\n");
    }
}
void list_of_directory(char **args, int argc)
{
    const char *start_dir = (argc > 1) ? args[1] : ".";
    printf("%s\n", start_dir);
    sub_class_of_list_of_directory(start_dir, 0);
}
void sub_class_of_list_of_directory(const char *dir_path, int depth)
{
    DIR *directory = opendir(dir_path);
    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue; 
        }
        for (int i = 0; i < depth; i++)
        {
            printf("│   ");
        }
        printf("├── %s\n", entry->d_name);
        char *full_path = malloc(strlen(dir_path) + strlen(entry->d_name) + 2);
        if (!full_path)
        {
            perror("malloc");
            closedir(directory);
            return;
        }
        sprintf(full_path, "%s/%s", dir_path, entry->d_name);

        struct stat path_status;
        if (stat(full_path, &path_status) == 0 && S_ISDIR(path_status.st_mode))
        {
            sub_class_of_list_of_directory(full_path, depth + 1); 
        }
        free(full_path);
    }
    closedir(directory);
}
