CXX := c++
CXXFLAGS += -Wall -Wextra -Werror
SRC_DIR := ./src
OBJ_DIR := ./obj
SRC := Contact.cpp PhoneBook.cpp pbsoftware.cpp
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -Iinclude $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -Iinclude $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
