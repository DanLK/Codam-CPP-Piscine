NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:%.cpp=%.o)
CXX = c++
CXXFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o megaphone

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re