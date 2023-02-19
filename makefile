TARGET = ./bin/prog

CXX 		= 	g++
CXXFLAGS 	= 	-ggdb3 -std=c++11 -O2 -Wall -Wextra 								\
			  	-no-pie -Wno-narrowing -Wno-unused-parameter -Wno-unused-variable	\

# SRC_DIR		= ./ ./src/class_kernel ./src/class_sys ./src/class_r_vector 
# BUILD_DIR 	= build

SRC 	= $(wildcard src/*.cpp src/graph_lib/*.cpp src/log/*.cpp src/class_tool/*.cpp)

INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ $(INCLUDE) -o $@


.PHONY: build
build:
	$(CXX) $(CXXFLAGS) $(SRC) $(INCLUDE) -o $(TARGET)


.PHONY: run
run:
	./bin/prog


.DEFAULT_GOAL = build
# all:
# 	g++ src/main.cpp src/general_func.cpp                                                   \
#                     src/class_r_vector/class_r_vector.cpp src/class_r_vector/operators.cpp  \
#                     src/class_sys/class_sys.cpp src/class_kernel/class_kernel.cpp           \
#                         -lsfml-graphics -lsfml-window -lsfml-system