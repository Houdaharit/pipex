NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC = src/pipex.c src/ft_strjoin.c src/ft_strnstr.c\
      src/ft_split.c src/pipex_utils.c src/ft_putstr.c

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

fclean : clean

re: fclean all
