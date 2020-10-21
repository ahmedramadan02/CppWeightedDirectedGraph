TARGET=output.exe
CC=c++
CPPFLAGS=-g -std=c++14 # C++14 for testing Variable template
LDFLAGS= 

# Becuase of the template functions		
# We include .hpp otherwise a linking error will be thrown
SRCS = main.cpp \
		graph.hpp \
		vertex.hpp \
		edge.cpp \
		GraphSet.hpp \
		utils.cpp \
		GraphNode.hpp \
		MyException.cpp \
		UTest/UTest.c \

.PHONY: all
all: $(TARGET)

$(TARGET):  $(SRCS)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm $(TARGET)