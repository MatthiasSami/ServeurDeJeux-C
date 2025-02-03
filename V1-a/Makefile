# Définitions des variables
CC = gcc
CFLAGS = -I../include -Wall
SRC = main.c server.c jeux.c
OBJ = $(SRC:.c=.o)
TARGET = main

# Règles de compilation
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

