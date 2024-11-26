# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:53:44 by mgendrot          #+#    #+#              #
#    Updated: 2024/11/26 02:09:42 by max_dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME        = push_swap
CHECKER     = checker

INCLUDE     = include
LIBFT       = libft/

CC          = cc 
CFLAGS      = -Wall -Wextra -Werror -I $(INCLUDE)

RM          = rm -f
MKDIR       = mkdir

# **************************************************************************** #
#                                   Colors                                     #
# **************************************************************************** #

DEF_COLOR           =   \033[0;39m
GRAY                =   \033[0;90m
RED                 =   \033[0;91m
GREEN               =   \033[0;92m
YELLOW              =   \033[0;93m
BLUE                =   \033[0;94m
MAGENTA	            =   \033[0;95m
CYAN                =   \033[0;96m
WHITE               =   \033[0;97m
BOLD                =   $'\x1b[1m'
END                 =   $'\x1b[0m'
TERM_UP             =   \033[1A
TERM_CLEAR_LINE     =   \033[2K\r

# **************************************************************************** #
#                                   Sources                                    #
# **************************************************************************** #

SRC_FILES       =   main
SRC_UTILS       =   parse utils utils_stack check
SRC_SORT_FILES 	=   tiny_sort sort get cost
PRINTERS_FILES  =   Push reverse_rotate rotate swap
SRC_BONS_FILES  =   checker 

SRC_DIR         =   src/
OBJ_DIR         =   obj/
UTILS_DIR       =   $(SRC_DIR)utils/
PRINTERS_DIR    =   $(SRC_DIR)instructions/
SRC_SORT_DIR    =   $(SRC_DIR)sort/
SRC_BONS_DIR    =   $(SRC_DIR)bonus/

SRC_PUSH_SWAP   = $(addprefix $(UTILS_DIR), $(addsuffix .c, $(SRC_UTILS))) \
                  $(addprefix $(SRC_SORT_DIR), $(addsuffix .c, $(SRC_SORT_FILES))) \
                  $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES))) \
                  $(addprefix $(PRINTERS_DIR), $(addsuffix .c, $(PRINTERS_FILES)))

OBJ_PUSH_SWAP   = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_PUSH_SWAP))

SRC_CHECKER     = $(addprefix $(SRC_BONS_DIR), $(addsuffix .c, $(SRC_BONS_FILES))) \
                  $(addprefix $(UTILS_DIR), $(addsuffix .c, $(SRC_UTILS))) \
                  $(addprefix $(PRINTERS_DIR), $(addsuffix .c, $(PRINTERS_FILES)))

OBJ_CHECKER     = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_CHECKER))



# **************************************************************************** #
#                             progress_update                                  #
# **************************************************************************** #

TOTAL_FILES := $(words $(OBJ_PUSH_SWAP) $(OBJ_CHECKER))
COMPILED_COUNT  = 0

define progress_update
    @if [ ! -f .compiled_count ]; then \
        echo 0 > .compiled_count; \
        printf "\n"; \
    fi; \
    COMPILED_COUNT=$$(cat .compiled_count); \
    COMPILED_COUNT=$$((COMPILED_COUNT + 1)); \
    echo $$COMPILED_COUNT > .compiled_count; \
    printf "$(TERM_UP)$(TERM_CLEAR_LINE)$(CYAN)Compilation progress: \
        $$((COMPILED_COUNT * 100 / $(TOTAL_FILES)))%% $(BLUE) ->$(1) $(DEF_COLOR)\n"; \
    if [ $$COMPILED_COUNT -eq $(TOTAL_FILES) ]; then \
        rm -f .compiled_count; \
    fi
endef

# **************************************************************************** #
#                                   Rules                                      #
# **************************************************************************** #

all: $(NAME)
	@echo "$(GREEN)All targets compiled successfully!$(DEF_COLOR)"

$(NAME): $(OBJ_PUSH_SWAP)
	@$(MAKE) -C $(LIBFT) all -s
	@$(CC) $(CFLAGS) $(OBJ_PUSH_SWAP) -L $(LIBFT) -lft -o $(NAME)
	@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@mkdir -p $(dir $@)
	$(call progress_update,$(notdir $@))
	@$(CC) $(CFLAGS) -c $< -o $@


bonus: $(CHECKER)

$(CHECKER): $(OBJ_CHECKER)
	@$(MAKE) -C $(LIBFT) all -s
	@$(CC) $(CFLAGS) $(OBJ_CHECKER) -L $(LIBFT) -lft -o $(CHECKER)
	@echo "$(GREEN)Checker bonus compiled!$(DEF_COLOR)"

$(OBJF):
	@$(MKDIR) -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR);
	@echo "$(RED)push_swap object files cleaned!$(DEF_COLOR)";
	@$(MAKE) clean -C $(LIBFT) -s

fclean: clean
	
	@$(RM) $(NAME);
	@echo "$(CYAN)push_swap executable cleaned!$(DEF_COLOR)"; 
	@$(RM) $(CHECKER);
	@echo "$(CYAN)Checker bonus cleaned!$(DEF_COLOR)";
	@$(MAKE) fclean -C $(LIBFT) -s

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

norm:
	@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm bonus
