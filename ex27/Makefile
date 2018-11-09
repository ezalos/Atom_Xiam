# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 16:50:28 by ldevelle          #+#    #+#              #
#    Updated: 2018/11/09 17:40:36 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRCS = srcs/*.c

OBJS = ./*.o

HEAD = includes/*.h

FLAG = 	-Wall\
		-Werror\
		-Wextra

all : $(NAME) clean

$(OBJS):
			gcc -c $(FLAG) $(SRCS) -I $(HEAD)

$(NAME):	$(OBJS)
			gcc -o $(NAME) $(FLAG) $(OBJS) -I $(HEAD)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
			rm -rf $(OBJS)
