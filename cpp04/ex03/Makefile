NAME = polymorph

SRCS = AMateria.cpp MateriaSource.cpp Cure.cpp Ice.cpp Character.cpp main.cpp

HEADERS = AMateria.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp Cure.hpp Ice.hpp Character.hpp colours.hpp

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
