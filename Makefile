NAME = cub3D

CC = clang
CFLAGS = -Wall -Werror -Wextra

INTERNAL_LIBS = -lmlx -lft
EXTERNAL_LIBS = -lm -lXext -lX11 

LIBFT = libft.a
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCHIVE = $(ARCHIVES_PATH)/$(LIBFT)

MLX = libmlx.a
MLX_PATH = $(LIBS_PATH)/mlx_linux
MLX_ARCHIVE = $(ARCHIVES_PATH)/$(MLX)

MAKE_EXTERNAL = make -C 
SAFE_MAKEDIR = mkdir -p

COPY = cp -p 
REMOVE = rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs
ARCHIVES_PATH = ./archives

HEADER_FILE = cub3d.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCES_FILES =	main.c \
				handle_args.c \
				read_map.c \
				temp.c \
				utils.c \
				get_map_config.c \
				create_image.c \
				check_map.c

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCES_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCES_FILES)))

all: $(NAME)

$(NAME): build_libft build_mlx $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) -g $(OBJECTS) -o $(NAME) -L $(ARCHIVES_PATH) -I $(EXTERNAL_LIBS) $(INTERNAL_LIBS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) $(CFLAGS) -g -I $(INCLUDES_PATH) -o $@ -c $<

build_libft: 
	$(MAKE_EXTERNAL) $(LIBFT_PATH)
	$(SAFE_MAKEDIR) $(ARCHIVES_PATH)
	$(COPY) $(LIBFT_PATH)/$(LIBFT) $(ARCHIVES_PATH)

build_mlx:
	$(MAKE_EXTERNAL) $(MLX_PATH)
	$(SAFE_MAKEDIR) $(ARCHIVES_PATH)
	$(COPY) $(MLX_PATH)/$(MLX) $(ARCHIVES_PATH)

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean 
	$(REMOVE) $(LIBFT_ARCHIVE)

libmlx_clean:
	$(MAKE_EXTERNAL) $(MLX_PATH) clean
	$(REMOVE) $(MLX_ARCHIVE)

re:	fclean all

archives_clean: 
	$(REMOVE) $(ARCHIVES_PATH)

clean: libft_clean libmlx_clean
	$(REMOVE) $(OBJECTS_PATH)

fclean: clean archives_clean libft_clean libmlx_clean
	$(REMOVE) $(NAME)
