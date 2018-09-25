CC = g++
CFLAGS = -Wall -std=c++17 -g
EXE = main test_database
OBJ = database/dataentry.o database/database.o
#CPPFLAGS = -Dwith_cuda

BUILD_DIR = database


all: $(EXE)

clean: 
	rm $(EXE) $(OBJ) $(EXE).o

main: main.o $(OBJ)
	$(CC) -g $(OBJ) main.o -o main

test_database: test_database.o $(OBJ)
	$(CC) -g $(OBJ) test_database.o -o test_database

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ 
