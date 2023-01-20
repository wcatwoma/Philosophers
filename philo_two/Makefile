SRCS = main.c parse.c \
	philosopher.c utils.c \
	forks.c pthread.c \
	utils.c utils2.c \
	control.c \
	time.c 
HEADER = ./header.h
APP = philo_two
FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:%.c=%.o)

all: $(APP)

$(APP): $(OBJS)
	gcc $(FLAGS) -o $@ $^

%.o: %.c $(HEADER)
	gcc -I $(HEADER) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -f $(APP)

re: fclean all

.PHONY: all, clean, fclean, re
