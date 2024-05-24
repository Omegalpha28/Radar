/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** close the windows and display or not sprites and hitboxes
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "../header/my_radar.h"
#include <stdio.h>
#include <fcntl.h>

void show_event(sfEvent event, show_all *show)
{
    if (event.key.code == sfKeyL && show->show_box == 1)
        show->show_box = 0;
    else if (event.key.code == sfKeyL && show->show_box == 0)
        show->show_box = 1;
    if (event.key.code == sfKeyS && show->show_sprite == 1)
        show->show_sprite = 0;
    else if (event.key.code == sfKeyS && show->show_sprite == 0)
        show->show_sprite = 1;
}

void close_event(sfRenderWindow *window, sfEvent event, show_all *show)
{
    if (event.type == sfEvtKeyPressed) {
        show_event(event, show);
        if (event.key.code == sfKeyEscape || event.key.code == sfKeyQ)
            sfRenderWindow_close(window);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void sprite_size(sfSprite *sprite, sfVector2f scale, sfVector2f pos)
{
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
}

void analyse_event(sfRenderWindow *window, show_all *show)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        close_event(window, event, show);
}
