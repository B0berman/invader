##
## Makefile for  in /home/hugo/invader
## 
## Made by Hugo
## Login   <hugo@epitech.net>
## 
## Started on  Sun Jul 22 01:59:10 2018 Hugo
## Last update Sun Jul 22 02:53:35 2018 Hugo
##

CXX	= 	g++

NAME	=	invader

SRCS	=	main.cpp \
		Core.cpp \
		Atribute.cpp

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS	+= -std=c++11 -fPIC -g -I ./external-lib/SFML-2.5.0/include \
			-I ./external-lib/SFML-2.5.0/include \
			-I ./external-lib/SFML-2.5.0/include/SFML \
			-I ./external-lib/SFML-2.5.0/include/SFML/System \
			-I ./external-lib/SFML-2.5.0/include/SFML/Audio \
			-I ./external-lib/SFML-2.5.0/include/SFML/Network \
			-I ./external-lib/SFML-2.5.0/include/SFML/Window \
			-I ./external-lib/SFML-2.5.0/include/SFML/Graphics

LDXXFLAGS	+= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDXXFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
