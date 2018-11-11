#CC = g++
CC = nvcc
DEBUG=yes
INC=-I/usr/local/cuda-8.0/include/ -I./
SUBDIRS := $(wildcard */.)


ifeq ($(DEBUG),yes)
	#CFLAGS= -W -Wall -ansi -pedantic -std=c++14 -g
	#CFLAGS= -std=c++11 -I /usr/local/cuda-8.0/include/ -arch=sm_50 --dont-use-profile -ldir=/usr/local/cuda/nvvm/libdevice
	CFLAGS= -std=c++11 $(INC) -arch=sm_50 -L/usr/local/cuda-8.0/lib64
	LDFLAGS= $(INC) -std=c++11 -L/usr/local/cuda-8.0/lib64 -lcudadevrt -lcudart -lcurand
else
	CFLAGS= -W -Wall -ansi -pedantic -std=c++14
	LDFLAGS= -L/usr/local/cuda-9.0/lib64 -lcudadevrt -lcudart -lcurand
endif


EXE = main
#EXE = main
OBJ = database/dataentry.o database/database.o ml/knn.o
#CPPFLAGS = -Dwith_cuda

BUILD_DIR = database


all: $(EXE) $(SUBDIRS)


clean:
	rm $(EXE) main.o */*.o

main: main.o $(OBJ)
	g++ $(OBJ) $< -o $@ $(LDFLAGS) $(CPPFLAGS)

test:
				$(MAKE) -C $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< $(CPPFLAGS)

%.o: %.cu
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< $(CPPFLAGS)

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all $(SUBDIRS)
