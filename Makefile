SRC = get_next_line_utils.c get_next_line.c
B_SRC = get_next_line_utils_bonus.c get_next_line_bonus.c

OBJ_FILES	=	$(SRC:.c=.o)

B_OBJ_FILES	=	$(B_SRC:.c=.o)

RM 			= rm -rf

NAME		= get_next_line.a

CFLAGS		= -Wall -Wextra -Werror

$(NAME): $(OBJ_FILES)
	ar rc  $(NAME) $(OBJ_FILES)

all: $(NAME)

bonus: $(OBJ_FILES) $(B_OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES) $(B_OBJ_FILES)

clean :
	$(RM) $(OBJ_FILES) $(B_OBJ_FILES)

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

#.PHONY : fclean clean re
