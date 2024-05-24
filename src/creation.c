/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** create the windows and boxes
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "../header/my_radar.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

void init_all(all *object)
{
    object->tower = init_tower();
    object->plane = init_plane();
}

sfRenderWindow *create_window(void)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "MY HUNTER",
        sfClose, NULL);

    sfRenderWindow_setFramerateLimit(window, 100);
    return window;
}

sfCircleShape *create_circle(my_tower *t, show_all *show)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f origin;

    sfCircleShape_setRadius(circle, t->scale * 5);
    origin = (sfVector2f){sfCircleShape_getRadius(circle),
        sfCircleShape_getRadius(circle)};
    sfCircleShape_setOutlineThickness(circle, 2.0f);
    if (show->show_box == 1)
        sfCircleShape_setOutlineColor(circle, sfBlue);
    else if (show->show_box == 0)
        sfCircleShape_setOutlineColor(circle, sfTransparent);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setPosition(circle,
        (sfVector2f){t->pos_init_x, t->pos_init_y});
    sfCircleShape_setOrigin(circle, origin);
    return circle;
}

float rotation(my_plane *plane)
{
    float my_x = plane->pos_arr_x - plane->pos_init_x;
    float my_y = plane->pos_arr_y - plane->pos_init_y;
    float rotationDegrees = atan2(my_y, my_x) * (180.f / M_PI);

    return rotationDegrees;
}

sfRectangleShape *create_rect(my_plane *p, show_all *show, sfVector2f pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){20, 20});
    sfRectangleShape_setOutlineThickness(rect, 2.0f);
    if (show->show_box == 1)
        sfRectangleShape_setOutlineColor(rect, sfRed);
    else if (show->show_box == 0)
        sfRectangleShape_setOutlineColor(rect, sfTransparent);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOrigin(rect, (sfVector2f){0.25, 0.5});
    sfRectangleShape_setPosition(rect, (sfVector2f){pos.x, pos.y});
    sfRectangleShape_setRotation(rect, rotation(p));
    sfRectangleShape_setOrigin(rect, (sfVector2f){8, 9});
    return rect;
}
