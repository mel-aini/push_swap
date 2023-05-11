# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:02:54 by mel-aini          #+#    #+#              #
#    Updated: 2023/05/11 18:05:56 by mel-aini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

HEADERS = mandatory/push_swap.h mandatory/parsing/parsing.h mandatory/find_lis/find_lis.h \
	mandatory/push_swap_utils/push_swap_utils.h mandatory/operations/operations.h mandatory/helpers/helpers.h

HEADERS_BONUS = bonus/checker.h bonus/parsing/parsing.h bonus/operations/operations.h bonus/helpers/helpers.h

SRC = mandatory/push_swap.c mandatory/find_lis/find_lis.c mandatory/find_lis/find_lis_utils.c \
	mandatory/parsing/parsing.c mandatory/parsing/parsing_utils.c mandatory/parsing/errors.c \
	mandatory/push_swap_utils/sort_small_nums.c mandatory/push_swap_utils/push_not_exist_to_stack_b.c \
	mandatory/push_swap_utils/iterate_stack_b.c mandatory/push_swap_utils/iterate_stack_b_2.c \
	mandatory/push_swap_utils/small_functions.c mandatory/push_swap_utils/put_small_at_top.c\
	mandatory/operations/sa.c mandatory/operations/sb.c mandatory/operations/ss.c \
	mandatory/operations/pa.c mandatory/operations/pb.c \
	mandatory/operations/ra.c mandatory/operations/rb.c mandatory/operations/rr.c \
	mandatory/operations/rra.c mandatory/operations/rrb.c mandatory/operations/rrr.c \
	mandatory/helpers/ft_strlen.c mandatory/helpers/ft_strncmp.c mandatory/helpers/ft_strlcpy.c mandatory/helpers/ft_atoi.c mandatory/helpers/ft_strtrim.c \
	mandatory/helpers/ft_split.c mandatory/helpers/ft_lstnew.c mandatory/helpers/ft_lstsize.c mandatory/helpers/ft_lstadd_back.c

SRC_BONUS = bonus/checker.c \
	bonus/parsing/parsing.c bonus/parsing/parsing_utils.c bonus/parsing/errors.c \
	bonus/operations/sa.c bonus/operations/sb.c bonus/operations/ss.c \
	bonus/operations/pa.c bonus/operations/pb.c \
	bonus/operations/ra.c bonus/operations/rb.c bonus/operations/rr.c \
	bonus/operations/rra.c bonus/operations/rrb.c bonus/operations/rrr.c \
	bonus/helpers/ft_strlen.c bonus/helpers/ft_strncmp.c bonus/helpers/ft_strlcpy.c bonus/helpers/ft_atoi.c bonus/helpers/ft_strtrim.c \
	bonus/helpers/ft_split.c bonus/helpers/ft_lstnew.c bonus/helpers/ft_lstsize.c bonus/helpers/ft_lstadd_back.c \
	bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAGS) $(OBJ) -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	cc $(FLAGS) $(OBJ_BONUS) -o $@

mandatory/%.o : mandatory/%.c $(HEADERS)
	cc $(FLAGS) -c $< -o $@

bonus/%.o : bonus/%.c $(HEADERS_BONUS)
	cc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus