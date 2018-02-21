# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 17:07:31 by vmercadi          #+#    #+#              #
#    Updated: 2018/02/19 18:38:17 by cquillet         ###   ########.fr        #
#    Updated: 2018/02/16 19:48:27 by cquillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = srcs/maintest2.c srcs/error.c srcs/event.c srcs/vect_calc1.c \
	srcs/vect_calc2.c srcs/vect_utils.c srcs/utils.c srcs/init.c \
	srcs/intersections.c srcs/color.c srcs/lux.c srcs/scene.c srcs/matrice.c \
	srcs/cam.c srcs/vector.c srcs/to_fdf.c srcs/obj.c srcs/calc_obj.c 	\
	srcs/action.c srcs/event_obj.c srcs/parsing.c srcs/help.c
#srcs/afficahgetest. \

INCLUDES = -I includes -I libft -I lib/SDL2/Headers
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
MFLAGS = -lpthread -O3
SDL = lib/SDL2/SDL2
SRCO = $(SRC:%.c=%.o)
LIB = lib/libft/libft.a
H = includes/RTv1.h includes/parse.h

# Installing SDL2_ttf and SDL2_image if necessary
SDL_IMG := $(shell ls ~/.brew/lib/ | grep libSDL2_image.a)
SDL_TTF := $(shell ls ~/.brew/lib/ | grep libSDL2_ttf.a)
ifeq ($(SDL_TTF), "libSDL2_ttf.a")
	$(shell brew install SDL2_ttf))
endif

ifeq ($(SDL_IMG), "libSDL2_image.a")
	$(shell "brew install SDL2_image))
endif

.PHONY: all re cleans

all: $(NAME)

$(NAME):$(H) $(SRCO)
	@make -s -C lib/libft/
	@echo "\033[32;4mLIBFT\x1b[0m	\033[32;7mcompiled\x1b[0m"
	@gcc $(CFLAGS) $(SDL) $(LIB) -o $(NAME) $(SRC) $(MFLAGS)
	@echo "\033[32;4mRTV1\x1b[0m	\033[32;7mcompiled\x1b[0m"
	@echo "\033[32;3m-----------------------------------"
	@echo "Things went great ! For this time.."
	@echo "-----------------------------------\x1b[0m"

it: all
	@./RTv1

clean:
	@rm -rf $(SRCO)
	@make clean -s -C lib/libft/

fclean: clean
	@rm -rf $(NAME)

re: fclean all

ultra: all clean

reit: re clean
	@./RTv1
