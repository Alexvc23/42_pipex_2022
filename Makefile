
#                   _         __ _ _              _
#   _ __ ___   __ _| | _____ / _(_) | ___   _ __ (_)_ __   _____  __
#  | '_ ` _ \ / _` | |/ / _ \ |_| | |/ _ \ | '_ \| | '_ \ / _ \ \/ /
#  | | | | | | (_| |   <  __/  _| | |  __/ | |_) | | |_) |  __/>  <
#  |_| |_| |_|\__,_|_|\_\___|_| |_|_|\___| | .__/|_| .__/ \___/_/\_\
#                                          |_|     |_|

# ─── VARIABLES ───────────────────────────────────────────────────
	
V_CC := @echo "Building $@..."; $(CC)
AT := @
CC := gcc
EXEC		:= pipex 
DIR_SRCS	:= srcs
FLAGS		:= -g -Wall -Werror -Wextra
DIR_OBJS	:= objs
DIR_INCS	:= includes
DIR_LIBFT	:= libft
DIR_GNL		:= gnl
FILE_INCS	:= pipex.h
SRCS = $(addprefix $(DIR_SRCS)/,$(C_FILES))
OBJS = $(addprefix $(DIR_OBJS)/,$(O_FILES))
INCS = $(addprefix $(DIR_INCS)/,$(FILE_INCS))
LIBFT := $(DIR_LIBFT)/libft.a
GNL	:= $(DIR_GNL)/gnl.a
O_FILES = $(C_FILES:.c=.o)
C_FILES	:= pipex.c tools.c \

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
	
all: $(EXEC)
	$(AT) chmod 777 $<

$(EXEC): $(LIBFT) $(GNL) $(OBJS) $(INCS)
	$(AT) $(CC)  $(OBJS) $(LIBFT) $(GNL) $< -o $(EXEC)
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(BOLD)$(CYAN) $@ $(END)\n"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c Makefile $(INCS) | $(DIR_OBJS)
	$(AT) $(CC) -I$(DIR_INCS) $(FLAGS) -c $< -o $@ 
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(RED) $@ $(END)\n"

$(DIR_OBJS):
	$(AT) mkdir -p $@ 

$(LIBFT): $(DIR_LIBFT)/Makefile $(DIR_LIBFT)/srcs/* $(DIR_LIBFT)/includes/libft.h
	 $(AT) $(MAKE) -C $(DIR_LIBFT)

$(GNL): $(DIR_GNL)/Makefile $(DIR_GNL)/srcs/* $(DIR_GNL)/includes/get_next_line.h
	 $(AT) $(MAKE) -C $(DIR_GNL)

	
clean:
	@echo Removing object files
	$(AT) $(MAKE) -C $(DIR_LIBFT) clean
	$(AT) $(MAKE) -C $(DIR_GNL) clean
	$(AT)-rm -rf $(DIR_OBJS)	 
fclean: clean
	@echo Removing application
	$(AT)-rm -f $(EXEC)
	$(AT) $(MAKE) -C $(DIR_LIBFT) fclean
	$(AT) $(MAKE) -C $(DIR_GNL) fclean
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)$(EXEC)$(END)\n"

re: fclean all	

.PHONY: all clean fclean
.DEFAULT: all
