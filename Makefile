NAME			=	launch

SRCS			=	main.cpp									\
					tests/test_vector.cpp					\
					tests/test_stack.cpp					\
					tests/test_map.cpp					
				#	tests/test_set.c					
SRC_DIR			=  

OBJ_DIR			= objs/

OBJS			= $(addprefix $(OBJ_DIR), ${SRCS:.cpp=.o})
OBJS_STD		= $(addprefix $(OBJ_DIR), ${SRCS:.cpp=.o.std})

DIR				= $(sort $(dir $(OBJS)))

DEP				= ${OBJS:.o=.d}

CC				= clang++

CFLAGS			= -Imap -Ivector -Istack -Iiterators -Itests -fsanitize=address -g3 -Wall -Wextra -Werror -MMD

RM				= rm -rf

MAKE			+= --no-print-directory

all:
				@${MAKE} -j ${NAME}


$(NAME):		${OBJS}
				@${CC} -o $@ ${OBJS} ${CFLAGS}
				@${CC} -o $@_std ${OBJS_STD} ${CFLAGS}
				@printf "\033[32mAll done. Please execute :)\033[0m\n"

$(DIR):    
				@mkdir -p $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp Makefile | $(DIR)
				$(CC) -c $< -o $@ ${CFLAGS}
				$(CC) -c $< -o $@.std ${CFLAGS} -DNAMESPACE=std

clean:   
				@echo "Cleaning files..."
				@${RM} ${OBJ_DIR}
				@printf "\033[32mClean done !\033[0m\n"

fclean:			clean
				@echo "Cleaning the rest..."
				@${RM} ${NAME}
				@printf "\033[32mFClean done !\033[0m\n"

re:				fclean 
				@${MAKE} all

test: all
	$(shell ./launch > ft_output )
	$(shell ./launch_std > std_output )
	$(shell diff ft_output std_output )
	@echo "OK !"

-include		${OBJS:.o=.d}

.PHONY:			all clean fclean re test
