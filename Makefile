#CC = g++
CC = nvcc
DEBUG=yes
ifeq ($(DEBUG),yes)
	#CFLAGS= -W -Wall -ansi -pedantic -std=c++14 -g
	CFLAGS=
	LDFLAGS=
else
	CFLAGS= -W -Wall -ansi -pedantic -std=c++14 
	LDFLAGS=
endif


EXE = main test_database test_dataentry
OBJ = database/dataentry.o database/database.o
#CPPFLAGS = -Dwith_cuda

BUILD_DIR = database


all: $(EXE)

clean: 
	rm $(EXE) $(OBJ) $(EXE).o

main: main.o $(OBJ)
	$(CC) $(OBJ) $< -o $@

test_dataentry: test_dataentry.o $(OBJ)
	$(CC) $(OBJ) $< -o $@

test_database: test_database.o $(OBJ)
	$(CC) $(OBJ) $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ 
