# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 16:35:58 by minhulee          #+#    #+#              #
#    Updated: 2024/04/22 16:52:11 by minhulee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


CC			=	cc
CFLAGS		=	-c -Werror -Wall -Wextra

SRCS_M		=	ft_printf.c \
				read_formats.c \
				print_format.c \
				print_format_c.c \
				print_format_s.c \
				print_format_p.c \
				print_format_di.c \
				print_format_u.c \
				print_format_xX.c \
				print_format_per.c \
				print_without_format.c \
				util_printf.c

OBJS_M		=	$(SRCS_M:.c=.o)

NAME 		=	libftprintf.a

all 		:	$(NAME)

%.o 		:	%.c
				$(CC) $(CFLAGS) $< -o $@

$(NAME)		:	$(OBJS_M)
				ar cr $@ $^

clean		:
				rm -f $(OBJS_M) $(OBJS_B)

fclean		:
				make clean
				rm -f $(NAME)

re			: 
				make fclean
				make all

.PHONY		:	all bonus clean fclean re