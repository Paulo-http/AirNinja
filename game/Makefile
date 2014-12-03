TARGETS = game

CC = gcc -std=c99
SRC = $(wildcard */*.c)
OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -pedantic

LIBS = -lallegro  -lallegro_color -lallegro_audio -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_dialog -lallegro_acodec -lopencv_core -lopencv_highgui

all: $(TARGETS)

game: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGETS)
	rm -rf */*.o
