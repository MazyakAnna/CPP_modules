NAME = bureaucrat

SRCS = Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp

HEADERS = Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp colours.hpp

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
