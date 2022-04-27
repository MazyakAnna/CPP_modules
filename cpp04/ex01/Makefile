NAME = polymorph

SRCS = Animal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp

HEADERS = Animal.hpp Dog.hpp Cat.hpp Brain.hpp colours.hpp

CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror --std=c++98
RM = rm -f

OBJS = ${SRCS:%.cpp=%.o}

all: ${NAME}

.cpp.o:
	${CPP} ${CPPFLAGS} -c $@ -o $<

${OBJS}: ${HEADERS} ${SRCS}
	${CPP} ${CPPFLAGS} -c ${SRCS}

${NAME} : ${OBJS}
	${CPP} ${CPPFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
