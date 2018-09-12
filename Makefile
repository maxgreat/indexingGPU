CC = g++
CFLAGS = -Wall
EXE = main
OBJ = database/dataentry.o

BUILD_DIR = database


all: $(EXE)

clean: rm $(EXE) $(OBJ)

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ 
