NAME = serialize

GXX = c++

CFLAGS = -Wall -Werror -Wextra --std=c++98 -g

SRC = main.cpp \
		Serializer.cpp

HEADERS = Serializer.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GXX) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(GXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re