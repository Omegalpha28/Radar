/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** display the timer
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "../header/my_radar.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void display_time_output(sfClock *clock, int *hours, int *minutes)
{
    int seconds;
    sfTime time = sfClock_getElapsedTime(clock);

    seconds = time.microseconds / 1000000;
    if (seconds % 60 == 0) {
        *minutes = (seconds % 3600) / 60;
        seconds = 0;
    }
    if (*minutes == 60) {
        *hours = ((seconds % 3600) / 60) / 3600;
        *minutes = 0;
    }
    my_putstr("Simulation ended with success! Time elapsed: ");
    my_put_nbr(*hours);
    my_putstr(" hours, ");
    my_put_nbr(*minutes);
    my_putstr(" minutes, ");
    my_put_nbr(seconds % 60);
    my_putstr(" seconds!\n");
}

void display_time(sfRenderWindow *window, int hours, int minutes, int secondes)
{
    char *timerText = malloc(sizeof(char *));
    sfFont *font = sfFont_createFromFile("font/font.ttf");
    sfText *text = sfText_create();

    timerText[0] = '\0';
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, (sfVector2f){1800, 10});
    my_strcat(timerText, int_to_string(hours));
    my_strcat(timerText, ":");
    my_strcat(timerText, int_to_string(minutes));
    my_strcat(timerText, ":");
    my_strcat(timerText, int_to_string(secondes));
    sfText_setString(text, timerText);
    sfRenderWindow_drawText(window, text, NULL);
    free(timerText);
}

void time(sfRenderWindow *window, sfClock *clock, int *minutes, int *hours)
{
    int seconds;
    int min_t;
    int h_t;
    sfTime time = sfClock_getElapsedTime(clock);

    seconds = time.microseconds / 1000000;
    if (seconds % 60 == 0) {
        *minutes = (seconds % 3600) / 60;
        seconds = 0;
    }
    if (*minutes == 60) {
        *hours = ((seconds % 3600) / 60) / 3600;
        *minutes = 0;
    }
    h_t = *hours;
    min_t = *minutes % 60;
    seconds = seconds % 60;
    display_time(window, h_t, min_t, seconds);
}
