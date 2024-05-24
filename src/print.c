/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** print any integers and strings
*/
#include <unistd.h>
#include "../header/my_radar.h"

char my_putchar(char a)
{
    write(1, &a, 1);
}

int my_putstr(char const *str)
{
    int step = 0;

    while (str[step] != '\0') {
        write(1, &str[step], 1);
        step++;
    }
    return (step);
}

int num_len(int n)
{
    int is_neg = -1;
    int step = 0;

    if (n < 0) {
        step++;
        n *= -1;
    }
    if (n == 0) {
        return (1);
    }
    while (n > 1) {
        step++;
        n = n / 10;
    }
    return (step + 1);
}

int my_put_nbr(int nb)
{
    int nombre;
    int len = num_len(nb);

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    nombre = nb % 10;
    if (nb / 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(48 + nombre);
    return (len);
}

int my_strlen(char const *str)
{
    int step = 0;

    while (str[step] != '\0') {
        step++;
    }
    return (step);
}
