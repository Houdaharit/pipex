NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC = pipex.c ft_strjoin.c ft_strnstr.c ft_split.c pipex_utils.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: all
