CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =  main.cpp\
        A.cpp\
		B.cpp\
		C.cpp\
		Base.cpp


NAME = real_type

OBJECTS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

%.o: %.cpp  A.hpp B.hpp C.hpp Base.hpp
	c++ $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	c++ $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all