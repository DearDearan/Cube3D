# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 13:42:42 by rboutelo          #+#    #+#              #
#    Updated: 2026/10/23 11:03:24 by lifranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include sources.mk
NAME	:=	libft.a
INCLUDES := ./includes
BUILD_DIR := build/
OBJECTS := $(SOURCES:src/%.c=$(BUILD_DIR)%.o)
DEPS := $(OBJECTS:.o=.d)
CFLAGS := -Wall -Werror -Wextra -MMD -MP -g3
CC := cc

all: monolithic

monolithic: $(NAME)

hierarchical: configure
	./waf build

configure:
	./waf configure

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(BUILD_DIR) $(OBJECTS)
	@ar r $(NAME) $(OBJECTS)

clean:
	@-rm -f $(OBJECTS)

fclean: clean
	@-rm -f $(NAME)

re: fclean all

test: all
	testament all

.PHONY: clean all re fclean hierarchical configure monolithic
-include $(DEPS)
