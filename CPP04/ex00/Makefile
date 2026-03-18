NAME = test
CXX = c++
CXXFLAGS += -Wall -Werror -Wextra -Wshadow
SRC_DIR = ./src
OBJ_DIR = ./obj
SRC = Animal.cpp Dog.cpp Cat.cpp main.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -Iinclude $(OBJ) -o $(NAME)
	@ echo "${GREEN}$(NAME)${RESET} made successfully"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re