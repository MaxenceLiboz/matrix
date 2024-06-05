HEADPATH	=	-I vector	\
				-I matrix

VECTOR_DIR		= vector
MATRIX_DIR		= matrix	


INCLUDES	=	${VECTOR_DIR}/Vector.hpp	\
				${MATRIX_DIR}/Matrix.hpp								

CC					=	c++
FLAGS				=	-std=c++98 -Wall -Wextra -Werror
RM					=	rm -rf

SRCS = main.cpp
NAME = ex00

.PHONY: all
all: $(NAME)

.PHONY: $(NAME)
$(NAME):
	$(CC) -D NAMESPACE=0 $(NAME)/${SRCS} ${HEADPATH} -o matrix_$@
	
.PHONY: clean
clean:
	${RM} matrix_$(NAME)

.PHONY: re
re:	clean all