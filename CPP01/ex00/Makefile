NAME = zombie
CXX = g++
CXXFLAGS += -Wall -Werror -Wextra
SRC = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

flcean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
