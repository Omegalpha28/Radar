/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** my_next_atoi
*/
#include "../header/my_radar.h"
#include <stdio.h>

int my_next_atoi(char *str, int i)
{
    int result = 0;
    int is_neg = 1;

    if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-')) {
        while (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
            i++;
    }
    if (str[i] == '-') {
        is_neg = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * is_neg;
}

int my_arraylen(char **args)
{
    int i = 0;

    while (args[i]) {
        i++;
    }
    return i;
}
