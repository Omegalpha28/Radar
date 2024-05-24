/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** move sprites
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
#include <math.h>

int stop(my_plane *plane)
{
    sfVector2f pos = sfSprite_getPosition(plane->p.sprite);
    sfVector2f initial = (sfVector2f){plane->pos_init_x, plane->pos_init_y};
    sfVector2f arr = (sfVector2f){plane->pos_arr_x, plane->pos_arr_y};
    sfColor color = sfSprite_getColor(plane->p.sprite);

    if ((pos.x <= (arr.x + 20) && pos.x >= (arr.x - 20)) &&
        (pos.y <= (arr.y + 20) && pos.y >= (arr.y - 20)))
        return -1;
    if (plane->collision_p == 1)
        return -1;
    return 0;
}

int movement(my_plane *plane, sfTime time)
{
    sfVector2f direction = {plane->pos_arr_x - plane->pos_init_x,
        plane->pos_arr_y - plane->pos_init_y};
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    sfVector2f position = sfSprite_getPosition(plane->p.sprite);
    int timer = time.microseconds / 1000000;
    float vitesse = plane->speed * 0.01;

    if (plane->delay <= timer) {
        direction.x /= length;
        direction.y /= length;
        position.x += direction.x * vitesse;
        position.y += direction.y * vitesse;
        sfSprite_setPosition(plane->p.sprite, position);
        return stop(plane);
    } else
        return 0;
}

int mov_all(all *object, int i, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    my_plane *prev = object->plane;
    my_plane *p = object->plane->next;

    for (my_plane *p = object->plane->next; p != NULL; p = p->next) {
        if (movement(p, time) == -1) {
            delete_in_list(object->plane, p);
        }
    }
    return i;
}

int move_set(sfRenderWindow *window, all *object, int i, sfClock *clock)
{
    mov_all(object, i, clock);
    return 0;
}
