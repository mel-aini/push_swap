# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:02:54 by mel-aini          #+#    #+#              #
#    Updated: 2023/02/11 09:04:25 by mel-aini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c find_lis.c \
	parsing/parsing.c parsing/errors.c \
	operations/sa.c operations/sb.c operations/ss.c \
	operations/pa.c operations/pb.c operations/ra.c operations/rb.c operations/rr.c \
	operations/rra.c operations/rrb.c \
	# operations/rrr.c


SRC_LIBFT = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c \
	libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c \
	libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c \
	libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
	libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c \
	libft/get_next_line/get_next_line.c libft/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

LIBFT = libft/libft.a

# FLAGS = -Wall -Wextra -Werror

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make -C libft/

$(NAME) : $(OBJ)
	cc $(LIBFT) $(OBJ) -o $@

%.o : %.c $(HEADERS)
	cc $(FLAGS) -c $< -o $@

clean :
	find . -name "*.o" -type f -delete

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re : fclean all

.PHONY : all clean fclean re