/*
** EPITECH PROJECT, 2023
** MYRADAR
** File description:
** convert word to array
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

int verif_word(char const *word)
{
    for (int i = 0; word[i] != '\0'; i++) {
        if (!(word[i] == 'A' || word[i] == 'T' || (word[i] >= '0' &&
            word[i] <= '9') || word[i] == ' ' || word[i] == '\n'))
            return 84;
    }
    return 0;
}

int my_length(char const *word)
{
    int longeur = 0;
    int i = 0;
    int size = 0;

    for (i; word[i] != '\0'; i++){
        longeur++;
        if (word[i] == '\n') {
            size = size_verif(size, longeur);
            longeur = 0;
        }
    }
    return size;
}

int my_column(char const *word)
{
    int column = 0;
    int i = 0;

    for (i; word[i] != '\0'; i++){
        if (word[i] == '\n')
            column++;
    }
    return column + 1;
}

char **my_convert_tab(char const *word, char **world, int size, int longeur_j)
{
    int j = 0;

    for (int i = 0; i < size; i++) {
        world[i] = malloc(sizeof(char) * (longeur_j + 1));
        j = 0;
        for (j; j < longeur_j && word[j] != '\n' && word[j] != '\0'; j++) {
            world[i][j] = word[j];
        }
        world[i][j] = '\0';
        if (word[j] == '\n') {
            j++;
            word += j;
        } else {
            break;
        }
    }
    world[size] = NULL;
    return world;
}
