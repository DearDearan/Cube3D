# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀     #
#                                                     +:+ +:+         +:+      #
#    By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/29 15:25:20 by lifranco          #+#    #+#              #
#    Updated: 2026/10/22 21:23:49 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟            #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

# COLORS

RESET := \033[0m
GREEN  := \033[0;32m
YELLOW := \033[0;33m
RED :=	\033[0;32m

# FLAGS
CC := cc
CFLAGS	= -Wall -Wextra -Werror -Iinclude -Iinclude/MacroLibX -g
MAKEFLAGS += --no-print-directory

LIBFT_DIR := include/libft/
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_DIR)$(LIBFT_NAME)


PEGGLE_DELUXE_DIR := include/peggle_deluxe/
PEGGLE_DELUXE_NAME := libpeggle_deluxe.a
PEGGLE_DELUXE := $(PEGGLE_DELUXE_DIR)$(PEGGLE_DELUXE_NAME)

MACROLIBX_DIR := include/MacroLibX/
MACROLIBX_NAME := libmlx.so
MACROLIBX := $(MACROLIBX_DIR)$(MACROLIBX_NAME)

# DEBUGGING FLAGS
ifeq ($(DEBUG),true)
    CFLAGS += -g
endif

ifeq ($(FSANITIZE), true)
	CFLAGS += -fsanitize=address
endif
# DEBUGGING FLAGS END

SRC_DIR	:= src/
PARSE_DIR := parser/
CAST_DIR := casting/
BONUS_SRC_DIR := bonus_src/
BONUS_MOVE_DIR := move/
BONUS_SOUND_DIR := sound/
BONUS_VECTORS_DIR := vectors/

# BASENAMES
SRC_BASENAMES_COMMON := main map_utils loading free_main
SRC_BASENAMES := keys
CAST_BASENAMES := init_cast raycast render get_txtrs 
PARSE_BASENAMES_COMMON := check_walls cleanup
PARSE_BASENAMES := utils parser

## BONUS
BONUS_CAST_BASENAMES := calc_door minimap sprites
BONUS_MOVE_BASENAMES := doors keys move
BONUS_PARSE_BASENAMES := maker matches utils parser
BONUS_SOUND_BASENAMES := ms_sfx
BONUS_VECTORS_BASENAMES := create

# ANIMATION
mute ?= 0

all :
	make start
	-make $(NAME)
	make stop

stop:
	@-pkill -f "sh ./.build/an[i]m.sh"
	@echo "--------------------------------------\n$(NAME) compiled!\n\n"
	@printf "################################################\n"
	@printf "## WELCOME TO DANGANRONCUB3: CODERS'S DESPAIR ##\n"
	@printf "################################################\n\n\n"
	@printf "(if you do not see Hajime, everything has been built or \
	something has gone terribly wrong.)\n"
start:
	@sh ./.build/anim.sh&
	@clear
	@$(if $(filter 0, $(mute)), \
	paplay .build/danganronpa.wav&,)
	@echo "\e[27B"

# COMPILE

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES))) \
		$(addprefix $(SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES_COMMON))) \
		$(addprefix $(SRC_DIR)$(CAST_DIR), $(addsuffix .c,$(CAST_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(PARSE_DIR), $(addsuffix .c,$(PARSE_BASENAMES_COMMON))) \
		$(addprefix $(SRC_DIR)$(PARSE_DIR), $(addsuffix .c,$(PARSE_BASENAMES))) \

BONUS_SRCS := $(addprefix $(BONUS_SRC_DIR), $(addsuffix .c,$(SRC_BASENAMES_COMMON))) \
		$(addprefix $(BONUS_SRC_DIR)$(CAST_DIR), $(addsuffix .c,$(CAST_BASENAMES))) \
		$(addprefix $(BONUS_SRC_DIR)$(CAST_DIR), $(addsuffix .c,$(BONUS_CAST_BASENAMES))) \
		$(addprefix $(SRC_DIR)$(PARSE_DIR), $(addsuffix .c,$(PARSE_BASENAMES_COMMON))) \
		$(addprefix $(BONUS_SRC_DIR)$(PARSE_DIR), $(addsuffix .c,$(BONUS_PARSE_BASENAMES))) \
		$(addprefix $(BONUS_SRC_DIR)$(BONUS_MOVE_DIR), $(addsuffix .c,$(BONUS_MOVE_BASENAMES))) \
		$(addprefix $(BONUS_SRC_DIR)$(BONUS_SOUND_DIR), $(addsuffix .c,$(BONUS_SOUND_BASENAMES))) \
		$(addprefix $(BONUS_SRC_DIR)$(BONUS_VECTORS_DIR), $(addsuffix .c,$(BONUS_VECTORS_BASENAMES)))

OBJ_DIR := .build/objs/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

LDFLAGS := -Linclude -Linclude/MacroLibX -lmlx -lSDL2 -lm -Wl,-rpath,'$$ORIGIN/include/MacroLibX/'

bonus: fclean $(MACROLIBX)
	@$(MAKE) -C $(PEGGLE_DELUXE_DIR) CFLAGS="-Wall -Wextra -Werror -ggdb -DMAX_MATCHES=40"
	
	make $(NAME) CFLAGS="-Wall -Wextra -Werror -Ibonus_src/include\
		-Iinclude/MacroLibX/includes -Iinclude/peggle_deluxe/include\
		-Iinclude/libft/includes -g -DMAX_MATCHES=40" SRCS="$(BONUS_SRCS)"
	make clean

$(MACROLIBX):
	@$(MAKE) -j -C $(MACROLIBX_DIR)
	@printf "$(GREEN)$(BOLD)%-20s [OK]$(RESET)\n" "MacroLibX"

$(NAME): $(MACROLIBX) $(OBJS) $(PEGGLE_DELUXE) $(LIBFT)
	@$(CC) $^ $(LDFLAGS) -o $@

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "$(GREEN)$(BOLD)%-20s [OK]$(RESET)\n" "libft"

$(PEGGLE_DELUXE): FORCE
	@$(MAKE) -C $(PEGGLE_DELUXE_DIR)
	@printf "$(GREEN)$(BOLD)%-20s [OK]$(RESET)\n" "peggle_deluxe"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	@printf "$(GREEN)$(BOLD)%-20s [OK]$(RESET)\n" "$<"


clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PEGGLE_DELUXE_DIR) clean
	@printf "Erasing the .o ? But i've put them out of your sight, Puhuhuhu...\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PEGGLE_DELUXE_DIR) fclean
	@clear
	@cat .build/clean.txt
	@echo "\n\n\n\n"
	@printf "Destroying the project? See you next time, Puhuhuhuhu!\n\n"
	@$(if $(filter 0, $(mute)), \
	paplay .build/buh_bye.wav,)

re: fclean all

FORCE:

.PHONY: re all clean fclean start stop bonus FORCE
