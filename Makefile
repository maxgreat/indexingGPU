#CC = g++
CC = nvcc
DEBUG=yes
ifeq ($(DEBUG),yes)
	#CFLAGS= -W -Wall -ansi -pedantic -std=c++14 -g
	#CFLAGS= -std=c++11 -I /usr/local/cuda-8.0/include/ -arch=sm_50 --dont-use-profile -ldir=/usr/local/cuda/nvvm/libdevice
	CFLAGS= -std=c++11 -I /usr/local/cuda-8.0/include/ -arch=sm_50 -L/usr/local/cuda-8.0/lib64
	LDFLAGS= -I /usr/local/cuda-8.0/include/ -std=c++11 -L/usr/local/cuda-8.0/lib64 -lcudadevrt -lcudart -lcurand
else
	CFLAGS= -W -Wall -ansi -pedantic -std=c++14 
	LDFLAGS= -L/usr/local/cuda-9.0/lib64 -lcudadevrt -lcudart -lcurand
endif


EXE = main test_database test_dataentry
#EXE = main
OBJ = database/dataentry.o database/database.o
#CPPFLAGS = -Dwith_cuda

BUILD_DIR = database


all: $(EXE)

clean: 
	rm $(EXE) $(OBJ) main.o test_dataentry.o test_database.o

main: main.o $(OBJ)
	g++ $(OBJ) $< -o $@ $(LDFLAGS) $(CPPFLAGS)
#g++ -L/usr/local/cuda-9.0/lib64  $(OBJ) main.o -o main -lcudadevrt -lcudart	

test_dataentry: test_dataentry.o $(OBJ)
	g++ $(OBJ) $< -o $@ $(LDFLAGS) $(CPPFLAGS)

test_database: test_database.o $(OBJ)
	g++ $(OBJ) $< -o $@ $(LDFLAGS) $(CPPFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< $(CPPFLAGS)
	 
%.o: %.cu
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< $(CPPFLAGS)

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ 
