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

all: $(LIBRARY) 

$(LIBRARY): $(OBJS)
	@echo creating library	
	$(AT)-ar -rcs $(LIBRARY) $(OBJS) $(INCS)
	$(AT)-ranlib $(LIBRARY)

$(OBJS): $(SRCS) $(INCS) Makefile $(DIR_OBJS)
	$(V_CC) -I$(DIR_INCS) -c $(FLAGS) $< -o $@

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
