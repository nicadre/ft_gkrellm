#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/18 09:53:09 by niccheva          #+#    #+#              #
#    Updated: 2015/04/19 03:18:29 by llapillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	ft_gkrellm

CC				=	clang++ $(FLAGS)

FLAGS			=	-Wall -Wextra -Werror

DSRC			=	./srcs/

DOBJ			=	./objs/

DINC			=	./includes/

SRC				=	CPUModule.class.cpp				\
					HostUsernameModule.class.cpp	\
					OSModule.class.cpp				\
					TimeModule.class.cpp			\
					MemoryModule.class.cpp			\
					getInfos.cpp					\
					main.cpp

OBJ				=	$(patsubst %.cpp, $(DOBJ)%.o, $(SRC))

RMF				=	/bin/rm -f
RMD				=	/bin/rm -Rf
MKD				=	/bin/mkdir -p

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creation de l'executable :\033[0;32m"
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lncurses
	@echo "\033[0;m\c"

$(DOBJ)%.o: $(DSRC)%.cpp
	@$(MKD) $(DOBJ)
	@echo "Compilation de l'objet :\033[0;32m"
	$(CC) -o $@ -c $< -I$(DINC)
	@echo "\033[0;m\c"

clean:
	@echo "Suppression de l'objet :\033[0;31m"
	$(RMF) $(OBJ)
	@echo "\033[0;m\c"
	@$(RMD) $(DOBJ)

fclean: clean
	@echo "Suppression de l'executable :\033[0;31m"
	$(RMF) $(NAME)
	@echo "\033[0;m\c"

re: fclean all

.PHONY: all clean fclean re
