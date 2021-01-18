NAME = libftc.a

LBPATH = ./libft/

LBNAME = $(LBPATH)libft.a

SRCS = ft_printf.c \
	   ft_conversion_picker.c \
	   ft_print.c \
	   ft_convert.c \
	   ft_parsing.c \
	   ft_utils.c \
	   ft_utils2.c

SRCS_PATH = ./ft_printf_srcs/

SRCS_NAME = $(addprefix $(SRCS_PATH), $(SRCS))

OBJS_NAME = ${SRCS:.c=.o}

OBJS_PATH = ./ft_printf_srcs/objs/

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

CC	 =	gcc -Wall -Werror -Wextra

RM	 = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LBPATH)
	@cp $(LBNAME) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	$(info ft_libc compiled !)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) -I ft_printf.h -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make fclean -C $(LBPATH)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
