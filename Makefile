compiler = g++
libs = -lstdc++fs
flags = -std=c++17

all: main.o
	$(compiler) main.o -o binary $(flags) $(libs)

main.o:main.cpp
	$(compiler) -c main.cpp 

run:binary
	./binary

clean:
	rm *.o binary
