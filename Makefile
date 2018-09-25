CC = g++
CFLAGS = -Wall -std=c++17
EXE = main
OBJ = database/dataentry.o main.o

BUILD_DIR = database


all: $(EXE)

clean: rm $(EXE) $(OBJ)

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ 
