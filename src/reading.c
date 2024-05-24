/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** read the file and create sprites
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

int size_verif(int size, int longeur)
{
    if (size < longeur) {
        return longeur;
    } else {
        return size;
    }
}

int create_plane_and_tower(char **world, size_tab *s)
{
    sprite background;
    all object;
    sfRenderWindow *window = create_window();
    int stop;
    show_all show;

    init_show(&show);
    object.tower = init_tower();
    object.plane = init_plane();
    for (int i = 0; world[i] != NULL; i++) {
        if (world[i][0] == 'A')
            add_plane(object.plane, world[i], &show);
        if (world[i][0] == 'T')
            add_tower(object.tower, world[i], &show);
    }
    simulation(window, &background, &object, &show);
}

int disp_tower(my_tower *tower)
{
    my_tower *head = tower;
    int i = 0;

    while (head != NULL) {
        head = head->next;
        i++;
    }
    return i;
}

int disp_plane(my_plane *plane)
{
    my_plane *head = plane;
    int i = 0;

    while (head != NULL) {
        i += 1;
        head = head->next;
    }
    return i - 1;
}

int reading(char const *word, int fd)
{
    char **world;
    size_tab s;

    s.size_col = my_column(word);
    s.size_length = my_length(word);
    if (verif_word(word) == 84)
        return 84;
    world = malloc(sizeof(char *) * (s.size_col + 1));
    world = my_convert_tab(word, world, s.size_col, s.size_length);
    create_plane_and_tower(world, &s);
    return 0;
}
