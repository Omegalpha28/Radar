/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** display sprites and hitboxes
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "../header/my_radar.h"
#include <stdio.h>
#include <fcntl.h>

void begin_display(sfRenderWindow *window, my_plane *p, int seconds,
    show_all *show)
{
    sfVector2f pos;

    if (p->delay <= seconds) {
        sfRenderWindow_drawSprite(window, p->p.sprite, NULL);
        pos = sfSprite_getPosition(p->p.sprite);
        p->p.rect = create_rect(p, show, pos);
        sfRenderWindow_drawRectangleShape(window, p->p.rect, NULL);
    }
}

void display_all(sfRenderWindow *window, all *object, sfClock *clock,
    show_all *show)
{
    sfTime time = sfClock_getElapsedTime(clock);
    int seconds = time.microseconds / 1000000;

    for (my_tower *t = object->tower->next; t != NULL; t = t->next) {
        if (show->show_sprite == 1)
            sfRenderWindow_drawSprite(window, t->t.sprite, NULL);
        t->t.circle = create_circle(t, show);
        sfRenderWindow_drawCircleShape(window, t->t.circle, NULL);
    }
    for (my_plane *p = object->plane->next; p != NULL; p = p->next) {
        if (show->show_sprite == 1)
            begin_display(window, p, seconds, show);
    }
}
