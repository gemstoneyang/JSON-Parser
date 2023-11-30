NAME		= json_parser
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS		= main.cpp \
			  Element/JsonElement.cpp \
			  Element/JsonObject.cpp \
			  Element/JsonArray.cpp

OBJS		= $(SRCS:%.cpp=%.o)

all	:		$(NAME)

$(NAME) : 	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o	: 		%.cpp
			$(CXX) $(CXXFLAGS) -c $^ -I./ -o $@

clean	:
			rm -f $(OBJS)

fclean	:
			make clean
			rm -f $(NAME)

re	:
			make fclean
			make all

.PHONY	:	all clean fclean re