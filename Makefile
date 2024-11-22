# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:53:44 by mgendrot          #+#    #+#              #
#    Updated: 2024/11/22 17:05:53 by mgendrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME        = push_swap

INCLUDE     = include
LIBFT       = libft/

CC          = cc 
CFLAGS      = -Wall -Wextra -Werror -I $(INCLUDE)

RM          = rm -f
MKDIR       = mkdir

# **************************************************************************** #
#                                   Colors                                     #
#                                                                              #
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
#                                                                              #
#                                   Sources                                    #
#                                                                              #
# **************************************************************************** #



SRC_FILES       =   main parse tiny_sort utils utils_stack position cost
PRINTERS_FILES  =   Push reverse_rotate rotate swap

# **************************************************************************** #
#                                                                              #
#                                   OBJS                                       #
#                                                                              #
# **************************************************************************** #

SRC_DIR         = src/
PRINTERS_DIR    = $(SRC_DIR)/instructions/

SRC             =   $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRC_PRINTERS    =   $(addprefix $(PRINTERS_DIR), $(addsuffix .c, $(PRINTERS_FILES)))

OBJ_DIR         = obj/
OBJ             =   $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_PRINTERS    =   $(addprefix $(OBJ_DIR), $(addsuffix .o, $(PRINTERS_FILES)))

# **************************************************************************** #
#                                                                              #
#                             progress_update                                  #
#                                                                              #
# **************************************************************************** #

TOTAL_FILES     :=   $(words $(SRC) $(SRC_PRINTERS))
COMPILED_COUNT  =   0


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
#                                                                              #
#                                                                              #
#                                                                              #
# **************************************************************************** #

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_PRINTERS)
			@$(MAKE) -C $(LIBFT) all -s
			@$(CC) $(CFLAGS) $(OBJ) $(OBJ_PRINTERS) -L $(LIBFT) -lft -o $(NAME)
			@echo  "$(TERM_CLEAR_LINE)$(GREEN)push_swap compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			$(call progress_update,$(notdir $@))
			@$(CC) $(CFLAGS)  -c $< -o $@
				
$(OBJ_DIR)%.o: $(PRINTERS_DIR)%.c | $(OBJF)
			$(call progress_update,$(notdir $@))
			@$(CC) $(CFLAGS)  -c $< -o $@


$(OBJF):
			@$(MKDIR) -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(MAKE) clean -C $(LIBFT) -s
			@echo  "$(RED)push_swap object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(MAKE) fclean -C $(LIBFT) -s
			@echo  "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo  "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true



.PHONY:		all clean fclean re norm