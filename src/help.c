/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** -h
*/
#include "../header/my_radar.h"
#include <unistd.h>

int my_help(char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        my_putstr("Air traffic simulation panel\n\nUSAGE\n");
        my_putstr("./my_radar [OPTIONS] ");
        my_putstr("path_to_script\n  path_to_script    ");
        my_putstr("The path to the script file.\n");
        my_putstr("\nOPTIONS\n -h\t\t   print the usage and quit.\n\nUSER ");
        my_putstr("INTERACTIONS\n ‘L’ key\t");
        my_putstr("enable/disable hitboxes and areas.\n");
        my_putstr(" ‘S’ key\tenable/disable sprites.\n");
        my_putstr(" ’Q’ key\tstop the simulation.\n");
    }
    return 0;
}

int arguments_invalid(void)
{
    my_putstr("./my_radar: bad arguments: 0 given but 84 is required\n");
    my_putstr("retry with -h\n");
    return 84;
}

int error_handlings(int ac, char **av, int error)
{
    if (error == 1 && my_strcmp(av[1], "-h") != 0) {
        write(2, "it's not a file bro!\n", 22);
        return 84;
    }
    if (ac != 2) {
        return arguments_invalid();
    } else if (ac == 2 && error != 1) {
        my_help(av);
    }
    return 0;
}
