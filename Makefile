SRC = get_next_line_utils.c get_next_line.c

OBJ_FILES	=	$(SRC:.c=.o)
RM 			= rm -rf

NAME		= get_next_line.a
CFLAGS		= -Wall -Wextra -Werror -I .

$(NAME): $(OBJ_FILES)
	ar rc  $(NAME) $(OBJ_FILES)

all: $(NAME)

clean :
	$(RM) $(OBJ_FILES)

fclean :
	$(RM) $(OBJ_FILES) $(NAME)

re : fclean $(NAME)

#.PHONY : fclean clean re