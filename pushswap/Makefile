CC		= gcc

# FT_SAN = -fsanitize=address
FT_SAN = 
CFLAGS	= -Wall -Wextra -Werror $(FT_SAN)

AR		= ar -rcs
RM		= /bin/rm -rf

NAME_PS	= push_swap
NAME_CH = checker

SRCS	= 	src/push_swap.c \
			src/ps_args.c src/ps_game.c \
			src/ps_solve1.c src/ps_solve2.c \
			src/ps_play_select.c src/ps_play_exec.c \
			src/ps_ops_aux.c src/ps_ops_ps.c src/ps_ops_r.c src/ps_ops_rr.c \
			src/ps_stack.c src/ps_stack2.c src/ps_stack3.c \
			src/ps_utils.c
OBJS	= $(SRCS:.c=.o)


LIBFT_PATH  = ./libft/42-libft/libft
# LIBFT_PATH  = ./libft
LIBFT	= $(LIBFT_PATH)/libft.a

all:		$(NAME_PS)

$(NAME_PS):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME_PS)
			make clean

bonus:		all

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(LIBFT):	
			make -C $(LIBFT_PATH) all

clean:
			make -C $(LIBFT_PATH) clean
			$(RM) $(OBJS)

fclean:		clean
			make -C $(LIBFT_PATH) fclean
			$(RM) $(NAME_PS)

re:			fclean all

.PHONY:		all clean fclean re libft