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

CFLAGS = -Wall -Werror -Wextra
LIBOBJECTS = -Llibft -lft
INCLUDE = -Ilibft -I/usr/include

RM		= rm -f
MKDIR	= mkdir -p

FILES = algorithm \
		check_input \
		push_swap_utils \
		main \
		reverse_rotate \
		rotate \
		sorting \
		sorting_utils \
		order_three \
		swap \
		push \
		algorithm_utils

BONUS = operations_bonus \
		parser_bonus \
		push_swap_utils_bonus \
		reverse_rotate_bonus \
		rotate_stack_bonus \
		tester_bonus

SRCS_DIR = srcs
OBJS_DIR = objs
BONUS_DIR = checker

MY_SOURCES = $(addsuffix .c, $(FILES))
BONUS_SOURCES = $(addsuffix .c, $(BONUS))
MY_OBJECTS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))
BONUS_OBJ = $(addprefix $(BONUS_DIR)/, $(addsuffix .o, $(BONUS)))

vpath %.c $(SRCS_DIR):$(CHECKER)

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
