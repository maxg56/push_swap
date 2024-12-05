# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxence <maxence@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:53:44 by mgendrot          #+#    #+#              #
#    Updated: 2024/12/05 17:41:29 by maxence          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME        = push_swap
CHECKER     = checker

INCLUDE     = include
LIBFT       = libft/

CC          = cc 
CFLAGS      = -Wall -Wextra -Werror -I $(INCLUDE) -g -O0 

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
SRC_UTILS		=	parse utils utils_stack check utils_stack_2 utils_move
SRC_SORT_FILES 	=   tiny_sort sort get cost sotrt_5
PRINTERS_FILES  =   Push reverse_rotate rotate swap
SRC_BONS_FILES  =   checker 

SRC_DIR         = src/
UTILS_DIR       = $(SRC_DIR)utils/
PRINTERS_DIR    = $(SRC_DIR)instructions/
SRC_SORT_DIR    = $(SRC_DIR)sort/
SRC_BONS_DIR    = $(SRC_DIR)bonus/

SRC			    =   $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES))) \
                    $(addprefix $(UTILS_DIR), $(addsuffix .c, $(SRC_UTILS))) \
                    $(addprefix $(SRC_SORT_DIR), $(addsuffix .c, $(SRC_SORT_FILES))) \
                    $(addprefix $(PRINTERS_DIR), $(addsuffix .c, $(PRINTERS_FILES))) 

SRC_BONS		=   $(addprefix $(UTILS_DIR), $(addsuffix .c, $(SRC_UTILS))) \
                    $(addprefix $(PRINTERS_DIR), $(addsuffix .c, $(PRINTERS_FILES))) \
                    $(addprefix $(SRC_BONS_DIR), $(addsuffix .c, $(SRC_BONS_FILES)))

OBJ_DIR         = obj/
OBJ             = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
OBJ_BONS		= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_BONS))
DEPS            = $(OBJ:.o=.d)

# **************************************************************************** #
#                             progress_update                                  #
# **************************************************************************** #

TOTAL_FILES     := $(words $(OBJ))
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
	@printf "$(TERM_CLEAR_LINE)$(GREEN)All targets compiled successfully!\n$(DEF_COLOR)"

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT) all -s
	@$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT) -lft -o $(NAME)
	@printf "$(GREEN)push_swap compiled!\n$(DEF_COLOR)"

$(OBJ_DIR)%.o: %.c | $(OBJF)
	@mkdir -p $(dir $@)
	$(call progress_update,$(notdir $@))
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(OBJ_BONS)
	@$(MAKE) -C $(LIBFT) all -s
	@$(CC) $(CFLAGS) $(OBJ_BONS) -L $(LIBFT) -lft -o $(CHECKER)
	@printf "$(GREEN)Checker bonus compiled!\n$(DEF_COLOR)"

-include $(DEPS)

%.d: %.c
	@$(CC) $(CFLAGS) -MM $< -MF $@

$(OBJF):
	@$(MKDIR) -p $(OBJ_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		$(RM) -r $(OBJ_DIR); \
		printf "$(RED)push_swap object files cleaned!\n$(DEF_COLOR)"; \
	fi
	@$(MAKE) clean -C $(LIBFT) -s

fclean: clean
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		printf "$(CYAN)push_swap executable cleaned!\n$(DEF_COLOR)"; \
	fi
	@if [ -f $(CHECKER) ]; then \
		$(RM) $(CHECKER); \
		printf "$(CYAN)Checker bonus cleaned!\n$(DEF_COLOR)"; \
	fi
	@$(MAKE) fclean -C $(LIBFT) -s

re: fclean all
	@printf "$(TERM_UP)$(GREEN)Cleaned and rebuilt everything for push_swap!\n$(DEF_COLOR)"

norm:
	@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm bonus
