CC		= gcc

# FT_SAN = -fsanitize=address
FT_SAN = 
CFLAGS	= -Wall -Wextra -Werror $(FT_SAN)

AR		= ar -rcs
RM		= /bin/rm -rf

NAME	= push_swap

SRCS	= 	push_swap.c ps_args.c ps_game.c ps_stack.c \
			ps_ops_aux.c ps_ops_ps.c ps_ops_r.c ps_ops_rr.c \
			ps_solver.c ps_solve_small.c \
			ps_utils.c 
OBJS	= $(SRCS:.c=.o)

LIBFT_PATH  = ./libft/42-libft/libft
# LIBFT_PATH  = ./libft
LIBFT	= $(LIBFT_PATH)/libft.a

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
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
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft