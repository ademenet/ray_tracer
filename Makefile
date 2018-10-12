SRC_PATH = ./src/
INC_PATH = ./include/
OBJ_PATH = ./obj/

SRC_NAME = main.cpp
OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
INC = $(addprefix -I, $(INC_PATH))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME = rt
CC = clang++
CFLGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLGS) $(INC) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -fv $(NAME)

re: fclean all
