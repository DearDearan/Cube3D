SOURCES := src/parse.c src/parsing_helpers.c src/peg_maybe.c src/peg_rule_manager.c src/string_view.c \
		src/parse_macro.c src/peg.c src/peg_public_api.c src/peg_rule_unparameterized.c src/utils.c \
		src/parse_micro.c src/peg_group.c src/peg_rule_container.c src/run.c
NAME	:=	libpeggle_deluxe.a
BUILD_DIR := build/
INCLUDES := ./include
OBJECTS := $(SOURCES:src/%.c=$(BUILD_DIR)%.o)
DEPS := $(OBJECTS:.o=.d)
CFLAGS := -Wall -Wextra -Werror -MMD -MP -ggdb
LDFLAGS := -lreadline
CC := cc

all: $(NAME)

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
	@-rm -fr $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)
