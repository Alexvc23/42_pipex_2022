#              _                       _       _ _
#    __ _  ___| |_     _ __   _____  _| |_    | (_)_ __   ___
#   / _` |/ _ \ __|   | '_ \ / _ \ \/ / __|   | | | '_ \ / _ \
#  | (_| |  __/ |_    | | | |  __/>  <| |_    | | | | | |  __/
#   \__, |\___|\__|___|_| |_|\___/_/\_\\__|___|_|_|_| |_|\___|
#   |___/        |_____|                 |_____|



V_CC = @echo "Building $@..."; $(CC)
AT = @
LIBRARY	= gnl.a 
FLAGS	= -Wall -Werror -Wextra -D BUFFER_SIZE=100
DIR_SRCS = srcs
DIR_OBJS = objs
DIR_INCS = includes
O_FILES = $(C_FILES:.c=.o)

SRCS = $(addprefix $(DIR_SRCS)/,$(C_FILES))
OBJS = $(addprefix $(DIR_OBJS)/,$(O_FILES))
INCS = $(addprefix $(DIR_INCS)/,$(INCLUDES))

C_FILES = get_next_line.c tools.c

INCLUDES := get_next_line.h

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

all: $(LIBRARY) 

$(LIBRARY): $(OBJS)
	$(AT)-ar -rcs $(LIBRARY) $(OBJS) $(INCS)
	$(AT)-ranlib $(LIBRARY)
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(BOLD)$(CYAN) $@ $(END)\n"

$(OBJS): $(SRCS) $(INCS) Makefile | $(DIR_OBJS)
	$(AT) $(CC) -I$(DIR_INCS) -c $(FLAGS) $< -o $@
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(RED) $@ $(END)\n"

$(DIR_OBJS):
	$(AT)-mkdir -p $@ 
	
clean:
	@echo Removing object files
	$(AT)-rm -rf $(DIR_OBJS)	 

fclean: clean
	@echo Removing application
	$(AT)-rm -f $(LIBRARY)

re: fclean all	

.PHONY: all clean fclean
.DEFAULT: all
