NAME := pipex_bonus

CC = gcc
C_FLAGS = -g -Wall -Werror -Wextra

DIR_SRCS := srcs
DIR_OBJS := objs
DIR_INCS := ../includes
DIR_LIBFT := ../libft
DIR_GNL	:= ../gnl

C_FILES := child_bonus.c error_bonus.c here_doc.c pipex_bonus.c tools.c

O_FILES := $(C_FILES:.c=.o)
H_FILE := pipex_bonus.h
LIBFT := $(DIR_LIBFT)/libft.a
GNL	:= $(DIR_GNL)/gnl.a

SRCS = $(addprefix $(DIR_SRCS)/,$(C_FILES))
OBJS = $(addprefix $(DIR_OBJS)/,$(O_FILES))
INC = $(addprefix $(DIR_INCS)/,$(H_FILE))

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(C_FLAGS) $^ -o $@ 

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INC) Makefile | $(DIR_OBJS)
	$(CC) $(C_FLAGS) -I$(DIR_INCS) -c $<  -o $@

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT) 
$(GNL):
	$(MAKE) -C $(DIR_GNL)

$(DIR_OBJS):
	mkdir -p $@

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: all clean fclean re