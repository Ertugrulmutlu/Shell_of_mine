
#include "read_command.h"
#include "parser.h"
#include "execute.h"
int main(void)
{
    Command commands[] = {
        {"help", help_action},
        {"clr", clear_action},
        {"say", say_action},
        {"exit", exit_action},
        {"cwp", cwp_command},
        {"date", date_command},
        {"clone", clone_file_command},
        {"cut", cut_file_command},
        {"read", read_file_command},
        {"del", delete_file_command},
        {"open", open_program_command},
        {"list", list_of_directory}};

    int command_count = sizeof(commands) / sizeof(commands[0]);
    while (1)
    {
        int argc;
        printf("shell_of_mine => ");
        char *command = read_command();
        char **args = parser(command, &argc);
        execute_command(args, argc, commands, command_count);
        // FREE----------------------------------
        free_args(args, argc);
        free(command);
    }
    return 0;
}