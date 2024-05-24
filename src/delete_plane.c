/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** delete planes when they are destroyed or when they are arrived
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

int deleted(my_plane *begin, my_plane *actual, my_plane *previous,
    my_plane *plane)
{
    if (plane == actual && previous == NULL) {
        sfSprite_destroy(plane->p.sprite);
        begin = actual;
        return -1;
    } else if (plane == actual && previous != NULL) {
        sfSprite_destroy(plane->p.sprite);
        previous->next = actual->next;
        return -1;
    }
    return 0;
}

void delete_in_list(my_plane *begin, my_plane *plane)
{
    my_plane *actual = begin;
    my_plane *previous = NULL;

    while (begin != NULL) {
        if (deleted(begin, actual, previous, plane) == -1)
            break;
        previous = actual;
        actual = actual->next;
    }
}
