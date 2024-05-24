/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** add tower and planes in my linked_list
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

my_tower *init_tower(void)
{
    my_tower *init_tower = malloc(sizeof(my_tower));

    if (init_tower != NULL) {
        init_tower->pos_init_x = 0;
        init_tower->pos_init_y = 0;
        init_tower->scale = 0;
        init_tower->next = NULL;
    }
    return (init_tower);
}

my_plane *init_plane(void)
{
    my_plane *init_plane = malloc(sizeof(my_plane));

    if (init_plane != NULL) {
        init_plane->pos_init_x = 0;
        init_plane->pos_init_y = 0;
        init_plane->pos_arr_x = 0;
        init_plane->pos_arr_y = 0;
        init_plane->speed = 0;
        init_plane->delay = 0;
        init_plane->next = NULL;
    }
    return (init_plane);
}

int space(char *word, int i)
{
    if (word[i] == ' ') {
        return 1;
    } else
        return 0;
}

void add_tower(my_tower *tower, char *word, show_all *show)
{
    my_tower *tower2 = malloc(sizeof(my_tower));
    int step = 0;

    tower2->t = sprite_tower(tower, show);
    tower2->pos_init_x = my_next_atoi(word, 0);
    step += num_len(my_next_atoi(word, 0)) + 2;
    tower2->pos_init_y = my_next_atoi(word, step);
    step += num_len(my_next_atoi(word, step)) + space(word, step);
    tower2->scale = my_next_atoi(word, step);
    tower2->t = sprite_tower(tower2, show);
    for (; tower->next != NULL; tower = tower->next);
    tower->next = tower2;
    tower2->next = NULL;
}

void add_plane(my_plane *plane, char *word, show_all *show)
{
    my_plane *plane2 = malloc(sizeof(my_plane));
    int step = 1;

    plane2->collision_p = 0;
    plane2->pos_init_x = my_next_atoi(word, 0);
    step += num_len(my_next_atoi(word, 0)) + space(word, step);
    plane2->pos_init_y = my_next_atoi(word, step);
    step += num_len(my_next_atoi(word, step)) + space(word, step);
    plane2->pos_arr_x = my_next_atoi(word, step);
    step += num_len(my_next_atoi(word, step)) + space(word, step);
    plane2->pos_arr_y = my_next_atoi(word, step);
    step += num_len(my_next_atoi(word, step)) + space(word, step);
    plane2->speed = my_next_atoi(word, step);
    step += num_len(my_next_atoi(word, step)) + space(word, step);
    plane2->delay = my_next_atoi(word, step);
    plane2->p = sprite_plane(plane2, show);
    for (; plane->next != NULL; plane = plane->next);
    plane->next = plane2;
    plane2->next = NULL;
}
