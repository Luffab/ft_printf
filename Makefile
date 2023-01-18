NAME = libftprintf.a
SRCS =  libft/ft_memset.c \
		libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memccpy.c \
		libft/ft_memmove.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_strlen.c \
		libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_toupper.c \
		libft/ft_tolower.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strncmp.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
		libft/ft_strnstr.c \
		libft/ft_atoi.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c 

SRCS_PRINTF = srcs/ft_printf.c \
				srcs/ft_parse.c \
				srcs/ft_parse2.c \
				srcs/ft_parse3.c \
				srcs/ft_parse4.c \
				srcs/ft_convert_string.c \
				srcs/ft_convert_string2.c \
				srcs/ft_convert_p.c \
				srcs/ft_convert_nbpos.c \
				srcs/ft_convert_nbneg.c \
				srcs/ft_convert_u.c \
				srcs/ft_convert_hexa.c \
				srcs/ft_itoa_base.c \
				srcs/ft_itoa_base2.c

HEADER = libft.h
OBJS = ${SRCS:.c=.o}
OBJS_SRCS = $(SRCS_PRINTF:.c=.o)

.c.o: $(HEADER)
	gcc -Wall -Wextra -Werror -I include -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS) $(OBJS_SRCS)
	ar rc $(NAME) $(OBJS) $(OBJS_SRCS)

all : $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_SRCS)

fclean: clean
	rm -f  $(NAME)

re: fclean all