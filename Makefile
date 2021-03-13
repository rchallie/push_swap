# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 15:26:30 by rchallie          #+#    #+#              #
#    Updated: 2021/03/13 20:59:40 by rchallie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM INFORMATIONS =========================================================
NAME = checker #push_swap
NAME_CHECKER	= checker
# ==============================================================================

# COLORS =======================================================================
GREEN=$'\x1b[32m
WHITE=$'\x1b[37m
# ==============================================================================

# SOURCES ======================================================================
SOURCES_DIR_CHECKER = 	checker_f/mandatory/sources/
SOURCES_CHECKER =	checker.c \
					error_clear.c \
					sequence.c
# ==============================================================================

# INCLUDES =====================================================================
INCLUDES_LIBFT = libft/

INCLUDES_CHECKER = checker_f/mandatory/includes/
# ==============================================================================

# OBJECTS ======================================================================
OBJECTS_DIR_CHECKER = checker_f/mandatory/objects/
OBJECT_CHECKER = $(SOURCES_CHECKER:.c=.o)
OBJECTS_CHECKER = $(addprefix $(OBJECTS_DIR_CHECKER), $(OBJECT_CHECKER))
# ==============================================================================

# FLAGS ========================================================================
FLAGS = -Wall -Wextra -Werror --std=c99
# ==============================================================================

# OBJECTS COMPILE ==============================================================
$(OBJECTS_DIR_CHECKER)%.o : $(SOURCES_DIR_CHECKER)%.c $(INCLUDES_CHECKER)checker.h
		@mkdir -p $(OBJECTS_DIR_CHECKER)
		@echo "$(_WHITE)Compiling: $(_GREEN)$<$(_WHITE)"
		@clang $(FLAGS) -I$(INCLUDES_LIBFT) -I$(INCLUDES_CHECKER) -c $< -o $@
# ==============================================================================

# LIBRARIES ====================================================================
LIB_LIBFT = $(INCLUDES_LIBFT)libft.a
# ==============================================================================

# COMMONS ======================================================================

$(NAME): $(OBJECTS_CHECKER)
		@$(MAKE) bonus -C libft 
		@echo "Compiling $(NAME_CHECKER) ..."
		@clang $(FLAGS) -I$(INCLUDES_CHECKER) -I$(INCLUDES_LIBFT) $(OBJECTS_CHECKER) -L$(INCLUDES_LIBFT) $(LIB_LIBFT) -o $(NAME_CHECKER)
		@echo "$(_GREEN)Done!$(_WHITE)"

all: $(NAME)

clean:
		@$(MAKE) clean -C libft
		@echo "$(_WHITE)Cleaning: $(_GREEN)$(OBJECTS_DIR_CHECKER)$(_WHITE)"
		@rm -rf $(OBJECTS_DIR_CHECKER)

fclean: clean
		@$(MAKE) fclean -C libft 
		@echo "$(_WHITE)Cleaning: $(_GREEN)$(NAME_CHECKER)$(_WHITE)"
		@rm -f $(NAME_CHECKER)

re: fclean all

# ==============================================================================

# ADDONS =======================================================================
run : all
	./checker
# ==============================================================================