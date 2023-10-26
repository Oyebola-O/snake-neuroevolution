CC=g++
SFML_INCLUDE=-I/opt/homebrew/Cellar/sfml/2.6.0/include
SFML_LIB=-L/opt/homebrew/Cellar/sfml/2.6.0/lib

LIB=-I./lib
SRC=-I./src

INCLUDE_DIRS=$(LIB) $(SRC) $(SFML_INCLUDE)
LIB_DIRS=$(SFML_LIB)
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

CFLAGS=-std=c++20 -g $(INCLUDE_DIRS)
LDFLAGS=$(LIB_DIRS) $(LIBS)

SRCS = $(shell find src -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

all: exec

debug: exec
	lldb ./exec

exec: $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

main.o: main.cpp
	$(CC) -c $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o exec
	find . -name "*.o" -type f -delete

run: exec
	./exec
