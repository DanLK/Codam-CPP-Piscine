NAME = clapTrap
CXX = c++
CXXFLAGS += -Wall -Werror -Wextra
SRC = ClapTrap.cpp main.cpp
OBJ = $(SRC:%.cpp=%.o)

GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@ echo "${GREEN}$(NAME)${RESET} made successfully"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re