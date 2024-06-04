END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m
ERASE=\033[2K\r

HEADPATH	=	-I vector	\
				-I matrix

VECTOR_DIR		= vector
MATRIX_DIR		= matrix	

SRCS		=	main.cpp								

INCLUDES	=	${VECTOR_DIR}/Vector.hpp	\
				${MATRIX_DIR}/Matrix.hpp	\
				main.hpp								

CC					=	c++
FLAGS				=	-std=c++98 -Wall -Wextra -Werror
RM					=	rm -rf

NAME 	=	ft_matrix

.PHONY: all
all: $(NAME)

.PHONY: $(NAME)
$(NAME): 
	$(CC) -D NAMESPACE=1 ${SRCS} ${HEADPATH} -o $@
	# @echo "$(ERASE)$(GREEN)[CREATED $@]$(END)"
	
.PHONY: clean
clean:
	${RM} .objects
	# @echo "${RED}[DELETED]${END} .objects"

.PHONY: fclean
fclean: clean
	${RM}	$(NAME)
	# @echo "${RED}[DELETED]${END} $(NAME)"

.PHONY: re
re:			fclean all