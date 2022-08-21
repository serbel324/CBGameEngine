CC=g++
CFLAGS=-c -Wall -std=c++17
LDFLAGS=
EXECUTABLE=game

COMMON_INC = .

SFML_SRC_PATH=src

SFML_WINDOWS_PATH=/MinGW
SFML_LINUX_PATH=/GCC

EXECUTABLE=app
SFML_BIN_PATH=

SFML_PATH=$(SFML_SRC_PATH)
ifeq ($(OS),Windows_NT)
	SFML_PATH=$(SFML_SRC_PATH)$(SFML_WINDOWS_PATH)
	EXECUTABLE+=.exe
	SFML_BIN_PATH=$(SFML_PATH)/bin
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		SFML_PATH+=$(SFML_SRC_PATH)$(SFML_LINUX_PATH)
	endif
endif

SFML_INC_PATH=$(SFML_PATH)/include
SFML_LIB_PATH=$(SFML_PATH)/lib

INC=-I$(SFML_INC_PATH) -I$(COMMON_INC)
LIB=-L$(SFML_LIB_PATH)

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

SRCS=$(wildcard *.cpp) $(wildcard */*.cpp)
OBJS=$(patsubst %.cpp, $(ODIR)/%.o, $(SRCS))

ODIR=obj

app: $(OBJS)
	mkdir -p obj
	mkdir -p obj/core
	mkdir -p obj/util

	$(CC) $(OBJS) -o app.exe $(LIB) $(LIBS)
	export LD_LIBRARY_PATH=SFML_LIB_PATH

ifeq ($(OS),Windows_NT)
	cp -a $(SFML_BIN_PATH)/*.dll ./
endif

	
$(ODIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) $< -o $@

clean:
	rm *.exe
	rm *.dll
	find . -type f -name "*.o" -delete