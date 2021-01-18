NAME		= miniRT
CC				= clang -Wall -Werror -Wextra
RM				= rm -rf

MLX_PATH		= ./libs/minilibx-linux/
MLX_NAME		= $(MLX_PATH)libmlx.a
MLX_INC			= -I$(MLX_PATH)
MLX_MAC_PATH 	= ./libs/mlx/
MLX_MAC_NAME 	= $(MLX_MAC_PATH)libmlx.dylib

LIBC_PATH		= ./libs/ft_libc/
LIBC_NAME		= $(LIBC_PATH)libftc.a
LIBC_INC		= -I$(LIBC_PATH)

SRCS_PATH		= ./srcs/
OBJS_PATH		= ./objs/
INC				= ./includes/

SRCS_NAME	=	minirt.c 									\
				parsing/ft_free.c							\
				parsing/ft_utils.c 							\
				parsing/ft_parser.c 						\
				parsing/ft_init_scene.c 					\
				parsing/ft_parsing_lib.c					\
				parsing/ft_parsing_lib2.c					\
				parsing/ft_check_params.c 					\
				parsing/ft_objs_config.c					\
				parsing/ft_line_parser.c					\
				parsing/ft_config_utils.c 					\
				parsing/ft_scene_config.c					\
				parsing/ft_get_obj_components.c				\
				rendering/ft_display.c						\
				rendering/ft_render.c						\
				rendering/ft_look_at.c						\
				rendering/ft_get_phong.c					\
				rendering/ft_lightning.c					\
				rendering/ft_collision.c					\
				rendering/ft_color_helpers.c				\
				rendering/ft_plane_collision.c				\
				rendering/ft_square_collision.c				\
				rendering/ft_sphere_collision.c				\
				rendering/ft_vector_computing_01.c			\
				rendering/ft_vector_computing_02.c			\
				rendering/ft_triangle_collision.c			\
				rendering/ft_cylinder_collision.c			\
				rendering/ft_bitmap.c								

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
	#OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

all: $(NAME)

%.o: %.c
	$(CC) -I$(INC) -Imlx $(LIBC_INC) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	$(info mlx compiled)
	make -C $(LIBC_PATH)
	$(info libft compiled)
	$(CC) $(OBJS) $(MLX_NAME) $(LIBC_NAME) -L$(MLX_PATH) -L$(LIBC_PATH) $(LIBC_INC) $(MLX_INC) -I$(INC) -lXext -lX11 -lm -o $(NAME) 
#	$(CC) $(OBJS) $(LIBC_NAME) -L$(LIBC_PATH) $(LIBC_INC) -I$(INC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
	$(info minirt ready)

nice: all clean

renice:
	make re
	make clean

clean:
	make clean -C $(LIBC_PATH)
	$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	$(info executable file deleted)

re-libs:
	@make re -C $(MLX_PATH)
	$(info MLX re-made)
	@make re -C $(LIBC_PATH)
	$(info libft re-made)

re: re-libs fclean all

.PHONY: re fclean all clean
