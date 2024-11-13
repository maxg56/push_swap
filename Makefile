# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:59:30 by mgendrot          #+#    #+#              #
#    Updated: 2024/11/13 13:42:32 by mgendrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= push_swap
NAMETESTS	= tests.out
LIBFT_DIR		= libft/
INCLUDES	= push_swap.h

CC			= cc 
CFLAGS		= -Wall -Wextra -Werror 

RM 			= rm 
AR			= ar rcs
MKDIR		= mkdir

# **************************************************************************** #
#                                   Colors                                     #
#                                                                              #
# **************************************************************************** #
DEF_COLOR   		=   \033[0;39m
GRAY 				=   \033[0;90m
RED 				=   \033[0;91m
GREEN      			=   \033[0;92m
YELLOW 				=   \033[0;93m
BLUE        		=   \033[0;94m
MAGENTA				=	\033[0;95m
CYAN       			=   \033[0;96m
WHITE 				=   \033[0;97m
BOLD 				=   $'\x1b[1m'
END 				=   $'\x1b[0m'
TERM_UP				=   \033[1A
TERM_CLEAR_LINE		=   \033[2K\r

# **************************************************************************** #
#                                                                              #
#                                   Sources                                    #
#                                                                              #
# **************************************************************************** #

FTPRINT       	=   push_swap Push swap rotate reverse_rotate

SRCS 		= 	$(addsuffix .c, $(FTPRINT))
# **************************************************************************** #
#                                                                              #
#                                   OBJS                                       #
#                                                                              #
# **************************************************************************** #

OBJS_DIR	=	obj/
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FTPRINT)))

# **************************************************************************** #
#                                                                              #
#                             progress_update                                  #
#                                                                              #
# **************************************************************************** #
TOTAL_FILES      := $(words $(FTPRINT))
COMPILED_COUNT    = 0

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
OBJSF		=	.cache_exists


all:		${NAME}

${NAME}:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -L $(LIBFT_DIR)  -l ft -o ${NAME} 
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"


$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@mkdir -p $(dir $@)
			$(call progress_update,$(notdir $@))
			@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
$(OBJSF):

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)
			@echo  "$(RED)push_swap objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@${RM} -f ${NAME}
			@echo  "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo  "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"


tests:		all
			 @${CC} ${CFLAGS} tests/.tests.c tests/main.c -L . -l ft  -o ${NAMETESTS}
			 @echo -e "$(GREEN)$(BOLD)tests compiled!$(END)$(DEF_COLOR)""
			 ./${NAMETESTS}
			 @rm -f ${NAMETESTS}
			
.PHONY:		all clean fclean re  tests 