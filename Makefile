SRC = src/get_next_line_utils.c src/get_next_line.c

OBJ_FILES	=	$(SRC:.c=.o)
RM 			= rm -rf

NAME		= get_next_line.a
# CFLAGS		= -Wall -Wextra -Werror -I .

$(NAME): $(OBJ_FILES)
	ar -crs $(NAME) $(OBJ_FILES)

all: $(NAME)

clean :
	$(RM) $(OBJ_FILES)

fclean :
	$(RM) $(OBJ_FILES) $(NAME)

re : $(clean) $(NAME)
