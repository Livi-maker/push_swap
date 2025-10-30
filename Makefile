# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 14:15:06 by ldei-sva          #+#    #+#              #
#    Updated: 2025/02/01 19:28:33 by ldei-sva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
##
## MY_SOURCES = $(wildcard *.c)
##
## MY_OBJECTS = $(MY_SOURCES:.c=.o)
##
## BONUS_SRC = $(wildcard checker/*.c)
##
## BONUS_OBJ = $(BONUS_SRC:.c=.o)
##
##

CFLAGS = -Wall -Werror -Wextra
LIBOBJECTS = -Llibft -lft
INCLUDE = -Ilibft -I/usr/include

RM		= rm -f
MKDIR	= mkdir -p

FILES = final_sorting \
		check_input \
		push_swap_utils \
		main \
		reverse_rotate \
		rotate \
		sorting \
		sorting_utils \
		order_three \
		swap \
		push

SRCS_DIR = srcs
OBJS_DIR = objs

MY_SOURCES = $(addsuffix .c, $(FILES))
MY_OBJECTS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

vpath %.c $(SRCS_DIR)

all: $(NAME)

my_checker: $(BONUS_OBJ) lib
	$(CC) $(BONUS_OBJ) $(LIBOBJECTS) -o my_checker

$(NAME): $(MY_OBJECTS) lib
	$(CC) $(MY_OBJECTS) $(LIBOBJECTS) -o $(NAME)

$(OBJS_DIR)/%.o:%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

lib:
	make -C libft
	make bonus -C libft

bonus: my_checker

clean:
	$(RM) $(MY_OBJECTS)
	make clean -C libft
	$(RM) $(BONUS_OBJ)
	$(RM) -r $(OBJS_DIR)

fclean:
	$(RM) $(MY_OBJECTS) $(NAME)
	make fclean -C libft
	$(RM) $(BONUS_OBJ)
	$(RM) my_checker

re: fclean all
