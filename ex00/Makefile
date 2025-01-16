NAME = scalar

GXX = c++

CFLAGS = -Wall -Werror -Wextra --std=c++98 -g

SRC = main.cpp \
		ScalarConverter.cpp

HEADERS = ScalarConverter.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(OBJ): $(SRC)
	$(GXX) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(GXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re