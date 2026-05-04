CXX = g++-14
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = census_bst

SOURCES = main.cpp CensusData.cpp BinarySearchTree.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)