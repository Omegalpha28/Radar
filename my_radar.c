/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** it's my_main bro
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "header/my_radar.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

void init_show(show_all *show)
{
    show->show_box = 1;
    show->show_sprite = 1;
}

int simulation(sfRenderWindow *window, sprite *background, all *object,
    show_all *show)
{
    int i = 0;
    int hours = 0;
    int minutes = 0;
    sfClock *clock = sfClock_create();

    sprite_background(window, background);
    while (sfRenderWindow_isOpen(window) && object->plane->next != NULL) {
        analyse_event(window, show);
        move_set(window, object, i, clock);
        collision(object);
        sfRenderWindow_drawSprite(window, background->sprite, NULL);
        display_all(window, object, clock, show);
        time(window, clock, &minutes, &hours);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_destroy(window);
    display_time_output(clock, &hours, &minutes);
}

int main(int ac, char **av)
{
    int fd = 0;
    char *word = NULL;
    struct stat c;

    if (error_handlings(ac, av, 0) == 84)
        return 84;
    fd = open(av[1], O_RDONLY);
    if (fd != -1) {
        stat(av[1], &c);
        word = malloc(c.st_size + 1);
        if (word != NULL) {
            read(fd, word, c.st_size);
            word[c.st_size] = '\0';
            fd = reading(word, fd);
            free(word);
            return fd;
        }
    } else {
        return error_handlings(ac, av, 1);
    }
}
