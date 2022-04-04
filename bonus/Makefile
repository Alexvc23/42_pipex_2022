NAME := pipex_bonus
AT	 = @

CC = gcc
C_FLAGS = -g -Wall -Werror -Wextra

DIR_SRCS_BONUS = srcs
DIR_OBJS_BONUS = objs
DIR_INCS := ../includes
DIR_LIBFT := ../libft
DIR_GNL	:= ../gnl

C_FILES_BONUS := child_bonus.c error_bonus.c here_doc.c pipex_bonus.c tools.c

O_FILES_BONUS := $(C_FILES_BONUS:.c=.o)
H_FILE_BONUS := pipex_bonus.h
LIBFT := $(DIR_LIBFT)/libft.a
GNL	:= $(DIR_GNL)/gnl.a

SRCS_BONUS = $(addprefix $(DIR_SRCS_BONUS)/,$(C_FILES_BONUS))
OBJS_BONUS = $(addprefix $(DIR_OBJS_BONUS)/,$(O_FILES_BONUS))
FILE_INCS_BONUS = $(addprefix $(DIR_INCS)/,$(H_FILE))

# ─── COLORS ────────────────────────────────────────────────────────
	
ERASE	=	\033[2K\r
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PINK	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m
BOLD	=	\033[1m
UNDER	=	\033[4m
SUR		=	\033[7m
END		=	\033[0m

# ─── RULES ──────────────────────────────────────────────────────────
all : $(NAME)

$(NAME): $(OBJS_BONUS) $(LIBFT) $(GNL)
	$(AT) $(CC) $(C_FLAGS) $^ -o ../$@ 
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(BOLD)$(CYAN) $@ $(END)\n"

$(DIR_OBJS_BONUS)/%.o: $(DIR_SRCS_BONUS)/%.c $(INC) Makefile | $(DIR_OBJS_BONUS)
	$(AT) $(CC) $(C_FLAGS) -I$(DIR_INCS) -c $<  -o $@
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(RED) $@ $(END)\n"

$(LIBFT):
	$(AT) $(MAKE) -C $(DIR_LIBFT)

$(GNL):
	$(AT) $(MAKE) -C $(DIR_GNL)

$(DIR_OBJS_BONUS):
	$(AT) mkdir -p $@

clean:
	$(AT) rm -rf $(DIR_OBJS_BONUS)

fclean: clean
	$(AT) rm -rf ../$(NAME)

re: clean fclean all 

.PHONY: all clean fclean re