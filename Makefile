
#                   _         __ _ _              _
#   _ __ ___   __ _| | _____ / _(_) | ___   _ __ (_)_ __   _____  __
#  | '_ ` _ \ / _` | |/ / _ \ |_| | |/ _ \ | '_ \| | '_ \ / _ \ \/ /
#  | | | | | | (_| |   <  __/  _| | |  __/ | |_) | | |_) |  __/>  <
#  |_| |_| |_|\__,_|_|\_\___|_| |_|_|\___| | .__/|_| .__/ \___/_/\_\
#                                          |_|     |_|

# ─── VARIABLES ───────────────────────────────────────────────────
	
V_CC := @echo "Building $@..."; $(CC)
AT := 
CC := gcc
EXEC			:= pipex 
EXEC_BONUS		:= pipex_bonus 
DIR_SRCS		:= srcs
DIR_SRCS_BONUS	:= bonus 
FLAGS			:= -g -Wall -Werror -Wextra
DIR_OBJS		:= objs
DIR_OBJS_BONUS	:= objs_bonus
DIR_INCS		:= includes
DIR_LIBFT		:= libft
DIR_GNL			:= gnl
FILE_INCS		:= pipex.h
FILE_INCS_BONUS	:= pipex_bonus.h
SRCS = 			$(addprefix $(DIR_SRCS)/,$(C_FILES))
OBJS = 			$(addprefix $(DIR_OBJS)/,$(O_FILES))
SRCS_BONUS = 	$(addprefix $(DIR_SRCS_BONUS)/,$(C_FILES_BONUS))
OBJS_BONUS = 	$(addprefix $(DIR_OBJS_BONUS)/,$(O_FILES_BONUS))
INCS = 			$(addprefix $(DIR_INCS)/,$(FILE_INCS))
LIBFT = 		$(DIR_LIBFT)/libft.a
GNL	:= 			$(DIR_GNL)/gnl.a

# ─── O FILES ───────────────────────────────────────────────────────
	
O_FILES = $(C_FILES:.c=.o)
O_FILES_BONUS = $(C_FILES_BONUS:.c=.o)

# ─── C FILES ───────────────────────────────────────────────────────
	
C_FILES	=	pipex.c \
			tools.c 
C_FILES_BONUS =	child_bonus.c \
					error_bonus.c \
					here_doc.c \
					tools.c \
					pipex_bonus.c

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
	
all: $(EXEC) libft gnl
	$(AT) chmod 777 $<

bonus:	$(EXEC_BONUS)

# Executable creation mandatory part 
$(EXEC): $(LIBFT) $(GNL) $(OBJS) $(INCS)
	$(AT) $(CC)  $(OBJS) $(LIBFT) $(GNL) $< -o $(EXEC)
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(BOLD)$(CYAN) $@ $(END)\n"

# Executable creation bonus part 
$(EXEC_BONUS): $(LIBFT) $(GNL) $(OBJS_BONUS)
	$(AT) $(CC)  $(OBJS_BONUS) $(LIBFT) $(GNL) $< -o $(EXEC_BONUS)
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(BOLD)$(CYAN) $@ $(END)\n"

# Mandatory objs creation part 
$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c Makefile $(INCS) | $(DIR_OBJS)
	$(AT) $(CC) -I$(DIR_INCS) $(FLAGS) -c $< -o $@ 
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(RED) $@ $(END)\n"

# Bonus objs creation part 
$(DIR_OBJS_BONUS)/%.o: $(DIR_SRCS_BONUS)/%.c Makefile | $(DIR_OBJS_BONUS)
	$(AT) $(CC)  $(DIR_INCS)/$(FILE_INCS_BONUS) $(FLAGS) -c $< -o $@
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(RED) $@ $(END)\n"

$(DIR_OBJS):
	$(AT) mkdir -p $@

$(DIR_OBJS_BONUS):
	$(AT) mkdir -p $@

$(LIBFT): libft 
$(GNL): gnl 

gnl:
	$(AT) $(MAKE) -C $(DIR_GNL)
libft:
	$(AT) $(MAKE) -C $(DIR_LIBFT)

clean:
	@echo Removing object files
	$(AT) $(MAKE) -C $(DIR_LIBFT) clean
	$(AT) $(MAKE) -C $(DIR_GNL) clean
	$(AT)-rm -rf $(DIR_OBJS) $(DIR_OBJS_BONUS)	 
fclean: clean
	@echo Removing application
	$(AT)-rm -f $(EXEC) $(EXEC_BONUS)
	$(AT) $(MAKE) -C $(DIR_LIBFT) fclean
	$(AT) $(MAKE) -C $(DIR_GNL) fclean
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)$(EXEC)$(END)\n"

re: fclean all	

.PHONY: all clean fclean gnl libft
.DEFAULT: all
