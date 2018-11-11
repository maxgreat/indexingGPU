#CC = g++
CC = nvcc
DEBUG=yes
INC=-I/usr/local/cuda-8.0/include/ -I../

CFLAGS= -std=c++11 $(INC) -arch=sm_50
LDFLAGS= -std=c++11 -L/usr/local/cuda-8.0/lib64 -lcudadevrt -lcudart -lcurand

BUILD_DIR = ../database
BUILD_DIR += ../ml


EXE = test_database test_dataentry
#CPPFLAGS = -Dwith_cuda
OBJ = ../database/database.o ../database/dataentry.o ../ml/knn.o

all: $(EXE)

clean:
	rm $(EXE) *.o

test_database: test_database.o
	g++ $(OBJ) $< -o $@ $(LDFLAGS)

test_dataentry: test_dataentry.o
		g++ $(OBJ) $< -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES)-c $< $(CPPFLAGS)

%.o: %.cu
	$(CC) $(CFLAGS) $(INCLUDES)-c $< $(CPPFLAGS)
