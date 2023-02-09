NAME = pipex

NAME_BONUS = pipex_bonus

DIRSRC = ./srcs/mandatory

DIRBONUS = ./srcs/bonus

DIRCINC = ./includes/

DIRLIB = ./libft/

SRC =	childs \
		utils \
		main \

SRC_B =	childs \
		here_doc \
		initialization \
		main \
		utils \

SRCS = $(addprefix ${DIRSRC}/, $(addsuffix .c, ${SRC}))

SRCS_B = $(addprefix ${DIRBONUS}/, $(addsuffix .c, ${SRC_B}))

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

LFT = libft.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

.c.o:
	@${CC} ${CFLAGS} -c -I${DIRCINC} -I${DIRLIB} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@cd ${DIRLIB} && ${MAKE}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L./libft -lft
	@echo "🚀 pipex has been created 🚀"

${NAME_BONUS}: ${OBJS_B}
	@cd ${DIRLIB} && ${MAKE}
	@${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_B} -L./libft -lft
	@echo "💰 pipex_bonus has been created 💰"

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
	@${RM} ${OBJS} ${OBJS_B}
	@cd ${DIRLIB} && ${MAKE} clean
	@echo "🧽 Directory is clean 🧽"

fclean:
	@${RM} ${OBJS} ${OBJS_B}
	@${RM} ${NAME} ${NAME_BONUS}
	@cd ${DIRLIB} && ${MAKE} fclean
	@echo "🔥 Directory is fclean 🔥"

re : fclean all

.PHONY : all clean fclean re bonus