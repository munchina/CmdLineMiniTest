CXX = g++
TARGET = shell_test
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))
CXXFLAGS = -std=c++11 -Wall -g

all: shell_test
INCLUDES = -I ./ /usr/include/

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

# shell_test: shell_test.o
# 	$(CXX) -o shell_test.out shell_test.o
# 	./shell_test.out

# shell_test.o: shell_test.cpp
# 	$(CXX) -c shell_test.cpp


.PHONY: clean shell_test

clean:
	rm -f *.o *.out $(TARGET)
