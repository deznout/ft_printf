NAME = 	libftprintf.a

SRCS =	ft_printf.c		ft_itoa.c		parsing.c		hex_all.c		nums.c\
		string.c		un_nums.c		utils2.c		point.c\
		hex_utils.c		nums_utils.c

HEADER = ft_printf.h

OBJS = $(patsubst %.c, %.o, $(SRCS))


CFLAGS  = -Wall -Wextra -Werror

ARCS = ar rcs

RM	= rm -f

all : $(NAME)

$(NAME): $(OBJS)
	$(ARCS)	$(NAME)	$?

bonus : re

%.o : %.c $(HEADER)
	gcc -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_bonus)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
