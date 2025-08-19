
CC=gcc
FLAGS=-Wall -Werror -pthread

all: client server

client: client.c
	$(CC) $(FLAGS) client.c utils.c -o client

server: server.c
	$(CC) $(FLAGS) server.c utils.c -o server
