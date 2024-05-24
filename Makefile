##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## SIUUUUUUUUUU look at this Makefile it work.
##

SRC = src/help.c \
	src/my_strcmp.c \
	src/print.c \
	src/sprite.c \
	src/analyse_event.c \
	src/reading.c \
	src/my_convert_tab.c \
	src/add_tower_and_plane.c \
	src/my_atoi.c \
	src/creation.c \
	src/display_all.c \
	src/my_movement.c \
	src/delete_plane.c \
	src/time.c \
	src/int_to_string.c \
	src/my_strcat.c \
	src/collision.c

FILE_O = *.o
LIBMY_A = libmy.a
MY_RADAR = my_radar
CFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm


$(LIBMY_A):
	gcc -c $(SRC) -Iinclude
	gcc -g3 -o $(MY_RADAR) my_radar.c $(CFLAGS) $(SRC) -Iinclude
	make clean

clean:
	find -type f -iname '*.o' -delete
	find -type f -iname $(LIBMY_A) -delete

fclean:
	make clean
	rm -f $(MY_RADAR)

re:
	make fclean
	make
