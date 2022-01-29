NAME			= minitalk
EX_NAME			= server client
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

FLAGS			= -L${LIBFT_D} -lft
RM				= rm -f
AR				= ar rcs

SRC_D			= srcs
SERVER_SRCS		= server.c
SRC_S			= $(addprefix ${SRC_D}/, ${SERVER_SRCS})

SRC_D			= srcs
CLIENT_SRCS		= client.c
SRC_C			= $(addprefix ${SRC_D}/, ${CLIENT_SRCS})

ALL_SRCS		= server.c client.c
ALL_SRCS_C		= $(addprefix ${SRC_D}/, ${ALL_SRCS})

INC_D			= includes
HEADER_LIST		= minitalk.h
HEADER_H		= $(addprefix ${INC_D}/, ${HEADER_LIST})

LIBFT			= libft.a
LIBFT_D			= libft
LIBFT_A			= $(addprefix ${LIBFT_D}/, ${LIBFT})

OBJS			= ${ALL_SRCS:.c=}

all:			${NAME}

${LIBFT}:
				make -C ${LIBFT_D}
				cp ${LIBFT_D}/${LIBFT} .

${NAME}:		${LIBFT} $(OBJS)

server: ${HEADER_H} ${SRC_S}
				${CC} -I${LIBFT_D} -I${INC_D} ${SRC_S} ${LIBFT} -o server

client: ${HEADER_H} ${SRC_C}
				${CC} -I${LIBFT_D} -I${INC_D} ${SRC_C} ${LIBFT} -o client

clean:
				$(MAKE) -C ${LIBFT_D} clean

fclean: clean
				$(MAKE) -C ${LIBFT_D} fclean
				${RM} ${LIBFT} ${EX_NAME}

re: 			fclean all
