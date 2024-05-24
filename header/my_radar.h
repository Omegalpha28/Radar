/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** header for my_hunter
*/

#ifndef MY_HUNTER_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #define MY_HUNTER_
typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
}sprite;
typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfCircleShape *circle;
}tower_sprite;
typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f my_move;
    sfVector2f pos;
    sfRectangleShape *rect;
    sfVector2f arr;
}plane_sprite;
typedef struct {
    int show_sprite;
    int show_box;
}show_all;
typedef struct {
    sfMusic *music;
}music;
typedef struct my_linked_list_airplane {
    int collision_p;
    int pos_init_x;
    int pos_init_y;
    int pos_arr_x;
    int pos_arr_y;
    int speed;
    int delay;
    plane_sprite p;
    struct my_linked_list_airplane *next;
}my_plane;
typedef struct my_linked_list_tower {
    int id;
    int pos_init_x;
    int pos_init_y;
    int scale;
    tower_sprite t;
    struct my_linked_list_tower *next;
}my_tower;
typedef struct {
    int size_col;
    int size_length;
    int playing;
}size_tab;
typedef struct {
    my_plane *plane;
    my_tower *tower;
}all;
typedef struct quadtree {
    sfIntRect boundary;
    my_plane *planes;
    struct quadtree **children;
    sfBool is_divided;
} quadtree_t;
my_tower *init_tower(void);
my_plane *init_plane(void);
int space(char *word, int i);
void add_tower(my_tower *tower, char *word, show_all *show);
void add_plane(my_plane *plane, char *word, show_all *show);
void close_event(sfRenderWindow *window, sfEvent event, show_all *show);
void sprite_size(sfSprite *sprite, sfVector2f scale, sfVector2f pos);
void analyse_event(sfRenderWindow *window, show_all *show);
void init_all(all *object);
sfRenderWindow *create_window(void);
int my_help(char **av);
int arguments_invalid(void);
int error_handlings(int ac, char **av, int error);
int my_next_atoi(char *str, int i);
int my_arraylen(char **args);
int verif_word(char const *word);
int my_length(char const *word);
int my_column(char const *word);
char **my_convert_tab(char const *word, char **world, int size, int longeur_j);
int my_strcmp(char const *s1, char const *s2);
char my_putchar(char a);
int my_putstr(char const *str);
int num_len(int n);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int size_verif(int size, int longeur);
int create_plane_and_tower(char **world, size_tab *s);
int disp_tower(my_tower *tower);
int disp_plane(my_plane *plane);
int reading(char const *word, int fd);
void end_of_the_window(sfRenderWindow *window, music *music);
void sprite_background(sfRenderWindow *window, sprite *background);
tower_sprite sprite_tower(my_tower *tower, show_all *show);
plane_sprite sprite_plane(my_plane *plane, show_all *show);
int error_handlings(int ac, char **av, int error);
int simulation(sfRenderWindow *window, sprite *background, all *object,
    show_all *show);
sfCircleShape *create_circle(my_tower *t, show_all *show);
sfRectangleShape *create_rect(my_plane *p, show_all *show, sfVector2f pos);
void display_all(sfRenderWindow *window, all *object, sfClock *clock,
    show_all *show);
int move_set(sfRenderWindow *window, all *object, int i, sfClock *clock);
int mov_all(all *object, int i, sfClock *clock);
int stop(my_plane *plane);
int movement(my_plane *plane, sfTime time);
void delete_in_list(my_plane *begin, my_plane *plane);
void time(sfRenderWindow *window, sfClock *clock, int *minutes, int *hours);
void display_time(sfRenderWindow *window, int hours, int minutes,
    int secondes);
char *my_strcat(char *dest, char const *src);
char const *int_to_string(int number);
char *size_string(int number);
int size_num(int number);
void init_show(show_all *show);
int deleted(my_plane *begin, my_plane *actual, my_plane *previous,
    my_plane *plane);
char *base_case(int number);
void collision(all *object);
int verif_area(my_plane *p, all *object);
int verif_collision(my_plane *p, my_plane *pl, all *object);
void collide_rect(my_plane *p, all *object);
float rotation(my_plane *plane);
void begin_display(sfRenderWindow *window, my_plane *p, int seconds,
    show_all *show);
void display_time_output(sfClock *clock, int *hours, int *minutes);
int my_rect_collide_square(my_plane *plane, my_tower *tower);
#endif
