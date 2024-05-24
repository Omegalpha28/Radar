/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** create sprites and clear all
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

void end_of_the_window(sfRenderWindow *window, music *music)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_close(window);
    sfMusic_stop(music->music);
    sfMusic_destroy(music->music);
}

void sprite_background(sfRenderWindow *window, sprite *background)
{
    background->texture = sfTexture_createFromFile("asset/map.png", NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
}

tower_sprite sprite_tower(my_tower *tower, show_all *show)
{
    tower_sprite t;

    t.texture = sfTexture_createFromFile("asset/tower.png", NULL);
    t.sprite = sfSprite_create();
    t.pos = (sfVector2f){tower->pos_init_x, tower->pos_init_y};
    sfSprite_setTexture(t.sprite, t.texture, sfTrue);
    sfSprite_setPosition(t.sprite, t.pos);
    sfSprite_setOrigin(t.sprite, (sfVector2f){500, 500});
    sfSprite_setScale(t.sprite, (sfVector2f){0.1, 0.1});
    t.circle = create_circle(tower, show);
    return t;
}

plane_sprite sprite_plane(my_plane *plane, show_all *show)
{
    plane_sprite p;

    p.texture = sfTexture_createFromFile("asset/plane.png", NULL);
    p.sprite = sfSprite_create();
    p.pos = (sfVector2f){plane->pos_init_x, plane->pos_init_y};
    p.arr = (sfVector2f){plane->pos_arr_x, plane->pos_arr_y};
    sfSprite_setTexture(p.sprite, p.texture, sfTrue);
    sfSprite_setPosition(p.sprite, p.pos);
    sfSprite_setRotation(p.sprite, rotation(plane));
    sfSprite_setScale(p.sprite, (sfVector2f){0.065, 0.06});
    sfSprite_setOrigin(p.sprite, (sfVector2f){142.5f, 130});
    p.rect = create_rect(plane, show, p.pos);
    return p;
}
