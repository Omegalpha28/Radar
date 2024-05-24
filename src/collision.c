/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** collision
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

int my_rect_collide_square(my_plane *plane, my_tower *tower)
{
    sfVector2f posRect = sfRectangleShape_getPosition(plane->p.rect);
    sfVector2f posCircle = sfCircleShape_getPosition(tower->t.circle);
    sfVector2f rectSize = sfRectangleShape_getSize(plane->p.rect);
    float radius = sfCircleShape_getRadius(tower->t.circle);
    float rectCenterX = posRect.x + rectSize.x / 2;
    float rectCenterY = posRect.y + rectSize.y / 2;
    float my_posX = fmaxf(posRect.x,
        fminf(posCircle.x, posRect.x + rectSize.x));
    float my_posY = fmaxf(posRect.y,
        fminf(posCircle.y, posRect.y + rectSize.y));
    float my_distanceX = posCircle.x - my_posX;
    float my_distanceY = posCircle.y - my_posY;
    float my_distance = sqrtf((my_distanceX * my_distanceX) +
        (my_distanceY * my_distanceY));

    if (my_distance <= radius)
        return 1;
    else
        return 0;
}

int verif_area(my_plane *plane, all *object)
{
    for (my_tower *t = object->tower->next; t != NULL; t = t->next) {
        if (my_rect_collide_square(plane, t) == 1)
            return 1;
    }
    return 0;
}

int verif_collision(my_plane *p, my_plane *pl, all *object)
{
    sfVector2f pos1 = sfRectangleShape_getPosition(p->p.rect);
    sfVector2f pos2 = sfRectangleShape_getPosition(pl->p.rect);

    if ((pos1.x < pos2.x + 20 && pos1.x + 20 > pos2.x &&
        pos1.y < pos2.y + 20 && pos1.y + 20 > pos2.y)) {
        p->collision_p = 1;
        pl->collision_p = 1;
        return 0;
    }
    return 1;
}

void collide_rect(my_plane *p, all *object)
{
    for (my_plane *pl = p->next; pl != NULL; pl = pl->next) {
        if (verif_area(p, object) == 0)
            verif_collision(p, pl, object);
    }
}

void collision(all *object)
{
    for (my_plane *p = object->plane->next; p != NULL; p = p->next)
        collide_rect(p, object);
}
