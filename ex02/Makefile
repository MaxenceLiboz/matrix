HEADPATH	=	-I ../vector	\
				-I ../matrix

VECTOR_DIR		= ../vector
MATRIX_DIR		= ../matrix	

SRCS		=	main.cpp								

INCLUDES	=	${VECTOR_DIR}/Vector.hpp	\
				${MATRIX_DIR}/Matrix.hpp								

CC					=	c++
FLAGS				=	-std=c++98 -Wall -Wextra -Werror
RM					=	rm -rf

NAME 	=	ex02

.PHONY: all
all: $(NAME)

.PHONY: $(NAME)
$(NAME): 
	$(CC) -D NAMESPACE=1 ${SRCS} ${HEADPATH} -o $@
	
.PHONY: clean
clean:
	${RM} .objects

.PHONY: fclean
fclean: clean
	${RM}	$(NAME)

.PHONY: re
re:			fclean all