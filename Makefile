CC=g++
CFLAGS=-c -Wall
LDFLAGS=
EXECUTABLE=game

COMMON_INC = .

SFML_PATH=src

SFML_INC_PATH=$(SFML_PATH)/include
SFML_LIB_PATH=$(SFML_PATH)/lib

INC=-I$(SFML_INC_PATH) -I$(COMMON_INC)
LIB=-L$(SFML_LIB_PATH)

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

SRCS=$(wildcard *.cpp) $(wildcard */*.cpp)
OBJS=$(patsubst %.cpp, $(ODIR)/%.o, $(SRCS))

ODIR=obj

app: $(OBJS)
	ls $(SFML_LIB_PATH)
	$(CC) $(OBJS) -o app.exe $(LIB) $(LIBS)
	
$(ODIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) $< -o $@

clean:
	find . -type f -name "*.o" -delete